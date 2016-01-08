/*
Author: Josh Seifert
Date Created: 11/19/2014
Date Last Modified: 11/21/2014
Filename: gameOfLife.cpp

Overview: This is an implementation of the cellular automata Conway's Game of Life. The zero-player "game" simulates life based on simple
mathematical rules. The board is a 80x22 grid where each cell can be either "alive" or "dead", and every subsequent turn (generation) the flow
of life changes depending on the population density of every cell's neighbors. The program begins by explaining the rules, and allows the user to
choose from a number of options. The user has several preprogrammed oscillators (shapes that repeat after a certain number of cycles) to choose from,
as well as other interesting shapes to choose from. In addition, they have the option to create a random board. The player may choose how many 
generations to run at a time before the board is reprinted.

Input: The user chooses from a number of starting configurations as explained above. Once the starting configuration is determined, they can choose
how many generations to run at once.

Output: Displays the instructions of the game, starting options for the player, and displays the 80x22 grid. Live cells are marked with an 'O' shape,
and dead cells are marked with a '.'.
*/

#include <iostream>
#include <ctime>
#include <string>
#include <climits>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;


char rules();
void display(int world[][22]);
void ran();
void glider();
void diehard();
void pentadecathalon();
void rpentomino();
void queenbee();
void generation(int world[][22]);

int main()
{
	char start = rules(); //Displays the rules of the game, and the starting configuations available to the user

	switch (start)
	{
	case 'X': //Creates a random board
		ran();
		break;
	case 'G': //Creates the "glider" oscillator
		glider();
		break;
	case 'D': //Creates the "diehard" methuselah
		diehard();
		break;
	case 'P': //Creates the "pentadecathalon" oscillator
		pentadecathalon();
		break;
	case 'R': //Creates the r-pentomino methuselah
		rpentomino();
		break;
	case 'Q': //Creates the rare trans-queen bee shuttle oscillator
		queenbee();
		break;
	default:
		break;
	}
	return 0;
}

char rules()
{
	char start;

	cout << "Welcome to the Game of Life!" << endl << endl //Explains rules to player
		<< "This program is a cellular automaton on an 80 x 22 grid." << endl
		<< "Each cell on the grid is either alive 'O' or dead '.'" << endl
		<< "Every successive generation, cells live or die based on the following rules:" << endl << endl
		<< "1. A living cell with fewer than 2 live neighbors dies (underpopulation)" << endl
		<< "2. A living cell with 2 or 3 neighbors lives to the next generation" << endl
		<< "3. A living cell with greater than 3 live neighbors dies (overcrowding)" << endl
		<< "4. A dead cell with three living neighbors is \"born\" (reproduction)" << endl;

	cout << "To initialize the grid, you may choose a random configuration, or you may" << endl //List of starting choices, roughly in order of complexity.
		<< "choose from a list of standard configurations." << endl << endl
		<< "[X] random" << endl
		<< "[G] glider" << endl
		<< "[D] diehard" << endl
		<< "[P] pentadecathalon" << endl
		<< "[R] r-Pentomino" << endl
		<< "[Q] queen bee" << endl << endl

		<< "Which configuration would you like to start with? Enter a letter: ";

	cin >> start;
	start = toupper(start);
	while ((start != 'X')&&(start != 'D')&&(start != 'P')&&(start != 'R')&&(start != 'G')&&(start != 'Q')) //Verifies user input
	{
		cout << "Sorry, that is not a valid choice. Please enter a starting configuration: ";
		cin >> start;
		start = toupper(start);
	}
	return start;
}

void glider()
{
	int world[80][22]; //Creates the array for the world
	for (int i = 0; i < 80; i++) //First fills the array with dead cells
	{
		for (int j = 0; j < 22; j++)
		{
			world[i][j] = 0;
		}
	}
	world[41][10] = 1; //Hard coded which cells should be alive to make the correct shape. Places the shape in the middle of the array.
	world[41][11] = 1;
	world[41][12] = 1;
	world[40][12] = 1;
	world[39][11] = 1;

	generation(world); //Sends array to the main game loop.
}

void diehard() //All of these hard coded configurations follow the same pattern.
{
	int world[80][22]; 
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			world[i][j] = 0;
		}
	}
	world[40][7] = 1;
	world[40][8] = 1;
	world[41][8] = 1;
	world[41][12] = 1;
	world[41][13] = 1;
	world[39][13] = 1;
	world[41][14] = 1;

	generation(world);
}

void rpentomino()
{
	int world[80][22];
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			world[i][j] = 0;
		}
	}
	world[40][10] = 1;
	world[40][11] = 1;
	world[41][11] = 1;
	world[39][11] = 1;
	world[39][12] = 1;

	generation(world);
}

void pentadecathalon()
{
	int world[80][22];
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			world[i][j] = 0;
		}
	}
	world[40][6] = 1;
	world[40][7] = 1;
	world[39][8] = 1;
	world[41][8] = 1;
	world[40][9] = 1;
	world[40][10] = 1;
	world[40][11] = 1;
	world[40][12] = 1;
	world[39][13] = 1;
	world[41][13] = 1;
	world[40][14] = 1;
	world[40][15] = 1;

	generation(world);
}

void queenbee() 
{
	int world[80][22];
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			world[i][j] = 0;
		}
	}
	world[20][10] = 1;//Some of them become quite complex.
	world[21][10] = 1;
	world[20][11] = 1;
	world[21][11] = 1;
	world[40][10] = 1;
	world[41][10] = 1;
	world[40][11] = 1;
	world[41][11] = 1;
	world[25][10] = 1;
	world[26][9] = 1;
	world[26][11] = 1;
	world[27][8] = 1;
	world[27][12] = 1;
	world[28][11] = 1;
	world[28][10] = 1;
	world[28][9] = 1;
	world[29][8] = 1;
	world[29][7] = 1;
	world[29][12] = 1;
	world[29][13] = 1;
	
	generation(world);
}

void ran()
{
	int world[80][22]; //Initializes all the cells to dead
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			world[i][j] = 0;
		}
	}
	srand(time(NULL)); 
	for (int i = 30; i < 50; i++) //Sets ~25% of cells in the middle of the array to be alive.
	{
		for (int j = 5; j < 16; j++)
		{
			if(rand()%4 == 0)
				world[i][j] = 1;
		}
	}

	generation(world);
}

void generation(int world[][22])
{
	int temp[80][22]; 
	int iteration = 1;

	while(iteration > 0) //Can run multiple times in a row depending on user input.
	{
		for (int i = 0; i < 80; i++)
			{
				for (int j = 0; j < 22; j++) //Counts the number of neighbors in every cell on the board
				{							//The mod operator allows the cells to "wrap" around the edges of the board.
						int neighbors = 0; 
						neighbors = 
							world[(i-1+80)%80][(j-1+22)%22] //Up & Left
							+world[(i+80)%80][(j-1+22)%22] //Left
							+world[(i+1+80)%80][(j-1+22)%22] //Down & Left
							+world[(i-1+80)%80][(j+22)%22] //Up
							+world[(i+1+80)%80][(j+22)%22] //Down
							+world[(i-1+80)%80][(j+1+22)%22] //Up & Right
							+world[(i+80)%80][(j+1+22)%22] //Right
							+world[(i+1+80)%80][(j+1+22)%22]; //Down & Right
							
							if (neighbors < 2 || neighbors > 3) //Cell is dead next generation
								temp[i][j] = 0;
							if (neighbors == 2) //Cell retains current state next generation
								temp[i][j] = world[i][j];
							if (neighbors == 3) //Cell is alive next generation
								temp[i][j] = 1;
				}
			}
			for (int i = 0; i < 80; i++)
			{
				for (int j = 0; j < 22; j++)
				{
					world[i][j] = temp[i][j]; //Copies the temp array back to the world array. 
				}
			}
		iteration--; //Runs as many times as the user enters.
		if (iteration == 0)
		{
			display(world); //Displays the current world.
			
			cout << "How many generations do you want to advance? Enter an integer. " << endl
				<<"Enter '0' to return to main menu, or '-1' to quit.";
			cin >> iteration;
			
			while ((!cin)||(iteration < -1)) //To filter out invalid entries from the user.
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Sorry, you did not enter a valid number. Please try again: ";
				cin >> iteration;
			}			
			
			if (iteration == 0) //Clears screen, returns to main menu
			{
				cout << std::string(50, '\n');
				main(); //I haven't seen this done before. I have a feeling it may be poor programming practice, but I wanted to see if it works.
			}
			if (iteration == -1) //Quits game.
			{
				cout << "Thank you!" << endl << endl;
				return;
			}
		}
	}
}

void display(int world[][22]) //Simple function to display world. 
{
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (world[i][j] == 1)
				cout << 'O';
			else
				cout << '.';
		}
		cout << endl;
	}
}