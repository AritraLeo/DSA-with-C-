#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <iostream>

using namespace std;

/*
Split the path by / to handle each component.
Use a stack to keep track of the valid directory names.
Process each component:
Ignore . as it refers to the current directory.
For .., pop the stack if it's not empty (to go up one level).
Push valid directory names onto the stack.
After processing all components, join the stack contents with / to form the simplified path.
*/

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        stringstream ss(path);
        string token;

        // Split the input path by '/'
        while (getline(ss, token, '/'))
        {
            if (token == "." || token.empty())
            {
                continue;
            }
            if (token == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(token);
            }
        }

        // Construct the simplified path
        string simplifiedPath;
        while (!st.empty())
        {
            simplifiedPath = "/" + st.top() + simplifiedPath;
            st.pop();
        }

        // Return the root if the stack was empty
        return simplifiedPath.empty() ? "/" : simplifiedPath;
    }
};

// Example usage
int main()
{
    Solution sol;
    string path = "/a/./b/../../c/";
    string result = sol.simplifyPath(path);
    cout << "Simplified Path: " << result << endl; // Expected output: "/c"
    return 0;
}
