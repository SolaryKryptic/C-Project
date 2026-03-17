int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size){
    int player1win = 0;
    int player2win = 0;
    int empty = 0;
    
    for (int row = 0; row < size; row ++){
        for (int col = 0; col < size; col++){
            if (board[row][col] == 0) {
                empty++;
            }
            int result = FourInARow(board,size,row,col); // check for FourInARow
            if (result == 1){
                player1win = 1;
            }
            else if (result == 2){
                player2win = 1;
            }
        }
    }
    if (player1win && player2win){
        return 3; // draw
    }
    else if (player1win){
        return 1; // player 1 win
    }
    else if (player2win){
        return 2; // player 2 win
    }
    else if (empty == 0){
        return 3; // board full draw
    }
    else {
        return 0; // keep playing
    }
}