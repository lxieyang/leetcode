/*
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>


using namespace std;


// Version 1: Expand from center
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < (int)s.size(); ++i) {

            cout << "Current pass: " << i << "\n";
            
            cout << "Current center: " << s[i] << "\t";
            int single = expandAroundCenter(s, i, i);
            cout << "length: " << single << "\n";
            cout << "Current center: " << s[i] << " and " << s[i + 1] << "\t";
            int doub = expandAroundCenter(s, i, i + 1);
            cout << "length: " << doub << "\n";

            int len = max(single, doub);
            if(len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right) {
        int l = left, r = right;
        while(l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};




int main() {
    string angela = "abbaismyfaviriatebanddnab";
    // string michael = "abba";
    Solution sol;
    string ret = sol.longestPalindrome(angela);
    cout << "longestPalindrome: " << ret << "\n";

}
