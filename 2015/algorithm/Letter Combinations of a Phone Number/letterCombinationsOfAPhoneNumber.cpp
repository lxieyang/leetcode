/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    const vector<string> keyboard {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        vector<string> result;
        for(int i = 0; i < (int) digits.size(); ++i){
            if(!isdigit(digits[i]))
                return vector<string>();
            int d = digits[i] - '0';
            if(result.size() <= 0){
                for(int j = 0; j < (int)keyboard[d].size(); ++j){
                    string s;
                    s += keyboard[d][j];
                    result.push_back(s);
                }
                continue;
            }
            vector<string> tmp;
            for(int k = 0; k < (int)result.size(); ++k){
                for(int p = 0; p < (int)keyboard[d].size(); ++p){
                    string s = result[k] + keyboard[d][p];
                    tmp.push_back(s);
                }
            }
            result = tmp;
        }
        return result;
    }
};

int main(){
    Solution sol;
    string cand = "234";
    vector<string> ret = sol.letterCombinations(cand);
    cout << "--------------------\n";
    for(auto x : ret)
        cout << x << " ";
    cout << endl;
    return 0;
}
