/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> myMap;
        int lastRepeatPos = -1;
        int retVal = 0;
        for(int i = 0; i < (int)s.size(); i++){
            if(myMap.find(s[i]) != myMap.end() && lastRepeatPos < myMap[s[i]]){
                lastRepeatPos = myMap[s[i]];
            }
            if(i - lastRepeatPos > retVal){
                retVal = i - lastRepeatPos;
            }
            myMap[s[i]] = i;
        }
        return retVal;
    }
};

int main()
{
    Solution sol;
    string cand [] = {"abcabcdabccde", "abcabcbb", "bbbbb"};
    for (auto x : cand)
        cout << "String is: " << x << "\nReturn value is: " << sol.lengthOfLongestSubstring(x) << "\n";
    return 0;
}
