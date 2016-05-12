/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/ 

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


// Version 1: O(m + n) [Time limit exceeded]
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Thoughts:
        //      combine the two ==> [O(m + n)]
        //      then, get the median
        unsigned size = nums1.size() + nums2.size(); 
        vector<int> total;
        total.reserve(size);

        // combine
        unsigned i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                total.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                total.push_back(nums2[j]);
                j++;
            }
            else {
                total.push_back(nums1[i]);
                total.push_back(nums2[j]);
                i++; j++;
            }
        }
        if(i < nums1.size()) {
            for(; i < nums1.size(); ++i) {
                total.push_back(nums1[i]);
            }
        }
        else {
            for(; j < nums2.size(); ++j) {
                total.push_back(nums2[j]);
            }
        }

        // test output
        for(auto x : total) {
            cout << x << " ";
        }
        cout << "\n";

        // get median
        
        if(size % 2 == 0) {
            return (total[size / 2] + total[size / 2 - 1]) / 2.0;
        }
        else {
            return total[size / 2];
        }
    }
};


// Version 2: O(log(m + n))
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Thoughts:
        //      generalization: finding the kth element in two sorted array
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m + n;
        if(total & 0x1) {
            return find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
        }
        else {
            return (find_kth(nums1.begin(), m, nums2.begin(), n, total / 2) + 
                    find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
        }
        
    }

    int find_kth(vector<int>::const_iterator A, int m,
                 vector<int>::const_iterator B, int n,
                 int k) {
        // assume that m <= n
        if(m > n)
            return find_kth(B, n, A, m, k);
        if(m == 0)
            return *(B + k - 1);
        if(k == 1)
            return min(*A, *B);

        // divide k into two parts
        int ia = min(k / 2, m);
        int ib = k - ia;
        if(*(A + ia - 1) < *(B + ib - 1)) {
            return find_kth(A + ia, m - ia, B, n, k - ia);
        }
        else if(*(A + ia - 1) > *(B + ib - 1)) {
            return find_kth(A, m, B + ib, n - ib, k - ib);
        }
        else {
            return A[ia - 1];
        }
    }
};





int main() {
    vector<int> michael = {1};
    vector<int> angela;
    Solution2 sol;
    double ret = sol.findMedianSortedArrays(michael, angela);
    cout << "median: " << ret << "\n";
}



