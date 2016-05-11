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


using namespace std;

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



int main() {
    string anglea = "abcdefgabcdefghabcdefghi";
    Solution sol;
    cout << "String: \n" << anglea << "\n";
    cout << "Length of longest no dup substring: " << sol.lengthOfLongestSubstring(anglea) << "\n";

    return 0;
}
