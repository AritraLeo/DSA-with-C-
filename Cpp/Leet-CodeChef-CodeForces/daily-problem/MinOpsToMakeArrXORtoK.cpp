/*

// int minOperations(vector<int>& nums, int k) {
//     int mini = INT_MAX;

//     // Iterate through the nums array
//     for(int i = 0; i < nums.size(); i++) {
//         // Get the target number that sums to k
//         int target = getNumReq(nums, i, k);
        
//         // Calculate the minimum number of operations needed for nums[i] to reach the target
//         int operations = findCountBits(nums[i] ^ target);
        
//         // Update the minimum operations required
//         mini = min(mini, operations);
//     }
//     return mini;
// }

// // Function to find the number needed to sum to k
// int getNumReq(vector<int>& nums, int index, int k) {
//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++) {
//         if (i != index) {
//             sum += nums[i];
//         }
//     }
//     return sum ^ k;
// }

// // Function to count the number of set bits (1s) in an integer
// int findCountBits(int num) {
//     int count = 0;
//     while (num > 0) {
//         count += num & 1;
//         num >>= 1;
//     }
//     return count;
// }


Initial approach incomplete- 
// public:
//     int minOperations(vector<int>& nums, int k) {
//         
//         iterate nums{
//             e = nums[i]
//             f = getNumReq -> find the num at i'th that equals XOR of all nums to k
//             mini = min(mini, findCountBits -> bit manp. count to make e == f)
//         }
//         return mini
//         
//         for(int i=0; i < nums.size(); i++){
//             f = getNumReq(nums, i, k);
//             mini = min(mini, findCountBitManp(nums[i], k));
//         }
//         return mini;
//     }
// public:
//     int getNumReq(vector<int>& nums, int i, int k){

//         // Calc XOR before i'th
//         int xorBefore;
//         for(int j=0; j < i; j++){
//             xorBefore = xorbefore ^ nums[j];
//         }

//         int c=0, xor = nums[i];
//         while(true){
//             for(int k=i+1; k < nums.size() - 1; k++){
//                 xor = xor ^ c;
//             }
//             if(xor == k)
//             c++;
//         }
//     }

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorResult = k;
        for (int num : nums) {
            xorResult ^= num;
        }
        return __builtin_popcount(xorResult);
    }
};

/*
The __builtin_popcount(xorResult) function is a built-in function in GCC that counts the number of set bits in an unsigned integer. It is used to determine the number of 1's in the binary representation of a positive integer. This function is available in C++11 and later versions of the language.
Here's how it works:
It takes an unsigned integer x as input.
It returns the number of 1-bits set in x.
It is implemented using hardware instructions that are optimized for population count operations, providing fast and efficient implementations of population count.
The time complexity of __builtin_popcount(x) is O(log2(n)), where n is the input integer. This is because the function uses a loop to iterate through each bit in the input number, and the number of iterations is proportional to the number of bits in the input number.
The auxiliary space complexity is O(1), as the function does not use any additional space that scales with the input size.
In summary, __builtin_popcount(x) is a built-in function in GCC that counts the number of set bits in an unsigned integer. It is a fast and efficient way to determine the population count of an integer, and it is available in C++11 and later versions of the language.
*/

int main() {
    Solution solution;
    vector<int> nums = {2, 1, 3, 4};
    int k = 1;

    int result = solution.minOperations(nums, k);

    cout << "Output: " << result << endl;

    return 0;
}
