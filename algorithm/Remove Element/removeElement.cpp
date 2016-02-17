/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int target) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), target));
    }
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int target) {
        int idx = 0;
        for(int probe = 0; probe < (int)nums.size(); ++probe){
        	if(nums[probe] != target)
        		nums[idx++] = nums[probe];
        }
        return idx;
    }
};