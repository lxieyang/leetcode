#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while(num / 10 != 0){
        	int sum = num % 10;
        	while(num / 10 != 0){
        		num /= 10;
        		sum += (num % 10);
        	}
        	num = sum;
        }
        return num;
    }

    int addDigits2(int num){
    	while(num > 9){
    		num = num / 10 + num % 10;
    	}
    	return num;
    }
};


int main(){
	Solution sol;
	int seed = 38;
	cout << "Adding the digits of " << seed << ": " 
		<< sol.addDigits(seed) // << sol.addDigits2(seed)
		<< endl;
	return 0;
}