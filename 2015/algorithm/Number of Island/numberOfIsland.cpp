/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

#include "../global.h"


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	if(grid.empty())	return 0;
        rowSize = grid.size();
        colSize = grid[0].size();
        // cout << "Grid size: " << rowSize << " x " << colSize << "\n";
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
        queue<px> ones;

        int islandCount = 0;
        for(int i = 0; i < rowSize; i++) {
        	for(int j = 0; j < colSize; j++) {
        		if(visited[i][j])
        			continue;
        		visited[i][j] = true;
        		if(grid[i][j] == '1') {
        			ones.push({i, j});
        			// cout << "pushing " << "(" << i << ", " << j << ")\n";
        			while(!ones.empty()) {
        				px curr, next;
        				curr = ones.front(); ones.pop();
        				// cout << "CURRENT: (" << curr.row << ", " << curr.col << ")\n";
        				for(int k = 0; k < 4; k++) {
        					if(getNextPos(curr, next, k)) {
        						if(!visited[next.row][next.col] 
        							&& grid[next.row][next.col] == '1') {
        							ones.push(next);
        						}
        						visited[next.row][next.col] = true;
        					}
        				}
        			}
        			islandCount++;
        		}
        	}
        }
        return islandCount;
    }
private:
	struct px {
		int row,
			col;
	};

	int rowSize,
		colSize;

	bool getNextPos(const px & curr, px & next, int dir) {
		switch(dir) {
			case 0:		// west
				next.row = curr.row;
				next.col = curr.col - 1;
				break;
			case 1:		//  north
				next.row = curr.row - 1;
				next.col = curr.col;
				break;
			case 2:		// east
				next.row = curr.row;
				next.col = curr.col + 1;
				break;
			case 3:		// south
				next.row = curr.row + 1;
				next.col = curr.col;
				break;
			default:
				next = curr;
				break;
		}
		if(next.row < 0 || next.row >= rowSize 
			|| next.col < 0 || next.col >= colSize)
			return false;
		return true;
	}
};

int main() {
	vector<vector<char> > grid;
	grid.push_back({'1','1'});
	Solution sol;
	for(auto x : grid) {
		for(auto y : x)
			cout << y << " ";
		cout << "\n";
	}
	int result = sol.numIslands(grid);
	cout << "\n# of island is: " << result << endl;

	return 0;
}