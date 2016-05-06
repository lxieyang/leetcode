/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

#include "../global.h"


class Solution {
public:
	bool checkValid(vector<vector<char>> & board, int x, int y) {
		int i, j;
		// check the yth col
		for(i = 0; i < (int)board.size(); ++i)
			if(i != x && board[x][y] == board[i][y])
				return false;
		// check the xth row
		for(j = 0; j < (int)board.size(); ++j) 
			if(j != y && board[x][y] == board[x][j])
				return false;
		// check grid
		for(i = (x / 3) * 3; i < (x / 3 + 1) * 3; ++i) 
			for(j = (y / 3) * 3; j < (y / 3 + 1) * 3; ++j)
				if((i != x || j != y) && (board[i][j] == board[x][y]))
					return false;
		return true;
	}

    bool solveSudoku(vector<vector<char>>& board) {
    	for(unsigned int i = 0; i < board.size(); ++i) {
    		for(unsigned int j = 0; j < board.size(); ++j) {
    			if(board[i][j] == '.') {
    				for(int k = 0; k < (int)board.size(); ++k) {
    					board[i][j] = k + '1';
    					// check if valid. if valid, take it to the next level
    					if(checkValid(board, i, j) && solveSudoku(board))
    						return true;
    					// invalid fill! roll back action and try the next number
    					board[i][j] = '.';
    				}
    				return false;
    			}
    		}
    	}
    	return true;	// all points are filled and there's no problem
    }
};

