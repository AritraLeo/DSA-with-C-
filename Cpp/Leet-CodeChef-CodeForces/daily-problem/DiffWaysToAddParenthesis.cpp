#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        return compute(expression, memo);
    }

private:
    unordered_map<string, vector<int>> memo;

    vector<int> compute(const string &expression, unordered_map<string, vector<int>> &memo)
    {
        if (memo.find(expression) != memo.end())
        {
            return memo[expression];
        }

        vector<int> result;
        for (int i = 0; i < expression.length(); ++i)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                // Divide the expression into two parts and solve them recursively
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftResult = compute(left, memo);
                vector<int> rightResult = compute(right, memo);

                // Combine the results from the left and right sub-expressions
                for (int l : leftResult)
                {
                    for (int r : rightResult)
                    {
                        if (c == '+')
                        {
                            result.push_back(l + r);
                        }
                        else if (c == '-')
                        {
                            result.push_back(l - r);
                        }
                        else if (c == '*')
                        {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If the expression is a single number, convert it to an integer
        if (result.empty())
        {
            result.push_back(stoi(expression));
        }

        memo[expression] = result;
        return result;
    }
};

int main()
{
    Solution sol;
    string expression1 = "2-1-1";
    vector<int> result1 = sol.diffWaysToCompute(expression1);
    cout << "Results for expression " << expression1 << ": ";
    for (int res : result1)
    {
        cout << res << " ";
    }
    cout << endl;

    string expression2 = "2*3-4*5";
    vector<int> result2 = sol.diffWaysToCompute(expression2);
    cout << "Results for expression " << expression2 << ": ";
    for (int res : result2)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
