/* a simple game of TicTacToe */

// addStruct branch

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ASCII_0 48

// prototypes
char * playerName(void);
void drawBoard(char *);
int promptMove(char *, char *, char);
int checkMove (int, char *, char);
int win(char *);

int main(void)
{
	int move;
	// starting piece
	char turn = 'x';

	char board[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	char * playerOne;
	char * playerTwo;

	// get names and announce x and o
	playerOne = playerName();
	playerTwo = playerName();
	printf("\n%s gets x and %s gets o - let's go!!!\n", playerOne, playerTwo);

	do {
		// moves
		drawBoard(board);
		move = promptMove(playerOne, board, turn);
		if (win(board) == 1) break;
		// changes next piece to x or o
		turn = 'o';

		drawBoard(board);
		move = promptMove(playerTwo, board, turn);
		if (win(board) == 1) break;
		// check for valid move - check for win
		turn = 'x';
	}
	while (1 == 1);

	return 0;
}

/*****************************************************************************/
// change to struct 
// prompt for x or y
char * playerName(void) {
	char * playerName = malloc(sizeof(char) * 25);
	printf("Player name: "); 
	scanf(" %s", playerName);
	return playerName;
}

/************************************/

int promptMove(char * playerName, char * board, char turn) {

	// stores the move
	int move;
	// number of items scanned
	int scanVal;

	do {
		printf("%s - choose a square: ", playerName);
		scanVal = scanf(" %d", &move);
		// consumes remaining characters preventing perpetual loop
		if (scanVal == 0) {
			scanf("%*s");
		}
	}
	while (scanVal == 0 || (move < 1) || (move > 9) || (checkMove(move, board, turn) == 1));

	return move;
}

/************************************/

void drawBoard(char * board) {
	printf("\n   %c %c %c\n", board[0], board[1], board[2]);
	printf("   %c %c %c\n", board[3], board[4], board[5]);
	printf("   %c %c %c\n\n", board[6], board[7], board[8]);

	return;
}

/************************************/

int checkMove (int move, char * board, char turn) {
	
	// checks new move - if not ok, returns 1. If ok, stores move and returns 0
	if ((move + ASCII_0) == board[move - 1]) {
			board[move - 1] = turn;
			return 0;
	}
	else {
		printf("That square is already taken\n");
	}
	return 1;
}

/************************************/

int win(char * board) {

	printf("Checking for win");

	if (board[0] == board[1] && board[1] == board[2]) {
		printf(" - %c wins!!!\n", board[0]);
		return 1;
	}
	else if (board[3] == board[4] && board[4] == board[5]) {
		printf(" - %c wins!!!\n", board[3]);
		return 1;
	}
	else if (board[6] == board[7] && board[7] == board[8]) {
		printf(" - %c wins!!!\n", board[6]);
		return 1;
	}
	else if (board[0] == board[3] && board[3] == board[6]) {
		printf(" - %c wins!!!\n", board[0]);
		return 1;
	}
	else if (board[1] == board[4] && board[4] == board[7]) {
		printf(" - %c wins!!!\n", board[1]);
		return 1;
	}
	else if (board[2] == board[5] && board[5] == board[8]) {
		printf(" - %c wins!!!\n", board[2]);
		return 1;
	}
	else if (board[0] == board[4] && board[4] == board[8]) {
		printf(" - %c wins!!!\n", board[0]);
		return 1;
	}
	else if (board[2] == board[4] && board[4] == board[6]) {
		printf(" - %c wins!!!\n", board[2]);
		return 1;
	}
	else {
		printf(" - no win.\n");
		return 0;
	}	
}
