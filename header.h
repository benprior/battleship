#ifndef Battleshipheader_H
#define BattleshipHeader_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define DISPLAY 1
#define PLAY 2
#define EXIT 3
#define CARRIER 5
#define BATTLESHIP 4
#define CRUISER 3
#define SUBMARINE 3
#define DESTROYER 2
#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct stats
{
	int Hits, Misses, total_shots;
	double hits_misses;
} stats;

typedef enum value
{
	False, True
} Value;

typedef struct coordinate
{
	int row;
	int column;
} coordinate;

typedef enum Dir
{
	HORIZ, VERT
} Dir;
/*****************************************
* Function: rules()
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: prints rules of battleship
* Input parameters: void
* Returns:void
* Preconditions: n/a
* Postconditions: n/a
******************************************/
void rules(void);


/*********************************
* Function: print_menu(void)
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: prints the menu
* Input parameters: void
* Returns: void
* Preconditions:n/a
* Postconditions:n/a
**********************************/
void print_menu(void);


/************************************************
* Function: get_choice(void)
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: gets the choice from the user
* Input parameters: void
* Returns: choice
* Preconditions: n/a
* Postconditions: n/a
************************************************/
int get_choice(void);


/*****************************************************************************
* Function: init_board(char board[][MAX_COLS], int num_rows, int num_cols)
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: initalizes the playing board
* Input parameters:  board, num_rows, num_cols
* Returns: void
* Preconditions: n/a
* Postconditions: n/a
*****************************************************************************/
void init_board(char board[][MAX_COLS], int num_rows, int num_cols);


/*****************************************************************************
* Function: print_board
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: prints the playing board
* Input parameters: board, num_rows, num_cols
* Returns: board
* Preconditions: board has been initialized
* Postconditions: board is printed
*****************************************************************************/
void print_board(char board[][MAX_COLS], int num_rows, int num_cols);


/*****************************************************************************
* Function: who_goes
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: decides who goes first
* Input parameters: void
* Returns: 1 or 2
* Preconditions: n/a
* Postconditions: n/a
*****************************************************************************/
int who_goes(void);


/*****************************************************************************
* Function: place_ships_manually
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: places the ships manually if decided to
* Input parameters: board
* Returns: board
* Preconditions: user decided to have ships placed manually
* Postconditions: board has ships placed
*****************************************************************************/
char place_ships_manually(char board[][MAX_COLS]);


/*****************************************************************************
* Function: carrier_placement
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: places the carrier ship
* Input parameters: board
* Returns: void
* Preconditions: board has been initalized and printed and user chose manually to place ships
* Postconditions: carrier is on the board
*****************************************************************************/
void carrier_placement(char board[][MAX_COLS]);


/*****************************************************************************
* Function: battleship_placement
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: places the battleship
* Input parameters: board
* Returns: none
* Preconditions: user has chosen to place ships manually
* Postconditions: battleship is placed
*****************************************************************************/
void battleship_placement(char board[][MAX_COLS]);


/*****************************************************************************
* Function: submarine_placement
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: places the submarine
* Input parameters: board
* Returns: none
* Preconditions: user has chosen to place ships manually
* Postconditions: submarine is on board
*****************************************************************************/
void submarine_placement(char board[][MAX_COLS]);


/*****************************************************************************
* Function: cruiser_placement
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: places the cruiser
* Input parameters: board
* Returns: none
* Preconditions: user chose to place ships manually
* Postconditions: cruiser is on the board
*****************************************************************************/
void cruiser_placement(char board[][MAX_COLS]);


/*****************************************************************************
* Function: destroyer_placement
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: places the destroyer
* Input parameters: board
* Returns: none
* Preconditions: user has chosen to place ships manually
* Postconditions: destroyer ship is on board
*****************************************************************************/
void destroyer_placement(char board[][MAX_COLS]);


/*****************************************************************************
* Function: gen_dir
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: whether direction is horiz or vert
* Input parameters: void
* Returns: direction
* Preconditions: n/a
* Postconditions: n/a
*****************************************************************************/
Dir gen_dir(void);


/*****************************************************************************
* Function: gen_start_pt
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: generates the starting point of the ships
* Input parameters: ship_length, num_rows, num_cols
* Returns: start_pt
* Preconditions: n/a
* Postconditions: starting point has been declared
*****************************************************************************/
coordinate gen_start_pt(int ship_length, Dir dir, int num_rows, int num_cols);


/*****************************************************************************
* Function: is_valid
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: makes sure everything fits together and doesnt overlap
* Input parameters: board, length, num_rows, num_cols, start_pt
* Returns: valid (1 or 0)
* Preconditions: ships have been placed and board printed
* Postconditions: valid or not valid
*****************************************************************************/
int is_valid(char board[][MAX_COLS], Dir dir, int length, int num_rows, int num_cols, coordinate start_pt);


/*****************************************************************************
* Function: place_ship_r
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: places ships automatically
* Input parameters: board, num_rows, num_cols, symbol, length
* Returns: none
* Preconditions: board has been printed
* Postconditions: ships have been placed with validity
*****************************************************************************/
void place_ship_r(char board[][MAX_COLS], int num_rows, int num_cols, char symbol, int length, Dir dir, coordinate start_pt);


/*****************************************************************************
* Function: check_shot
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: makes sure the inputed target shot is availble
* Input parameters: board, x and y coords
* Returns: points
* Preconditions: board has been printed, and ships have been placed
* Postconditions: shot is either a hit or a miss or a re-do
*****************************************************************************/
int check_shot(char board[][MAX_COLS], int x, int y);


/*****************************************************************************
* Function: update_board
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: updates the board of a hit or miss
* Input parameters: board, x, y, guess
* Returns: none
* Preconditions: board has been printed, and ships have been placed
* Postconditions: a * or M on the board
*****************************************************************************/
void update_board(char board[][MAX_COLS], int x, int y, int guess);


/*****************************************************************************
* Function: check_if_sunk
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: checks to see if a hit sunk the ship or just damaged
* Input parameters: board, x, y, inputs for all the ships
* Returns: total
* Preconditions: ships have been placed, a shot has been fired and hit a ship
* Postconditions: a sunk ship or just a hit
*****************************************************************************/
int check_if_sunk(char board[][MAX_COLS], int x, int y, int* carrierSize, int* battleshipSize, int* cruiserSize, int* submarineSize, int* destroyerSize);


/*****************************************************************************
* Function: output_current_move
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: updates the log file of game moves
* Input parameters: outfile, x, y, player, res, sunk
* Returns: none
* Preconditions: game has started
* Postconditions: outfile has data in it
*****************************************************************************/
void output_current_move(FILE* outfile, int x, int y, int player, int res, int sunk);


/*****************************************************************************
* Function: output_stats
* Date Created: 4/8/23
* Date last modified: 4/13/23
* Description: prints the final stats of the player and CPU
* Input parameters: outfile, playerone, and playertwo
* Returns: none
* Preconditions: game has been played
* Postconditions: stats show up in the output file
*****************************************************************************/
void output_stats(FILE* outfile, stats playerone, stats playertwo);



#endif