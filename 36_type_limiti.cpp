#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<sizeof(T) < sizeof(void *), void>
fun(T t)
{
    std::cout << 2 << std::endl;
}
template <typename T, std::enable_if_t<sizeof(T) < sizeof(void *), int> = 0>
void fun2()
{
    std::cout << "是int" << std::endl;
}

struct tt
{
    char arr[100];
};

struct T1
{
};
struct T2
{
    void method() {}
    int member;
};

template <typename T>
std::enable_if_t<std::is_same_v<decltype(T().method()), void>, void>
fun3()
{
    std::cout << "T类型包含method";
}

// 我们只关注method的类型，因此把一个空指针转化为指向T的指针调用method
template <typename T>
// std::enable_if_t<std::is_same_v<decltype(static_cast<T *>(nullptr)->method()), void>, void>
std::enable_if_t<std::is_same_v<decltype(std::declval<T>().method()), void>, void>
fun4()
{
    std::cout << "T类型不包含method";
}

template <typename T>
struct tovoid
{
    using type = void;
};
template <typename T>
using tovoid_t = typename tovoid<T>::type;

template <typename T>
std::enable_if_t<std::is_same_v<tovoid_t<decltype(std::declval<T>().method())>, void>, void>
fun5()
{
}

template <typename T>
std::enable_if_t<std::is_void_v<std::void_t<decltype(std::declval<T>().method())>>, void>
fun6()
{
}

template <typename T>
struct remove_reference
{
    using type = T;
};
template <typename T>
struct remove_reference<T &>
{
    using type = T;
};
template <typename T>
struct remove_reference<T &&>
{
    using type = T;
};
template <typename T>
using remove_reference_t = typename remove_reference<T>::type;

// std::remove_reference_t<T> 是 T 去掉引用后的类型

void test01()
{
    tt t1;
    // fun2(3.4);
    // fun2(t1);
    fun2<int>(); // int的大小小于void*
}

void test02()
{
    T1 t1;
    T2 t2;
    // fun6<T1>();
    fun6<T2>();
}
int main()
{
    test01();
    test02();
}