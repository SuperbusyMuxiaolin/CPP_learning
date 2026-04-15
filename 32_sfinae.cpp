#include <iostream>

// 使用 SFINAE 检测类型 T 是否存在成员函数: void reserve()
template <typename T>
struct has_reserve
{
    // 当且仅当 U 存在签名为 void reserve() 的成员函数时，&U::reserve 才能匹配成功
    template <typename U, void (U::*)()>
    class sfinae
    {
    };

    // 通过返回类型大小区分匹配结果
    class good
    {
        char dummy[2];
    };
    class bad
    {
        char dummy;
    };

    // 优先匹配：如果 sfinae<U, &U::reserve> 合法，则命中该重载，返回 good
    template <typename U>
    static good test(sfinae<U, &U::reserve> *);

    // 兜底重载：上面的匹配失败时走这里，返回 bad
    template <typename U>
    static bad test(...);

    // good 的大小为 2，bad 的大小为 1，据此得到是否存在 reserve()
    static const bool value = sizeof(test<T>(nullptr)) == sizeof(good);
};

class testreserve
{
public:
    void reserve();
};
class testnoreserve
{
public:
};

int main()
{
    // testreserve 有 reserve()，输出 1（true）
    std::cout << has_reserve<testreserve>::value << std::endl;

    // testnoreserve 没有 reserve()，输出 0（false）
    std::cout << has_reserve<testnoreserve>::value << std::endl;

    return 0;
}