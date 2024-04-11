/*
We iterate through each digit in the input number num.
While iterating, we maintain a stack to keep track of the digits we've seen so far.
For each digit, we compare it with the top of the stack. If the digit is smaller than the top of the stack, and there are still k removals remaining, we pop digits from the stack until either the condition is not met or k becomes 0.
After iterating through all digits, if k is still greater than 0, we pop remaining digits from the end of the stack.
We construct the resulting string from the digits in the stack and reverse it to get the correct order.
We remove leading zeros from the resulting string.
We repeat this process for each test case in the main function and output the results.

*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> stack;
        
        // Iterate through each digit in the number
        for (char digit : num) {
            // While the stack is not empty, k > 0, and the top of the stack is greater than the current digit
            // Remove digits from the stack
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            // Push the current digit onto the stack
            stack.push(digit);
        }
        
        // Remove remaining k digits from the end of the stack
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        // Construct the resulting string from the stack
        std::string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        // Reverse the resulting string to get the correct order
        std::reverse(result.begin(), result.end());
        
        // Remove leading zeros
        size_t pos = result.find_first_not_of('0');
        result = (pos == std::string::npos) ? "0" : result.substr(pos);
        
        return result;
    }
};

int main() {
    Solution solution;
    std::string num1 = "1432219";
    int k1 = 3;
    std::cout << "Input: num = " << num1 << ", k = " << k1 << std::endl;
    std::cout << "Output: " << solution.removeKdigits(num1, k1) << std::endl;

    std::string num2 = "10200";
    int k2 = 1;
    std::cout << "Input: num = " << num2 << ", k = " << k2 << std::endl;
    std::cout << "Output: " << solution.removeKdigits(num2, k2) << std::endl;

    std::string num3 = "10";
    int k3 = 2;
    std::cout << "Input: num = " << num3 << ", k = " << k3 << std::endl;
    std::cout << "Output: " << solution.removeKdigits(num3, k3) << std::endl;

    return 0;
}
