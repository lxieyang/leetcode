/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include "../global.h"

// Recursive
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return vector<string>(1, "");
        if(n == 1) return vector<string>(1, "()");
        vector<string> result;
        for(int i = 0; i < n; ++i){
            for(auto inner : generateParenthesis(i))
                for(auto outer : generateParenthesis(n - 1 - i))
                    result.push_back("(" + inner + ")" + outer);
        }
        return result;
    }
};

// Recursive
class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        generate(s, n, n, result);
        return result;
    }

    void generate(string s, int l, int r, vector<string> & result){
        if(l == 0 && r == 0){
            result.push_back(s);
            return;
        }
        if(l > 0){
            // printVector(result);
            generate(s + '(', l - 1, r, result);
        }
        if(r > 0 && r > l){
            // printVector(result);
            generate(s + ')', l, r - 1, result);
        }
    }

    void printVector(vector<string> & vec){
        for(auto x : vec) cout << x << " | ";
        cout << endl;
    }
};

// Brute force
class Solution3 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<string> path;
        deque<string> unvisited;
        for(int i = 0; i < n; ++i){
            unvisited.push_back("(");
            unvisited.push_back(")");
        }
        genPerms(unvisited, path, result);
        sort(result.begin(), result.end());
        auto it = unique(result.begin(), result.end());
        result.resize(distance(result.begin(), it));
        return result;
    }

    void genPerms(deque<string> & unvisited, vector<string> & path, vector<string> & result){
        if(unvisited.empty()){
            string s;
            for(auto x : path) s += x;
            if(isValid(s))
                result.push_back(s);
        }
        for(unsigned k = 0; k < unvisited.size(); ++k){
            path.push_back(unvisited.front());
            unvisited.pop_front();
            genPerms(unvisited, path, result);
            unvisited.push_back(path.back());
            path.pop_back();
        }
    }

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
    Solution3 sol;
    int seed = 3;
    for(auto x : sol.generateParenthesis(seed))
        cout << x << "  ";
    cout << endl;
    return 0;
}
