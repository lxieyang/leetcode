/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        const int m = A.size();
        const int n = B.size();
        int total = m + n;
        if(total & 0x1){
            return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
        }
        else{
            return (find_kth(A.begin(), m, B.begin(), n, total / 2)
                    + find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
        }
    }

    int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k){
        if(m > n) return find_kth(B, n, A, m, k);
        if(m == 0) return *(B + k - 1);
        if(k == 1) return min(*A, *B);

        int ia = min(k / 2, m), ib = k - ia;
        if (*(A + ia - 1) < *(B + ib - 1))
            return find_kth(A + ia, m - ia, B, n, k - ia);
        else if (*(A + ia - 1) > *(B + ib - 1))
            return find_kth(A, m, B + ib, n - ib, k - ib);
        else
            return A[ia - 1];
    }
};




int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7, 9};

    Solution sol;
    cout << sol.findMedianSortedArrays(arr1, arr2) << "\n";

    return 0;
}
