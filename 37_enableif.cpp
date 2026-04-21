#include <iostream>
#include <type_traits>

template <typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
void fun1(T t)
{
    std::cout << "T是整型" << std::endl;
}

template <typename T>
std::enable_if_t<std::is_floating_point_v<T>, void>
fun1(T t)
{
    std::cout << "T是浮点" << std::endl;
}

void test01()
{
    fun1(10);
    // fun1(10.5);
    // fun2(20);
    fun1(10.5);
}

int main()
{
    test01();
}