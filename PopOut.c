void PopOut(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player) {
// this function shifts all tokens on a row or coloumn to the direction specified
// leaving an empty cell
	if (side == 'T') {
		for (int row = 0; row < size - 1; row++) {
			board[row][move] = board[row+1][move];
			if (board[row][move] == 0) { // theres a 0
				if (row < size - 1) {
					board[row+1][move] = 0;
				}
				return; // exit early
			}
		}
		board[size-1][move] = 0; // no zeroes were found so set opposite side to 0

	}
// same logic applies to all sides here so no need for any more comments
	else if (side == 'B') {
		for (int row = size - 1; row >0; row--) {
			board[row][move] = board[row-1][move];
			if (board[row][move] == 0) {
				if (row > 0) {
					board[row-1][move] = 0;
				}
				return;
			}
		}
		board[0][move]=0;
	}
	else if (side == 'L') {
		for (int coloumn = 0; coloumn < size - 1; coloumn++) {
			board[move][coloumn] = board[move][coloumn+1];
			if (board[move][coloumn] == 0) {
				if (coloumn < size -1) {
					board[move][coloumn+1] = 0;
				}
				return;
			}
		}
		board[move][size-1] = 0;

	}
	else if (side == 'R') {
		for (int coloumn = size - 1; coloumn > 0; coloumn--) {
			board[move][coloumn] = board[move][coloumn-1];
			if (board[move][coloumn] == 0) {
				if (coloumn > 0) {
					board[move][coloumn-1] = 0;
				}
				return;
			}
		}
		board[move][0] = 0;

	}
}