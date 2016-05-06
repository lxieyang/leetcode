/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())    return "";

        for(int i = 0; i < (int)strs[0].size(); ++i){
            for(int j = 1; j < strs.size(); ++j){
                if(strs[j][i] != strs[0][i])
                return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

int main(){
    const char * s [] = {"abcd123", "abc123", "abcde123"};
    vector<string> cand(s, s + 3);
    Solution sol;
    cout << "The original string vector is given by:\n";
    for(auto x : s)
        cout << x << "\n";
    cout << "--------------\n";
    cout << "The longest common prefix is given by: " << sol.longestCommonPrefix(cand) << endl;
    return 0;
}
