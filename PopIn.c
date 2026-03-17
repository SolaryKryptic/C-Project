void PopIn(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player) {
// this function will 'drop' a token into the board from the specified side
// the token will keep falling until it hits something or the other side of the board
	if (side == 'T') {
		for (int row = 0; row < size; row++) {
			if (board[row][move] != 0) { // != 0 so that when it hits something it will stop
				board[row-1][move] = player;
				return;
			}
		}
		board[size-1][move] = player; // didnt hit anything
	}
	else if (side =='B') {
		for (int row = size-1; row >=0; row--) {
			if (board[row][move] !=0) {
				board[row+1][move] = player;
				return;
			}
		}
		board[0][move] = player;
	}
	else if (side =='L') {
		for (int coloumn = 0; coloumn < size; coloumn++) {
			if (board[move][coloumn] != 0) {
				board[move][coloumn-1] = player;
				return;
			}
		}
		board[move][size-1] = player;
	}
	else if (side == 'R') {
		for (int coloumn = size-1; coloumn >=0; coloumn--) {
			if (board[move][coloumn] != 0) {
				board[move][coloumn+1] = player;
				return;
			}
		}
		board[move][0]=player;
	}
}