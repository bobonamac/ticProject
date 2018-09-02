/* a simple game of TicTacToe */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ASCII_0 48

// prototypes
char * playerName(void);
void drawBoard(char *);
int promptMove(char *, char *, char);
int checkMove (int, char *, char);
bool win(char *);

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
		// changes next piece to x or o
		turn = 'o';

		drawBoard(board);
		move = promptMove(playerTwo, board, turn);
		// check for valid move - check for win
		turn = 'x';
	}
	while (win(board) == false);

	//sanity check
	printf("looks good :-)\n");

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

int promptMove(char * playerName, char * board, char turn) {

	int move;
	int scanVal;

	do {
		printf("%s - choose a square: ", playerName);
		// scanVal consumes remaining characters preventing perpetual loop
		// why return value of 0???
		scanVal = scanf(" %d", &move);
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

bool win(char * board) {

	printf("Checking for win\n");

	if (board[0] == board[1] == board[2]) {
		printf("%c wins!!!\n", board[0]);
		return true;
	}
	else if (board[3] == board[4] == board[5]) {
		printf("%c wins!!!\n", board[3]);
		return true;
	}
	else if (board[6] == board[7] == board[8]) {
		printf("%c wins!!!\n", board[6]);
		return true;
	}
	else if (board[0] == board[3] == board[6]) {
		printf("%c wins!!!\n", board[0]);
		return true;
	}
	else if (board[1] == board[4] == board[7]) {
		printf("%c wins!!!\n", board[1]);
		return true;
	}
	else if (board[2] == board[5] == board[8]) {
		printf("%c wins!!!\n", board[2]);
		return true;
	}
	else if (board[0] == board[4] == board[8]) {
		printf("%c wins!!!\n", board[0]);
		return true;
	}
	else if (board[2] == board[4] == board[6]) {
		printf("%c wins!!!\n", board[2]);
		return true;
	}
	else return false;
}


 /*

Sample display
 o o x
 4 x 6
 x 8 9

 */


