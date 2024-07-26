#include <iostream>
#include <vector>
#include <unordered_set>
#include <string> // Include this for std::string

using namespace std; // This allows you to use std:: without prefix

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> uniqueEmails;

        for (string email : emails)
        {
            size_t pos = email.find('@');
            if (pos != string::npos)
            {
                string local = email.substr(0, pos);
                string domain = email.substr(pos + 1);

                // Process local part
                string actualLocal;
                for (char c : local)
                {
                    if (c == '+')
                    {
                        break;
                    }
                    else if (c != '.')
                    {
                        actualLocal += c;
                    }
                }

                // Form the final email address
                string finalEmail = actualLocal + "@" + domain;

                // Insert into set
                uniqueEmails.insert(finalEmail);
            }
        }

        return uniqueEmails.size();
    }
};

void testSolution()
{
    Solution solution;

    // Test case 1
    vector<string> emails1 = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"};
    int result1 = solution.numUniqueEmails(emails1);
    cout << "Test case 1: Expected 2, Actual: " << result1 << endl;

    // Test case 2
    vector<string> emails2 = {
        "a@leetcode.com",
        "b@leetcode.com",
        "c@leetcode.com"};
    int result2 = solution.numUniqueEmails(emails2);
    cout << "Test case 2: Expected 3, Actual: " << result2 << endl;
}

int main()
{
    testSolution();
    return 0;
}
