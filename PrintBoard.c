void PrintBoard(int board[MAX_SIZE][MAX_SIZE], int size) {
    //top row 
    printf("-- ");
    for (int coloumn = 0; coloumn < size; coloumn++) {
        printf("T ");
    }
    printf("--\n");
    
    // coloumn numbers
    printf("-- ");
    for (int coloumn = 0; coloumn < size; coloumn++) {
        printf("%d ", coloumn);
    }
    printf("--\n");
    
    // print each row 
    for (int row = 0;row < size; row++){
        printf("L%d ",row);  // left side
        for (int coloumn=0; coloumn<size; coloumn++){
            if (board[row][coloumn] == 0){ // empty
                printf(". "); // print .
            }
            else if (board[row][coloumn] == 1) {
                printf("X "); // player 1 
            }
            else if (board[row][coloumn] == 2) {
                printf("O "); // player 2 
            }
        }
        printf("%dR\n",row); // right side
    }
    // bottom coloumn numbers
    printf("-- ");
    for (int coloumn = 0; coloumn < size; coloumn++) {
        printf("%d ", coloumn);
    }
    printf("--\n");
    //bottom row 
    printf("-- ");
    for (int coloumn = 0; coloumn < size; coloumn++) {
        printf("B ");
    }
    printf("--\n");
}