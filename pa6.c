#include "header.h"
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
void rules(void)
{
	printf("*********************************************************\n");
	printf("                 WELCOME TO BATTLESHIP                   \n");
	printf("*********************************************************\n");
	printf("Start off the game by placing ships on the board using \n");
	printf("coordinates. You will then pick coordinates to shoot at.\n");
	printf("Either a 'M' or a '*' will show up on the location where \n");
	printf("you shot, the M means a miss and the asterick a hit.\n");
	printf("Try to hit all the opponents ships before they hit yours. \n");
	printf("Your stat will show up in the file after the game is played \n");
	printf("                    GOOD LUCK!!!!                          \n");
}

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
void print_menu(void)
{
	printf("1. Display rules\n");
	printf("2. Play game \n");
	printf("3. Quit game \n");
}

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
int get_choice(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

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
void init_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

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
void print_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	
	for (; row_index < num_rows; ++row_index)
	{
		printf("%-2d", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%-2c", board[row_index][col_index]);
		}
		putchar('\n');
	}
	return board;
}

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
int who_goes(void)
{
	return rand() % 2;
}

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
char place_ships_manually(char board[][MAX_COLS]) 
{


	int x = 0, temp = 0, x_1 = 0, y = 0, x_2 = 0, y_2 = 0, choice = 0, y_1 = 0;

	printf("Remember: Place your ships in correct available spaces for your ship\n");
	printf("Do not place your ship off the grid, I will make you re-do your placement\n");
	printf("You got this!\n");
	system("pause");


	printf("Do you want to place the carrier horizontally, or vertically?\n");
	printf("1 for vertical, 2 for horizontal\n");
	do
	{
		scanf("%d", &choice);
	} while (choice < 1 || choice > 2);
	printf("Select 5 cells where you want your carrier to be!\n");

	switch (choice)
	{
	case 1:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x < 6)
			{
				board[x][y];
				board[x][y] = 'C';
				temp = 1;
			}
			else
			{
				printf("The carrier cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);
		x_1 = x;
		y_1 = y;
		for (int i = 0; i < 4; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 + 1 && y == y_1)
			{

				x_1++;
				board[x][y];
				board[x][y] = 'C';
			}
			else
			{
				i--;
				printf("RE-DO!!!!\n");
			}


		}
		break;
	case 2:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && y < 6)
			{
				board[x][y];
				board[x][y] = 'C';
				temp = 1;
			}
			else
			{
				printf("The carrier cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);

		x_1 = x;
		y_1 = y;
		for (int i = 0; i < 4; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 && y == y_1 + 1)
			{

				y_1++;
				board[x][y];
				board[x][y] = 'C';
			}
			else
			{
				i--;
				printf("RE-DO!!!!\n");
			}


		}
		break;
	}
	system("cls");
	print_board(board, MAX_ROWS, MAX_COLS);




	x = 0,
		temp = 0,
		x_1 = 0,
		y = 0,
		choice = 0,
		y_1 = 0;
	printf("Do you want to place the Battleship horizontally, or vertically?\n");
	printf("1 for vertical, 2 for horizontal\n");
	do
	{
		scanf("%d", &choice);
	} while (choice < 1 || choice > 2);
	printf("Select 4 cells where you want your battleship to be!\n");




	switch (choice)
	{
	case 1:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x < 7 && board[x + 1][y] == '~' && board[x + 2][y] == '~' && board[x + 3][y] == '~')

			{
				board[x][y];
				board[x][y] = 'B';
				temp = 1;
			}
			else
			{
				printf("The Battleship cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				printf("Or a pre existing ship is there\n");
				temp = 2;
			}
		} while (temp == 2);
		x_1 = x;
		y_1 = y;
		temp = 0;
		for (int i = 0; i < 3; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 + 1 && y == y_1)
			{

				x_1++;
				board[x][y];
				board[x][y] = 'B';
			}
			else
			{
				i--;
				temp++;
				printf("RE-DO!!!!\n");
			}


		}

		break;
	case 2:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && y < 7 && board[x][y + 1] == '~' && board[x][y + 2] == '~' && board[x][y + 3] == '~')
			{
				board[x][y];
				board[x][y] = 'B';
				temp = 1;
			}
			else
			{
				printf("The Battleship cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);

		x_1 = x;
		y_1 = y;
		temp = 0;
		for (int i = 0; i < 3; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 && y == y_1 + 1)
			{

				y_1++;
				board[x][y];
				board[x][y] = 'B';
			}
			else
			{
				i--;
				temp++;
				printf("RE-DO!!!!\n");

			}

		}
		break;
	}





	system("cls");
	print_board(board, MAX_ROWS, MAX_COLS);
	x = 0,
		temp = 0,
		x_1 = 0,
		y = 0,
		choice = 0,
		y_1 = 0;
	printf("Do you want to place the Cruiser horizontally, or vertically?\n");
	printf("1 for vertical, 2 for horizontal\n");
	do
	{
		scanf("%d", &choice);
	} while (choice < 1 || choice > 2);
	printf("Select 3 cells where you want your Cruiser to be!\n");

	switch (choice)
	{
	case 1:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x < 8 && board[x + 1][y] == '~' && board[x + 2][y] == '~')
			{
				board[x][y];
				board[x][y] = 'R';
				temp = 1;
			}
			else
			{
				printf("The cruiser cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);
		x_1 = x;
		y_1 = y;
		temp = 0;
		for (int i = 0; i < 2; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 + 1 && y == y_1)
			{

				x_1++;
				board[x][y];
				board[x][y] = 'R';
			}
			else
			{
				i--;
				temp++;
				printf("RE-DO!!!!\n");
			}


		}
		break;
	case 2:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && y < 8 && board[x][y + 1] == '~' && board[x][y + 2] == '~')
			{
				board[x][y];
				board[x][y] = 'R';
				temp = 1;
			}
			else
			{
				printf("The cruiser cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);

		x_1 = x;
		y_1 = y;
		temp = 0;
		for (int i = 0; i < 2; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 && y == y_1 + 1)
			{

				y_1++;
				board[x][y];
				board[x][y] = 'R';
			}
			else
			{
				i--;
				temp++;
				printf("RE-DO!!!!\n");
			}



		}
		break;
	}

	system("cls");
	print_board(board, MAX_ROWS, MAX_COLS);

	x = 0,
		temp = 0,
		x_1 = 0,
		y = 0,
		choice = 0,
		y_1 = 0;

	printf("Do you want to place the Submarine horizontally, or vertically?\n");
	printf("1 for vertical, 2 for horizontal\n");
	do
	{
		scanf("%d", &choice);
	} while (choice < 1 || choice > 2);
	printf("Select 3 cells where you want your Submarine to be!\n");

	switch (choice)
	{
	case 1:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x < 8 && board[x + 1][y] == '~' && board[x + 2][y] == '~')
			{
				board[x][y];
				board[x][y] = 'S';
				temp = 1;
			}
			else
			{
				printf("The Sub cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);
		x_1 = x;
		y_1 = y;
		temp = 0;
		for (int i = 0; i < 2; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 + 1 && y == y_1)
			{

				x_1++;
				board[x][y];
				board[x][y] = 'S';
			}
			else
			{
				i--;
				temp++;
				printf("RE-DO!!!!\n");
			}



		}
		break;
	case 2:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && y < 8 && board[x][y + 1] == '~' && board[x][y + 2] == '~')
			{
				board[x][y];
				board[x][y] = 'S';
				temp = 1;
			}
			else
			{
				printf("The Sub cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);

		x_1 = x;
		y_1 = y;
		temp = 0;
		for (int i = 0; i < 2; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 && y == y_1 + 1)
			{

				y_1++;
				board[x][y];
				board[x][y] = 'S';
			}
			else
			{
				i--;
				temp++;
				printf("RE-DO!!!!\n");
			}


		}
		break;
	}
	system("cls");
	print_board(board, MAX_ROWS, MAX_COLS);

	x = 0,
		temp = 0,
		x_1 = 0,
		y = 0,
		choice = 0,
		y_1 = 0;

	printf("Do you want to place the Destroyer horizontally, or vertically?\n");
	printf("1 for vertical, 2 for horizontal\n");
	do
	{
		scanf("%d", &choice);
	} while (choice < 1 || choice > 2);

	printf("Select 2 cells where you want your Destroyer to be!\n");

	switch (choice)
	{
	case 1:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x < 9 && board[x + 1][y] == '~')
			{
				board[x][y];
				board[x][y] = 'D';
				temp = 1;
			}
			else
			{
				printf("The destroyer cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);
		x_1 = x;
		y_1 = y;
		temp = 0;
		for (int i = 0; i < 1; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 + 1 && y == y_1)
			{

				x_1++;
				board[x][y];
				board[x][y] = 'D';
			}
			else
			{
				i--;
				temp++;
				printf("RE-DO!!!!\n");
			}

		}
		break;
	case 2:
		do
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);



			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && y < 9 && board[x][y + 1] == '~')
			{
				board[x][y];
				board[x][y] = 'D';
				temp = 1;
			}
			else
			{
				printf("The destroyer cannot start there RE-DO\n");
				printf("Or Invalid starting point\n");
				temp = 2;
			}
		} while (temp == 2);

		x_1 = x;
		y_1 = y;
		temp = 0;
		for (int i = 0; i < 1; i++)
		{
			printf("Type in the cells\n");
			scanf("%d %d", &x, &y);
			if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[x][y] == '~' && x == x_1 && y == y_1 + 1)
			{

				y_1++;
				board[x][y];
				board[x][y] = 'D';
			}
			else
			{
				i--;
				temp++;
				printf("RE-DO!!!!\n");
			}


		}
		break;
	}

	print_board(board, MAX_ROWS, MAX_COLS);


}

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
void carrier_placement(char board[][MAX_COLS])
{
	Dir dir = HORIZ;
	coordinate start_point = { -1,-1 };

	dir = gen_dir();
	start_point = gen_start_pt(CARRIER, dir, MAX_ROWS, MAX_COLS);
	place_ship_r(board, MAX_ROWS, MAX_COLS, 'C', CARRIER, dir, start_point);

}

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
void battleship_placement(char board[][MAX_COLS])
{
	Dir dir = HORIZ;
	coordinate start_pt = { -1,-1 };
	int val = -1;

	dir = gen_dir();
	do
	{
		start_pt = gen_start_pt(BATTLESHIP, dir, MAX_ROWS, MAX_COLS);
		if (is_valid(board, dir, 4, MAX_ROWS, MAX_COLS, start_pt) == 1)
		{
			place_ship_r(board, MAX_ROWS, MAX_COLS, 'B', BATTLESHIP, dir, start_pt);
			val = 1;
		}
		else
		{
			val = 0;
		}
	} while (val == 0);
}

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
void submarine_placement(char board[][MAX_COLS]) 
{
	Dir dir = HORIZ;
	coordinate start_pt = { -1, -1 };
	int val = -1;
	dir = gen_dir();

	do
	{


		start_pt = gen_start_pt(SUBMARINE, dir, MAX_ROWS, MAX_COLS);
		if (is_valid(board, dir, 3, MAX_ROWS, MAX_COLS, start_pt) == 1)
		{
			place_ship_r(board, MAX_ROWS, MAX_COLS, 'S', SUBMARINE, dir, start_pt);
			val = 1;

		}
		else
		{
			val = 0;
		}

	} while (val == 0);
}

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
void cruiser_placement(char board[][MAX_COLS]) 
{

	Dir dir = HORIZ;
	coordinate start_pt = { -1, -1 };
	int val = -1;


	dir = gen_dir();
	do
	{



		start_pt = gen_start_pt(CRUISER, dir, MAX_ROWS, MAX_COLS);
		if (is_valid(board, dir, 3, MAX_ROWS, MAX_COLS, start_pt) == 1)
		{
			place_ship_r(board, MAX_ROWS, MAX_COLS, 'R', CRUISER, dir, start_pt);
			val = 1;
		}
		else
		{
			val = 0;
		}

	} while (val == 0);
}

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
void destroyer_placement(char board[][MAX_COLS]) 
{
	Dir dir = HORIZ;
	coordinate start_pt = { -1, -1 };
	int val = -1;

	dir = gen_dir();
	do
	{


		start_pt = gen_start_pt(DESTROYER, dir, MAX_ROWS, MAX_COLS);

		if (is_valid(board, dir, 2, MAX_ROWS, MAX_COLS, start_pt) == 1)
		{
			place_ship_r(board, MAX_ROWS, MAX_COLS, 'D', DESTROYER, dir, start_pt);
			val = 1;
		}
		else
		{
			val = 0;
		}


	} while (val == 0);
}

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
Dir gen_dir(void)  
{
	return (Dir)(rand() % 2);
}

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
coordinate gen_start_pt(int ship_length, Dir dir, int num_rows, int num_cols)
{
	coordinate start_pt = { -1, -1 };

	if (dir == HORIZ)
	{


		start_pt.row = rand() % num_rows; 
		start_pt.column = rand() % (num_cols - ship_length + 1); 


	}
	else
	{



		start_pt.row = rand() % (num_rows - ship_length + 1); 
		start_pt.column = rand() % num_cols;  


	}


	return start_pt;
}

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
int is_valid(char board[][MAX_COLS], Dir dir, int length, int num_rows, int num_cols, coordinate start_pt)
{
	int count = 0;
	int valid = 0;

	if (dir == VERT)
	{
		valid = 1;

		for (count = 0; count < length; ++count)
		{
			if ((board[start_pt.row + count][start_pt.column]) != '~')
			{
				valid = 0;
			}
		}
	}

	else if (dir == HORIZ)
	{
		valid = 1;

		for (count = 0; count < length; ++count)
		{
			if (board[start_pt.row][start_pt.column + count] != '~')
			{
				valid = 0;
			}
		}
	}


	return valid;
}

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
void place_ship_r(char board[][MAX_COLS], int num_rows, int num_cols, char symbol, int length,
	Dir dir, coordinate start_pt) 
{
	int valid = -1;
	int count = 0,
		x = 0,
		y = 0;




	if (dir == VERT)
	{
		for (count = 0; count < length; ++count)
		{
			board[start_pt.row + count][start_pt.column] = symbol;
		}
	}

	else
	{
		for (count = 0; count < length; ++count)
		{
			board[start_pt.row][start_pt.column + count] = symbol;
		}
	}
}

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
int check_shot(char board[][MAX_COLS], int x, int y)
{
	int points = 0;

	if (board[x][y] == 'M' || board[x][y] == '*')
	{
		printf("RE-DO\n");
		points = 2;
	}

	else if (board[x][y] == '~')
	{
		board[x][y];
		board[x][y] = 'M';
		printf("That was a miss.\n");
		points = 0;
	}
	else
	{

		board[x][y] = '*';
		printf("Thats a hit!\n");
		points = 1;

	}
	return points;
}

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
void update_board(char board[][MAX_COLS], int x, int y, int guess)
{
	if (guess == 1)
	{
		board[x][y] = '*';

	}
	else if (guess == 0)
	{
		board[x][y] = '0';
	}
}

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
int check_if_sunk(char board[][MAX_COLS], int x, int y, int* carrierSize, int* battleshipSize, int* cruiserSize, int* submarineSize, int* destroyerSize)
{
	int total = 0;

	if (board[x][y] == 'C')
	{
		*carrierSize -= 1;

		if (*carrierSize == 0)
		{
			printf("The carrier was sunk!\n");
			total = 1;

		}
	}
	if (board[x][y] == 'B')
	{
		*battleshipSize -= 1;

		if (*battleshipSize == 0)
		{
			printf("The battleship was sunk!\n");
			total = 2;
		}
	}

	if (board[x][y] == 'R')
	{
		*cruiserSize -= 1;

		if (*cruiserSize == 0)
		{
			printf("The cruiser was sunk!\n");
			total = 3;
		}
	}

	if (board[x][y] == 'S')
	{
		*submarineSize -= 1;

		if (*submarineSize == 0)
		{
			printf("The submarine was sunk!\n");
			total = 4;

		}
	}

	if (board[x][y] == 'D')
	{
		*destroyerSize -= 1;

		if (*destroyerSize == 0)
		{
			printf("The destroyer was sunk!\n");
			total = 5;

		}
	}

	if (*battleshipSize == 0 && *carrierSize == 0 && *cruiserSize == 0 && *submarineSize == 0 && *destroyerSize == 0)
	{
		total = 17;
	}

	return total;
}

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
void output_current_move(FILE* outfile, int x, int y, int player, int res, int sunk)
{
	if (player == 1)
	{
		if (res == 1)
		{
			fprintf(outfile, "Player 1 shot at %d, %d and they hit!!\n", x, y);
			fprintf(outfile, "\n");
		}
		else if (res == 0)
		{
			fprintf(outfile, "Player 1 shot at %d, %d and they missed :/\n", x, y);
			fprintf(outfile, "\n");
		}

		if (sunk == 1)
		{
			fprintf(outfile, "Player 1 sunk the enemies Carrier!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 2)
		{
			fprintf(outfile, "Player 1 sunk the enemies Battleship!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 3)
		{
			fprintf(outfile, "Player 1 sunk the enemies Cruiser!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 4)
		{
			fprintf(outfile, "Player 1 sunk the enemies Submarine!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 4)
		{
			fprintf(outfile, "Player 1 sunk the enemies destroyer!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 17)
		{
			fprintf(outfile, "Player 1 won the game by sinking all of the enemies ships!\n");
			fprintf(outfile, "\n");
		}


	}

	if (player == 0)
	{
		if (res == 1)
		{
			fprintf(outfile, "The computer shot at %d, %d and they hit ;(\n", x, y);
			fprintf(outfile, "\n");
		}
		else if (res == 0)
		{
			fprintf(outfile, "The computer shot at %d, %d and they missed!!\n", x, y);
			fprintf(outfile, "\n");
		}

		else if (res == 0)
		{
			fprintf(outfile, "Player 1 shot at %d, %d and they missed :/\n", x, y);
			fprintf(outfile, "\n");
		}

		if (sunk == 1)
		{
			fprintf(outfile, "The computer sunk the Carrier!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 2)
		{
			fprintf(outfile, "The computer sunk the Battleship!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 3)
		{
			fprintf(outfile, "The computer sunk theCruiser!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 4)
		{
			fprintf(outfile, "The computer sunk the Submarine!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 4)
		{
			fprintf(outfile, "The computer sunk the destroyer!\n");
			fprintf(outfile, "\n");
		}
		else if (sunk == 17)
		{
			fprintf(outfile, "The computer won the game by sinking all of the enemies ships!\n");
			fprintf(outfile, "\n");
		}
	}

}

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
void output_stats(FILE* outfile, stats playerone, stats playertwo)
{
	fprintf(outfile, "PLAYER ONE STATS\n");
	fprintf(outfile, "\n");
	fprintf(outfile, "***************\n");
	fprintf(outfile, "\n");
	fprintf(outfile, "Number of total hits: %d\n", playerone.Hits);
	fprintf(outfile, "\n");
	fprintf(outfile, "Number of total misses: %d\n", playerone.Misses);
	fprintf(outfile, "\n");
	fprintf(outfile, "The number of total shots taken: %d\n", playerone.total_shots);
	fprintf(outfile, "\n");
	fprintf(outfile, "The average hit rate: %.2lf%%\n", playerone.hits_misses);
	fprintf(outfile, "\n");
	fprintf(outfile, "***************\n");
	fprintf(outfile, "\n");
	fprintf(outfile, "COMPUTER STATS\n");
	fprintf(outfile, "\n");
	fprintf(outfile, "***************\n");
	fprintf(outfile, "\n");
	fprintf(outfile, "Number of total hits: %d\n", playertwo.Hits);
	fprintf(outfile, "\n");
	fprintf(outfile, "Number of total misses: %d\n", playertwo.Misses);
	fprintf(outfile, "\n");
	fprintf(outfile, "The number of total shots taken: %d\n", playertwo.total_shots);
	fprintf(outfile, "\n");
	fprintf(outfile, "The average hit rate: %.2lf%%\n", playertwo.hits_misses);



}