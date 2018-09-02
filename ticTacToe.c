/* a simple game of TicTacToe */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// prototypes
char * playerName(void);
void drawBoard(char *);
int promptMove(char *);

int main(void)
{
	int move;
	char whosNext = 'x';

	char board[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	char * playerOne;
	char * playerTwo;

	// get names and announce x and o
	playerOne = playerName();
	playerTwo = playerName();
	printf("\n%s gets x and %s gets o - let's go!!!\n", playerOne, playerTwo);
	
	// moves
	drawBoard(board);
	move = promptMove(playerOne);
	// check for valid move - check for win
	whosNext = 'y';

	drawBoard(board);
	move = promptMove(playerTwo);
	// check for valid move - check for win
	whosNext = 'x';

	//sanity check
	printf("move is %d\n", move);
	printf("looks good\n");

	return 0;
}

/**************************************************************************80*/

char * playerName(void) {
	char * playerName = malloc(sizeof(char) * 25);
	printf("Player name: "); 
	scanf(" %s", playerName);
	return playerName;
}

/************************************/

int promptMove(char * playerName) {

	int mTemp;
	int scanVal;

	do {
		printf("%s - choose a square: ", playerName);
		scanVal = scanf(" %d", &mTemp);
		if (scanVal == 0) {
			scanf("%*s");
		}
	}
	while (scanVal == 0 || (mTemp < 1) || (mTemp > 9));

	return mTemp;
}

/************************************/

void drawBoard(char * board) {
	printf("\n   %c %c %c\n", board[0], board[1], board[2]);
	printf("   %c %c %c\n", board[3], board[4], board[5]);
	printf("   %c %c %c\n\n", board[6], board[7], board[8]);
	return;
}

 /*
Sample display
 o o x
 4 x 6
 x 8 9

 */


