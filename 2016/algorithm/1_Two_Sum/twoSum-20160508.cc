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
#include <unordered_map>

using namespace std;

// Version 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
         * Thoughts:
         *      Using map on the fly
        */

        vector<int> ret;
        unordered_map<int, int> intMap;
        for(unsigned i = 0; i < nums.size(); ++i) {
            if(!intMap.count(nums[i]))  {   // didn't find!
                intMap[target - nums[i]] = i;
            }
            else {
                ret.push_back(intMap[nums[i]]);
                ret.push_back(i);
                break;
            }
        }

        return ret;
    }
};


// Version 2 [This solution do not work with the "indices" version of the problem]
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
         * Thoughts:
         *      The input vector better be sorted, or it's hard to iterate.
         *      Therefore, first sort the input vector [O(NlogN)]
         *      Then iterate through the whole vector from both sides.
         */

        // return vector:
        vector<int> ret;

        // init condition:
        if(nums.empty())
            return ret;

        // init vector:
        cout << "Init:\n";
        for (auto x : nums) cout << x << " ";   cout << "\n";

        // sort the input vector
        sort(nums.begin(), nums.end());

        // examine the sorted vector:
        cout << "Sorted:\n";
        for (auto x : nums) cout << x << " ";   cout << "\n";

        // iterate from start to finish
        int start = 0, end = nums.size() - 1;

        while(start < end) {
            if(nums[start] + nums[end] == target) {
                ret.push_back(nums[start]);
                ret.push_back(nums[end]);
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

    vector<int> antonia = {2, 7, 15, 11};
    int michael = 9;

    Solution sol;
    vector<int> ret = sol.twoSum(antonia, michael);
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
