/*
You are given a 0 - indexed array of strings words.Each string consists of lowercase English letters only.No letter occurs more than once in any string of words.

                    Two strings s1 and s2 are said to be connected if the set of letters of s2 can be obtained from the set of letters of s1 by any one of the following operations :

    Adding exactly one letter to the set of the letters of s1.Deleting exactly one letter from the set of the letters of s1.Replacing exactly one letter from the set of the letters of s1 with any letter,
    including itself.The array words can be divided into one or more non - intersecting groups.A string belongs to a group if any one of the following is true :

    It is connected to at least one other string of the group.It is the only string present in the group.Note that the strings in words should be grouped in such a manner that a string belonging to a group cannot be connected to a string present in any other group.It can be proved that such an arrangement is always unique.

    Return an array ans of size 2 where :

    ans[0] is the maximum number of groups words can be divided into,
    and ans[1] is the size of the largest group.
    */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// List of Lower case letters
char Letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

// All operations to be done on s1 taking s2 secondary thus s1 is primary:

bool addLetter(string s1, string s2)
{
    // string res;
    int length2 = s2.length();
    int length1 = s1.length();
    if (length2 - length1 < 0)
    {
        swap(length1, length2);
        swap(s1, s2);
    }
    for (int i = 0; i < 26; i++)
    {
        if (s2 == s1 + Letters[i])
        {
            return true;
        }
        else if (Letters[i] + s1 == s2)
        {
            return true;
        }
    }
    return false;
}

bool removeLetter(string s1, string s2)
{
    int length2 = s2.length();
    int length1 = s1.length();
    if (length2 - length1 < 0)
    {
        swap(length1, length2);
        swap(s1, s2);
    }
    for (int i = 0; i < length1; i++)
    {
        if (s2 == s1.erase(i))
        {
            return true;
        }
    }
    return false;
}

bool ReplaceLetter(string s1, string s2)
{
    int length2 = s2.length();
    int length1 = s1.length();
    if (length2 != length1)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < length1; i++)
        {
            if (s1[i] != s2[i])
            {
                for (int j = 0; j < 26; j++)
                {
                    char replacement = Letters[j];
                    s1[i] = replacement;
                    if (s2[i] == s1[i])
                    {
                        if (s1 == s2)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
}

int checkForS(vector<string> &words, string s)
{
    int pair = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (s == words[i])
        {
            pair++;
        }
        else if (addLetter(words[i], s))
        {
            pair++;
        }
        else if (removeLetter(words[i], s))
        {
            pair++;
        }
        else if (ReplaceLetter(words[i], s))
        {
            pair++;
        }
    }
    return pair;
}

vector<int> groupStrings(vector<string> &words)
{
    string s;
    int group = 0;
    int largestGrp = 0;
    for (int i = 0; i < words.size(); i++)
    {
        s = words[i];
        group += checkForS(words, s);
    }
    vector<int> ans;
    ans.push_back(group);
    ans.push_back(largestGrp);
    return ans;
}

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> words;
    words.push_back("a");
    words.push_back("ab");
    words.push_back("abc");
    vector<int> ans;
    ans = groupStrings(words);
    display(ans);
    return 0;
}