/*
Leetcode 287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
*/

/**
  Approach 1: using Frequency Array
  Time complexity: O(n)
  Space complexity: O(n)
**/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0);
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if( freq[nums[i]] > 1 )
                return nums[i];
        }
        return -1;
    }
};

/**
  Approach 2: Slow and Fast Pointers
  Time complexity: O(n)
  Space complexity: O(1)
**/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;
        do{
            s = nums[s];
            f = nums[nums[f]];
        }while( s != f );
        s = 0;
        while( s != f ) {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};

/**
  Approach 3: using Unordered Map
  Time complexity: O(n)
  Space complexity: O(n)
*//
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums)
            mp[i]++;
        for(auto i: mp)
            if( i.second > 1 )
                return i.first;
        return -1;
    }
};
