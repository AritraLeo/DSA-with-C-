/*
// first number before '[' is k
//         // from '[' to ']' there's encoded str
//         // out put is stored in map where for k there's a string
//         // unordered_map<int, string> m;
//         // return findKandStrEncoded(s, m, 0);
//         // Array to store counts and strings, simulating stack behavior


//         int countStack[1000];
//         std::string stringStack[1000];
//         int countStackIndex = -1;
//         int stringStackIndex = -1;

//         std::string currentString = "";
//         int i = 0;

//         while (i < s.size()) {
//             if (isdigit(s[i])) {
//                 // Build the number k
//                 int k = 0;
//                 while (isdigit(s[i])) {
//                     k = k * 10 + (s[i] - '0');
//                     i++;
//                 }
//                 countStack[++countStackIndex] = k;
//             } else if (s[i] == '[') {
//                 // Push the current string to the stack and start a new one
//                 stringStack[++stringStackIndex] = currentString;
//                 currentString = "";
//                 i++;
//             } else if (s[i] == ']') {
//                 // Pop from the stacks and build the string
//                 std::string temp = currentString;
//                 currentString = stringStack[stringStackIndex--];
//                 int k = countStack[countStackIndex--];
//                 for (int j = 0; j < k; j++) {
//                     currentString += temp;
//                 }
//                 i++;
//             } else {
//                 // Build the current string
//                 currentString += s[i];
//                 i++;
//             }
//         }

//         return currentString;
}



*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        int index = 0;
        return decode(s, index);
    }

private:
    string decode(const string &s, int &index)
    {
        string result;
        int n = s.size();
        while (index < n && s[index] != ']')
        {
            if (isdigit(s[index]))
            {
                int k = 0;
                while (index < n && isdigit(s[index]))
                {
                    k = k * 10 + (s[index] - '0');
                    index++;
                }
                // Skip the '['
                index++;
                string decodedString = decode(s, index);
                // Skip the ']'
                index++;
                while (k > 0)
                {
                    result += decodedString;
                    k--;
                }
            }
            else
            {
                result += s[index];
                index++;
            }
        }
        return result;
    }
};

// Helper function for testing
void testDecodeString(const string &input)
{
    Solution sol;
    string output = sol.decodeString(input);
    cout << "Input: " << input << "\nOutput: " << output << "\n\n";
}

int main()
{
    testDecodeString("3[a]2[bc]"); // Expected output: "aaabcbc"
    testDecodeString("3[a2[c]]");  // Expected output: "accacc
    return 0;
}