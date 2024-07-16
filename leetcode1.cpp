/*
1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

/**
  Approach 1: Brute Force
  Time Complexity: O(n^2)
  Space Complexity: O(1)
**/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]+nums[j]==target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

/**
  Approach 2: Two-Pass Hash Table
  Time Complexity: O(n)
  Space Complexity: O(n)
**/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        //hash table
        for( int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        //complement
        for( int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if( mp.count(c) && mp[c] != i ) {
                return { i, mp[c] };
            }
        }
        return {};
    }
};

/**
  Approach 3: One-Pass Hash Table
  Time Complexity: O(n)
  Space Complexity: O(n)
**/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for( int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if( mp.count(c) ) {
                return { mp[c], i };
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
