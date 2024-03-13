#include <iostream>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        // n = 1 return 1;
        // calc total sum till n -> sum = copy = n(n-1)/2
        // for(i=n->1) -> sum -= i; revSum = revSum+i -> if(sum == revSum) return i; 
        if(n==1) return 1;

        int sum = n*(n+1) / 2;
        int revSum = 0;
        for(int i=n; i>=1; i--){
            sum = sum - i;
            revSum += i;
            cout << i << "th " << "RevSum: " << revSum << " Sum: " << sum << endl;
            if(revSum + (i-1) == sum) return i-1;
        } 
        return -1;
    }
};

int main() {
    // Test cases
    Solution sol;
    cout << "Test Case 1: n = 1" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Output: " << sol.pivotInteger(1) << endl;
    
    cout << "Test Case 2: n = 5" << endl;
    cout << "Expected Output: -1" << endl;
    cout << "Output: " << sol.pivotInteger(5) << endl;

    cout << "Test Case 3: n = 8" << endl;
    cout << "Expected Output: 6" << endl;
    cout << "Output: " << sol.pivotInteger(8) << endl;

    return 0;
}
