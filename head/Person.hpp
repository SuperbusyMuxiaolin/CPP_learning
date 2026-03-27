#pragma once
#include <iostream>

template <class nametype, class agetype>
class Person
{
public:
    Person(nametype n, agetype a);
    void showperson();

    nametype name;
    agetype age;
};

template <class nametype, class agetype>
Person<nametype, agetype>::Person(nametype n, agetype a)
{
    this->age = a;
    this->name = n;
}

template <class nametype, class agetype>
void Person<nametype, agetype>::showperson()
{
    std::cout << this->age << this->name;
}