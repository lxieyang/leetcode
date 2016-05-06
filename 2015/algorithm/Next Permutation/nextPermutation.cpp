/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include "../global.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }

    template<typename BidirIterator>
    bool next_permutation(BidirIterator first, BidirIterator last) {
    	const auto rfirst = reverse_iterator<BidirIterator>(last);
    	const auto rlast = reverse_iterator<BidirIterator>(first);

    	auto pivot = next(rfirst);
    	while(pivot != rlast && *pivot >= *prev(pivot))
    		++pivot;

    	if(pivot == rlast) {
    		reverse(rfirst, rlast);
    		return false;
    	}

    	auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
    	swap(*change, *pivot);
    	reverse(rfirst, pivot);

    	return true;
    }
};





/*
 * Take a look the following continuous permutation, can you find the patern?
 *
 *    1 2 3 4
 *    1 2 4 3
 *    1 3 2 4
 *    1 3 4 2
 *    1 4 2 3
 *    1 4 3 2
 *    2 1 3 4
 *    ...
 *
 * The pattern as below:
 *
 *    1) find the first place which num[i-1] < num[i]
 *    2) find the first number from n-1 to i which >= num[i-1]
 *    3) swap the 2) num with num[i-1]
 *    4) sort the sub-array [i, n) //actuall sort is fine as well
 * 
 * For example:
 * 
 *     1 4 3 2   <-- 1) find the first place which num[i-1] < num[i]
 *     ^
 * 
 *     1 4 3 2   <-- 2) find the first number from n-1 to i which >= num[i-1]
 *     ^     ^  
 * 
 *     2 4 3 1   <-- 3) swap them
 *     ^     ^
 * 
 *     2 4 3 1   <-- 4) sort
 *       ^   ^
 *
 *     2 1 3 4   
 * 
 * Edge Case:
 *
 *     4 3 2 1, the next permutation is 1 2 3 4
 */

class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;

        for(int i = (int)nums.size() - 1; i > 0; i--) {
        	if(nums[i - 1] < nums[i]) {
        		int j = nums.size() - 1;
        		while(nums[i - 1] >= nums[j])
        			j--;
        		swap(nums[j], nums[i - 1]);
        		reverse(nums.begin() + i, nums.end());
        		return;
        	}

        	if(i == 1) {
        		reverse(nums.begin(), nums.end());
        		return;
        	}
        }
    }
};

