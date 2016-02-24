/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

#include "../global.h"


class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
    	stack<int> s;
    	height.push_back(0);
    	int maxArea = 0;
    	for(int i = 0; i < (int)height.size(); ) {
    		if(s.empty() || height[i] > height[s.top()]) 
    			s.push(i++);
    		else {
    			int temp = s.top(); s.pop();
    			maxArea = max(maxArea, height[temp] * (s.empty() ? i : i - s.top() - 1));
    		}
    	}
    	return maxArea;
    }
};


int main() {
	vector<int> height({2,1,5,6,2,3});
	Solution sol;
	int result = sol.largestRectangleArea(height);
	cout << result << endl;
	return 0;
}



