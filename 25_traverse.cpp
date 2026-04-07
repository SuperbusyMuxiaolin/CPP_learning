#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Mytrans
{
public:
    int operator()(int v)
    {
        return v + 1;
    }
};

class Myprint
{
public:
    void operator()(int v)
    {
        cout << v << " ";
    }
};
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), Mytrans());
    for_each(v1.begin(), v1.end(), Myprint());
    cout << "\n"
         << "-------------------" << endl;
    for_each(v2.begin(), v2.end(), Myprint());
}

int main()
{
    test01();
}