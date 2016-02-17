/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include "../global.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)	return nums.size();
        int i = 0, probe, total = nums.size();
        for(; i < total; i++){
        	// cout << "i: " << i << endl;
        	for(probe = i; probe < total; probe++){
        		if(nums[probe] != nums[i]){
        			break;
        		}
        	}
        	// cout << "dif is: " << probe - i - 1 << endl;
        	int newTotal = total - (probe - i - 1);
        	for(int j = i + 1; probe < total;){
        		nums[j++] = nums[probe++];
        	}
        	total = newTotal;
        	// cout << "Total: " << total << endl;
        }
        return total;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};

class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int probe = 0;
        for(int i = 1; i < (int)nums.size(); ++i){
        	if(nums[probe] != nums[i])
        		nums[++probe] = nums[i];
        }
        return (probe + 1);
    }
};

int main(){
	vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 10};
	Solution3 sol;
	for(auto x : nums)
		cout << x << " ";
	cout << endl;
	int result = sol.removeDuplicates(nums);
	cout << "--------------------\n";
	cout << result << endl;
	for(int i = 0; i < result; i++)
		cout << nums[i] << " ";
	cout << endl;

	return 0;
}