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