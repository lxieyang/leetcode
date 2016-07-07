/*

    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
    
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:
    
    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.size() <= 1) 
            return s;

        // create numRows vectors
        vector<vector<char> > myVec(numRows);
        int period = 2 * (numRows - 1);
        int cycle = s.size() / numRows + 1;
        for (int i = 0; i < cycle; ++i) {
            for (int j = 0; j < numRows && (i * period + j) < s.size(); ++j) {
                myVec[j].push_back(s[i * period + j]);
            }
            for (int k = 0; k < period - numRows && (i * period + k + numRows) < s.size(); ++k) {
                myVec[numRows - 2 - k].push_back(s[i * period + k + numRows]);
            }
        }
        
        string retVal = "";
        for (int i = 0; i < myVec.size(); ++i) {
            for(int j = 0; j < myVec[i].size(); ++j) {
                retVal.append(1, myVec[i][j]);
            }
        }
        return retVal;
    }
};


class Solution2 {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.size() <= 1) {
            return s;
        }

        string result;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0, idx = i; idx < s.size(); j++, idx = 2 * (numRows - 1) * j + i) {
                result += s[idx];  
                if(i == 0 || i == numRows - 1) 
                    continue;
                if(idx + (numRows - i - 1) * 2 < s.size()) {
                    result += s[idx + (numRows - i - 1) * 2];
                }
            }
        }

        return result;
    }
};


int main() {
    string test = "PAYPALISHIRING";
    Solution sol;
    cout << sol.convert(test, 4) << "\n";
}
