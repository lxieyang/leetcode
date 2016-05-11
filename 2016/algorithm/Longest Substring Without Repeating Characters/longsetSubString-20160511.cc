/*
 Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;


// Version 1: 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Thoughts:
        //      use a map to store each char's last known location
        
        unordered_map<char, int> posMap;     // map<char, last known pos>
        int lastDupPosition = -1;
        unsigned globalMax = 0;
        for(unsigned i = 0; i < s.size(); ++i) {
            char curr = s[i];
            if(posMap.count(curr) && posMap[curr] > lastDupPosition) {
                lastDupPosition = posMap[curr];
            }

            if(i - lastDupPosition > globalMax) {
                globalMax = i - lastDupPosition;
            }

            posMap[curr] = i;
        }

        return globalMax;
    }
};



// Version 2: Sliding Window
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
       // Thoughts:
       //       Using a sliding window to check for each i, if s[i, j) has dup chars
       //       We use HashSet to store the characters in current window [i, j) (j = i initially)
       //       Then we slide the index j to the right. If it is not in the HashSet, we slide j further.
       //       Doing so until s[j] is already in the HashSet. 
       //       At this point, we found the maximum size of substrings without duplicate 
       //       characters start with index i.
       //       If we do this for all i, we get out answer.
        
        unordered_set<char> window;
        unsigned i = 0, j = 0;
        unsigned globalMax = 0;
        while(i < s.size() && j < s.size()) {
            if(!window.count(s[j])){
                window.insert(s[j++]);
                globalMax = max(globalMax, j - i);
            }
            else {
                window.erase(s[i++]);
            }
        }
        return globalMax;
    }
};



// Version 3: Sliding Window with optimization
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        // Thoughts:
        //      Use map instead of set to cache the last known location of each char
        
        unsigned globalMax = 0;
        unsigned i = 0, j = 0;

        unordered_map<char, unsigned> posMap;   // map<char, last known pos>
        for(; j < s.size(); ++j) {
            if(posMap.count(s[j])) {
                i = max(i, posMap[s[j]] + 1);
                // jump directly to the next location
            }
            globalMax = max(globalMax, j - i + 1);
            posMap[s[j]] = j;
        }

        return globalMax;
    }
};




int main() {
    string anglea = "abcdefgabcdefghabcdefghi";
    Solution3 sol;
    cout << "String: \n" << anglea << "\n";
    cout << "Length of longest no dup substring: " << sol.lengthOfLongestSubstring(anglea) << "\n";

    return 0;
}
