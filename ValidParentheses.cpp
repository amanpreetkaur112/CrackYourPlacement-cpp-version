/**
Leetcode 20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
**/
/**
Approach: Stack and Switch Case
Time Complexity: O(n)
Space Complexity: O(n)
**/
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[':   bracket.push(c);
                            break;
                case ')':   if(bracket.empty() || bracket.top()!='(')
                                return false;
                            else
                                bracket.pop();
                            break;
                case '}':   if(bracket.empty() || bracket.top()!='{')
                                return false;
                            else
                                bracket.pop();
                            break;
                case ']':   if(bracket.empty() || bracket.top()!='[')
                                return false;
                            else
                                bracket.pop();
                            break;
            }
        }
        return bracket.empty() ;
    }
};
