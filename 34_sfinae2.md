# 34_sfinae2.cpp 代码讲解：enable_if 与 enable_if_t

## 1. 先回答你的问题

有，标准库已经提供了：

- `std::enable_if`
- `std::enable_if_t`（C++14 起提供）

头文件是：

```cpp
#include <type_traits>
```

你代码里的 `enab_if_t` 一般是笔误，正确名字是 `enable_if_t`。

---

## 2. enable_if 的核心原理

`enable_if` 的本质是一个“按条件决定是否提供类型成员 `type` 的模板”。

你的实现是：

```cpp
template <bool condition, typename T>
struct enable_if
{
};

template <typename T>
struct enable_if<true, T>
{
    using type = T;
};
```

含义：

- `condition == true`：存在 `type`，即 `enable_if<true, T>::type` 等于 `T`
- `condition == false`：没有 `type`

当模板替换过程中遇到“没有 `type`”时，在很多模板上下文中会触发 SFINAE：

- 替换失败，不当作编译错误
- 该候选模板被移除

这就是它能做“编译期条件重载”的原因。

---

## 3. enable_if_t 是什么

你写的别名模板：

```cpp
template <bool condition, typename T>
using enable_if_t = typename enable_if<condition, T>::type;
```

作用是简化书写。

- 不用写冗长的 `typename ...::type`
- 语义更清晰

标准库同名版本：

```cpp
std::enable_if_t<condition, T>
```

---

## 4. 结合你的代码看调用流程

你的判断条件：

```cpp
template <typename T>
struct is_small
{
    static const bool value = sizeof(T) <= sizeof(void *);
};
```

两个重载：

```cpp
template <typename T>
void fun(enable_if_t<is_small<T>::value, T> t)
{
    std::cout << 1 << std::endl;
}

template <typename T>
void fun(enable_if_t<!is_small<T>::value, T> const &t)
{
    std::cout << 2 << std::endl;
}
```

在 `main` 中你写的是：

```cpp
fun<int>(3);
test t;
fun<test>(t);
```

这能工作，是因为你显式给了模板参数 `T`。

### 为什么 `fun(3)` 可能推导失败

因为 `T` 被包在 `enable_if_t<...>` 里，参数类型处于 non-deduced context（不可推导上下文）时，编译器无法从实参直接反推 `T`，会出现“无匹配重载”。

这也是你前面报错的根因。

---

## 5. 标准库版本写法（推荐）

### 5.1 保留你原来的风格

```cpp
#include <type_traits>

template <typename T>
void fun(typename std::enable_if<(sizeof(T) <= sizeof(void *)), T>::type t)
{
    std::cout << 1 << std::endl;
}

template <typename T>
void fun(typename std::enable_if<(sizeof(T) > sizeof(void *)), T>::type const &t)
{
    std::cout << 2 << std::endl;
}
```

### 5.2 用 `std::enable_if_t` 简化

```cpp
#include <type_traits>

template <typename T>
void fun(std::enable_if_t<(sizeof(T) <= sizeof(void *)), T> t)
{
    std::cout << 1 << std::endl;
}

template <typename T>
void fun(std::enable_if_t<(sizeof(T) > sizeof(void *)), T> const &t)
{
    std::cout << 2 << std::endl;
}
```

说明：这两种写法仍可能需要 `fun<int>(3)` 这种显式模板参数。

---

## 6. 更常见且更稳的 SFINAE 写法

把 `enable_if_t` 放到模板参数列表里，让函数参数保持 `T`，通常推导更顺畅：

```cpp
#include <type_traits>

template <typename T, std::enable_if_t<(sizeof(T) <= sizeof(void *)), int> = 0>
void fun(T t)
{
    std::cout << 1 << std::endl;
}

template <typename T, std::enable_if_t<(sizeof(T) > sizeof(void *)), int> = 0>
void fun(const T &t)
{
    std::cout << 2 << std::endl;
}
```

这样一般可以直接写：

```cpp
fun(3);
test t;
fun(t);
```

---

## 7. enable_if 常见放置位置

1. 返回值位置

```cpp
template <typename T>
std::enable_if_t<std::is_integral<T>::value, T> foo(T x);
```

2. 额外函数参数位置

```cpp
template <typename T>
void foo(T x, std::enable_if_t<std::is_integral<T>::value, int> = 0);
```

3. 模板参数位置（常用）

```cpp
template <typename T, std::enable_if_t<std::is_integral<T>::value, int> = 0>
void foo(T x);
```

---

## 8. 相关知识点（建议一起掌握）

1. 类型萃取（type traits）

- `std::is_integral`
- `std::is_floating_point`
- `std::is_same`
- `std::remove_reference`

2. `std::void_t` 与检测惯用法（Detection Idiom）

- 适合检测“某个成员类型/成员函数是否存在”
- 比早期 `sizeof + 重载` 技术更直观

3. `if constexpr`（C++17）

- 同一模板内部做编译期分支
- 在很多场景可替代一部分 enable_if 重载

4. Concepts / requires（C++20）

- 语义最清晰，可读性最好
- 是现代 C++ 对模板约束的主流方案

---

## 9. 常见坑

1. 推导失败

- 症状：调用时提示没有匹配重载
- 原因：约束写在不可推导上下文

2. 两个重载条件写得不互斥

- 可能二者都可行或都不可行
- 导致二义性或找不到函数

3. 条件写错括号或逻辑非号

- 特别是 `!condition` 容易漏括号

4. 没包含 `<type_traits>`

- 使用 `std::enable_if`、`std::is_xxx` 时必须包含

---

## 10. 一句话总结

- `enable_if`：条件成立才“放出类型”，用于模板约束
- `enable_if_t`：`enable_if` 的别名简写
- 你这份代码已经体现了核心思想，后续建议优先用 `std::enable_if_t`，并逐步过渡到 `if constexpr` / `concepts`
