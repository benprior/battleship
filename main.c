#include "header.h"

int main(void)
{
	srand((unsigned int)time(NULL));

	Dir dir = HORIZ;
	coordinate start_pt = { -1, -1 };


	// initalize variables
	char player1[MAX_ROWS][MAX_COLS] = { {'\0'} },
		player2not[MAX_ROWS][MAX_COLS] = { { '\0' } },
		player2[MAX_ROWS][MAX_COLS] = { { '\0' } };

	int choice = 0, option = 0, points = 0, choose_player = 0, val = 0, x = 0, y = 0, guess = 0;
	int	guess2 = 0, x_1 = 0, y_1 = 0, x1 = 10, y1 = 10, rands = 0, rows = 10, P2_point = 0, P1_point = 0, cols = 10;
	int carriers = 5, battleships = 4, cruisers = 3, submarines = 3, destroyers = 2;
	int carriers2 = 5, battleships2 = 4, cruisers2 = 3, submarines2 = 3, destroyers2 = 2;
	stats P1 = { 0,0,0,0.0 };
	stats P2 = { 0,0,0,0.0 };

	FILE* outfile = NULL;

	outfile = fopen("battleship.log", "w"); 


	do
	{


		choice = 0;


		do
		{



			print_menu();
			choice = get_choice();
		} while (choice <  DISPLAY || choice > EXIT); 
		system("cls");

		switch (choice)
		{
		case DISPLAY: rules(); //displays rules
			break;

		case PLAY:
			init_board(player1, MAX_ROWS, MAX_COLS); 
			init_board(player2, MAX_ROWS, MAX_COLS); 
			init_board(player2not, MAX_ROWS, MAX_COLS);  //initalizes boards
			rands = who_goes(); //who goes first?

			if (rands == 1) 
			{
				printf("Player one will go first!\n");
			}
			else
			{
				printf("Player two will go first!\n");
			}

			printf("Do you want to place your ships manually, or automatically?\n"); 
			printf("1. Manually\n");
			printf("2. Automatically\n");
			do
			{
				scanf("%d", &option);
			} while (!(option == 1 || option == 2));

			if (option == 1)
			{
				print_board(player1, MAX_ROWS, MAX_COLS);
				place_ships_manually(player1); 
			}


			else
			{

				carrier_placement(player1);
				battleship_placement(player1);
				cruiser_placement(player1);
				submarine_placement(player1);
				destroyer_placement(player1);
				//placements for all ships

			}
			carrier_placement(player2);
			battleship_placement(player2);
			cruiser_placement(player2);
			submarine_placement(player2);
			destroyer_placement(player2);
			//placements for ships

			system("cls");



			while (P1_point != 17 && P2_point != 17) 
			{


				if (rands == 1) 
				{
					system("cls");

					print_board(player1, MAX_ROWS, MAX_COLS); 

					do
					{
						printf("\n");
						print_board(player2not, MAX_ROWS, MAX_COLS); 

						printf("Select where you want to shoot!!\n");
						do
						{
							scanf("%d %d", &x, &y);

						} while (x > 9 || y > 9);

						system("cls");
						P1_point = check_if_sunk(player2, x, y, &carriers, &battleships, &cruisers, &submarines, &destroyers); 
						guess = check_shot(player2, x, y); 
						if (guess == 1)
						{
							P1.Hits++; 
						}
						else if (guess == 0)
						{
							P1.Misses++; 
						}
					} while (guess == 2);
					output_current_move(outfile, x, y, rands, guess, P1_point); 

					update_board(player2not, x, y, guess);
					print_board(player2not, MAX_ROWS, MAX_COLS); 
					system("pause");

					rands = 0; 
				}

				if (rands == 0)
				{

					system("cls");
					printf("Its the computers turn!\n");
					do
					{
						x_1 = rand() % 10;
						y_1 = rand() % 10;
						printf("%d %d\n", x_1, y_1);
						P2_point = check_if_sunk(player1, x_1, y_1, &carriers2, &battleships2, &cruisers2, &submarines2, &destroyers2); // checks if they have sunk a ship
						guess2 = check_shot(player1, x_1, y_1); 
						if (guess2 == 1)
						{
							P2.Hits++; 
						}
						else if (guess2 == 0)
						{
							P2.Misses++; 
						}

					} while (guess2 == 2);
					output_current_move(outfile, x, y, rands, guess2, P2_point); 
					print_board(player1, MAX_ROWS, MAX_COLS); 
					system("pause");

					rands = 1;
				}
			}

			if (P1_point == 17)
			{
				printf("You beat the computer!\n");
			}
			else
			{
				printf("The computer beat you!\n");
			}

			printf("Thank you for playing! Check the statistics of the game in the log file!\n");
			printf("If you want to play again press 2!\n");
			P1.total_shots = P1.Hits + P1.Misses;
			P2.total_shots = P2.Hits + P2.Misses;
			P1.hits_misses = ((double)P1.Hits / P1.total_shots) * 100;
			P2.hits_misses = ((double)P2.Hits / P2.total_shots) * 100;
			output_stats(outfile, P1, P2);
			fclose(outfile);
			//stats file has been closed
			break;

		case EXIT: printf("Thanks for stopping by!\n");
			break;
		}
	} while (!(choice == EXIT));
	return 0;
}