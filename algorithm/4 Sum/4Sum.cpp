/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<pair<int, int> > > cache;
        for(int i = 0; i < (int)nums.size(); i++){
            for(int j = i + 1; j < (int)nums.size(); j++){
                cache[nums[i] + nums[j]].push_back(pair<int, int>(i, j));
            }
        }

        for(int k = 0; k < (int)nums.size(); k++){
            for(int l = k + 1; l < (int)nums.size(); l++){
                int key = target - nums[k] - nums[l];
                if(cache.find(key) == cache.end())
                    continue;
                vector<pair<int, int> > tempVec = cache[key];
                for(int p = 0; p < (int)tempVec.size(); p++){
                    if(k <= tempVec[p].second)   
                        continue;
                    result.push_back({nums[tempVec[p].first], nums[tempVec[p].second], nums[k], nums[l]});
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};


int main(){
	Solution sol;
	vector<int> nums;
    int target = 0;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(-2);

	vector<vector<int> > retVal = sol.fourSum(nums, target);

    for(auto x : retVal){
        for(auto y : x)
            cout << y << " ";
        cout << "\n";
    }
	return 0;
}

