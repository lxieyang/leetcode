/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include "../global.h"

class Solution {
private:
	int bestDistance,
		currentDistance;
	string begin,
		   end;
	vector<string> currentPath,
				   bestPathSoFar;
	vector<vector<string> > paths;
	unordered_set<string> dict;

public:
	bool promising() {
		// check if current distance is greater than the best distance so far
		return currentDistance > bestDistance ? false : true;
	}

	void genPerms() {
		if(currentPath.back() == end && currentDistance <= bestDistance) {
			bestDistance = currentDistance;
			bestPathSoFar.assign(currentPath.begin(), currentPath.end());
			paths.push_back(currentPath);
			return;
		}

		if(!promising()) {
			return;
		}

		for(unsigned i = 0; i < dict.size(); i++) {
			// check if valid, and put stuff in path

			// recursive call
			genPerms();

			// get the back of path out
		}
	}

    vector<vector<string> > findLadders(string begin, string end, unordered_set<string> & dict) {
    	bestDistance = INT_MAX;
    	this->dict = dict;
    	this->begin = begin; this->end = end;
    	currentPath.push_back(begin);
    	bestPathSoFar.push_back(begin);

    	genPerms();

    	// erase all instances in paths that has a size greater than bestDistance

        return paths;
    }
};

int main() {
	string begin = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot", "got", "dog","lot", "log", "cog"};
	Solution sol;
	vector<vector<string> > ret = sol.findLadders(begin, end, dict);
	cout << "POSSIBLE LADDER(S) IS(ARE): \n";
	for(auto x : ret) {
		for (auto y : x)
			cout << y << " ";
		cout << "\n";
	}
	return 0; 
}