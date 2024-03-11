/*
Prev wrong appraoch -

bool checkForPattern(string sub, string order){
    unordered_map<char, int> m;
    for(int i=0; i<sub.length(); i++){
        m[sub[i]]++;
    }

    int counter = 0;
    for (int i = 0; i < order.length(); i++)
    {
        if(m.find(order[i]) != m.end()) counter++;
    }

    if(counter == order.length())
        return true;
}

class Solution {
public:
    string customSortString(string order, string s) {
        // if (order size > s size) -> not possible
        // for(i=0 -> s.size()) -> if(i+order.size() <= s.size()) -> sub = s.subStr(i, i+order.size()-1) -> if(checkForpattern(sub, order)) return (order + s.substr(i+order.length(), s.length() - 1));
        // checkForpattern(sub, order) -> make a map m<char, int> -> for(i=0 -> sub.size()) -> m.push(sub[i]); then 
        // int counter = 0; for(i=0 -> order.size()) -> if(m.find(order[i]) != m.end()) counter++; outside for -> if(counter == order.size()) return true;

        if(order.length() > s.length())
            return "";
        
        string sub;

        for (int i = 0; i < s.length(); i++)
        {
            if(i+order.length() <= s.length()){
                sub = s.substr(i, order.length()+i-1);
                if(checkForPattern(sub, order))
                    return (order + s.substr(i+order.length(), s.length() - 1));
            }
        }
        return sub;
    }
};


auto comparator = [&](char a, char b) {
    return order.find(a) < order.find(b);
};

Explanation -

The lambda function captures the variable order by reference (&). This allows the lambda to access the order string defined outside its scope.
Inside the lambda function, a and b represent two characters that are being compared.
order.find(a) retrieves the index of character a in the order string.
Similarly, order.find(b) retrieves the index of character b in the order string.
The lambda function returns true if the index of a in the order string is less than the index of b. This means that a should come before b in the sorted order.
If a and b have the same index in the order string, their relative order remains unchanged.
This comparator function is used with the sort function to sort characters of string s based on their positions in the order string.


*/


#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        // Custom comparator function to sort characters based on their order in 'order' string
        auto comparator = [&](char a, char b) {
            return order.find(a) < order.find(b);
        };

        // Sort characters of 's' using custom comparator
        sort(s.begin(), s.end(), comparator);

        // Return the sorted permutation of 's'
        return s;
    }
};


int main() {
    // Test case
    string order = "bcafg";
    string s = "abcd";
    
    // Create a Solution object
    Solution sol;

    // Call the customSortString function and print the result
    string result = sol.customSortString(order, s);
    cout << "Output: " << result << endl;

    return 0;
}
