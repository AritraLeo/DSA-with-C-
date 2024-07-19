/*
        // // form sub strs from word and check from set if it exists
        // set<string> p;
        // for(auto s: patterns){
        //     p.insert(s);
        // }
        // int c=0;
        // string sub;
        // for(int i=0; i < word.length(); i++){
        //     // check if word[i] in set then c++
        //     string s;
        //     s += word[i];
        //     cout << s << endl;
        //     if(p.find(s) != p.end()){
        //         cout << "i " << i << " " << s << endl;
        //         c++;
        //     }

        //     for(int j=i+1; j < word.length(); j++){
        //         sub = word.substr(i, j);
        //         // if in set c++;
        //         if(p.find(sub) != p.end()) {
        //             cout << "j " << j << " " << sub << endl;
        //             c++;
        //         }
        //     }
        // }

        // return c;

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countMatchingSubstrings(const vector<string> &patterns, const string &word)
{
    int count = 0;

    for (const string &pattern : patterns)
    {
        if (word.find(pattern) != string::npos)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";

    int result = countMatchingSubstrings(patterns, word);
    cout << "Number of matching substrings: " << result << endl; // Output should be 3

    return 0;
}
