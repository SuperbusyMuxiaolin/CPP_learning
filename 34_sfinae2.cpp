#include <iostream>
#include <string>

template <bool condition, typename T>
struct enable_if
{
};

template <typename T>
struct enable_if<true, T>
{
    using type = T;
};

template <bool condition, typename T>
using enable_if_t = typename enable_if<condition, T>::type;

template <typename T>
struct is_small
{
    static const bool value = sizeof(T) <= sizeof(void *);
};

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

struct test
{
    int arr[9999];
};

int main()
{
    fun<int>(3);
    test t;
    fun<test>(t);
}