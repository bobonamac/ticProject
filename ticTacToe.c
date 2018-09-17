/* a simple game of TicTacToe */

// addStruct branch

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ASCII_0 48

// data type declaration - didn't include board because of {} conflict
struct game  {
	int turn;
	char * playerOne;
	char * playerTwo;
}thisGame;

// prototypes
char * playerName(void);
void drawBoard(char * board);
void promptMove(struct game thisGame, char * board);
int checkMove (int move, char * board, char turn);
int win(char * board);

int main(void)
{

	// assign starting values
 	thisGame.turn = 0;
 	char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	// get names and announce x and o
	thisGame.playerOne = playerName();
	thisGame.playerTwo = playerName();

	printf("\n%s gets x and %s gets o - let's go!!!\n", 
			thisGame.playerOne, thisGame.playerTwo);

	do {
		// moves
		drawBoard(board);
		promptMove(thisGame, board);
		thisGame.turn++;
	}
	while (win(board) == 0);

	drawBoard(board);

	printf("Way to go, %s!!!\n\n",
		    thisGame.turn % 2 == 1 ? thisGame.playerOne : thisGame.playerTwo);

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

void drawBoard(char * board) {
	printf("\n");
	printf("   %c %c %c\n", board[0], board[1], board[2]);
	printf("   %c %c %c\n", board[3], board[4], board[5]);
	printf("   %c %c %c\n", board[6], board[7], board[8]);
	printf("\n");

	return;
}

/************************************/

void promptMove(struct game thisGame, char * board) {

	// stores the move
	int move;
	// number of items scanned
	int scanVal;

	do {
		printf("%s - choose a square: ", 
			thisGame.turn % 2 == 0 ? thisGame.playerOne : thisGame.playerTwo);
		scanVal = scanf(" %d", &move);
		// consumes remaining characters preventing perpetual loop
		if (scanVal == 0) {
			scanf("%*s");
		}
	}

	while (scanVal == 0 || (move < 1) || (move > 9) || (checkMove(move, board,
	 thisGame.turn) == 1));

	return;
}

/************************************/

int checkMove (int move, char * board, char turn) {
	
	// checks new move - if not ok, returns 1. If ok, stores move and returns 0
	if ((move + ASCII_0) == board[move - 1]) {
			board[move - 1] = (turn % 2 == 0 ? 'x' : 'o');
			return 0;
	}
	else {
		printf("That square is already taken\n");
	}
	return 1;
}

/************************************/

int win(char * board) {

	printf("\nChecking for win");

	int row, column;

	for (row = 0; row < 3; row++) {
		if (board[row * 3] == board[row * 3 + 1] &&
		 board[row * 3] == board[row * 3 + 2]) {
			printf(" - %c wins!!!\n", board[0]);
			return 1;
        }
	}
	for (column = 0; column < 3; column++) {
		if (board[column * 3] == board[column * 3 + 3] && 
		 board[column * 3 + 3] == board[column * 3 + 6]) {
			printf(" - %c wins!!!\n", board[0]);
			return 1;
        }
	}
	// check for diaginal win
	if (board[0] == board[4] && board[4] == board[8]) {
		printf(" - %c wins!!!\n", board[0]);
		return 1;
	}
	// check for diaginal win
	else if (board[2] == board[4] && board[4] == board[6]) {
		printf(" - %c wins!!!\n", board[2]);
		return 1;
	}
	else {
		printf(" - no win.\n");
		printf("turn: %d\n", thisGame.turn);
		return 0;
	}	
}
