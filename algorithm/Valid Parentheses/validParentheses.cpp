/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;

        for(int i = 0; i < (int)s.size(); ++i){
            // cout << s[i] << "\n";
            if(left.find(s[i]) != string::npos){
                stk.push(s[i]);
            }
            else{
                if(stk.empty() || stk.top() != left[right.find(s[i])])
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};


int main(){
    vector<string> tests;
    tests.push_back("{}[]()()[]{}}");
    tests.push_back("({){}}})");
    tests.push_back("()()()()()()()()()()");
    tests.push_back("()");
    Solution sol;
    for(auto x : tests)
        cout << "Original String is: " << x << ". And it's a valid string? " << sol.isValid(x) << endl;
    return 0;
}
