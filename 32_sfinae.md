# 32_sfinae.cpp 代码讲解

## 1. 代码目标
这段代码使用 **SFINAE**（Substitution Failure Is Not An Error，替换失败不是错误）来判断：

- 某个类型 `T` 是否拥有成员函数 `void reserve()`。

最终通过 `has_reserve<T>::value` 返回布尔结果：

- `true`（输出为 `1`）：有 `reserve()`
- `false`（输出为 `0`）：没有 `reserve()`

---

## 2. 核心结构说明

### 2.1 `sfinae<U, &U::reserve>`
```cpp
template <typename U, void (U::*)()>
class sfinae {};
```

- 第二个模板参数要求是“指向 `U` 成员函数”的指针，签名必须是 `void (U::*)()`。
- 只有当 `U` 真正存在 `void reserve()` 时，`&U::reserve` 才能匹配成功。

### 2.2 两个重载的 `test`
```cpp
template <typename U>
static good test(sfinae<U, &U::reserve> *);

template <typename U>
static bad test(...);
```

- 第一条重载：如果 `sfinae<U, &U::reserve>` 能成立，优先匹配，返回 `good`。
- 第二条重载：兜底匹配，返回 `bad`。

### 2.3 用 `sizeof` 区分匹配路径
```cpp
class good { char dummy[2]; };
class bad  { char dummy; };

static const bool value = sizeof(test<T>(nullptr)) == sizeof(good);
```

- `good` 大小是 2，`bad` 大小是 1。
- 如果走到 `good`，`value == true`；否则为 `false`。

---

## 3. main 函数中的两个测试类

- `testreserve`：定义了 `void reserve();`
- `testnoreserve`：没有 `reserve()`

所以：

- `has_reserve<testreserve>::value` 为 `true`
- `has_reserve<testnoreserve>::value` 为 `false`

---

## 4. 程序输出
预期输出：
```text
1
0
```

含义：

- 第 1 行 `1`：`testreserve` 有 `reserve()`。
- 第 2 行 `0`：`testnoreserve` 没有 `reserve()`。

---

## 5. 补充说明
该写法是经典的早期 SFINAE 风格。现代 C++（C++17/20）里，也可以用 `std::void_t` 或 `requires`（concept）写得更直观。