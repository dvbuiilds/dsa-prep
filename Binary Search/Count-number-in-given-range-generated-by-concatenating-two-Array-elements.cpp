/**
 * @file Count-number-in-given-range-generated-by-concatenating-two-Array-elements
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * @link https://www.geeksforgeeks.org/count-number-in-given-range-generated-by-concatenating-two-array-elements/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary search
 */
/*
Given an array arr[] of size N and integers L and R defining the given range, the task is to find the number of elements in the given range that can be generated by concatenating any two elements of the array.

Examples:

Input:  N = 2, L = 10, R = 52, arr = {2, 5}
Output:  3
Explanation: All pairs available  
(2, 2) => 22 (10 ≤ 22 ≤ 52)
(2, 5) => 25 (10 ≤ 25 ≤ 52)
(5, 2) => 52 (10 ≤ 52 ≤ 52)
(5, 5) => 55 (10 ≤ 55 > 52) invalid
Hence output is 3.

Input:  N = 3, L = 100, R = 1000, arr = {28, 5, 100}
Output:  2
Explanation: The only valid pairs available  
(28, 5) => 285 (100 ≤ 285 ≤ 1000)
(5, 28) => 528 (100 ≤ 528 ≤ 1000)
Rest other pairs either fall short or higher then given range
Hence output is 2.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ValidPair(vector<int>& nums, int& N, int& L, int& R){
    sort(nums.begin(), nums.end());

    vector<long> powerOfTen(15, 1);
    for(int i = 1; i<15; ++i){
        powerOfTen[i] = powerOfTen[i-1]*(long)10;
    }
    int ans = 0;

    for(int i =0; i<N; ++i){
        int curr = nums[i], len = 0;

        while(curr){
            ++len, curr /= 10;
        }

        int right = (R - nums[i])/powerOfTen[len];
        int left = (L-nums[i]+powerOfTen[len]-1)/powerOfTen[len];

        if(right >= left){
            int noInRange = upper_bound(nums.begin(), nums.end(), right) - lower_bound(nums.begin(), nums.end(), left);
            ans += noInRange;
        }
    }

    return ans;
}

int ValidPairGFG(vector<int>& a, int n, int l, int r){
    // Sort the array in the increasing order
    sort(a.begin(), a.end());
 
    // Precompute the powers
    // to avoid later calculations
    vector<int> pow10(17, 1);
    for (int i = 1; i <= 16; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }
 
    int ans = 0;
    for (int j = 0; j < n; j++) {
 
        // Determining the length of a[j]
        int len = 0;
        int cur = a[j];
        while (cur) {
            cur /= 10;
            len++;
        }
 
        // Finding out the range
        int right = (r - a[j]) / pow10[len];
        int left = (l - a[j] + pow10[len] - 1) / pow10[len];
 
        // Applying the binary search to find number of
        // elements
        if (left <= right)
            ans += (upper_bound(a.begin(), a.end(), right)
                    - lower_bound(a.begin(), a.end(), left));
    }
    return ans;
}

int main(){
    // vector<int> nums = {5,101,10,20,220};
    vector<int> nums = {28, 10, 5};
    int N = nums.size(), L = 100, R = 1000;
    cout<<ValidPairGFG(nums, N, L, R);
    return 0;

}