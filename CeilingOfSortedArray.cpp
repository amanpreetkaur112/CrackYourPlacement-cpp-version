/**
Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than or equal to x.
Assume that the array is sorted in non-decreasing order.
For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    ceil  = 1
For x = 1:    ceil  = 1
For x = 5:    ceil  = 8
For x = 20:   ceil doesn't exist in array
**/

/**
Time Complexity: O(log n)
Space Complexity: O(1)
**/
#include <bits/stdc++.h>
using namespace std;

int ceilSearch(int arr[], int low, int high, int x) {
    if ( sizeof(arr) / sizeof(arr[0]) == 0) {
        return -1;
    }
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 3;
    int index = ceilSearch(arr, 0, n - 1, x);
    if (index == -1)
        cout << "Ceiling of " << x << " doesn't exist in array ";
    else
        cout << "ceiling of " << x << " is " << arr[index];
    return 0;
}
