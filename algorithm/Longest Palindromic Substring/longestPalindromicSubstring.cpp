/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Dynamic Programming Solution
    string longestPalindrome(string s) {
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n * n, false);
        size_t len = 1, start = 0;
        for(size_t i = 0; i < s.size(); i++){
            f[i][i] = true;
            for(size_t j = 0; j < i; j++){
                if(i == j || (s[i] == s[j] && (i - j < 2 || f[i - 1][j + 1]))){
                    f[i][j] = true;
                    if (len < i-j+1){
                        start = j;
                        len = i-j+1;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};

int main(){
    string cand = "acbcdcbcb";
    Solution sol;
    cout << cand << "\n-------------\n" << sol.longestPalindrome(cand) << "\n";
    return 0;
}
