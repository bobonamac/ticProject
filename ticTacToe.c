/* a simple game of TicTacToe */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ASCII_0 48

// data type declaration
struct game  {
	int turn;
	int move;
	char * playerOne;
	char * playerTwo;
	char board[9];
}thisGame;

// prototypes
char * playerName(void);
void drawBoard(void);
void promptMove(void);
int checkMove (void);
int win(void);

int main(void)
{
	// assign starting values
 	thisGame.turn = 1;
 	// fill board array with chars 1-9
 	for (int i = 0; i < 9; i++){
 		thisGame.board[i] = (char) i + ASCII_0 + 1;
 	}

	// get names and announce x and o
	thisGame.playerOne = playerName();
	thisGame.playerTwo = playerName();
	printf("\n%s gets x and %s gets o - let's go!!!\n", 
			thisGame.playerOne, thisGame.playerTwo);

	do {
		// moves
		drawBoard();
		thisGame.turn++;
		promptMove();
	}
	while (win() == 0);

	drawBoard();

	printf("Way to go, %s!!!\n\n",
		    thisGame.turn % 2 == 0 ? thisGame.playerOne : thisGame.playerTwo);

	free(thisGame.playerOne);
	free(thisGame.playerTwo);

	return 0;
}

/*****************************************************************************/

char * playerName(void) {
	char * playerName = malloc(sizeof(char) * 25);
	printf("Player name: "); 
	scanf(" %s", playerName);

	return playerName;
}

/************************************/

void drawBoard(void) {
	printf("\n");
	printf("   %c %c %c\n", thisGame.board[0], thisGame.board[1], thisGame.board[2]);
	printf("   %c %c %c\n", thisGame.board[3], thisGame.board[4], thisGame.board[5]);
	printf("   %c %c %c\n", thisGame.board[6], thisGame.board[7], thisGame.board[8]);
	printf("\n");

	return;
}

/************************************/

void promptMove(void) {

	// number of items scanned
	int scanVal;

	do {
		printf("%s - choose a square: ", 
			thisGame.turn % 2 == 0 ? thisGame.playerOne : thisGame.playerTwo);
		scanVal = scanf(" %d", &thisGame.move);
		// consumes remaining characters preventing perpetual loop
		if (scanVal == 0) {
			scanf("%*s");
		}
	}

	while (scanVal == 0 || (thisGame.move < 1) || (thisGame.move > 9) ||
	      (checkMove() == 1));

	return;
}

/************************************/

int checkMove (void) {
	
	// checks new move - if not ok, returns 1. If ok, stores move and returns 0
	if ((thisGame.move + ASCII_0) == thisGame.board[thisGame.move - 1]) {
			thisGame.board[thisGame.move - 1] = (thisGame.turn % 2 == 0 ? 'x' : 'o');
			printf("turn: %d\n", thisGame.turn);
			printf("move: %d\n", thisGame.move);

			return 0;
	}
	else {
		printf("That square is already taken\n");
	}
	return 1;
}

/************************************/

int win(void) {

	printf("\nChecking for win");

	for (int i = 0; i < 3; i++) {
		if (thisGame.board[i * 3] == thisGame.board[i * 3 + 1] &&
		 	thisGame.board[i * 3] == thisGame.board[i * 3 + 2]) {
			printf(" - %c wins!!!\n", thisGame.board[0]);
			return 1;
		}
	}
	for (int j = 0; j < 3; j++) {
		if (thisGame.board[j] == thisGame.board[j + 3] && 
		 	thisGame.board[j + 3] == thisGame.board[j + 6]) {
			printf(" - %c wins!!!\n", thisGame.board[0]);
			return 1;
        }
	}
	// check for diaginal win
	if (thisGame.board[0] == thisGame.board[4] && thisGame.board[4] == thisGame.board[8]) {
		printf(" - %c wins!!!\n", thisGame.board[0]);
		return 1;
	}
	// check for diaginal win
	else if (thisGame.board[2] == thisGame.board[4] && thisGame.board[4] == thisGame.board[6]) {
		printf(" - %c wins!!!\n", thisGame.board[2]);
		return 1;
	}
	else {
		printf(" - no win.\n");
		return 0;
	}	
}
