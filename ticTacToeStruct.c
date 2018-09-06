/* a simple game of TicTacToe */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ASCII_0 48

// prototypes
char * playerName(struct players);
int drawBoard(char *, char *);
int promptMove(struct players *, char *);
int checkMove (int, char *, char);
bool win(char *);

struct players {
		bool oneOrTwo;
		char * playerOne;
		char pieceOne;
		char * playerTwo;
		char pieceTwo;
	};

int main(void)
{
	struct players whoseTurn = malloc(sizeof(struct player));

	int move;
	char turn = 'x';
	char board[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	char * playerOne;
	char * playerTwo;

	int winner = 0;

	// get names and xo preferences
	whoseTurn.playerOne = playerName();
	whoseTurn.playerTwo = playerName();
	printf("\n%s gets x and %s gets o - let's go!!!\n", playerOne, playerTwo);
	
	drawBoard(whoseTurn, board);
	do {
		// moves
		winner = drawBoard(playerOne, board);
		move = promptMove(playerOne, board, turn);
		// changes next piece to x or o
		turn = 'o';

	//if (winner == 0) break;

		winner = drawBoard(playerTwo, board);
		move = promptMove(playerTwo, board, turn);
		
		turn = 'x';
	}
	while (winner == 0);

	printf("Way to go, not %s.\n", name);

	return 0;
}

/**************************************************************************80*/

/**************************************************************************80*/


char * playerName(struct player whoseTurn) {
	char * playerName = malloc(sizeof(char) * 25);
	printf("Player name: "); 
	scanf(" %s", playerName);
	whoseTurn.oneOrTwo;
	return;
}

char xOrY {
	printf("Would you like x or y?");
	scanf("%c", players.pieceOne);
}

/************************************/

int drawBoard(char * name, char * board) {
	printf("\n   %c %c %c\n", board[0], board[1], board[2]);
	printf("   %c %c %c\n", board[3], board[4], board[5]);
	printf("   %c %c %c\n\n", board[6], board[7], board[8]);
	
	return 0;
}

/*
 if (win(board) == 1) {
		printf("Way to go, not %s.\n", name); // wrong name here ??????????????
		return 1; 
/*
	}
/************************************/

int promptMove(struct players * whoseTurn, char * board) {

	int move;
	int scanVal;

//    char* playerName = player == 1 ? playerOne : playerTwo // conditional operator
	do {
		printf("%s - choose a square: ", playerName);
		// scanVal consumes remaining characters preventing perpetual loop
		scanVal = scanf(" %d", &move);
		if (scanVal == 0) {
			scanf("%*s");
		}
	}
	while (scanVal == 0 || (move < 1) || (move > 9) || (checkMove(move, board, turn) == 1));

	return move;
}

/************************************/

int checkMove (int move, char * board, char turn) {
	// checks new move - if taken, returns 1. If ok, stores move and returns 0
	if ((move + ASCII_0) == board[move - 1]) {
			board[move - 1] = turn;
			return 0;
	}
	else {
		printf("That square is already taken\n");
		return 1;
	}
}

/************************************/

bool win(char * board) {

	printf("Checking for win\n");
	if (board[0] == board[1] && board[1] == board[2]) {
		printf("%c wins!!!\n", board[0]);
		return true;
	}
	else if (board[3] == board[4] && board[4] == board[5]) {
		printf("%c wins!!!\n", board[3]);
		return true;
	}
	else if (board[6] == board[7] && board[7] == board[8]) {
		printf("%c wins!!!\n", board[6]);
		return true;
	}
	else if (board[0] == board[3] && board[3] == board[6]) {
		printf("%c wins!!!\n", board[0]);
		return true;
	}
	else if (board[1] == board[4] && board[4] == board[7]) {
		printf("%c wins!!!\n", board[1]);
		return true;
	}
	else if (board[2] == board[5] && board[5] == board[8]) {
		printf("%c wins!!!\n", board[2]);
		return true;
	}
	else if (board[0] == board[4] && board[4]== board[8]) {
		printf("%c wins!!!\n", board[0]);
		return true;
	}
	else if (board[2] == board[4] && board[4]== board[6]) {
		printf("%c wins!!!\n", board[2]);
		return true;
	}
	else {
		return false;
	}	
}



