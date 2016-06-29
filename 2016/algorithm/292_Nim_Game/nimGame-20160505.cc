#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return ! (n % 4 == 0);
    }
};


int main() {
    Solution sol;
    string concern;
    cout << "Let's see if you can win!\n"
        << "Hit 'q' to quit!\n";

    while(cin >> concern) {
        if(concern != "q") {
            int real = stoi(concern, nullptr, 0);
            if (sol.canWinNim(real)) {
                cout << "Can Win Nim!\n";
            }
            else {
                cout << "Oops! Can't win!\n";
            }
        }
        else
            break;
    }

    

    return 0;
}



