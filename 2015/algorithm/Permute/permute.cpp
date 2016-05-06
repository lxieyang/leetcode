/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include "../global.h"

class Solution {
public:
	void genPerms(deque<int> & unvisited, vector<int> & path) {
		if(unvisited.empty()) {
			ret.push_back(path);
		}

		for(unsigned k = 0; k < unvisited.size(); k++) {
			path.push_back(unvisited.front());
			unvisited.pop_front();
			genPerms(unvisited, path);
			unvisited.push_back(path.back());
			path.pop_back();
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
    	deque<int> unvisited(nums.begin(), nums.end());
    	vector<int> path;
    	genPerms(unvisited, path);
        return ret;
    }
    
private:
	vector<vector<int>> ret;
};

