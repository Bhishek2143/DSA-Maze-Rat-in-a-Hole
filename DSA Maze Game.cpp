#include <iostream> 
#include <time.h> 
#include <stdlib.h>

using namespace std;

struct character
	{
		int posX ; 
		int posY ; 
		char symbol;
		int hp;
	}player; 

struct enemies
	{
		int posX;
		int posY;
		char enemy_symbol;
	};

void player_hit()
	{
		player.posX = 1;
		player.posY =1;
		player.hp --;
	}

int main ()
{
	
	enemies enemy_horizontal = {13, 9, 'H'};
	enemies enemy_vertical = { 11 , 9, 'V'};
	enemies enemy_jump = {1, 15, 'J'};


	const char HEIGHT = 18, WIDTH = 18;  
	bool update = false;  
	char move_key = 'd';

	player.posX = 1;
	player.posY = 1;
	player.symbol = 'O';

	player.hp = 3;  


	unsigned char maze[WIDTH][HEIGHT] = 
	{
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
		'#',' ',' ',' ',' ',' ','#','#','#',' ',' ','#','#',' ','#',' ','#','#',
		'#',' ',' ','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#',' ', 
		'#',' ','#','#',' ',' ',' ',' ','#',' ','#','#',' ','#',' ',' ',' ',' ',
		'#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',
		'#',' ',' ','#',' ','#',' ','#','#',' ','#','#',' ',' ','#',' ',' ','#',
		'#','#','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#','#',' ','#','#',
		'#','#',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#','#',
		'#','#','#',' ','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',
		'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ','#','#',
		'#',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ','#',' ','#','#', 
		'#',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#',
		'#',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#','#','#',' ','#',
		'#',' ','#','#',' ','#',' ','#',' ',' ','#','#',' ',' ',' ',' ',' ','#',
		'#','#','#',' ',' ','#',' ',' ','#',' ',' ','#',' ','#','#',' ','#','#',
		'#','#','#','#',' ','#','#','#',' ',' ','#',' ',' ','#','#',' ','#','#',
		'#','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#','#',' ','#','#',
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	};
	cout << "press (d) (a) (w) or (s) and then return to start the game\n";
	cout << "presse (Q) then return to quit the game\n";

	
	
	while (move_key !='q') 
{
	
srand(time(NULL)); 
int random_move = rand() %2 +1  ; 

cin >> move_key; 
update = true;	

	if (update == true) 
	{
	system("CLS");

	maze[enemy_horizontal.posX][enemy_horizontal.posY] = enemy_horizontal.enemy_symbol;
	maze[enemy_vertical.posX][enemy_vertical.posY] = enemy_vertical.enemy_symbol;
	maze[enemy_jump.posX][enemy_jump.posY] = enemy_jump.enemy_symbol;
	
	maze[player.posX][player.posY] = player.symbol;	
		

	for(int y=0;y<HEIGHT;y++)
	{
		cout << endl;
	for(int x=0;x<WIDTH;x++)
	{
		cout << maze[x][y];
	}
	}
	cout << endl << endl << "    Life: " << player.hp << endl << "____________________\n \n";
	update = false;
	}
	
	switch (move_key)  
	{
		case 'w':
			update = true;
		if (maze[player.posX][player.posY -1] != '#')
		{
			maze[player.posX][player.posY] = ' '; 
			player.posY --;

			if ( maze[player.posX ][player.posY ] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
				maze[player.posX ][player.posY ] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
				maze[player.posX ][player.posY ] == maze[enemy_jump.posX][enemy_jump.posY])
			{
				player_hit();
			}
			
			cout << player.posX << " " << player.posY << endl;
	   }
		else 
			cout << "  YOU HIT A WALL";
		break;
	
		case 's':
			update = true;
		if (maze[player.posX][player.posY +1] != '#')
		{
			maze[player.posX][player.posY] = ' ';
			player.posY ++;

			if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
			{
				player_hit();
			}
			
			cout << player.posX << " " << player.posY << endl;
		}
		else 
			cout << "  YOU HIT A WALL";
		break;

		case 'a':
			update = true;
		if (maze[player.posX -1][player.posY] != '#')
		{
			maze[player.posX][player.posY] = ' '; 
			player.posX --;

			if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
			{
				player_hit();
			}
			
			cout << player.posX << " " << player.posY << endl;
		}
		else 
			cout << "  YOU HIT A WALL";
		
		break;

		case 'd':
			update = true;
			if ( maze[player.posX +1][player.posY] != '#')
		{	
			maze[player.posX][player.posY] = ' '; 
			player.posX ++;

			if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
			{
				player_hit();
			}
			
			cout << player.posX << " " << player.posY << endl;
		}
		else 
			cout << "  YOU HIT A WALL";
		break;
	}

		switch (random_move) 
		{
		case 1:

	
	if 
			(maze[enemy_horizontal.posX +1][enemy_horizontal.posY] != '#')
	{
		maze[enemy_horizontal.posX][enemy_horizontal.posY] = ' ';
		enemy_horizontal.posX ++;
	}
	
	break;


		case 2:	
	if 
		(maze[enemy_horizontal.posX -1][enemy_horizontal.posY] != '#')
	{
		maze[enemy_horizontal.posX][enemy_horizontal.posY] = ' ';
		enemy_horizontal.posX --;
	}

	break;
	}

		if (maze[enemy_vertical.posX][enemy_vertical.posY +1] != '#')
	{
		maze[enemy_vertical.posX][enemy_vertical.posY] = ' ';
		enemy_vertical.posY ++;
	}
	else if 
		(maze[enemy_vertical.posX][enemy_vertical.posY -5] != '#')
	{
		maze[enemy_vertical.posX][enemy_vertical.posY] = ' ';
		enemy_vertical.posY -=6;
	}


	if (maze[enemy_jump.posX +2][enemy_jump.posY] != '#')                                                                           
	{
		maze[enemy_jump.posX][enemy_jump.posY] = ' ';
		enemy_jump.posX += 2;
	}
	else if 
		(maze[enemy_jump.posX -14][enemy_jump.posY] != '#')
	{
		maze[enemy_jump.posX][enemy_jump.posY] = ' ';
		enemy_jump.posX -= 14;
	}

	if (player.hp == 0)
	{                    
		move_key = 'q';
		cout <<" YOU HAVE LOST THE GAME \n";
	}

	if (player.posY == 17)
	{
		cout << "\n CONGRATS!! YOU HAVE WON THE GAME\n"; 
	}

} 
	return 0;
}
