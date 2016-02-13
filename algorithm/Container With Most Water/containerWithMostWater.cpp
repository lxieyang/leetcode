/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxArea = 0;
        while(start < end){
            int area = min(height[start], height[end]) * (end - start);
            maxArea = max(area, maxArea);
            if(height[start] <= height[end]){
                ++start;
            }
            else{
                --end;
            }
        }
        return maxArea;
    }
};

int main(){
    Solution sol;
    vector<int> height = {5, 9, 7, 3, 4, 6, 8, 10, 2, 6};
    cout << "The heights are given by:\n";
    for(auto x : height)    cout << x << " ";
    cout << "\n";
    cout << "THe max area is given by: " << sol.maxArea(height) << endl;
    return 0;
}
