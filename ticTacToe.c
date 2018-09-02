/* a simple game of TicTacToe */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// prototypes
char * playerName(void);
void drawBoard(char *, char *, char *);
int promptMove(char *);

int main(void)
{
	int move;

	char topRow[4] = {'1', '2', '3'};
	char midRow[4] = {'4', '5', '6'};
	char botRow[4] = {'7', '8', '9'};

	char * playerOne;
	char * playerTwo;

	// get names and announce x and o
	playerOne = playerName();
	playerTwo = playerName();
	printf("\n%s gets x and %s gets o - let's go!!!\n", playerOne, playerTwo);
	
	// moves
	drawBoard(topRow, midRow, botRow);
	move = promptMove(playerOne);
	// check for valid move - check for win
	drawBoard(topRow, midRow, botRow);
	move = promptMove(playerTwo);
	// check for valid move - check for win
	drawBoard(topRow, midRow, botRow);

	//sanity check
	printf("move is %d\n", move);
	printf("looks good\n");

	return 0;
}

/***************************************************************************80/

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

void drawBoard(char * topRow, char * midRow, char * botRow) {
	printf("\n   %c %c %c\n", topRow[0], topRow[1], topRow[2]);
	printf("   %c %c %c\n", midRow[0], midRow[1], midRow[2]);
	printf("   %c %c %c\n\n", botRow[0], botRow[1], botRow[2]);
	return;
}

 /*
Sample display
 o o x
 4 x 6
 x 8 9

 */


