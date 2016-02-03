/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> retVal;
        unordered_map<int, int> map;
        for(int i = 0; i < (int)nums.size(); i++){
        	if(map.find(nums[i]) == map.end()){
        		map[target - nums[i]] = i;
        	}
        	else{
        		retVal.push_back(1 + map[nums[i]]);
        		retVal.push_back(i + 1);
        		break;
        	}
        }
        return retVal;
    }

    // this solution will give the exact two numbers that add up to the target
    // rather than their indecies
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> retVal;
        sort(nums.begin(), nums.end());
        for(auto x : nums) cout << x << " ";
        cout << endl;
        int i = 0, j = nums.size() - 1;
        while(i < j){
        	int sum = nums[i] + nums[j];
        	if(sum == target){
        		retVal.push_back(nums[i]);
        		retVal.push_back(nums[j]);
        		break;
        	}
        	else if(sum < target)
        		i++;
        	else
        		j--;
        }
        return retVal;
    }
};


int main(){
	Solution sol;
	int target = 6;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);

	vector<int> retVal = sol.twoSum(nums, target);
	cout << retVal[0] << ", " << retVal[1] << endl;

	return 0;
}