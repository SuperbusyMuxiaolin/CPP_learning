#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void test01()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "栈顶的元素为：" << s1.top() << endl;
    s1.pop();
    cout << "栈顶的元素为：" << s1.top() << endl;
    s1.pop();
    cout << "栈顶的元素为：" << s1.top() << endl;
    s1.pop();
    cout << "栈的size为：" << s1.size() << endl;
}

void test02()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout << "队列的队首元素为：" << q1.front() << endl;
    q1.pop();
    cout << "队列的队首元素为：" << q1.front() << endl;
    q1.pop();
    cout << "队列的队首元素为：" << q1.front() << endl;
    q1.pop();
}
int main()
{
    // test01();
    test02();
    return 0;
}