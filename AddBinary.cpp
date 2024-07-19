/**
Leetcode 67. Add Binary
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
**/

/**
Time Complexity: O( max(n,m) )
Space Complexity: O( max(n,m) )
**/
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
	    int blen = b.length();
	    int i = 0, c = 0;
	    string ans = "";
	    while( i<alen || i<blen || c!=0 ) {
		    int x = 0;
		    if( i<alen && a[alen-i-1]=='1' )
			    x = 1;
		    int y = 0;
		    if( i<blen && b[blen-i-1]=='1' )
			    y = 1;
		    ans = to_string((x+y+c)%2) + ans;
		    c = (x+y+c) / 2;
		    i++;
	    }
        return ans;
    }
};
