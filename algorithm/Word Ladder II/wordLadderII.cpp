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
		   current,
		   end;
	vector<string> currentPath,
				   bestPathSoFar;
	vector<vector<string> > paths;
	unordered_set<string> dict;
	// deque<string> unvisited;

public:
	bool promising() {
		// check if current distance is greater than the best distance so far
		return currentDistance > bestDistance ? false : true;
	}

	void genPerms() {
		if(currentPath.back() == end && currentDistance < bestDistance) {
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
			current = currentPath.back();
			bool isBreak = false;
			for(int i = 0; i < (int)current.size(); i++) {
				string tempWord = current;
				for(char ch = 'a'; ch < 'z'; ch++) {
					tempWord[i] = ch;
					if(dict.count(tempWord) > 0 || 
						(dict.count(tempWord) == 0 && tempWord == end)) {
							cout << "ERASING " << tempWord << endl;
							currentPath.push_back(tempWord);
							dict.erase(tempWord);
							currentDistance += 1;
							isBreak = true;
							genPerms();
							// break;
					}
				}
				// if(isBreak)
				// 	break;
			}

			// recursive call
			// genPerms();

			// get the back of path out and put it back to dict
			dict.insert(currentPath.back());
			currentPath.pop_back();
			currentDistance -= 1;
		}
	}

    vector<vector<string> > findLadders(string begin, string end, unordered_set<string> & dict) {
    	bestDistance = INT_MAX;
    	this->dict = dict;
    	this->begin = begin; this->end = end;
    	currentPath.push_back(begin); currentDistance = 1;
    	bestPathSoFar.push_back(begin);

    	genPerms();

    	// erase all instances in paths that has a size greater than bestDistance

        return paths;
    }
};

int main() {
	string begin = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot", "got", "dog", "lot", "log"};
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