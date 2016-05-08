/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * UPDATE (2016/2/13):
 * The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
         * Thoughts:
         *      The input vector better be sorted, or it's hard to iterate.
         *      Therefore, first sort the input vector [O(NlogN)]
         *      Then iterate through the whole vector from both sides
         */
        
        // return vector:
        vector<int> ret;

        // init condition: 
        if(nums.empty())
            return ret;
        
        // sort the input vector
        sort(nums.begin(), nums.end());
        
        // examine the sorted vector:
        for (auto x : nums) cout << x << " ";   cout << "\n";

        // iterate from start to finish
        int start = 0, end = nums.size() - 1;

        while(start < end) {
            if(nums[start] + nums[end] == target) {
                ret.push_back(start);
                ret.push_back(end);
                break;
            }
            else if(nums[start] + nums[end] < target) {
                start++;
            }
            else {
                end--;
            }
        }
        
        // return 
        return ret;
    }
};




int main() {
    
    vector<int> angela = {2, 7, 15, 11};
    int michael = 9;
    
    Solution sol;
    vector<int> ret = sol.twoSum(angela, michael);
    if(ret.empty()) {
        cout << "No matches!\n";
    }
    else {
        cout << "indices:\n";
        for(auto x : ret) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
