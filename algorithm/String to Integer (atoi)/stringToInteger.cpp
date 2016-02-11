/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/


#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int num = 0, sign = 1;
        int i = 0;
        while(str[i] == ' ' && i < str.size()) i++;
        if(str[i] == '+') i++;
        else if(str[i] == '-'){
            sign = -1; i++;
        }        
        
        for(; i < str.size(); i++){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            if(num > INT_MAX / 10 || (num == INT_MAX / 10 &&
                                     (str[i] - '0') > INT_MAX % 10)){
                return sign == -1 ? INT_MIN : INT_MAX;                            
            }
            num = num * 10 + str[i] - '0';
        }
        return num * sign;
    }
};


int main(){
    string cand = "";
    Solution sol;
    cout << "myAtoi(). Press 'q' to abort!\n";
    while(true){
        cin >> cand;
        if(cand[0] == 'q')
            break;
        cout << "original: " << cand << " | converted: " << sol.myAtoi(cand) << endl;
    }
    return 0;
}

