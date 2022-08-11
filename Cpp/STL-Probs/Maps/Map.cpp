#include <iostream>
#include <map>
#include <string>

using namespace std;

void display(map<string, int> &marksMap)
{
    map<string, int>::iterator itr;
    for (itr = marksMap.begin(); itr != marksMap.end(); itr++)
    {
        cout << (*itr).first << "  " << (*itr).second << endl;
    }
}

int main()
{

    map<string, int> marksMap;
    marksMap["Harry"] = 55;
    marksMap["Jack"] = 59;
    marksMap["Rohan"] = 2;

    marksMap.insert({{"Aritra", 100}, {"Shuvo", 20}});

    display(marksMap);

    /*
    map<string, int>::iterator itr;
    for (itr = marksMap.begin(); itr != marksMap.end(); itr++)
    {
        cout << (*itr).first << "  " << (*itr).second << endl;
    }
    */

    return 0;
}
