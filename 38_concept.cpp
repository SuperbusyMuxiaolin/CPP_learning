#include <iostream>

// 基础用法
template <typename T>
concept C1 = requires {
    std::is_trivial_v<T>;
    sizeof(T) <= sizeof(void *);
};

template <typename T>
    requires C1<T>
void fun1(T t)
{
}
struct Test
{
    int a[20];
};

// 提高用法
struct Test1
{
    void test() {}
};
struct Test2
{
};

struct Test3
{
    int test() { return 0; }
};

template <typename T>
// 虚拟一个t，然后requires后面使用这个t来调用test函数，如果T类型没有test函数，那么concept C2就是false，这里不要求函数返回值
concept C2 = requires(T t) {
    t.test();
};

template <typename T>
concept C3 = requires(T t) {
    { t.test() } -> std::same_as<int>; // 这里相当于std::is_same_v<decltype(t.test()), int>，要求test函数的返回值必须是int类型
};

template <typename T>
    requires C2<T>
void fun2(T &t)
{
}

template <typename T>
    requires C3<T>
void fun3(T &t)
{
}

// 对于只有一个requies的函数模板，可以直接把concept放在template后面，简化代码
template <C2 T>
void fun4(T &t)
{
}
// 或者直接
void fun5(C2 auto &t) {}

int main()
{
    // fun1<Test>();
    fun1<int>(5);
    Test1 t1;
    Test2 t2;
    Test3 t3;
    fun2<Test1>(t1);
    // fun2<Test2>(t2);
    fun2<Test3>(t3);
    fun3<Test3>(t3);
    // fun3<Test1>(t1);
    return 0;
}