/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include "../global.h"

class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        if(grid.empty())	return;
        rowSize = grid.size();
        colSize = grid[0].size();
        // cout << "Grid size: " << rowSize << " x " << colSize << "\n";
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
        queue<px> zeros;
        bool isRegion;
        vector<px> mark;

        for(int i = 0; i < rowSize; i++) {
        	for(int j = 0; j < colSize; j++) {
        		if(visited[i][j])
        			continue;
        		visited[i][j] = true;
        		isRegion = true;
        		if(grid[i][j] == 'O') {
        			zeros.push({i, j});
        			mark.push_back({i, j});
        			// cout << "pushing " << "(" << i << ", " << j << ")\n";
        			while(!zeros.empty()) {
        				px curr, next;
        				curr = zeros.front(); zeros.pop();
        				// cout << "CURRENT: (" << curr.row << ", " << curr.col << ")\n";
        				for(int k = 0; k < 4; k++) {
        					if(getNextPos(curr, next, k)) {
        						if(!visited[next.row][next.col] 
        							&& grid[next.row][next.col] == 'O') {
        							zeros.push(next);
        							mark.push_back(next);
        						}
        						visited[next.row][next.col] = true;
        					} else {
        						isRegion = false;
        					}
        				}
        			}
        			if(!isRegion)
        				mark.clear();
        			else {
        				for(auto x :mark) {
        					// cout << x.row << ", " << x.col << "\n";
        					grid[x.row][x.col] = 'X';
        				}
        			}
        		}
        		mark.clear();
        	}
        }

    }
private:
	int rowSize,
		colSize;

	struct px {
		int row,
			col;
	};

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
	grid.push_back({'X', 'X', 'X', 'X'});
	grid.push_back({'X', 'O', 'O', 'X'});
	grid.push_back({'X', 'X', 'O', 'X'});
	grid.push_back({'X', 'O', 'X', 'X'});
	Solution sol;
	for(auto x : grid) {
		for(auto y : x)
			cout << y << " ";
		cout << "\n";
	}
	sol.solve(grid);
	cout << "\nResult: " << endl;
	for(auto x : grid) {
		for(auto y : x)
			cout << y << " ";
		cout << "\n";
	}

	return 0;
}



