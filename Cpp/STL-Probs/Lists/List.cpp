#include <iostream>
#include <list>

using namespace std;
// template <class T>

void display(list<int> &lst)
{

    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    list<int> list1;

    for (int i = 1; i < 6; i++)
    {
        list1.push_back(i);
    }

    display(list1);

    return 0;
}