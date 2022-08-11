#include <iostream>
#include <vector>

using namespace std;
template <class T>

void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec1;
    vector<char> vesc2(4);     // Vesctor with 4 elements
    vector<char> vesc3(vesc2); // 4 element char vector from vec2
    // vector<char> v(5, 3);      // 6 element vector of 3's
    // display(v);
    for (int i = 1; i < 5; i++)
    {
        vector<char> v(i, 3);
        display(v);
    }

    /*  part - 1:

    int e, n;
    cout << "Enter Size" << endl;
    cin >> n;

    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        vec1.push_back(e);
    }
    display(vec1);
    vector<int>::iterator iter = vec1.begin();
    vec1.insert(iter, 100);
    display(vec1);
    */

    return 0;
}
