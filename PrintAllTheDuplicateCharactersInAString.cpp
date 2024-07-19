/**
Print all the duplicate characters in a string
Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

Example:
Input: S = “geeksforgeeks”
Output:
e, count = 4
g, count = 2
k, count = 2
s, count = 2

Explanation: e,g,k,and s are characters which are occured in string in more than one times.
**/

/**
Approach: Hashing
Time Complexity: O(n)
Space Complexity: O(1)
**/
void func(string& s) {
    unordered_map<char,int> mp;
    for(char c: s)
        mp[c]++;
    for(auto i: mp) {
        if( i.second > 1 )
            cout << i.first << " : " << i.second << endl;
    }
}
