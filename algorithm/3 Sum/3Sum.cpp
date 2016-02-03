/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// sort -> 2 sum
// neglect dups
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        vector<vector<int> > retVal;
        if(nums.size() < 3) return retVal;
        sort(nums.begin(), nums.end());

        auto last = nums.end();
        for(auto i = nums.begin(); i < last - 2; i++){
            auto j = i + 1;
            if(i > nums.begin() && *i == *(i - 1)) continue;
            auto k = last - 1;
            while(j < k){
                if(*i + *j + *k < target){
                    j++;
                    while(*j == *(j - 1) && j < k) j++;
                }
                else if(*i + *j + *k > target){
                    k--;
                    while(*k == *(k + 1) && j < k) k--;
                }
                else{
                    retVal.push_back({*i, *j, *k});
                    j++;
                    k--;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k) j++;
                }
            }
        }
        return retVal;
    }
};


int main(){
	Solution sol;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(-1);
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(3);

	vector<vector<int>> retVal = sol.threeSum(nums);

    for(auto x : retVal){
        for(auto y : x)
            cout << y << " ";
        cout << "\n";
    }
	return 0;
}