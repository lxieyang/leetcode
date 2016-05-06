#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, nonZeroPos = 0;
        for(i = 0; i < (int)nums.size() && nonZeroPos < (int)nums.size();i++){
        	while(nums[nonZeroPos] == 0)
        		nonZeroPos++;
        	if(nonZeroPos < (int)nums.size())
        		nums[i] = nums[nonZeroPos];
        	else
        		i--;
        	nonZeroPos++;
        }
        for(; i < (int)nums.size(); i++){
        	nums[i] = 0;
        }
    }
};


int main(){
	Solution sol;
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(12);
	nums.push_back(0);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(12);
	nums.push_back(0);
	nums.push_back(0);

	for(auto x : nums)
		cout << x << " ";
	cout << endl;

	sol.moveZeroes(nums);

	for(auto x : nums)
		cout << x << " ";
	cout << endl;

	return 0;
}