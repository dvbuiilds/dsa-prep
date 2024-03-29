/**
 * @file 41. First Missing Positive
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * @link https://leetcode.com/problems/first-missing-positive/ @endlink
 * @copyright Copyright (c) 2022
 * @tags arrays
 */
/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/
// TC: O(N), SC: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), ans = n+1;
        
        for(int &i: nums){
            if(i<=0) i = n+5;
        }
        
        for(int i = 0; i<n; ++i){
            int num = abs(nums[i]);
            if(num and num <= n){
                nums[num-1] = -(abs(nums[num-1]));
            }
        }
        
        for(int i = 0; i<n; ++i){
            if(nums[i] >= 0) return i+1;
        }
        return ans;
    }
};
