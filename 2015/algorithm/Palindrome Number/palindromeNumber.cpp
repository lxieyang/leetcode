/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int d = 1; // divisor
        while(x / d >= 10) d *= 10;
        while(x > 0){
            int q = x / d;   // quotient    
            int r = x % 10;     // remainder
            if(q != r) return false;
            x = (x % d) / 10;
            d /= 100;
        }
        return true;
    }
};

int main(){
    Solution sol;
    int cand = 12321;
    cout << cand << " is a Palindrome? -> " << sol.isPalindrome(cand) << endl;
    return 0;
}