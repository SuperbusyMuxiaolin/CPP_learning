#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Person
{
public:
    Person(string name, int score) : name(name), score(score) {}
    string name;
    int score;
};

int score()
{
    deque<int> score;
    for (int i = 0; i < 10; i++)
    {
        score.push_back(rand() % 41 + 60);
    }
    sort(score.begin(), score.end());
    score.pop_back();
    score.pop_front();
    int sum = 0;
    for (auto s : score)
    {
        sum += s;
    }
    return sum / score.size();
}

int main()
{
    vector<Person> v;
    for (int i = 0; i < 5; i++)
    {
        string name = "选手" + to_string(i + 1);
        int s = score();
        v.push_back(Person(name, s));
    }
    for (auto p : v)
    {
        cout << p.name << " " << p.score << endl;
    }
    return 0;
}