/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// sort -> 2 sum
// neglect dups
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        sort(nums.begin(), nums.end());

        for(auto i = nums.begin(); i < nums.end() - 2; i++){
            auto j = i + 1;
            auto k = nums.end() - 1;

            while(j < k){
                int sum = *i + *j + *k;
                int gap = abs(sum - target);
                if(gap < min_gap){
                    result = sum;
                    min_gap = gap;
                }
                if(sum < target) j++;
                else k--;
            }
        }
        return result;
    }
};


int main(){
	Solution sol;
	vector<int> nums;
    int target = 1;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
    nums.push_back(-4);

	int retVal = sol.threeSumClosest(nums, target);

    cout << "For the vector: ";
    for(auto x: nums)
        cout << x << " ";
    cout << ", the 3SumClosest is " << retVal << "\n";
    
	return 0;
}