/**
Leetcode 462. Minimum Moves to Equal Array Elements II
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment or decrement an element of the array by 1.
Test cases are designed so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,3]
Output: 2
Explanation: Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

Example 2:
Input: nums = [1,10,2,9]
Output: 16
**/

/**
  Appraoch: Maths
    1. sort the array
    2. find the element in the middle of the array
    3. find the difference of each element to the mid-th element, i.e.,
       substracting each element of the array from the mid-th element and storing all these differences
       an variable, which is the number of moves we need to make all the elements equal.
       Here we aim to making all the elements equal to the mid-th element
Time Complexity: O(n log n)
  Space Complexity: O(1)
**/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort( nums.begin(), nums.end());
        int mid = nums[nums.size()/2], ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += abs(mid - nums[i]);
        }
        return ans;
    }
};
