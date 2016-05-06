#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return !(n % 4 == 0);
    }
};

int main(){
	Solution sol;
	int seed = 8;
	cout << "Can win with " << seed << " stones? " 
		<< sol.canWinNim(seed) << endl;
	return 0;
}