#include <iostream>
#include <vector>
#include <list>

// 构造一个模板当模板参数的例子，比较少见
template <template <typename, typename> class Container, typename T>
class ContainerPrinter
{
public:
    void print(const Container<T, std::allocator<T>> &container)
    {
        for (const auto &elem : container)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst = {10, 20, 30};

    ContainerPrinter<std::vector, int> vecPrinter;
    vecPrinter.print(vec); // 输出：1 2 3 4 5

    ContainerPrinter<std::list, int> listPrinter;
    listPrinter.print(lst); // 输出：10 20 30

    return 0;
}