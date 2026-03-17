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
