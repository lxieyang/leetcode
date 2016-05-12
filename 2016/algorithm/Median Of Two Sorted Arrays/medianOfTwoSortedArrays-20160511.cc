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


// Version 2:
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Thoughts:
        //      
        
    }
};





int main() {
    vector<int> michael = {1, 3, 5, 7};
    vector<int> angela = {2, 4, 6, 8};
    Solution2 sol;
    double ret = sol.findMedianSortedArrays(michael, angela);
    cout << "median: " << ret << "\n";
}



