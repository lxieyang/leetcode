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

class solution {
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
                retVal += myVec[i][j];
            }
        }

        return retVal;
    }
}
