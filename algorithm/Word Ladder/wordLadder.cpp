/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include "../global.h"

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string>& dict) {
    	// distance will:
    	// 1) store the distance so far
    	// 2) remove the dups
        map<string, int> distance;
        distance[start] = 1;

        // using a queue for BFS
        queue<string> wordQueue;
        wordQueue.push(start);

        while(!wordQueue.empty()) {
            string current = wordQueue.front(); 	wordQueue.pop();
            
            // done looking for words!
            if(current == end)
            	break;

            // put everything prospective into the queue
            for(int i = 0; i < (int)current.size(); i++) {
            	// find those words that are a letter different from current
            	string tempWord = current;
            	for(char ch = 'a'; ch < 'z'; ++ch) {
            		// replace the ith letter with ch
            		tempWord[i] = ch;
            		if((dict.count(tempWord) > 0 // found this in dict
            			&& distance.count(tempWord) == 0) // didn't find this in the distance map
            			|| 
            			(dict.count(tempWord) == 0 && tempWord == end)	// end word not in dict and tempWord is the same as end
            			) {
            			distance[tempWord] = distance[current] + 1; 	// update the distance
            			wordQueue.push(tempWord); 	// push it into the back of the queue
            		}
            	}
            }
        }
        return (distance.count(end) == 0) ? 0 : distance[end];
    }
};


int main() {
	string begin = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot", "got", "dog","lot", "log", "cog"};
	Solution sol;
	int ret = sol.ladderLength(begin, end, dict);
	cout << "FROM \'" << begin << "\' TO \'" << end << "\' TAKES " << ret << " STEPS\n";
	return 0; 
}
