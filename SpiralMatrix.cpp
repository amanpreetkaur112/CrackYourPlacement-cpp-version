/**
54. Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
**/

/**
  Time Complexity: O(m*n)
  Space Complexity: O(1)
**/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        int i;
        vector<int> ans;
        while( top <= down && left <= right ) {
            for(i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            for(i = top; i <= down; i++)
                ans.push_back(matrix[i][right]);
            right--;
            if (top <= down) {
                for (i = right; i >= left; i--)
                    ans.push_back(matrix[down][i]);
                down--;
            }
            if (left <= right) {
                for (i = down; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};
