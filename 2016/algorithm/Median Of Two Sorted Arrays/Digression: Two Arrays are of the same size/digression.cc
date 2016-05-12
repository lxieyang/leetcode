/*
 * This is a digression:
 *      what if the two arrays are of the same size n?
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


// Version 1: Simply count while merging
class Solution {
public:
    double findMedian(vector<int> & nums1, vector<int> & nums2) {
        int i = 0, j = 0;
        int m1 = -1, m2 = -1;
        int count = 0;
        int size = nums1.size();
        for(; count <= size; ++count) {
            if(i == size) {
                m1 = m2;    // store previous median
                m2 = nums2.front();
                break;
            }
            if(j == size) {
                m1 = m2;    // store previous median
                m2 = nums1.front();
                break;
            }
            if(nums1[i] < nums2[j]) {
                m1 = m2;    // store previous median
                m2 = nums1[i++];
            }
            else {
                m1 = m2;    // store previous median
                m2 = nums2[j++];    
            }
        }
        
        cout << "\nBefore returning: m1: " << m1 << "\t m2: " << m2 << "\n\n";
        return (m1 + m2) / 2.0;
    }
};


// Version 2: By comparing the medians of the two arrays
//      1) Calculate the medians m1 and m2 of the input arrays ar1[] 
//         and ar2[] respectively.
//      2) If m1 and m2 both are equal then we are done.
//         return m1 (or m2)
//      3) If m1 is greater than m2, then median is present in one 
//         of the below two subarrays.
//         a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
//         b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
//      4) If m2 is greater than m1, then median is present in one    
//         of the below two subarrays.
//         a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
//         b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
//      5) Repeat the above process until size of both the subarrays 
//         becomes 2.
//      6) If size of the two arrays is 2 then use below formula to get 
//         the median.
//         Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
class Solution2 {
public:
    double median(int arr[], int n) {
        if(n % 2 == 0) {
            return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
        }
        else {
            return arr[n / 2];
        }
    }

    double findMedian(int arr1[], int arr2[], int n) {
        if(n <= 0) {
            return -1;
        }

        if(n == 1) {
            return (arr1[0] + arr2[0]) / 2.0;
        }

        if(n == 2) {
            return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2.0;
        }
        
        int m1 = median(arr1, n);
        int m2 = median(arr2, n);

        if(m1 == m2) {
            return m1;
        }

        if(m1 < m2) {
            if(n % 2 == 0) {
                return findMedian(arr1 + n /2 - 1, arr2, n - n / 2 + 1);
            }
            else {
                return findMedian(arr1 + n / 2, arr2, n - n / 2);
            }
        }
        else {
            if(n % 2 == 0) {
                return findMedian(arr1, arr2 + n / 2 - 1, n - n / 2 + 1);
            }
            else {
                return findMedian(arr1, arr2 + n / 2, n - n / 2);
            }
        }
    }
};





int main() {
    vector<int> michael, angela;
    michael.reserve(5); angela.reserve(5);
    for(unsigned i = 0; i < 5; ++i) {
        michael.push_back(i + 1);
        angela.push_back(i + 6);
    }

    Solution sol;
    cout << "median: " << sol.findMedian(michael, angela) << "\n";


    cout << "\n\nSecond solution:\n";
    int size = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    Solution2 sol2;
    cout << "median: " << sol2.findMedian(arr1, arr2, size);

    return 0;
}
