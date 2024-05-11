/*
Initial approach 

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        // run counter x till n + x digits if(s equal / less than target) return
        // x; getDigits(y => n+x) -> while(y>0) { s += y%10; y/= 10;} return s

        if(getSum(n) <= target) return 0;

        long long x = 0;
        while (true) {
            if (getSum(n + x) <= target)
                return x;
            x++;
        }
        return 0;
    }

public:
    int getSum(long long y) {
        int s = 0;
        while (y > 0) {
            s += y % 10;
            y /= 10;
        }
        return s;
    }
};
*/

/*
Logic - 

Store the the digits of n in vector.
Check the sum of the digit.
If the sum of the digits exceeds the target, add + 1 with previous index (idx-1) and make the rest of the digits to 0
Repeat this untill we get the Beautiful Number
*/


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        // if n is already beautiful number, return 0
        if (sumDigit(n) <= target)
            return 0;
        
        // check whether n is beautiful, if not repeat until we get the beautiful number
        long long num = makeBeautiful(n, target);
        while (sumDigit(num) > target)
            num = makeBeautiful(num, target);
        
        // return the num - n which is the result 
        return num - n;
    }
    
    // sum of digits
    int sumDigit(long long n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    // function to calculate the beautiful number
    long long makeBeautiful(long long n, int target) {
        vector<int> arr;
        
        // push each digits of n to arr
        while (n > 0) {
            arr.insert(arr.begin(), n % 10);
            n /= 10;
        }
        
        // insert 0 at start. Say if the first digit of the number itself > target, 
        // we need add +1 with the previous digit. So this 0 does that trick here.
        arr.insert(arr.begin(), 0); 
        
        int sum = 0, idx;
        for (idx = 0; idx < arr.size(); idx++) {
            // calculate the sum
            sum += arr[idx];
            // if sum > target, add +1 with idx-1 and assign 0 to rest of the index.
            if (sum > target) {
                arr[idx - 1] += 1;
                arr[idx] = 0;
                // breaking here to avoid further changes in array
                break;
            }
        }
        
        // make the rest of the digits after idx to 0
        for (int i = idx; i < arr.size(); i++)
            arr[i] = 0;
        
        // calculate the new num
        long long num = 0;
        for (int i = 0; i < arr.size(); i++)
            num = (num * 10) + arr[i];
        
        return num;
    }
};

int main() {
    Solution solution;

    // Test cases
    long long n1 = 16;
    int target1 = 6;
    cout << "Test Case 1: " << solution.makeIntegerBeautiful(n1, target1) << endl;

    long long n2 = 467;
    int target2 = 6;
    cout << "Test Case 2: " << solution.makeIntegerBeautiful(n2, target2) << endl;

    long long n3 = 1;
    int target3 = 1;
    cout << "Test Case 3: " << solution.makeIntegerBeautiful(n3, target3) << endl;

    return 0;
}
