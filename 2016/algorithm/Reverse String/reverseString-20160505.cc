#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public: 
    string reverseString(string s) {
        stack<char> stk;
        for(unsigned i = 0; i < s.size(); i++) {
            stk.push(s[i]);
        }
        
        string ret = "";
        while(!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }

        return ret;
    }
};

int main() {
    Solution sol;
    string concern = "angela";
    cout << sol.reverseString(concern) << "\n";
    return 0;
}
