#include <stack>
#include <iostream>
#include <string>

using namespace std;


// Solution 1
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


// Solution 2
class Solution2 {
public: 
    string reverseString(string s) {
       string ret = "";
       for(int i = s.size() - 1; i >= 0; i--) {
           ret += s[i];
       }

       return ret;
    }
};




int main() {
    Solution sol;
    Solution2 sol2;
    string concern = "angela";
    cout << sol.reverseString(concern) << "\n";
    cout << sol2.reverseString(concern) << "\n";
    return 0;
}
