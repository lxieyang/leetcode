/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/


#include "../global.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // current position
        int i = 0, j = 0;
        while(i < m && j < n) {
        	// in the current row
        	j = 0;
            if(matrix[i][0] > target)
                return false;
        	else if(matrix[i][0] <= target && matrix[i][n - 1] >= target) {
        		// linear search
        		// for(; j < n; j++)
        		//   if(matrix[i][j] == target)
        		//      return true;

        		// binary search
        		if(binarySearch(matrix[i], 0, n - 1, target))
                    return true;
                else 
                    return false;
        	}
        	else
        		i++;
        }
        return false;
    }

    bool binarySearch(vector<int> & range, int left, int right, int target) {
    	while(left <= right) {
    		int mid = (left + (right - left) / 2);
            // cout << "LEFT: " << left << " RIGHT: " << right << " MID: " << mid << "\n";
            // cout << "range[mid] = " << range[mid] << "\n";
    		if(range[mid] == target) {
    			return true;
    		}
    		else if(range[mid] < target) {
    			left = mid + 1;
    		}
    		else {
    			right = mid - 1;
    		}
            // sleep(1);
    	}
    	return false;
    }
};

int main() {

	vector<vector<int> > matrix = {{1, 3, 5, 7}, {10, 11, 16,20}, {23, 30, 34, 50}};
	int target = 22;
	Solution sol;
	cout << "In the matrix: \n";
	for(auto x : matrix){
		for(auto y : x)
			cout << y << "\t";
		cout << "\n";
	}
	cout << "there is " << target << "? " << sol.searchMatrix(matrix, target) << "\n";

	return 0;
}