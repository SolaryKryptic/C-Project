void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size, char *initialise) {
// this function will initialise a square board from a string of characters 
	int index = 0; // position in string
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (initialise == NULL || initialise[index] == '\0') { // check if null or if at end of the string
				board[row][col] = 0;
			}
			else if (initialise[index] =='X') { // player 1 uses X
				board[row][col] = 1;
			}
			else if (initialise[index] == 'O') { // player 2 uses O
				board[row][col] = 2;
			}
			else {
				board[row][col] = 0; // if current position in string doesnt have X or O then put 0 in the grid
			}
			if (initialise != NULL && initialise[index] != '\0') {
				index++; // move to next position if possible
			}
		}
	}
}