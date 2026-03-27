#include "Mylist.hpp"
#include "Point.hpp"

int main()
{
    Mylist<int> ls(4);
    ls.push_back(1);
    ls.push_back(1);
    ls.push_back(1);
    for (int i = 0; i < ls.get_size(); i++)
    {
        std::cout << ls[i] << std::endl;
    }

    Mylist<int> ls2(ls);
    for (int i = 0; i < ls2.get_size(); i++)
    {
        std::cout << ls2[i] << std::endl;
    }

    Mylist<int> ls3(2);
    ls3 = ls;
    for (int i = 0; i < ls3.get_size(); i++)
    {
        std::cout << ls3[i] << std::endl;
    }

    Mylist<Point> ls4(4);
    Point p1(3, 4);
    Point p2(3, 5);
    Point p3(2, 3);
    ls4.push_back(p1);
    ls4.push_back(p2);
    ls4.push_back(p3);
    for (int i = 0; i < ls4.get_size(); i++)
    {
        std::cout << ls4[i].getX() << ls4[i].getY() << std::endl;
    }

    return 0;
}