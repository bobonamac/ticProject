/* a simple game of TicTacToe */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// prototypes
char * playerName(void);
int promptMove(char *);

int main(void)
{
	int move;

	int topRow[4];
	int midRow[4];
	int botRow[4];

	char * playerOne;
	char * playerTwo;

	// function calls
	playerOne = playerName();
	playerTwo = playerName();
	printf("%s gets x and %s gets o - let's go!\n", playerOne, playerTwo);

	// display board
	move = promptMove(playerOne);
	// promptMove - check for valid move - check for win
	// display board
	move = promptMove(playerTwo);
	// promptMove - check for valid move - check for win
	// display board

	//sanity check
	printf("move is %d\n", move);
	printf("looks good\n");

	return 0;
}

/************************************/

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
		printf("%s - choose a square 1 thru 9: ", playerName);
		scanVal = scanf(" %d", &mTemp);
		if (scanVal == 0) {
			scanf("%*s");
		}
	}
	while (scanVal == 0 || (mTemp < 1) || (mTemp > 9));

	return mTemp;
}

/************************************/

 /*
Sample display
 o o x
 4 x 6
 x 8 9

 */


