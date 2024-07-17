/*
Leetcode 75. Sort Color
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
*/

/**
  Approach 1: Dutch National Flag Algorithm
  Time complexity: O(n)
  Space complexity: O(1)
**/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, m = 0, h = n-1;
        while( m <= h ) {
            switch( nums[m] ) {
                case 0: swap( nums[l++], nums[m++] );
                        break;
                case 1: m++;
                        break;
                case 2: swap( nums[m], nums[h--] );
                        break;
            }
        }
    }
};

/**
  Approach 1: Brute Force
  Time complexity: O(n)
  Space complexity: O(1)
**/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, b = 0;
        for(int i: nums) {
            if( i == 0 )
                a++;
            if( i == 1 )
                b++;
        }
        for(int i = 0; i < a; i++)
            nums[i] = 0;
        for(int i = a; i < a+b; i++)
            nums[i] = 1;
        for(int i = a+b; i < nums.size(); i++)
            nums[i] = 2;
    }
};
