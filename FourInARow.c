int FourInARow(int board[MAX_SIZE][MAX_SIZE], int size, int row, int col){
// this function will check if a four in a row has been made and if it has it will return the player
// that made the four in a row 
    int player = board[row][col];
    // if board is empty
    if (player == 0){
        return 0;
    }
    // horizontal
    int count = 1;
    for (int c = col - 1; c >= 0 && board[row][c] == player; c--) { //left
        count++;
    }
    for (int c = col + 1; c < size && board[row][c] == player; c++) { //right
        count++;
    }
    if (count >= 4) {
        return player;
    }
    // vertical
    count = 1;
    for (int r = row - 1; r >= 0 && board[r][col] == player; r--) { //up
        count++;
    }
    for (int r = row + 1; r < size && board[r][col] == player; r++) { //down
        count++;
    }
    if (count >= 4){
        return player;
    }
    // diagonally
    count = 1;
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0 && board[r][c] == player; r--, c--) { // up to the left
        count++;
    }
    for (int r = row + 1, c = col + 1; r < size && c < size && board[r][c] == player; r++, c++) { // down to the right
        count++;
    }
    if (count >= 4){
        return player;
    }
    count = 1;
    for (int r = row - 1, c = col + 1; r >= 0 && c < size && board[r][c] == player; r--, c++) { // up to the right
        count++;
    }
    for (int r = row + 1, c = col - 1; r < size && c >= 0 && board[r][c] == player; r++, c--) { // down to the left
        count++;
    }
    if (count >= 4){
        return player;
    }
    return 0;
}