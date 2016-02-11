/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int y) {
        long long x = y;
        bool isNeg = x > 0 ? false : true;
        long long returnVal = 0;
        x = abs(x);
        while(x / 10){
            returnVal = returnVal * 10 + x % 10;
            x /= 10;
        }     
        returnVal = returnVal * 10 + x;
        if(returnVal > 2147483647){
            returnVal = 0;
        }
        if(isNeg)
            returnVal = -1 * returnVal; 
        return returnVal;  
    }
};

int main(){
    int seed = 1234567;
    int seed2 = -1534236469;
    Solution sol;
    cout << "original:" << seed << " | reversed:" << sol.reverse(seed) << endl;
    cout << "original:" << seed2 << " | reversed:" << sol.reverse(seed2) << endl;
    return 0;
}