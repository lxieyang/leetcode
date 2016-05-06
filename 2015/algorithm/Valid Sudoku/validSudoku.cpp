/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/

#include "../global.h"

#include <atomic>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        bool rowValid[N][N] = {false};
        bool colValid[N][N] = {false};
        bool gridValid[N][N] = {false};

        for(unsigned int r = 0; r < board.size(); ++r) {
        	for(unsigned int c = 0; c < board[r].size(); ++c) {
        		if(!isdigit(board[r][c]))	// not filled
        			continue;
        		int idx = board[r][c] - '0' - 1;

        		// check row
        		if(rowValid[r][idx] == true) 
        			return false;
        		rowValid[r][idx] = true;

        		// check col
        		if(colValid[c][idx] == true)
        			return false;
        		colValid[c][idx] = true;

        		int gridNo = (r / 3) * 3 + (c / 3);
        		// check grid
        		if(gridValid[gridNo][idx] == true)
        			return false;
        		gridValid[gridNo][idx] = true;
        	}
        }
        return true;
    }
};


class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<std::atomic<bool>>> rowValid;
        vector<vector<std::atomic<bool>>> colValid;
        vector<vector<std::atomic<bool>>> gridValid;
        rowValid.resize(board.size());
        colValid.resize(board.size());
        gridValid.resize(board.size());
        for(unsigned int i = 0; i < board.size(); ++i) {
        	rowValid[i].resize(board[i].size());
        	colValid[i].resize(board[i].size());
        	gridValid[i].resize(board[i].size());
        	for(unsigned int j = 0; j < board[i].size(); ++j) {
        		rowValid[i][j] = false;
        		colValid[i][j] = false;
        		gridValid[i][j] = false;
        	}
        }

        for(unsigned int r = 0; r < board.size(); ++r) {
        	for(unsigned int c = 0; c < board[r].size(); ++c) {
        		if(!isdigit(board[r][c]))	// not filled
        			continue;
        		int idx = board[r][c] - '0' - 1;

        		// check row
        		if(rowValid[r][idx].exchange(true)) 
        			return false;

        		// check col
        		if(colValid[c][idx].exchange(true))
        			return false;

        		int gridNo = (r / 3) * 3 + (c / 3);
        		// check grid
        		if(gridValid[gridNo][idx].exchange(true))
        			return false;
        	}
        }
        return true;
    }
};


