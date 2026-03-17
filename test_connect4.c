#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* This is the maximum size allowed for the underlying 2D array */
#define MAX_SIZE 10

/*********************************************************************************/
/*********************************************************************************/
/*** Place your definitions of the functions from connect4.c here ***/
/*********************************************************************************/
/*********************************************************************************/


/*********************************************************************************/
int FourPos(int values[], int length) {
	for (int i = 0; i <= length-4; i++) {
		if (values[i] == values[i+1] && values[i] == values[i+2] && values[i] == values[i+3]) {
			return i;
		}
	}
	return -1;
}
#define MAX_SIZE 10
void PrintGrid(int board[MAX_SIZE][MAX_SIZE], int size) {
// this function will print a square grid with a border of #s
// size - determines the size of the grid 
	// top border
	for (int i = 0; i <size*2+1; i++) {
		printf("#");
	}
	printf("\n");

	// each row
	for (int row = 0; row < size; row++) {
		printf("#");
		for (int col=0; col<size; col++) {
			printf("%d",board[row][col]);
			if (col < size -1) {
				printf(" "); // add spacing
			}
		}
		printf("#\n");
	}
	// bottom border
	for (int i = 0; i <size*2+1; i++) {
		printf("#");
	}
	printf("\n");
}

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size, char *initialise) {
// this function will initialise a square board from a string of characters 
	int index = 0; // position in string
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (initialise == 0 || initialise[index] == '\0') { // check if null or if at end of the string
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
			if (initialise != 0 && initialise[index] != '\0') {
				index++; // move to next position if possible
			}
		}
	}
}
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
void MakeMove(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player){
// this function will make a PopIn or PopOut move depending on the inputs, if the inputs
// are invalid it will not alter the board

//validation rules
if ( side != 'T' && side != 'B' && side != 'L' && side != 'R') {
	return; // side input is invalid
}
if (move < 0 || move >= size) {
	return; // out of bounds
}
if (player != 1 && player != 2) {
	return; //player is invalid
}
int row,coloumn; // entry based on chosen side
if (side == 'T') {
	row = 0;
	coloumn = move;
}
else if (side == 'B') {
	row = size-1;
	coloumn = move;
}
else if (side == 'L') {
	row = move;
	coloumn = 0;
}
else { // side must be R
	row = move;
	coloumn = size -1;
}
int cell = board[row][coloumn]; // get the current value of the cell at the position
if (cell ==0) { // when empty PopIn
	PopIn(board,size,side,move,player);
}
else if (cell == player) { // if players token PopOut
	PopOut(board,size,side,move,player);
}
// otherwise do nothing
}
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
        return 0; // board full draw
    }
    else {
        return 0; // keep playing
    }
}
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
/*********************************************************************************/


/*********************************************************************************/
/*********************************************************************************/
/*** The following functions support an interactive game of Connect Four ***/
/*********************************************************************************/
 /*********************************************************************************/
 /*********************************************************************************/
/** GetMove **/
/** This function is called when a human player is asked to enter their move.  The character
(representing the side of the board) and the digit (representing the row/column) are
returned via the pointers *side and *move.
/*********************************************************************************/
void GetMove(char *side, int *move, int player)
{
	char a = ' ';
	char b = ' ';
	printf("Player %d: enter move [side/position]: ", player);
	while (!(a == 'T' || a == 'L' || a == 'R' || a == 'B')) {
		scanf("%c", &a);
	}
	while (!(b >= '0' && b <= '9')) {
		scanf("%c", &b);
	}
	*side = a;
	*move = (int)(b - '0');
}

 /*********************************************************************************/
 /*********************************************************************************/
/** GetMoveBot1 **/
/** This function is called when the first bot (Bot 1) is asked to select a move.
The function is given the current configuration of the board, and its chosen move
is returned via the pointers *side and *move. 
/*********************************************************************************/
void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	char sides[] = {'T', 'B', 'L', 'R'};
	int temp_board[MAX_SIZE][MAX_SIZE];
	int opponent = 3 - player;  // if player 1, opponent is playwer 2 / if player 2, opponent is player 1

	player = board[0][0]; // statement to prevent compiler warning
	// first strat -> if can win on this move then win
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size; j++) { // get the board
			for (int k = 0; k < size; k++) {
				for (int x = 0; x < size; x++) {
					temp_board[k][x] = board[k][x];
				}
			}	
			PopIn(temp_board, size, sides[i], j, player); // test by adding a token
			// check if this is winning
			if (CheckGameOver(temp_board, size) == player) {
			*side = sides[i];
			*move = j;
			return;
			}
		}
	}
	// strat 2-> if can block opponents win do that - the first 2 strategies are what Paulbot is using I think so 
	// this bot needs to atleast match it to win
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size; j++) { // get the board
			for (int k = 0; k < size; k++) {
				for (int x = 0; x < size; x++) {
					temp_board[k][x] = board[k][x];
				}
			}
			
			PopIn(temp_board, size, sides[i], j, opponent);  // try opponent move
			
			// check if opponent would win
			if (CheckGameOver(temp_board, size) == opponent) {
				*side = sides[i];
				*move = j;
				return;  // Block by playing here ourselves
			}
		}
	}
	// strat 3 (after all other strats) -> add only to empty
	
	int rand_side = rand() % 4;
	int rand_move = rand() % size;
	
	int row, col;
		
	// find entry through randomness
	if (rand_side == 0) { // top
		row = 0;
		col = rand_move;
	} else if (rand_side == 1) { // bottom
		row = size - 1;
		col = rand_move;
	} else if (rand_side == 2) { // left
		row = rand_move;
		col = 0;
	} else { // right
		row = rand_move;
		col = size - 1;
	}
		
	// cehck if empty
	if (board[row][col] == 0) {
		*side = sides[rand_side];
		*move = rand_move;
		return;
	}

}

 /*********************************************************************************/
 /*********************************************************************************/
/** GetMoveBot2 **/
/** This function is called when the second bot (Bot 2) is asked to select a move.
The function is given the current configuration of the board, and its chosen move
is returned via the pointers *side and *move. 
/*********************************************************************************/
void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	char sides[] = {'T', 'B', 'L', 'R'};
	int temp_board[MAX_SIZE][MAX_SIZE];
	int opponent = 3 - player;  // if player 1, opponent is playwer 2 / if player 2, opponent is player 1

	player = board[0][0]; // statement to prevent compiler warning
	// first strat -> if can win on this move then win
	for (int s = 0; s < 4; s++) {
		for (int m = 0; m < size; m++) { // get the board
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					temp_board[i][j] = board[i][j];
				}
			}	
			PopIn(temp_board, size, sides[s], m, player); // test by adding a token
			// check if this is winning
			if (CheckGameOver(temp_board, size) == player) {
			*side = sides[s];
			*move = m;
			return;
			}
		}
	}
	// strat 2-> if can block opponents win do that - the first 2 strategies are what Paulbot is using I think so 
	// this bot needs to atleast match it to win
	for (int s = 0; s < 4; s++) {
		for (int m = 0; m < size; m++) { // get the board
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					temp_board[i][j] = board[i][j];
				}
			}
			
			PopIn(temp_board, size, sides[s], m, opponent);  // try opponent move
			
			// check if opponent would win
			if (CheckGameOver(temp_board, size) == opponent) {
				*side = sides[s];
				*move = m;
				return;  // Block by playing here ourselves
			}
		}
	}
}


 /*********************************************************************************/
 /*********************************************************************************/
/** PlayOneGame **/
/** This function plays one game of Connect Four.  The starting player (either 1 
or 2) is provided as input.  This function returns the player who won the game.
/*********************************************************************************/
int PlayOneGame(int startingPlayer, int size, int gameType)
{
	int board[MAX_SIZE][MAX_SIZE];
	int player, gameOver, move;
	char side;

	player = startingPlayer;
	gameOver = 0;

	// Initialise the board, and if a human is playing then display the board.
	InitialiseBoard(board, size, 0);
	if (gameType != 3) {
		PrintBoard(board, size);
	}

	// Play one move at a time, displaying the board if necessary, until the game is over
	while (!gameOver) {
		if (gameType == 1) {
			GetMove(&side, &move, player);
		} else if (gameType == 2) {
			if (player == 1) {
				GetMove(&side, &move, player);
			} else {
				GetMoveBot1(board, size, player, &side, &move);
				printf("Bot has decided to move: %c %d\n", side, move);
			}
		} else {
			if (player == 1) {
				GetMoveBot1(board, size, player, &side, &move);
			} else {
				GetMoveBot2(board, size, player, &side, &move);
			}
		}

		MakeMove(board, size, side, move, player);
		gameOver = CheckGameOver(board, size);

		if (gameType != 3) {
			PrintBoard(board, size);
		}
		if (!gameOver) {
			player = 3 - player;
		}
	}
	return gameOver;
}

 /*********************************************************************************/
 /*********************************************************************************/
/** PlayOneGame **/
/** This function plays Connect Four.  The user can choose the size of the board, who the
players will be (human or bot) and how many games will be played (if the bots are competing).
/*********************************************************************************/
void PlayConnectFour(void)
{
	int size, gameType, numberOfGames, result;
	int i, wins1, wins2, draws, player;

	// Initialise the seed for the random number generator
	srand((unsigned int)time(0));

	// Prompt the user for the board size
	printf("\n\n==================");
	printf("\nEnter board size: ");
	scanf("%d", &size);

	// Get play options:
	printf("Options:\n");
	printf(" [1] = Human vs. Human\n");
	printf(" [2] = Human vs. Bot1\n");
	printf(" [3] = Bot1 vs. Bot2\n");
	printf("Choose game type: ");
	scanf("%d", &gameType);
	numberOfGames = 1;
	result = 0;

	// If two bots are playing a tournament, let the user choose how many games
	if (gameType == 3) {
		printf("Number of games: ");
		scanf("%d", &numberOfGames);
	}

	wins1 = 0;
	wins2 = 0;
	draws = 0;

	// Player 1 will always start the first game
	// If a tournament is being played (between two bots), the starting player alternates
	player = 1;

	for (i = 0; i < numberOfGames; i++) {
		result = PlayOneGame(player, size, gameType);
		if (result == 1) {
			wins1++;
		} else if (result == 2) {
			wins2++;
		} else {
			draws++;
		}
		// Switch the starting player for the next game
		player = 3 - player;
	}

	// If a single game was played, show the result:
	if (gameType != 3) {
		if (result == 3) {			
			printf("\nGame over! The game was a draw!\n\n");
		} else {
			printf("\nGame over! Congratulations! Winner is Player %d\n\n", result);
		}
	} else {
		printf("\nTournament over! Games played = %d\nPlayer 1 wins = %d / Player 2 wins = %d / Draws = %d\n\n", numberOfGames, wins1, wins2, draws);
	}
}



/*********************************************************************************/
int main(void)
{
	printf("ENGGEN131 Project - Semester Two - 2025\n");
	printf("                                 _      __                 \n");
	printf("                                | |    / _|                \n");
	printf("  ___ ___  _ __  _ __   ___  ___| |_  | |_ ___  _   _ _ __ \n");
	printf(" / __/ _ \\| '_ \\| '_ \\ / _ \\/ __| __| |  _/ _ \\| | | | '__|\n");
	printf("| (_| (_) | | | | | | |  __/ (__| |_  | || (_) | |_| | |   \n");
	printf(" \\___\\___/|_| |_|_| |_|\\___|\\___|\\__| |_| \\___/ \\__,_|_|   \n\n");

	PlayConnectFour();

	return 0;
}
