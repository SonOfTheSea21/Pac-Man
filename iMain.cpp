# include "iGraphics.h"
# include <math.h>
# include "maze.h"
# include "gamefunc.h"
# include "videos.h"
# include <stdio.h>
# include <time.h>
# include <stdlib.h>



int currPage = -1;
int stcolor[8];
int a, b;
int start = 2;
bool movesound = false;

bool diesound = false;
int die = 0;
int dii = 0;

bool fghostsound = false;

bool music = true;
int i = 0, sth = 0;
int introframe = 0;
int len, slen;
int cux = 430, count_i = 0, cons_i = 0;
int pellet = 0;
int namedone = 0;
int fcount;
int lvupanim = 0;
int ghost_isF = 0;
int savedshow = 0;
int backi = 0;



void iDraw()
{
	iClear();
	if (currPage == -1)
		playIntro();
	else if (currPage == 0)
		drawHome();
	else if (currPage == 1)
		drawMaze();
	else if (currPage == 2)
		drawLearn();
	else if (currPage == 3)
		drawLead();
	else if (currPage == 4)
		drawPoints();
	else if (currPage == 5)
		drawPause();
	else if (currPage == 6)
		gameover();
	else if (currPage == 7)
		drawName();
	else if (currPage == 8)
		drawLead2();
	else if (currPage == 9)
		drawCreds();
	else if (currPage == 10)
		drawMode();
	else if (currPage == 11)
		drawWin();
	else if (currPage == 12)
		drawLead3();
}


void iMouseMove(int mx, int my)
{

}

void iMouseHover(int mx, int my)
{
	int i, tmp = -1;
	if (currPage == 0)
	{
		if (mx >= 100 && mx <= 380 && my >= 400 && my <= 480)
		{
			stcolor[0] = 1;

			tmp = 0;
		}
		else if (mx >= 470 && mx <= 750 && my >= 400 && my <= 480)
		{
			stcolor[1] = 1;

			tmp = 1;
		}
		else if (mx >= 100 && mx <= 380 && my >= 280 && my <= 360)
		{
			stcolor[2] = 1;

			tmp = 2;
		}
		else if (mx >= 470 && mx <= 750 && my >= 280 && my <= 360)
		{
			stcolor[3] = 1;

			tmp = 3;
		}
		else if (mx >= 100 && mx <= 380 && my >= 160 && my <= 240)
		{
			stcolor[4] = 1;

			tmp = 4;
		}
		else if (mx >= 470 && mx <= 750 && my >= 160 && my <= 240)
		{
			stcolor[5] = 1;

			tmp = 5;
		}
		else if (mx >= 180 && mx <= 660 && my >= 40 && my <= 120)
		{
			stcolor[6] = 1;

			tmp = 6;
		}
		else if (mx >= 750 && mx <= 800 && my >= 900 && my <= 950)
		{
			stcolor[7] = 1;

			tmp = 7;
		}

		for (i = 0; i < 8; i++)
		{
			if (i != tmp) stcolor[i] = 0;
		}
	}
	else if (currPage == 2)
	{
		if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
		{
			stcolor[0] = 1;

			tmp = 0;
		}
		else if (mx >= 520 && mx <= 800 && my >= 25 && my <= 75)
		{
			stcolor[1] = 1;

			tmp = 1;
		}

		for (i = 0; i < 2; i++)
		{
			if (i != tmp) stcolor[i] = 0;
		}
	}

	else if (currPage == 4)
	{
		if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
		{
			stcolor[0] = 1;

			tmp = 0;
		}

		for (i = 0; i < 1; i++)
		{
			if (i != tmp) stcolor[i] = 0;
		}
	}

	else if (currPage == 3 || currPage == 8 || currPage == 12)
	{
		if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
		{
			stcolor[0] = 1;

			tmp = 0;
		}

		for (i = 0; i < 1; i++)
		{
			if (i != tmp) stcolor[i] = 0;
		}
	}
	else if (currPage == 5)
	{
		if (mx >= 180 && mx <= 660 && my >= 615 && my <= 695)
		{
			stcolor[0] = 1;

			tmp = 0;
		}
		else if (mx >= 180 && mx <= 660 && my >= 505 && my <= 585)
		{
			stcolor[1] = 1;

			tmp = 1;
		}
		else if (mx >= 180 && mx <= 660 && my >= 395 && my <= 475)
		{
			stcolor[2] = 1;

			tmp = 2;
		}
		else if (mx >= 180 && mx <= 660 && my >= 285 && my <= 365)
		{
			stcolor[3] = 1;

			tmp = 3;
		}
		else if (mx >= 180 && mx <= 660 && my >= 175 && my <= 255)
		{
			stcolor[4] = 1;

			tmp = 4;
		}
		else if (mx >= 180 && mx <= 660 && my >= 65 && my <= 145)
		{
			stcolor[5] = 1;

			tmp = 5;
		}

		for (i = 0; i < 6; i++)
		{
			if (i != tmp) stcolor[i] = 0;
		}
	}
	else if (currPage == 9)
	{
		if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
		{
			stcolor[0] = 1;

			tmp = 0;
		}

		for (i = 0; i < 1; i++)
		{
			if (i != tmp) stcolor[i] = 0;
		}
	}
	else if (currPage == 10)
	{
		if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
		{
			stcolor[0] = 1;

			tmp = 0;
		}
		else if (mx >= 80 && mx <= 520 && my >= 480 && my <= 600)
		{
			stcolor[1] = 1;

			tmp = 1;
		}
		else if (mx >= 320 && mx <= 760 && my >= 280 && my <= 400)
		{
			stcolor[2] = 1;

			tmp = 2;
		}
		else if (mx >= 80 && mx <= 520 && my >= 80 && my <= 200)
		{
			stcolor[3] = 1;

			tmp = 3;
		}

		for (i = 0; i < 4; i++)
		{
			if (i != tmp) stcolor[i] = 0;
		}
	}
}


void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (currPage == 0)
		{
			if (mx >= 100 && mx <= 380 && my >= 400 && my <= 480)
			{
				game.isPlaying = 1;
				game.existsave = false;
				startGame();
				restartLevel();
				currPage = 1;
				playMusic();
				writeSavefile();
				game.isPlaying = 0;
			}
			else if (mx >= 470 && mx <= 750 && my >= 400 && my <= 480)
			{
				if (game.existsave == true)
				{
					game.isPlaying = 1;
					currPage = 1;
					playMusic();
					game.existsave = false;
					writeSavefile();
					game.isPlaying = 0;
				}
				else
				{
					;
				}
			}
			else if (mx >= 100 && mx <= 380 && my >= 160 && my <= 240)
			{
				currPage = 2;
				playMusic();
			}
			else if (mx >= 470 && mx <= 750 && my >= 280 && my <= 360)
			{
				currPage = 3;
				playMusic();
			}
			else if (mx >= 470 && mx <= 750 && my >= 160 && my <= 240)
			{
				currPage = 9;
				playMusic();
			}
			else if (mx >= 100 && mx <= 380 && my >= 280 && my <= 360)
			{
				currPage = 10;
				playMusic();
			}
			else if (mx >= 750 && mx <= 800 && my >= 900 && my <= 950)
			{
				if (music)
				{
					music = false;
				}
				else
				{
					music = true;
				}
				playMusic();
			}
			else if (mx >= 180 && mx <= 660 && my >= 50 && my <= 130)
			{
				game.mode = 1;
				exit(0);
			}
		}
		else if (currPage == 2)
		{
			if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
			{
				currPage = 0;
				playMusic();
			}
			else if (mx >= 520 && mx <= 800 && my >= 25 && my <= 75)
			{
				currPage = 4;
				playMusic();
			}
		}
		else if (currPage == 4)
		{
			if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
			{
				currPage = 2;
				playMusic();
			}
		}
		else if (currPage == 3 || currPage == 8)
		{
			if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
			{
				currPage = 0;
				playMusic();
			}
		}
		else if (currPage == 12)
		{
			if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
			{
				currPage = 5;
				playMusic();
			}
		}
		else if (currPage == 5)
		{
			if (mx >= 180 && mx <= 660 && my >= 615 && my <= 695)
			{
				game.isPlaying = 0;
				savedshow = 0;
				currPage = 1;
				playMusic();
			}
			else if (mx >= 180 && mx <= 660 && my >= 505 && my <= 585)
			{
				game.existsave = true;
				writeSavefile();
				savedshow = 1;
			}
			else if (mx >= 180 && mx <= 660 && my >= 395 && my <= 475)
			{
				if (music)
				{
					music = false;
				}
				else
				{
					music = true;
				}
				playMusic();
			}
			else if (mx >= 180 && mx <= 660 && my >= 285 && my <= 365)
			{
				currPage = 12;
				playMusic();
			}
			else if (mx >= 180 && mx <= 660 && my >= 175 && my <= 255)
			{
				currPage = 0;
				start = 2;
				playMusic();
			}
			else if (mx >= 180 && mx <= 660 && my >= 65 && my <= 145)
			{
				game.mode = 1;
				exit(0);
			}
		}
		else if (currPage == 9)
		{
			if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
			{
				currPage = 0;
				playMusic();
			}
		}
		else if (currPage == 10)
		{
			if (mx >= 30 && mx <= 80 && my >= 935 && my <= 985)
			{
				currPage = 0;
				playMusic();
			}
			else if (mx >= 80 && mx <= 520 && my >= 480 && my <= 600)
			{
				game.mode = 1;
			}
			else if (mx >= 320 && mx <= 760 && my >= 280 && my <= 400)
			{
				game.mode = 2;
			}
			else if (mx >= 80 && mx <= 520 && my >= 80 && my <= 200)
			{
				game.mode = 3;
			}
		}


	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}


void iKeyboard(unsigned char key)
{
	if (key == 27)
	{
		game.mode = 1;
		exit(0);
	}
	if (currPage == -1)
	{
		if (key <= 222 && key >= 8)
		{
			currPage = 0;
			playMusic();
		}
	}
	if (currPage == 1)
	{
		if (key == 'p')
		{
			currPage = 5;
			playMusic();
		}
	}
	else if (currPage == 5)
	{
		if (key == 'r')
		{
			game.isPaused = 0;
			currPage = 1;
			playMusic();
		}
	}
	else if (currPage == 6 || currPage == 11)
	{
		if (key == '\r')
		{
			currPage = 7;
			playMusic();
		}
	}
	else if (currPage == 7)
	{
		writeName(key);

		if (key == '\r')
		{
			namedone = 1;
			writeScoreFile();
			if (game.isOver == 1)
			{
				game.isOver = 0;
			}
			if (game.isWon == 1)
			{
				game.isWon = 0;
			}
			currPage = 8;
			playMusic();
		}

	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		game.mode = 1;
		exit(0);
	}
	if (currPage == 1)
	{


		if (key == GLUT_KEY_LEFT)
		{
			start = 0;
			if (movesound == false)
			{
				playMusic();
				movesound = true;
			}

			if ((pac.y % 40 == 0 && (maze[24 - (pac.y / 40)][pac.x / 40] != 1)) || ((pac.y - 10) % 40 == 0 && (maze[24 - ((pac.y - 10) / 40)][pac.x / 40] != 1) && pac.stop == 3) || ((pac.y + 10) % 40 == 0 && (maze[24 - ((pac.y + 10) / 40)][pac.x / 40] != 1) && pac.stop == 2))
			{
				if (((pac.y - 10) % 40 == 0 && (maze[24 - ((pac.y + 10) / 40)][pac.x / 40] != 1) && pac.stop == 3))
				{
					pac.y = pac.y - 10;
				}
				else if (((pac.y + 10) % 40 == 0 && (maze[24 - ((pac.y + 10) / 40)][pac.x / 40] != 1) && pac.stop == 2))
				{
					pac.y = pac.y + 10;
				}
				
				if (pac.x % 40 == 0 && (maze[24 - (pac.y / 40)][(pac.x / 40) - 1] != 1))
				{
					pac.stop = 1;

				}
				else if (pac.x % 40 != 0 && (maze[24 - (pac.y / 40)][pac.x / 40] != 1))
				{


					pac.stop = 1;


				}
				else if (pac.x % 40 == 0 && (maze[24 - (pac.y / 40)][(pac.x / 40)] == 2))
				{
					pac.stop = 1;
				}

			}
		}
		else if (key == GLUT_KEY_RIGHT)
		{
			start = 0;
			if (movesound == false)
			{
				playMusic();
				movesound = true;
			}
			if ((pac.y % 40 == 0 && (maze[24 - (pac.y / 40)][pac.x / 40] != 1) && (maze[24 - (pac.y / 40)][pac.x / 40 + 1] != 1)) || ((pac.y - 10) % 40 == 0 && (maze[24 - ((pac.y - 10) / 40)][pac.x / 40] != 1) && (maze[24 - ((pac.y - 10) / 40)][pac.x / 40 + 1] != 1) && pac.stop == 3) || ((pac.y + 10) % 40 == 0 && (maze[24 - ((pac.y + 10) / 40)][pac.x / 40] != 1) && (maze[24 - ((pac.y + 10) / 40)][pac.x / 40 + 1] != 1) && pac.stop == 2))
			{
				if (((pac.y - 10) % 40 == 0 && (maze[24 - ((pac.y - 10) / 40)][pac.x / 40] != 1) && (maze[24 - ((pac.y - 10) / 40)][pac.x / 40 + 1] != 1) && pac.stop == 3))
				{
					pac.y = pac.y - 10;
				}
				else if (((pac.y + 10) % 40 == 0 && (maze[24 - ((pac.y + 10) / 40)][pac.x / 40] != 1) && (maze[24 - ((pac.y + 10) / 40)][pac.x / 40 + 1] != 1) && pac.stop == 2))
				{
					pac.y = pac.y + 10;
				}
				
				
				pac.stop = 0;

				if (pac.x % 40 == 0 && (maze[24 - (pac.y / 40)][(pac.x / 40)] == 2))
				{


					pac.stop = 0;
				}
			}
		}
		else if (key == GLUT_KEY_UP)
		{

			start = 0;
			if (movesound == false)
			{
				playMusic();
				movesound = true;
			}
			if ((pac.x % 40 == 0 && maze[24 - (pac.y / 40)][pac.x / 40] != 1 && maze[23 - (pac.y / 40)][pac.x / 40] != 1) || ((pac.x - 10) % 40 == 0 && maze[24 - (pac.y / 40)][(pac.x - 10) / 40] != 1 && maze[23 - (pac.y / 40)][(pac.x - 10) / 40] != 1 && pac.stop == 1) || ((pac.x + 10) % 40 == 0 && maze[24 - (pac.y / 40)][(pac.x + 10) / 40] != 1 && maze[23 - (pac.y / 40)][(pac.x + 10) / 40] != 1 && pac.stop == 0))
			{
				if (((pac.x - 10) % 40 == 0 && maze[24 - (pac.y / 40)][(pac.x - 10) / 40] != 1 && maze[23 - (pac.y / 40)][(pac.x - 10) / 40] != 1 && pac.stop == 1))
				{
					pac.x = pac.x - 10;
				}
				else if (((pac.x + 10) % 40 == 0 && maze[24 - (pac.y / 40)][(pac.x + 10) / 40] != 1 && maze[23 - (pac.y / 40)][(pac.x + 10) / 40] != 1 && pac.stop == 0))
				{
					pac.x = pac.x + 10;
				}

				pac.stop = 2;
			}
		}


		else if (key == GLUT_KEY_DOWN)
		{
			start = 0;
			if (movesound == false)
			{
				playMusic();
				movesound = true;
			}
			if ((pac.x % 40 == 0 && maze[24 - (pac.y / 40)][pac.x / 40] != 1) || ((pac.x - 10) % 40 == 0 && maze[24 - (pac.y / 40)][(pac.x - 10) / 40] != 1 && pac.stop == 1) || ((pac.x + 10) % 40 == 0 && maze[24 - (pac.y / 40)][(pac.x + 10) / 40] != 1 && pac.stop == 0))
			{
				if (((pac.x - 10) % 40 == 0 && maze[24 - (pac.y / 40)][(pac.x - 10) / 40] != 1 && pac.stop == 1))
				{
					pac.x = pac.x - 10;
				}
				else if (((pac.x + 10) % 40 == 0 && maze[24 - (pac.y / 40)][(pac.x + 10) / 40] != 1 && pac.stop == 0))
				{
					pac.x = pac.x + 10;
				}
				
				
				if (pac.y % 40 == 0 && maze[25 - (pac.y / 40)][pac.x / 40] != 1)
				{


					pac.stop = 3;
				}
				else if (pac.y % 40 != 0 && maze[24 - (pac.y / 40)][pac.x / 40] != 1)
				{


					pac.stop = 3;
				}

			}

		}
	}


}


/////////////////////////////////////////////////////////////////////Main Function/////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//place your own initialization codes here.


	playMusic();

	readSavefile();

	startGame();



	iSetTimer(80, pac_move);
	iSetTimer(80, rmpellet);
	iSetTimer(80, ghostmove);
	iSetTimer(80, lifeLoss);
	iSetTimer(80, PauseGame);
	iSetTimer(80, Fmove);
	iSetTimer(40, Emove);
	iPauseTimer(5);
	iPauseTimer(6);
	iSetTimer(20, change);

	iInitialize(840, 1015, "Pac-Man");


	return 0;
}

/**********************************************************************Subsidiary Functions***************************************************************************/

////////////////////////////////////////////////////////////////////Start, Pause, Restart/////////////////////////////////////////////////////////////////////////////

void startGame()
{
	readScoreFile();

	if (game.existsave == false)
	{
		if (game.level >= 1)
		{
			game.score = 0;

			pac.x = 400, pac.y = 280;
			pac.state = 0, pac.stop = 5;

			red.x = 360, red.y = 560;
			red.stop = 1, red.state = 0;
			red.ud = 20000000, red.dd = 20000000, red.ld = 20000000, red.rd = 20000000;
			red.scsmode = 0, red.cs = 0, red.sc = 0;
			red.isF = 0;
			F1.crmode = 0, F1.cr = 0, F1.rc = 0, F1.color = 0, F1.state = 0;
			F1.isDead = 0;

			for (int i = 0; high_score[10].name[i] != NULL; i++)
			{
				high_score[10].name[i] = '\0';
			}
		}
		if (game.level >= 2)
		{
			pink.x = 440, pink.y = 560;
			pink.stop = 0, pink.state = 0;
			pink.ud = 20000000, pink.dd = 20000000, pink.ld = 20000000, pink.rd = 20000000;
			pink.scsmode = 0, pink.cs = 0, pink.sc = 0;
			pink.isF = 0;
			F2.crmode = 0, F2.cr = 0, F2.rc = 0, F2.color = 0, F2.state = 0;
			F2.isDead = 0;
		}
		if (game.level >= 3)
		{
			blue.x = 400, blue.y = 560;
			blue.stop = 1, blue.state = 0;
			blue.ud = 20000000, blue.dd = 20000000, blue.ld = 20000000, blue.rd = 20000000;
			blue.scsmode = 0, blue.cs = 0, blue.sc = 0;
			blue.isF = 0;
			F3.crmode = 0, F3.cr = 0, F3.rc = 0, F3.color = 0, F3.state = 0;
			F3.isDead = 0;
		}
	}
}

void restartLevel()
{
	if (game.level >= 1)
	{
		pac.x = 400, pac.y = 280;
		pac.state = 0, pac.stop = 5;

		start = 2;

		movesound = false;

		ghost_isF = 0;

		red.x = 360, red.y = 560;
		red.stop = 1, red.state = 0;
		red.ud = 20000000, red.dd = 20000000, red.ld = 20000000, red.rd = 20000000;
		red.scsmode = 0, red.cs = 0, red.sc = 0;
		red.isF = 0;
		F1.crmode = 0, F1.cr = 0, F1.rc = 0, F1.color = 0, F1.state = 0;
		F1.isDead = 0;

		for (int i = 0; high_score[10].name[i] != NULL; i++)
		{
			high_score[10].name[i] = '\0';
		}
	}
	if (game.level >= 2)
	{
		pink.x = 440, pink.y = 560;
		pink.stop = 0, pink.state = 0;
		pink.ud = 20000000, pink.dd = 20000000, pink.ld = 20000000, pink.rd = 20000000;
		pink.scsmode = 0, pink.cs = 0, pink.sc = 0;
		pink.isF = 0;
		F2.crmode = 0, F2.cr = 0, F2.rc = 0, F2.color = 0, F2.state = 0;
		F2.isDead = 0;
	}
	if (game.level >= 3)
	{
		blue.x = 400, blue.y = 560;
		blue.stop = 1, blue.state = 0;
		blue.ud = 20000000, blue.dd = 20000000, blue.ld = 20000000, blue.rd = 20000000;
		blue.scsmode = 0, blue.cs = 0, blue.sc = 0;
		blue.isF = 0;
		F3.crmode = 0, F3.cr = 0, F3.rc = 0, F3.color = 0, F3.state = 0;
		F3.isDead = 0;
	}

	if (game.isPlaying == 1)
	{
		game.life = 3;

		game.level = 1;

		pellet = 0;

	}

	game.isPaused = 0;
}

void PauseGame()
{
	if (game.isPaused == 1)
	{
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
	}
	else
	{
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
		iResumeTimer(3);
	}
	if (ghost_isF == 1)
	{
		iPauseTimer(2);
		if (game.level == 1)
		{
			if (F1.isDead == 1)
			{
				iPauseTimer(5);
				iResumeTimer(6);

			}
			else
			{
				iResumeTimer(5);

			}
		}
		else if (game.level == 2)
		{
			if (F1.isDead == 1 && F2.isDead == 1)
			{
				iPauseTimer(5);
				iResumeTimer(6);

			}
			else if (F2.isDead == 1 || F1.isDead == 1)
			{
				iResumeTimer(5);
				iResumeTimer(6);

			}
			else if (F1.isDead == 0 && F2.isDead == 0)
			{
				iResumeTimer(5);

			}
		}
		else if (game.level == 3)
		{
			if (F1.isDead == 1 && F2.isDead == 1 && F3.isDead == 1)
			{
				iPauseTimer(5);
				iResumeTimer(6);

			}
			else if (F2.isDead == 1 || F1.isDead == 1 || F3.isDead == 1)
			{
				iResumeTimer(5);
				iResumeTimer(6);

			}
			else if (F1.isDead == 0 && F2.isDead == 0 && F3.isDead == 0)
			{
				iResumeTimer(5);

			}
		}

	}
	else
	{

		iPauseTimer(5);
		iPauseTimer(6);
		F1.crmode = 0, F1.cr = 0, F1.rc = 0, F1.color = 0, F1.state = 0;
		F1.isDead = 0;
		F2.crmode = 0, F2.cr = 0, F2.rc = 0, F2.color = 0, F2.state = 0;
		F2.isDead = 0;
		F3.crmode = 0, F3.cr = 0, F3.rc = 0, F3.color = 0, F3.state = 0;
		F3.isDead = 0;
		iResumeTimer(2);
	}
}

//////////////////////////////////////////////////////////////////////////Sounds////////////////////////////////////////////////////////////////////////////////////////////

void playMusic()
{
	if (currPage == -1)
	{
		if (music)
		{
			PlaySound("Sounds\\intro.wav", NULL, SND_ASYNC);
		}
		else
		{
			PlaySound(0, 0, 0);
		}
	}
	else if (currPage == 0)
	{
		if (music)
		{

			PlaySound("Sounds\\begin.wav", NULL, SND_ASYNC);
		}
		else
		{
			PlaySound(0, 0, 0);
		}
	}
	else if (currPage == 1)
	{
		if (music)
		{
			if (start == 0)
			{
				if (die == 1)
				{
					PlaySound("Sounds\\death.wav", NULL, SND_ASYNC);
				}
				else if (ghost_isF == 1)
				{
					PlaySound("Sounds\\fghost.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else if (game.isLevelUp == 1)
				{
					PlaySound("Sounds\\lvup.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound("Sounds\\move.wav", NULL, SND_LOOP | SND_ASYNC);
				}

			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
		else
		{
			PlaySound(0, 0, 0);
		}
	}
	else if (currPage == 11)
	{
		if (music)
		{
			PlaySound("Sounds\\congrats.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		else
		{
			PlaySound(0, 0, 0);
		}
	}
	else
	{
		PlaySound(0, 0, 0);
	}

}


//////////////////////////////////////////////////////////////////////////Draw Functions////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////HomePage/////////////////////////
void drawHome()
{
	iShowBMP(0, 0, "Pics\\Home\\Home.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(90, 390, "Pics\\Home\\ngame1.bmp");
	}
	else
	{
		iShowBMP(90, 390, "Pics\\Home\\ngame2.bmp");
	}
	if (game.existsave == true)
	{
		if (stcolor[1] == 1)
		{
			iShowBMP(460, 390, "Pics\\Home\\lgame1.bmp");
		}
		else
		{
			iShowBMP(460, 390, "Pics\\Home\\lgame2.bmp");
		}
	}
	else
	{
		iShowBMP(460, 390, "Pics\\Home\\lgame3.bmp");
	}
	if (stcolor[2] == 1)
	{
		iShowBMP(90, 270, "Pics\\Home\\Mode1.bmp");
	}
	else
	{
		iShowBMP(90, 270, "Pics\\Home\\Mode2.bmp");
	}
	if (stcolor[3] == 1)
	{
		iShowBMP(460, 270, "Pics\\Home\\Lead1.bmp");
	}
	else
	{
		iShowBMP(460, 270, "Pics\\Home\\Lead2.bmp");
	}
	if (stcolor[4] == 1)
	{
		iShowBMP(90, 150, "Pics\\Home\\Learn1.bmp");
	}
	else
	{
		iShowBMP(90, 150, "Pics\\Home\\Learn2.bmp");
	}
	if (stcolor[5] == 1)
	{
		iShowBMP(460, 150, "Pics\\Home\\Creds1.bmp");
	}
	else
	{
		iShowBMP(460, 150, "Pics\\Home\\Creds2.bmp");
	}
	if (stcolor[6] == 1)
	{
		iShowBMP(170, 30, "Pics\\Home\\Quit1.bmp");
	}
	else
	{
		iShowBMP(170, 30, "Pics\\Home\\Quit2.bmp");
	}
	if (stcolor[7] == 1)
	{
		if (music)
			iShowBMP2(750, 900, "Pics\\Home\\Sound1.bmp", 0);
		else
			iShowBMP2(750, 900, "Pics\\Home\\Sound2.bmp", 0);
	}
	else
	{
		if (music)
			iShowBMP2(750, 900, "Pics\\Home\\Sound12.bmp", 0);
		else
			iShowBMP2(750, 900, "Pics\\Home\\Sound22.bmp", 0);
	}
}

////////////////////Levels/Mazes////////////////////////
void drawMaze()
{
	if (game.isLevelUp == 0 && game.isWon == 0)
	{
		if (game.level == 1)
		{
			if (game.mode == 1)
				iShowBMP(0, 0, "Pics\\Maze\\L1maze.bmp");
			else if (game.mode == 2)
				iShowBMP(0, 0, "Pics\\Maze\\CLV1.bmp");
			else if (game.mode == 3)
				iShowBMP(0, 0, "Pics\\Maze\\RLV1.bmp");
		}
		else if (game.level == 2)
		{
			if (game.mode == 1)
				iShowBMP(0, 0, "Pics\\Maze\\L2maze.bmp");
			else if (game.mode == 2)
				iShowBMP(0, 0, "Pics\\Maze\\CLV2.bmp");
			else if (game.mode == 3)
				iShowBMP(0, 0, "Pics\\Maze\\RLV2.bmp");
		}
		else if (game.level == 3)
		{
			if (game.mode == 1)
				iShowBMP(0, 0, "Pics\\Maze\\L3maze.bmp");
			else if (game.mode == 2)
				iShowBMP(0, 0, "Pics\\Maze\\CLV3.bmp");
			else if (game.mode == 3)
				iShowBMP(0, 0, "Pics\\Maze\\RLV3.bmp");
		}

		drawPellets();

		showLives();

		showScore();

		drawPac();

		if (game.level >= 1)
		{
			if (red.isF == 0)
			{
				drawRed();
			}
			else
			{
				if (F1.isDead == 0)
				{
					drawF1();
				}
				else if (F1.isDead == 1)
				{
					drawE1();
				}
			}
		}
		if (game.level >= 2)
		{
			if (pink.isF == 0)
			{
				drawPink();
			}
			else
			{
				if (F2.isDead == 0)
				{
					drawF2();
				}
				else if (F2.isDead == 1)
				{
					drawE2();
				}
			}
		}
		if (game.level >= 3)
		{
			if (blue.isF == 0)
			{
				drawBlue();
			}
			else
			{
				if (F3.isDead == 0)
				{
					drawF3();
				}
				else if (F3.isDead == 1)
				{
					drawE3();
				}
			}
		}

	}
	else if (game.isLevelUp == 1)
	{
		if (lvupanim < 200)
		{
			if (game.lvupstate == 0)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup1.bmp");
				game.lvupstate = 2;
			}
			else if (game.lvupstate == 1)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup2.bmp");
				game.lvupstate = 0;
			}
			else if (game.lvupstate == 2)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup1.bmp");
				game.lvupstate = 4;
			}
			else if (game.lvupstate == 3)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup2.bmp");
				game.lvupstate = 1;
			}
			else if (game.lvupstate == 4)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup1.bmp");
				game.lvupstate = 6;
			}
			else if (game.lvupstate == 5)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup2.bmp");
				game.lvupstate = 3;
			}
			else if (game.lvupstate == 6)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup1.bmp");
				game.lvupstate = 8;
			}
			else if (game.lvupstate == 7)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup2.bmp");
				game.lvupstate = 5;
			}
			else if (game.lvupstate == 8)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup1.bmp");
				game.lvupstate = 9;
			}
			else if (game.lvupstate == 9)
			{
				iShowBMP(0, 0, "Pics\\Maze\\lvup2.bmp");
				game.lvupstate = 7;
			}


			lvupanim++;
		}
		else
		{
			lvupanim = 0;

			game.lvupstate = 0;

			game.isLevelUp = 0;

			restartLevel();

			playMusic();


		}
	}
}

//////////////Pause Menu////////////////////////

void drawPause()
{
	iShowBMP(0, 0, "Pics\\Pause\\pause.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(170, 605, "Pics\\Pause\\Resume1.bmp");
	}
	else
	{
		iShowBMP(170, 605, "Pics\\Pause\\Resume2.bmp");
	}
	if (stcolor[1] == 1)
	{
		iShowBMP(170, 495, "Pics\\Pause\\sgame1.bmp");
	}
	else
	{
		iShowBMP(170, 495, "Pics\\Pause\\sgame2.bmp");
	}
	if (stcolor[2] == 1)
	{
		if (music)
			iShowBMP(170, 385, "Pics\\Pause\\Soundon1.bmp");
		else
			iShowBMP(170, 385, "Pics\\Pause\\Soundoff1.bmp");
	}
	else
	{
		if (music)
			iShowBMP(170, 385, "Pics\\Pause\\Soundon2.bmp");
		else
			iShowBMP(170, 385, "Pics\\Pause\\Soundoff2.bmp");
	}
	if (stcolor[3] == 1)
	{
		iShowBMP(170, 275, "Pics\\Pause\\Lead1.bmp");
	}
	else
	{
		iShowBMP(170, 275, "Pics\\Pause\\Lead2.bmp");
	}
	if (stcolor[4] == 1)
	{
		iShowBMP(170, 165, "Pics\\Pause\\Main1.bmp");
	}
	else
	{
		iShowBMP(170, 165, "Pics\\Pause\\Main2.bmp");
	}
	if (stcolor[5] == 1)
	{
		iShowBMP(170, 55, "Pics\\Pause\\Quit1.bmp");
	}
	else
	{
		iShowBMP(170, 55, "Pics\\Pause\\Quit2.bmp");
	}

	if (savedshow == 1)
	{
		iShowBMP(180, 875, "Pics\\Pause\\saved.bmp");
	}


}


///////////Rules Page//////////////////////
void drawLearn()
{
	iShowBMP(0, 0, "Pics\\Rules\\Rules.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow11.bmp");
	}
	else
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow12.bmp");
	}
	if (stcolor[1] == 1)
	{
		iShowBMP(520, 25, "Pics\\Rules\\arrow21.bmp");
	}
	else
	{
		iShowBMP(520, 25, "Pics\\Rules\\arrow22.bmp");
	}
}

void drawPoints()
{
	iShowBMP(0, 0, "Pics\\Rules\\Points.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow11.bmp");
	}
	else
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow12.bmp");
	}
}

/////////GameOver Page////////////////////////////////////
void gameover()
{
	iShowBMP(0, 0, "Pics\\Maze\\over.bmp");
}

///////////////////Completion Page//////////////////
void drawWin()
{
	iShowBMP(0, 0, "Pics\\Maze\\congrats.bmp");
}


//////////////////////////////Credits///////////////////
void drawCreds()
{
	iShowBMP(0, 0, "Pics\\Credits\\creds.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow11.bmp");
	}
	else
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow12.bmp");
	}
}



////////////////Modes Page//////////////////
void drawMode()
{
	iShowBMP(0, 0, "Pics\\Modes\\mode.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow11.bmp");
	}
	else
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow12.bmp");
	}
	if (game.mode == 1 && stcolor[1] != 1)
	{
		iShowBMP(80, 480, "Pics\\Modes\\pacmode1.bmp");
	}
	else if (stcolor[1] == 1)
	{
		iShowBMP(80, 480, "Pics\\Modes\\pacmode1.bmp");
		iShowBMP(200, 680, "Pics\\Modes\\pacs.bmp");
	}
	else
	{
		iShowBMP(80, 480, "Pics\\Modes\\pacmode2.bmp");
	}
	if (game.mode == 2 && stcolor[2] != 1)
	{
		iShowBMP(320, 280, "Pics\\Modes\\cookiemode1.bmp");
	}
	else if (stcolor[2] == 1)
	{
		iShowBMP(320, 280, "Pics\\Modes\\cookiemode1.bmp");
		iShowBMP(200, 680, "Pics\\Modes\\cooks.bmp");
	}
	else
	{
		iShowBMP(320, 280, "Pics\\Modes\\cookiemode2.bmp");
	}
	if (game.mode == 3 && stcolor[3] != 1)
	{
		iShowBMP(80, 80, "Pics\\Modes\\raimode1.bmp");
	}
	else if (stcolor[3] == 1)
	{
		iShowBMP(80, 80, "Pics\\Modes\\raimode1.bmp");
		iShowBMP(200, 680, "Pics\\Modes\\rais.bmp");
	}
	else
	{
		iShowBMP(80, 80, "Pics\\Modes\\raimode2.bmp");
	}
}



/////////////Pellets(Pacman's Dots) Drawing///////////////
void drawPellets()
{
	for (int dotx = 120; dotx <= 680; dotx += 40)
	{
		for (int doty = 120; doty <= 840; doty += 40)
		{
			if (pellets[24 - (doty / 40)][dotx / 40] == 0)
			{
				iShowBMP2(dotx, doty, "Pics\\Objects\\pellet.bmp", 0);
			}
			else if (pellets[24 - (doty / 40)][dotx / 40] == 4)
			{
				iShowBMP2(dotx, doty, "Pics\\Objects\\Energizer.bmp", 0);
			}
		}
	}
}


////////////////////////////////Leaderboard Draw///////////////////////

///////Name input page///////
void writeName(unsigned char key)
{
	char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	char alphab[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };


	for (int i = 0; i < 26; i++)
	{
		if (key == alpha[i])
		{
			high_score[10].name[slen] = alpha[i];

			backi = 0;
		}
		else if (key == alphab[i])
		{
			high_score[10].name[slen] = alphab[i];

			backi = 0;
		}
		else if (key == '\b')
		{
			high_score[10].name[slen - 1] = '\0';

			if (high_score[10].name[slen - 2] == 'i' || high_score[10].name[slen - 2] == 'I')
			{
				backi = 1;
			}
		}
	}
}

void drawName()
{
	iShowBMP(0, 0, "Pics\\Name\\Namepage.bmp");

	int nx = 430, ny = 480;

	slen = strlen(high_score[10].name);


	char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	char alphab[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	char alp[26][30] = { "Pics\\Name\\Alpha\\a.bmp", "Pics\\Name\\Alpha\\b.bmp", "Pics\\Name\\Alpha\\c.bmp", "Pics\\Name\\Alpha\\d.bmp", "Pics\\Name\\Alpha\\e.bmp", "Pics\\Name\\Alpha\\f.bmp",
		"Pics\\Name\\Alpha\\g.bmp", "Pics\\Name\\Alpha\\h.bmp", "Pics\\Name\\Alpha\\i.bmp", "Pics\\Name\\Alpha\\j.bmp", "Pics\\Name\\Alpha\\k.bmp", "Pics\\Name\\Alpha\\l.bmp",
		"Pics\\Name\\Alpha\\m.bmp", "Pics\\Name\\Alpha\\n.bmp", "Pics\\Name\\Alpha\\o.bmp", "Pics\\Name\\Alpha\\p.bmp", "Pics\\Name\\Alpha\\q.bmp", "Pics\\Name\\Alpha\\r.bmp",
		"Pics\\Name\\Alpha\\s.bmp", "Pics\\Name\\Alpha\\t.bmp", "Pics\\Name\\Alpha\\u.bmp", "Pics\\Name\\Alpha\\v.bmp", "Pics\\Name\\Alpha\\w.bmp", "Pics\\Name\\Alpha\\x.bmp",
		"Pics\\Name\\Alpha\\y.bmp", "Pics\\Name\\Alpha\\z.bmp" };

	if (slen == 0)
	{
		iShowBMP2(cux - 20, ny - 5, "Pics\\Name\\cursor.bmp", 0);
	}
	else
	{
		if (high_score[10].name[slen - 1] == 'i' || high_score[10].name[slen - 1] == 'I')
		{
			if (cons_i == 0)
			{
				iShowBMP2(cux - 10 + (slen / 2) * 40, ny - 5, "Pics\\Name\\cursor.bmp", 0);

				cons_i = 1;
			}
			else
			{
				iShowBMP2(cux - 20 + (slen / 2) * 40, ny - 5, "Pics\\Name\\cursor.bmp", 0);
			}

			printf("Back: %i\n", backi);

			if (count_i == 0 && backi == 0)
			{
				cux -= 20;

				count_i = 1;
			}
			else if (count_i == 0 && backi == 1)
			{
				count_i = 1;
			}
		}
		else
		{
			iShowBMP2(cux - 20 + (slen / 2) * 40, ny - 5, "Pics\\Name\\cursor.bmp", 0);

			count_i = 0;

			if (backi == 1)
			{
				cux += 20;

				backi = 0;
			}
		}
	}

	for (int i = 0; i < slen; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (high_score[10].name[i] == alpha[j])
			{
				if (high_score[10].name[i] == 'i')
				{
					if (slen % 2 == 0)
					{
						if (i <= slen / 2 - 1)
						{
							iShowBMP2(nx - ((slen / 2) - i) * 40, ny, alp[j], 0);
						}
						else
						{
							iShowBMP2(nx + (i - (slen / 2)) * 40, ny, alp[j], 0);
						}
					}
					else
					{
						if (i <= slen / 2)
						{
							iShowBMP2(nx - (((slen + 1) / 2) - i) * 40, ny, alp[j], 0);
						}
						else
						{
							iShowBMP2(nx + (i - ((slen + 1) / 2)) * 40, ny, alp[j], 0);
						}
					}

					nx -= 20;
				}
				else
				{
					if (slen % 2 == 0)
					{
						if (i <= slen / 2 - 1)
						{
							iShowBMP2(nx - ((slen / 2) - i) * 40, ny, alp[j], 0);
						}
						else
						{
							iShowBMP2(nx + (i - (slen / 2)) * 40, ny, alp[j], 0);
						}
					}
					else
					{
						if (i <= slen / 2)
						{
							iShowBMP2(nx - (((slen + 1) / 2) - i) * 40, ny, alp[j], 0);
						}
						else
						{
							iShowBMP2(nx + (i - ((slen + 1) / 2)) * 40, ny, alp[j], 0);
						}
					}
				}


			}
			else if (high_score[10].name[i] == alphab[j])
			{
				if (high_score[10].name[i] == 'I')
				{
					if (slen % 2 == 0)
					{
						if (i <= slen / 2 - 1)
						{
							iShowBMP2(nx - ((slen / 2) - i) * 40, ny, alp[j], 0);
						}
						else
						{
							iShowBMP2(nx + (i - (slen / 2)) * 40, ny, alp[j], 0);
						}
					}
					else
					{
						if (i <= slen / 2)
						{
							iShowBMP2(nx - (((slen + 1) / 2) - i) * 40, ny, alp[j], 0);
						}
						else
						{
							iShowBMP2(nx + (i - ((slen + 1) / 2)) * 40, ny, alp[j], 0);
						}
					}

					nx -= 20;
				}
				else
				{
					if (slen % 2 == 0)
					{
						if (i <= slen / 2 - 1)
						{
							iShowBMP2(nx - ((slen / 2) - i) * 40, ny, alp[j], 0);
						}
						else
						{
							iShowBMP2(nx + (i - (slen / 2)) * 40, ny, alp[j], 0);
						}
					}
					else
					{
						if (i <= slen / 2)
						{
							iShowBMP2(nx - (((slen + 1) / 2) - i) * 40, ny, alp[j], 0);
						}
						else
						{
							iShowBMP2(nx + (i - ((slen + 1) / 2)) * 40, ny, alp[j], 0);
						}
					}
				}
			}
		}
	}
}

/////////////Start Up Leaderboard////////////////
void drawLead()
{
	iShowBMP(0, 0, "Pics\\Lead\\hscore.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow11.bmp");
	}
	else
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow12.bmp");
	}

	drawHScores();
}

void drawHScores()
{


	char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	char alphab[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	char alp[26][30] = { "Pics\\Name\\Alpha\\30px\\a.bmp", "Pics\\Name\\Alpha\\30px\\b.bmp", "Pics\\Name\\Alpha\\30px\\c.bmp", "Pics\\Name\\Alpha\\30px\\d.bmp", "Pics\\Name\\Alpha\\30px\\e.bmp", "Pics\\Name\\Alpha\\30px\\f.bmp",
		"Pics\\Name\\Alpha\\30px\\g.bmp", "Pics\\Name\\Alpha\\30px\\h.bmp", "Pics\\Name\\Alpha\\30px\\i.bmp", "Pics\\Name\\Alpha\\30px\\j.bmp", "Pics\\Name\\Alpha\\30px\\k.bmp", "Pics\\Name\\Alpha\\30px\\l.bmp",
		"Pics\\Name\\Alpha\\30px\\m.bmp", "Pics\\Name\\Alpha\\30px\\n.bmp", "Pics\\Name\\Alpha\\30px\\o.bmp", "Pics\\Name\\Alpha\\30px\\p.bmp", "Pics\\Name\\Alpha\\30px\\q.bmp", "Pics\\Name\\Alpha\\30px\\r.bmp",
		"Pics\\Name\\Alpha\\30px\\s.bmp", "Pics\\Name\\Alpha\\30px\\t.bmp", "Pics\\Name\\Alpha\\30px\\u.bmp", "Pics\\Name\\Alpha\\30px\\v.bmp", "Pics\\Name\\Alpha\\30px\\w.bmp", "Pics\\Name\\Alpha\\30px\\x.bmp",
		"Pics\\Name\\Alpha\\30px\\y.bmp", "Pics\\Name\\Alpha\\30px\\z.bmp" };

	char num[10][30] = { "Pics\\Numbers\\30px\\0.bmp", "Pics\\Numbers\\30px\\1.bmp", "Pics\\Numbers\\30px\\2.bmp", "Pics\\Numbers\\30px\\3.bmp", "Pics\\Numbers\\30px\\4.bmp",
		"Pics\\Numbers\\30px\\5.bmp", "Pics\\Numbers\\30px\\6.bmp", "Pics\\Numbers\\30px\\7.bmp", "Pics\\Numbers\\30px\\8.bmp", "Pics\\Numbers\\30px\\9.bmp" };

	for (int k = 0; k < 10; k++)
	{
		len = strlen(high_score[k].name);

		int cx = 310, cy = 665;

		int nx = 590;

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (high_score[k].name[i] == alpha[j])
				{
					if (high_score[k].name[i] == 'i')
					{
						iShowBMP2(cx + i * 30, cy - k * 64, alp[j], 0);

						cx -= 10;
					}
					else
					{
						iShowBMP2(cx + i * 30, cy - k * 64, alp[j], 0);
					}
				}
				else if (high_score[k].name[i] == alphab[j])
				{
					if (high_score[k].name[i] == 'I')
					{
						iShowBMP2(cx - 10 + i * 30, cy - k * 64, alp[j], 0);

						cx -= 20;
					}
					else
					{
						iShowBMP2(cx + i * 30, cy - k * 64, alp[j], 0);
					}
				}
			}
		}



		int a = high_score[k].score;

		int n4 = a / pow(10.0, 4);

		a = a % (int)pow(10.0, 4);

		iShowBMP2(nx, cy - k * 64, num[n4], 0);

		int n3 = a / pow(10.0, 3);

		a = a % (int)pow(10.0, 3);

		iShowBMP2(nx + 30, cy - k * 64, num[n3], 0);

		int n2 = a / pow(10.0, 2);

		a = a % (int)pow(10.0, 2);

		iShowBMP2(nx + 60, cy - k * 64, num[n2], 0);

		int n1 = a / pow(10.0, 1);

		a = a % (int)pow(10.0, 1);

		iShowBMP2(nx + 90, cy - k * 64, num[n1], 0);

		int n0 = a;

		iShowBMP2(nx + 120, cy - k * 64, num[n0], 0);

	}
}



//////////////Updated Leaderboard(just after a game session)//////////////////////
void drawLead2()
{
	iShowBMP(0, 0, "Pics\\Lead\\hscore.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow11.bmp");
	}
	else
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow12.bmp");
	}

	drawHScoresUpd();
}

void drawHScoresUpd()
{


	char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	char alphab[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	char alp[26][30] = { "Pics\\Name\\Alpha\\30px\\a.bmp", "Pics\\Name\\Alpha\\30px\\b.bmp", "Pics\\Name\\Alpha\\30px\\c.bmp", "Pics\\Name\\Alpha\\30px\\d.bmp", "Pics\\Name\\Alpha\\30px\\e.bmp", "Pics\\Name\\Alpha\\30px\\f.bmp",
		"Pics\\Name\\Alpha\\30px\\g.bmp", "Pics\\Name\\Alpha\\30px\\h.bmp", "Pics\\Name\\Alpha\\30px\\i.bmp", "Pics\\Name\\Alpha\\30px\\j.bmp", "Pics\\Name\\Alpha\\30px\\k.bmp", "Pics\\Name\\Alpha\\30px\\l.bmp",
		"Pics\\Name\\Alpha\\30px\\m.bmp", "Pics\\Name\\Alpha\\30px\\n.bmp", "Pics\\Name\\Alpha\\30px\\o.bmp", "Pics\\Name\\Alpha\\30px\\p.bmp", "Pics\\Name\\Alpha\\30px\\q.bmp", "Pics\\Name\\Alpha\\30px\\r.bmp",
		"Pics\\Name\\Alpha\\30px\\s.bmp", "Pics\\Name\\Alpha\\30px\\t.bmp", "Pics\\Name\\Alpha\\30px\\u.bmp", "Pics\\Name\\Alpha\\30px\\v.bmp", "Pics\\Name\\Alpha\\30px\\w.bmp", "Pics\\Name\\Alpha\\30px\\x.bmp",
		"Pics\\Name\\Alpha\\30px\\y.bmp", "Pics\\Name\\Alpha\\30px\\z.bmp" };

	char num[10][30] = { "Pics\\Numbers\\30px\\0.bmp", "Pics\\Numbers\\30px\\1.bmp", "Pics\\Numbers\\30px\\2.bmp", "Pics\\Numbers\\30px\\3.bmp", "Pics\\Numbers\\30px\\4.bmp",
		"Pics\\Numbers\\30px\\5.bmp", "Pics\\Numbers\\30px\\6.bmp", "Pics\\Numbers\\30px\\7.bmp", "Pics\\Numbers\\30px\\8.bmp", "Pics\\Numbers\\30px\\9.bmp" };

	for (int k = 0; k < 10; k++)
	{


		len = strlen(high_score[k].name);

		int cx = 310, cy = 665;

		int nx = 590;


		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (high_score[k].name[i] == alpha[j])
				{
					if (high_score[k].name[i] == 'i')
					{
						iShowBMP2(cx + i * 30, cy - k * 64, alp[j], 0);

						cx -= 10;
					}
					else
					{
						iShowBMP2(cx + i * 30, cy - k * 64, alp[j], 0);
					}
				}
				else if (high_score[k].name[i] == alphab[j])
				{
					if (high_score[k].name[i] == 'I')
					{
						iShowBMP2(cx - 10 + i * 30, cy - k * 64, alp[j], 0);

						cx -= 20;
					}
					else
					{
						iShowBMP2(cx + i * 30, cy - k * 64, alp[j], 0);
					}
				}
			}
		}



		int a = high_score[k].score;

		int n4 = a / pow(10.0, 4);

		a = a % (int)pow(10.0, 4);

		iShowBMP2(nx, cy - k * 64, num[n4], 0);

		int n3 = a / pow(10.0, 3);

		a = a % (int)pow(10.0, 3);

		iShowBMP2(nx + 30, cy - k * 64, num[n3], 0);

		int n2 = a / pow(10.0, 2);

		a = a % (int)pow(10.0, 2);

		iShowBMP2(nx + 60, cy - k * 64, num[n2], 0);

		int n1 = a / pow(10.0, 1);

		a = a % (int)pow(10.0, 1);

		iShowBMP2(nx + 90, cy - k * 64, num[n1], 0);

		int n0 = a;

		iShowBMP2(nx + 120, cy - k * 64, num[n0], 0);

	}
}

void drawLead3()
{
	iShowBMP(0, 0, "Pics\\Lead\\hscore.bmp");

	if (stcolor[0] == 1)
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow11.bmp");
	}
	else
	{
		iShowBMP(30, 935, "Pics\\Rules\\arrow12.bmp");
	}

	drawHScores();
}

///////////////////////////////////////////////////////////////
////////////////////Pac-man draw///////////////////////////////
///////////////////////////////////////////////////////////////
void drawPac()
{
	char paci[10][30] = { "Pics\\Pac\\pac0.bmp", "Pics\\Pac\\pac1.bmp", "Pics\\Pac\\pac2.bmp", "Pics\\Pac\\pac3.bmp", "Pics\\Pac\\pac4.bmp", "Pics\\Pac\\pac5.bmp" };
	char cook[10][30] = { "Pics\\CM\\CMl1.bmp", "Pics\\CM\\CMl2.bmp", "Pics\\CM\\CMd1.bmp", "Pics\\CM\\CMd2.bmp", "Pics\\CM\\CMr1.bmp", "Pics\\CM\\CMr2.bmp", "Pics\\CM\\CMu1.bmp", "Pics\\CM\\CMu2.bmp" };
	char rai[10][30] = { "Pics\\Raiyan\\rail1.bmp", "Pics\\Raiyan\\rail2.bmp", "Pics\\Raiyan\\raid1.bmp", "Pics\\Raiyan\\raid2.bmp", "Pics\\Raiyan\\rair1.bmp", "Pics\\Raiyan\\rair2.bmp", "Pics\\Raiyan\\raiu1.bmp", "Pics\\Raiyan\\raiu2.bmp" };
	if (game.isPaused == 0)
	{
		if (pac.stop == 5)
		{
			if (game.mode == 1)
				iShowBMP2(pac.x, pac.y, paci[5], 0);
			else if (game.mode == 2)
				iShowBMP2(pac.x, pac.y, cook[5], 0);
			else if (game.mode == 3)
				iShowBMP2(pac.x, pac.y, rai[5], 0);

		}
		else if (pac.stop == 0)
		{
			if (pac.state == 0)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[0], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[4], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[4], 0);
				pac.state = 2;
			}
			else if (pac.state == 1)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[5], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[5], 0);
				pac.state = 0;
			}
			else if (pac.state == 2)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[0], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[4], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[4], 0);
				pac.state = 4;
			}
			else if (pac.state == 3)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[5], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[5], 0);
				pac.state = 1;
			}
			else if (pac.state == 4)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[0], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[4], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[4], 0);
				pac.state = 5;
			}
			else if (pac.state == 5)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[5], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[5], 0);
				pac.state = 3;
			}

		}
		else if (pac.stop == 1)
		{
			if (pac.state == 0)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[1], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[0], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[0], 0);
				pac.state = 2;
			}
			else if (pac.state == 1)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[1], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[1], 0);
				pac.state = 0;
			}
			else if (pac.state == 2)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[1], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[0], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[0], 0);
				pac.state = 4;
			}
			else if (pac.state == 3)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[1], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[1], 0);
				pac.state = 1;
			}
			else if (pac.state == 4)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[1], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[0], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[0], 0);
				pac.state = 5;
			}
			else if (pac.state == 5)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[1], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[1], 0);
				pac.state = 3;
			}
		}
		else if (pac.stop == 2)
		{
			if (pac.state == 0)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[2], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[6], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[6], 0);
				pac.state = 2;
			}
			else if (pac.state == 1)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[7], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[7], 0);
				pac.state = 0;
			}
			else if (pac.state == 2)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[2], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[6], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[6], 0);
				pac.state = 4;
			}
			else if (pac.state == 3)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[7], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[7], 0);
				pac.state = 1;
			}
			else if (pac.state == 4)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[2], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[6], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[6], 0);
				pac.state = 5;
			}
			else if (pac.state == 5)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[7], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[7], 0);
				pac.state = 3;
			}
		}
		else if (pac.stop == 3)
		{
			if (pac.state == 0)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[3], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[2], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[2], 0);
				pac.state = 2;
			}
			else if (pac.state == 1)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[3], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[3], 0);
				pac.state = 0;
			}
			else if (pac.state == 2)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[3], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[2], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[2], 0);
				pac.state = 4;
			}
			else if (pac.state == 3)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[3], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[3], 0);
				pac.state = 1;
			}
			else if (pac.state == 4)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[3], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[2], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[2], 0);
				pac.state = 5;
			}
			else if (pac.state == 5)
			{
				if (game.mode == 1)
					iShowBMP2(pac.x, pac.y, paci[5], 0);
				else if (game.mode == 2)
					iShowBMP2(pac.x, pac.y, cook[3], 0);
				else if (game.mode == 3)
					iShowBMP2(pac.x, pac.y, rai[3], 0);
				pac.state = 3;
			}

		}
	}
	else if (game.isPaused == 1)
	{
		die = 1;
		if (diesound == false)
		{
			playMusic();
			diesound = true;
		}

		iResumeTimer(7);

		if (game.mode == 1)
		{
			if (pac.stop == 0)
				iShowBMP(pac.x, pac.y, pacdier[dii]);
			else if (pac.stop == 1)
				iShowBMP(pac.x, pac.y, pacdiel[dii]);
			else if (pac.stop == 2)
				iShowBMP(pac.x, pac.y, pacdieu[dii]);
			else if (pac.stop == 3)
				iShowBMP(pac.x, pac.y, pacdieD[dii]);


			if (dii == 72)
			{

				iPauseTimer(7);
				dii = 0;
				die = 0;
				restartLevel();
				diesound = false;
			}
		}
		else if (game.mode == 2)
		{
			iShowBMP(pac.x, pac.y, cookdie[dii]);

			if (dii == 59)
			{

				iPauseTimer(7);
				dii = 0;
				die = 0;
				restartLevel();
				diesound = false;
			}
		}
		else if (game.mode == 3)
		{
			iShowBMP(pac.x, pac.y, raidie[dii]);

			if (dii == 48)
			{

				iPauseTimer(7);
				dii = 0;
				die = 0;
				restartLevel();
				diesound = false;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////Ghosts draw/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

////////////////Red Ghost Creation////////////////////////
void drawRed()
{
	if (game.isPaused == 0 && ghost_isF == 0)
	{
		if (red.stop == 0)
		{

			if (red.state == 0)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redr1.bmp", 0);
				red.state = 2;
			}
			else if (red.state == 1)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redr2.bmp", 0);
				red.state = 0;
			}
			else if (red.state == 2)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redr1.bmp", 0);
				red.state = 4;
			}
			else if (red.state == 3)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redr2.bmp", 0);
				red.state = 1;
			}
			else if (red.state == 4)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redr1.bmp", 0);
				red.state = 5;
			}
			else if (red.state == 5)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redr2.bmp", 0);
				red.state = 3;
			}
		}
		else if (red.stop == 1)
		{
			if (start == 0)
			{
				if (red.state == 0)
				{
					iShowBMP2(red.x, red.y, "Pics\\Red\\redl1.bmp", 0);
					red.state = 2;
				}
				else if (red.state == 1)
				{
					iShowBMP2(red.x, red.y, "Pics\\Red\\redl2.bmp", 0);
					red.state = 0;
				}
				else if (red.state == 2)
				{
					iShowBMP2(red.x, red.y, "Pics\\Red\\redl1.bmp", 0);
					red.state = 4;
				}
				else if (red.state == 3)
				{
					iShowBMP2(red.x, red.y, "Pics\\Red\\redl2.bmp", 0);
					red.state = 1;
				}
				else if (red.state == 4)
				{
					iShowBMP2(red.x, red.y, "Pics\\Red\\redl1.bmp", 0);
					red.state = 5;
				}
				else if (red.state == 5)
				{
					iShowBMP2(red.x, red.y, "Pics\\Red\\redl2.bmp", 0);
					red.state = 3;
				}
			}
			else
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redl1.bmp", 0);
			}
		}
		else if (red.stop == 2)
		{
			if (red.state == 0)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redu1.bmp", 0);
				red.state = 2;
			}
			else if (red.state == 1)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redu2.bmp", 0);
				red.state = 0;
			}
			else if (red.state == 2)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redu1.bmp", 0);
				red.state = 4;
			}
			else if (red.state == 3)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redu2.bmp", 0);
				red.state = 1;
			}
			else if (red.state == 4)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redu1.bmp", 0);
				red.state = 5;
			}
			else if (red.state == 5)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redu2.bmp", 0);
				red.state = 3;
			}
		}
		else if (red.stop == 3)
		{
			if (red.state == 0)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redD1.bmp", 0);
				red.state = 2;
			}
			else if (red.state == 1)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redD2.bmp", 0);
				red.state = 0;
			}
			else if (red.state == 2)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redD1.bmp", 0);
				red.state = 4;
			}
			else if (red.state == 3)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redD2.bmp", 0);
				red.state = 1;
			}
			else if (red.state == 4)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redD1.bmp", 0);
				red.state = 5;
			}
			else if (red.state == 5)
			{
				iShowBMP2(red.x, red.y, "Pics\\Red\\redD2.bmp", 0);
				red.state = 3;
			}
		}
	}

}




///////////////////////Pink Ghost Creation///////////////////////////////////
void drawPink()
{
	if (game.isPaused == 0 && ghost_isF == 0)
	{
		if (pink.stop == 0)
		{
			if (start == 0)
			{
				if (pink.state == 0)
				{
					iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkr1.bmp", 0);
					pink.state = 2;
				}
				else if (pink.state == 1)
				{
					iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkr2.bmp", 0);
					pink.state = 0;
				}
				else if (pink.state == 2)
				{
					iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkr1.bmp", 0);
					pink.state = 4;
				}
				else if (pink.state == 3)
				{
					iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkr2.bmp", 0);
					pink.state = 1;
				}
				else if (pink.state == 4)
				{
					iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkr1.bmp", 0);
					pink.state = 5;
				}
				else if (pink.state == 5)
				{
					iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkr2.bmp", 0);
					pink.state = 3;
				}
			}
			else
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkr1.bmp", 0);
			}
		}
		else if (pink.stop == 1)
		{

			if (pink.state == 0)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkl1.bmp", 0);
				pink.state = 2;
			}
			else if (pink.state == 1)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkl2.bmp", 0);
				pink.state = 0;
			}
			else if (pink.state == 2)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkl1.bmp", 0);
				pink.state = 4;
			}
			else if (pink.state == 3)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkl2.bmp", 0);
				pink.state = 1;
			}
			else if (pink.state == 4)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkl1.bmp", 0);
				pink.state = 5;
			}
			else if (pink.state == 5)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkl2.bmp", 0);
				pink.state = 3;
			}

		}
		else if (pink.stop == 2)
		{
			if (pink.state == 0)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinku1.bmp", 0);
				pink.state = 2;
			}
			else if (pink.state == 1)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinku2.bmp", 0);
				pink.state = 0;
			}
			else if (pink.state == 2)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinku1.bmp", 0);
				pink.state = 4;
			}
			else if (pink.state == 3)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinku2.bmp", 0);
				pink.state = 1;
			}
			else if (pink.state == 4)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinku1.bmp", 0);
				pink.state = 5;
			}
			else if (pink.state == 5)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinku2.bmp", 0);
				pink.state = 3;
			}
		}
		else if (pink.stop == 3)
		{
			if (pink.state == 0)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkD1.bmp", 0);
				pink.state = 2;
			}
			else if (pink.state == 1)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkD2.bmp", 0);
				pink.state = 0;
			}
			else if (pink.state == 2)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkD1.bmp", 0);
				pink.state = 4;
			}
			else if (pink.state == 3)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkD2.bmp", 0);
				pink.state = 1;
			}
			else if (pink.state == 4)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkD1.bmp", 0);
				pink.state = 5;
			}
			else if (pink.state == 5)
			{
				iShowBMP2(pink.x, pink.y, "Pics\\pink\\pinkD2.bmp", 0);
				pink.state = 3;
			}
		}
	}

}

//////////////Blue Ghost Creation////////////////
void drawBlue()
{
	if (game.isPaused == 0 && ghost_isF == 0)
	{
		if (blue.stop == 0)
		{

			if (blue.state == 0)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluer1.bmp", 0);
				blue.state = 2;
			}
			else if (blue.state == 1)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluer2.bmp", 0);
				blue.state = 0;
			}
			else if (blue.state == 2)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluer1.bmp", 0);
				blue.state = 4;
			}
			else if (blue.state == 3)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluer2.bmp", 0);
				blue.state = 1;
			}
			else if (blue.state == 4)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluer1.bmp", 0);
				blue.state = 5;
			}
			else if (blue.state == 5)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluer2.bmp", 0);
				blue.state = 3;
			}

		}
		else if (blue.stop == 1)
		{
			if (start == 0)
			{
				if (blue.state == 0)
				{
					iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluel1.bmp", 0);
					blue.state = 2;
				}
				else if (blue.state == 1)
				{
					iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluel2.bmp", 0);
					blue.state = 0;
				}
				else if (blue.state == 2)
				{
					iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluel1.bmp", 0);
					blue.state = 4;
				}
				else if (blue.state == 3)
				{
					iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluel2.bmp", 0);
					blue.state = 1;
				}
				else if (blue.state == 4)
				{
					iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluel1.bmp", 0);
					blue.state = 5;
				}
				else if (blue.state == 5)
				{
					iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluel2.bmp", 0);
					blue.state = 3;
				}
			}
			else
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\bluel1.bmp", 0);
			}
		}
		else if (blue.stop == 2)
		{
			if (blue.state == 0)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueu1.bmp", 0);
				blue.state = 2;
			}
			else if (blue.state == 1)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueu2.bmp", 0);
				blue.state = 0;
			}
			else if (blue.state == 2)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueu1.bmp", 0);
				blue.state = 4;
			}
			else if (blue.state == 3)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueu2.bmp", 0);
				blue.state = 1;
			}
			else if (blue.state == 4)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueu1.bmp", 0);
				blue.state = 5;
			}
			else if (blue.state == 5)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueu2.bmp", 0);
				blue.state = 3;
			}
		}
		else if (blue.stop == 3)
		{
			if (blue.state == 0)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueD1.bmp", 0);
				blue.state = 2;
			}
			else if (blue.state == 1)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueD2.bmp", 0);
				blue.state = 0;
			}
			else if (blue.state == 2)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueD1.bmp", 0);
				blue.state = 4;
			}
			else if (blue.state == 3)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueD2.bmp", 0);
				blue.state = 1;
			}
			else if (blue.state == 4)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueD1.bmp", 0);
				blue.state = 5;
			}
			else if (blue.state == 5)
			{
				iShowBMP2(blue.x, blue.y, "Pics\\blue\\blueD2.bmp", 0);
				blue.state = 3;
			}
		}
	}

}

////////////////Frightened Ghost Creations////////////////////////////
void drawF1()
{
	if (game.isPaused == 0)
	{
		if (F1.color == 0)
		{
			if (game.mode == 1)
				iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FGB.bmp", 0);
			else if (game.mode == 2)
				iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FCB.bmp", 0);
			else if (game.mode == 3)
				iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FBB.bmp", 0);

		}
		else if (F1.color == 1)
		{
			if (F1.state == 0)
			{
				if (game.mode == 1)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FGB.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FCB.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FBB.bmp", 0);
				F1.state = 2;
			}
			else if (F1.state == 1)
			{
				if (game.mode == 1)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FGR.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FCR.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FBR.bmp", 0);
				F1.state = 0;
			}
			else if (F1.state == 2)
			{
				if (game.mode == 1)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FGB.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FCB.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FBB.bmp", 0);
				F1.state = 3;
			}
			else if (F1.state == 3)
			{
				if (game.mode == 1)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FGR.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FCR.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F1.x, F1.y, "Pics\\FGhost\\FBR.bmp", 0);
				F1.state = 1;
			}
		}
	}
}


void drawF2()
{
	if (game.isPaused == 0)
	{
		if (F2.color == 0)
		{
			if (game.mode == 1)
				iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FGB.bmp", 0);
			else if (game.mode == 2)
				iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FCB.bmp", 0);
			else if (game.mode == 3)
				iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FBB.bmp", 0);
		}
		else if (F2.color == 1)
		{
			if (F2.state == 0)
			{
				if (game.mode == 1)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FGB.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FCB.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FBB.bmp", 0);
				F2.state = 2;
			}
			else if (F2.state == 1)
			{
				if (game.mode == 1)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FGR.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FCR.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FBR.bmp", 0);
				F2.state = 0;
			}
			else if (F2.state == 2)
			{
				if (game.mode == 1)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FGB.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FCB.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FBB.bmp", 0);
				F2.state = 3;
			}
			else if (F2.state == 3)
			{
				if (game.mode == 1)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FGR.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FCR.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F2.x, F2.y, "Pics\\FGhost\\FBR.bmp", 0);
				F2.state = 1;
			}
		}
	}
}

void drawF3()
{
	if (game.isPaused == 0)
	{
		if (F3.color == 0)
		{
			if (game.mode == 1)
				iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FGB.bmp", 0);
			else if (game.mode == 2)
				iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FCB.bmp", 0);
			else if (game.mode == 3)
				iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FBB.bmp", 0);
		}
		else if (F3.color == 1)
		{
			if (F3.state == 0)
			{
				if (game.mode == 1)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FGB.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FCB.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FBB.bmp", 0);
				F3.state = 2;
			}
			else if (F3.state == 1)
			{
				if (game.mode == 1)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FGR.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FCR.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FBR.bmp", 0);
				F3.state = 0;
			}
			else if (F3.state == 2)
			{
				if (game.mode == 1)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FGB.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FCB.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FBB.bmp", 0);
				F3.state = 3;
			}
			else if (F3.state == 3)
			{
				if (game.mode == 1)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FGR.bmp", 0);
				else if (game.mode == 2)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FCR.bmp", 0);
				else if (game.mode == 3)
					iShowBMP2(F3.x, F3.y, "Pics\\FGhost\\FBR.bmp", 0);
				F3.state = 1;
			}
		}
	}
}




/////////////////////////Eaten Ghosts Creation///////////////////////
void drawE1()
{
	if (game.isPaused == 0)
	{
		if (E1.stop == 0)
		{
			iShowBMP2(E1.x, E1.y, "Pics\\FGhost\\eyes0.bmp", 0);
		}
		else if (E1.stop == 1)
		{
			iShowBMP2(E1.x, E1.y, "Pics\\FGhost\\eyes1.bmp", 0);
		}
		else if (E1.stop == 2)
		{
			iShowBMP2(E1.x, E1.y, "Pics\\FGhost\\eyes2.bmp", 0);
		}
		else if (E1.stop == 3)
		{
			iShowBMP2(E1.x, E1.y, "Pics\\FGhost\\eyes3.bmp", 0);
		}
	}
}

void drawE2()
{
	if (game.isPaused == 0)
	{
		if (E2.stop == 0)
		{
			iShowBMP2(E2.x, E2.y, "Pics\\FGhost\\eyes0.bmp", 0);
		}
		else if (E2.stop == 1)
		{
			iShowBMP2(E2.x, E2.y, "Pics\\FGhost\\eyes1.bmp", 0);
		}
		else if (E2.stop == 2)
		{
			iShowBMP2(E2.x, E2.y, "Pics\\FGhost\\eyes2.bmp", 0);
		}
		else if (E2.stop == 3)
		{
			iShowBMP2(E2.x, E2.y, "Pics\\FGhost\\eyes3.bmp", 0);
		}
	}
}

void drawE3()
{
	if (game.isPaused == 0)
	{
		if (E3.stop == 0)
		{
			iShowBMP2(E3.x, E3.y, "Pics\\FGhost\\eyes0.bmp", 0);
		}
		else if (E3.stop == 1)
		{
			iShowBMP2(E3.x, E3.y, "Pics\\FGhost\\eyes1.bmp", 0);
		}
		else if (E3.stop == 2)
		{
			iShowBMP2(E3.x, E3.y, "Pics\\FGhost\\eyes2.bmp", 0);
		}
		else if (E3.stop == 3)
		{
			iShowBMP2(E3.x, E3.y, "Pics\\FGhost\\eyes3.bmp", 0);
		}
	}
}





////////////////////////////////////////////////////////////////////////////Movement Functions///////////////////////////////////////////////////////////////////////////

////////////Pacman Movement/////////////////
void pac_move()
{
	if (pac.stop == 1)
	{
		if (pac.y % 40 == 0 && (maze[24 - (pac.y / 40)][pac.x / 40] != 1))
		{
			if (pac.x % 40 == 0 && (maze[24 - (pac.y / 40)][(pac.x / 40) - 1] != 1))
			{
				pac.x -= 10;
			}
			else if (pac.x % 40 != 0 && (maze[24 - (pac.y / 40)][pac.x / 40] != 1))
			{
				pac.x -= 10;
			}
			else if (pac.x % 40 == 0 && (maze[24 - (pac.y / 40)][(pac.x / 40)] == 2))
			{
				pac.x = 680;
			}

		}
	}
	else if (pac.stop == 0)
	{
		if (pac.y % 40 == 0 && (maze[24 - (pac.y / 40)][pac.x / 40] != 1) && (maze[24 - (pac.y / 40)][pac.x / 40 + 1] != 1))
		{
			pac.x += 10;

			if (pac.x % 40 == 0 && (maze[24 - (pac.y / 40)][(pac.x / 40)] == 2))
			{
				pac.x = 120;
			}
		}
	}
	else if (pac.stop == 2)
	{
		if (pac.x % 40 == 0 && maze[24 - (pac.y / 40)][pac.x / 40] != 1 && maze[23 - (pac.y / 40)][pac.x / 40] != 1)
		{
			pac.y += 10;
		}
	}
	else if (pac.stop == 3)
	{
		if (pac.x % 40 == 0 && maze[24 - (pac.y / 40)][pac.x / 40] != 1)
		{
			if (pac.y % 40 == 0 && maze[25 - (pac.y / 40)][pac.x / 40] != 1)
			{
				pac.y -= 10;
			}
			else if (pac.y % 40 != 0 && maze[24 - (pac.y / 40)][pac.x / 40] != 1)
			{
				pac.y -= 10;
			}
		}
	}
}

//////////////////////Ghost movement////////////////////


int dist(int a, int b, int c, int d)
{
	return (a - b)*(a - b) + (c - d)*(c - d);
}

int* shortest(int *a, int *b, int *c)
{
	if (*a <= *b && *a <= *c)
	{
		return a;
	}
	else if (*b <= *c)
	{
		return b;
	}
	else
	{
		return c;
	}
}





//////////////Combined Ghost Movement Function/////////////////////
void ghostmove()
{
	if (game.level >= 1)
	{
		redmove();
	}
	if (game.level >= 2)
	{
		pinkmove();
	}
	if (game.level >= 3)
	{
		bluemove();
	}
}

///////////////////Red Ghost//////////////////////
void redmove()
{
	if (currPage == 1 && start == 0)
	{
		if (red.scsmode == 0)
		{
			if (red.sc >= 87)
			{
				red.cs = 0;
				red.scsmode = 1;
				if (red.stop == 0)
				{
					red.stop = 1;
				}
				else if (red.stop == 1)
				{
					red.stop = 0;
				}
				else if (red.stop == 2)
				{
					red.stop = 3;
				}
				else if (red.stop == 3)
				{
					red.stop = 2;
				}
			}
			else
			{
				red.tx = 800, red.ty = 900;
			}
		}
		else if (red.scsmode == 1)
		{
			if (red.cs >= 250)
			{
				red.sc = 0;
				red.scsmode = 0;
				if (red.stop == 0)
				{
					red.stop = 1;
				}
				else if (red.stop == 1)
				{
					red.stop = 0;
				}
				else if (red.stop == 2)
				{
					red.stop = 3;
				}
				else if (red.stop == 3)
				{
					red.stop = 2;
				}
			}
			else
			{
				red.tx = pac.x, red.ty = pac.y;
			}
		}






		int uDist = dist(red.tx, red.x, red.ty, red.y + 40);

		int dDist = dist(red.tx, red.x, red.ty, red.y - 40);

		int rDist = dist(red.tx, red.x + 40, red.ty, red.y);

		int lDist = dist(red.tx, red.x - 40, red.ty, red.y);


		if (red.stop == 1)
		{
			if (red.y % 40 == 0 && (redm[24 - (red.y / 40)][red.x / 40] != 1))
			{
				if (red.x % 40 == 0 && (redm[24 - (red.y / 40)][(red.x / 40) - 1] != 1))
				{

					red.ud = 2000000, red.dd = 2000000, red.ld = 2000000, red.rd = 2000000;

					if (redm[23 - (red.y / 40)][red.x / 40] != 1)
					{
						red.ud = uDist;
					}
					if (redm[25 - (red.y / 40)][red.x / 40] != 1)
					{
						red.dd = dDist;
					}
					if (redm[24 - (red.y / 40)][(red.x / 40) - 1] != 1)
					{
						red.ld = lDist;
					}
					int *p = shortest(&red.ud, &red.ld, &red.dd);

					if (*p == red.ud)
					{
						red.stop = 2;

						red.y += 10;
					}
					else if (*p == red.ld)
					{
						red.stop = 1;

						red.x -= 10;
					}
					else if (*p == red.dd)
					{
						red.stop = 3;

						red.y -= 10;
					}

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}
				else if (red.x % 40 == 0 && (redm[24 - (red.y / 40)][(red.x / 40) - 1] == 1))
				{
					red.ud = 2000000, red.dd = 2000000, red.ld = 2000000, red.rd = 2000000;

					if (redm[23 - (red.y / 40)][red.x / 40] != 1)
					{
						red.ud = uDist;
					}
					if (redm[25 - (red.y / 40)][red.x / 40] != 1)
					{
						red.dd = dDist;
					}

					int *p = shortest(&red.ud, &red.ld, &red.dd);

					if (*p == red.ud)
					{
						red.stop = 2;

						red.y += 10;
					}
					else if (*p == red.dd)
					{
						red.stop = 3;

						red.y -= 10;
					}

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}

				else if (red.x % 40 != 0)
				{
					red.x -= 10;

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}

			}
		}

		else if (red.stop == 0)
		{
			if (red.y % 40 == 0 && (redm[24 - (red.y / 40)][red.x / 40] != 1))
			{
				if (red.x % 40 == 0)
				{
					red.ud = 2000000, red.dd = 2000000, red.ld = 2000000, red.rd = 2000000;

					if (redm[23 - (red.y / 40)][red.x / 40] != 1)
					{
						red.ud = uDist;
					}
					if (redm[25 - (red.y / 40)][red.x / 40] != 1)
					{
						red.dd = dDist;
					}
					if (redm[24 - (red.y / 40)][(red.x / 40) + 1] != 1)
					{
						red.rd = rDist;
					}
					int *p = shortest(&red.ud, &red.dd, &red.rd);

					if (*p == red.ud)
					{
						red.stop = 2;

						red.y += 10;
					}
					else if (*p == red.rd)
					{
						red.stop = 0;

						red.x += 10;
					}
					else if (*p == red.dd)
					{
						red.stop = 3;

						red.y -= 10;
					}

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}

				else if (red.x % 40 != 0)
				{
					red.x += 10;

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}

			}
		}

		else if (red.stop == 2)
		{
			if (red.x % 40 == 0 && (redm[24 - (red.y / 40)][red.x / 40] != 1))
			{
				if (red.y % 40 == 0)
				{
					red.ud = 2000000, red.dd = 2000000, red.ld = 2000000, red.rd = 2000000;

					if (redm[24 - (red.y / 40)][(red.x / 40) - 1] != 1)
					{
						red.ld = lDist;
					}
					if (redm[24 - (red.y / 40)][(red.x / 40) + 1] != 1)
					{
						red.rd = rDist;
					}
					if (redm[23 - (red.y / 40)][red.x / 40] != 1)
					{
						red.ud = uDist;
					}
					int *p = shortest(&red.ud, &red.ld, &red.rd);

					if (*p == red.ud)
					{
						red.stop = 2;

						red.y += 10;
					}
					else if (*p == red.rd)
					{
						red.stop = 0;

						red.x += 10;
					}
					else if (*p == red.ld)
					{
						red.stop = 1;

						red.x -= 10;
					}

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}

				}
				else if (red.y % 40 != 0)
				{
					red.y += 10;

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}

			}
		}

		else if (red.stop == 3)
		{
			if (red.x % 40 == 0 && (redm[24 - (red.y / 40)][red.x / 40] != 1))
			{
				if (red.y % 40 == 0 && redm[25 - (red.y / 40)][red.x / 40] != 1)
				{
					red.ud = 2000000, red.dd = 2000000, red.ld = 2000000, red.rd = 2000000;

					if (redm[24 - (red.y / 40)][(red.x / 40) - 1] != 1)
					{
						red.ld = lDist;
					}
					if (redm[24 - (red.y / 40)][(red.x / 40) + 1] != 1)
					{
						red.rd = rDist;
					}
					if (redm[25 - (red.y / 40)][red.x / 40] != 1)
					{
						red.dd = dDist;
					}
					int *p = shortest(&red.ld, &red.dd, &red.rd);

					if (*p == red.dd)
					{
						red.stop = 3;

						red.y -= 10;
					}
					else if (*p == red.rd)
					{
						red.stop = 0;

						red.x += 10;
					}
					else if (*p == red.ld)
					{
						red.stop = 1;

						red.x -= 10;
					}

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}

				else if (red.y % 40 == 0)
				{
					red.ud = 2000000, red.dd = 2000000, red.ld = 2000000, red.rd = 2000000;

					if (redm[24 - (red.y / 40)][(red.x / 40) - 1] != 1)
					{
						red.ld = lDist;
					}
					if (redm[24 - (red.y / 40)][(red.x / 40) + 1] != 1)
					{
						red.rd = rDist;
					}

					int *p = shortest(&red.ld, &red.dd, &red.rd);


					if (*p == red.rd)
					{
						red.stop = 0;

						red.x += 10;
					}
					else if (*p == red.ld)
					{
						red.stop = 1;

						red.x -= 10;
					}

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}

				else if (red.y % 40 != 0)
				{
					red.y -= 10;

					if (red.scsmode == 1)
					{
						red.cs++;
					}
					else if (red.scsmode == 0)
					{
						red.sc++;
					}
				}

			}
		}

	}


	F1.x = red.x, F1.y = red.y;

	if (red.stop == 0)
	{
		F1.stop = 1;
	}
	else if (red.stop == 1)
	{
		F1.stop = 0;
	}
	else if (red.stop == 2)
	{
		F1.stop = 3;
	}
	else if (red.stop == 3)
	{
		F1.stop = 2;
	}
}



//////////////////Pink Ghost////////////////////////////
void pinkmove()
{
	if (currPage == 1 && start == 0)
	{
		if (pink.scsmode == 0)
		{
			if (pink.sc >= 87)
			{
				pink.cs = 0;
				pink.scsmode = 1;
				if (pink.stop == 0)
				{
					pink.stop = 1;
				}
				else if (pink.stop == 1)
				{
					pink.stop = 0;
				}
				else if (pink.stop == 2)
				{
					pink.stop = 3;
				}
				else if (pink.stop == 3)
				{
					pink.stop = 2;
				}
			}
			else
			{
				pink.tx = 40, pink.ty = 900;
			}
		}
		else if (pink.scsmode == 1)
		{
			if (pink.cs >= 250)
			{
				pink.sc = 0;
				pink.scsmode = 0;
				if (pink.stop == 0)
				{
					pink.stop = 1;
				}
				else if (pink.stop == 1)
				{
					pink.stop = 0;
				}
				else if (pink.stop == 2)
				{
					pink.stop = 3;
				}
				else if (pink.stop == 3)
				{
					pink.stop = 2;
				}
			}
			else
			{
				if (pac.stop == 0)
				{
					pink.tx = pac.x + 80, pink.ty = pac.y;
				}
				else if (pac.stop == 1)
				{
					pink.tx = pac.x - 80, pink.ty = pac.y;
				}
				else if (pac.stop == 2)
				{
					pink.tx = pac.x, pink.ty = pac.y + 80;
				}
				else if (pac.stop == 3)
				{
					pink.tx = pac.x, pink.ty = pac.y - 80;
				}
			}
		}






		int uDist = dist(pink.tx, pink.x, pink.ty, pink.y + 40);

		int dDist = dist(pink.tx, pink.x, pink.ty, pink.y - 40);

		int rDist = dist(pink.tx, pink.x + 40, pink.ty, pink.y);

		int lDist = dist(pink.tx, pink.x - 40, pink.ty, pink.y);


		if (pink.stop == 1)
		{
			if (pink.y % 40 == 0 && (redm[24 - (pink.y / 40)][pink.x / 40] != 1))
			{
				if (pink.x % 40 == 0 && (redm[24 - (pink.y / 40)][(pink.x / 40) - 1] != 1))
				{

					pink.ud = 2000000, pink.dd = 2000000, pink.ld = 2000000, pink.rd = 2000000;

					if (redm[23 - (pink.y / 40)][pink.x / 40] != 1)
					{
						pink.ud = uDist;
					}
					if (redm[25 - (pink.y / 40)][pink.x / 40] != 1)
					{
						pink.dd = dDist;
					}
					if (redm[24 - (pink.y / 40)][(pink.x / 40) - 1] != 1)
					{
						pink.ld = lDist;
					}
					int *p = shortest(&pink.ud, &pink.ld, &pink.dd);

					if (*p == pink.ud)
					{
						pink.stop = 2;

						pink.y += 10;
					}
					else if (*p == pink.ld)
					{
						pink.stop = 1;

						pink.x -= 10;
					}
					else if (*p == pink.dd)
					{
						pink.stop = 3;

						pink.y -= 10;
					}

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}
				else if (pink.x % 40 == 0 && (redm[24 - (pink.y / 40)][(pink.x / 40) - 1] == 1))
				{
					pink.ud = 2000000, pink.dd = 2000000, pink.ld = 2000000, pink.rd = 2000000;

					if (redm[23 - (pink.y / 40)][pink.x / 40] != 1)
					{
						pink.ud = uDist;
					}
					if (redm[25 - (pink.y / 40)][pink.x / 40] != 1)
					{
						pink.dd = dDist;
					}

					int *p = shortest(&pink.ud, &pink.ld, &pink.dd);

					if (*p == pink.ud)
					{
						pink.stop = 2;

						pink.y += 10;
					}
					else if (*p == pink.dd)
					{
						pink.stop = 3;

						pink.y -= 10;
					}

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}

				else if (pink.x % 40 != 0)
				{
					pink.x -= 10;

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}

			}
		}

		else if (pink.stop == 0)
		{
			if (pink.y % 40 == 0 && (redm[24 - (pink.y / 40)][pink.x / 40] != 1))
			{
				if (pink.x % 40 == 0)
				{
					pink.ud = 2000000, pink.dd = 2000000, pink.ld = 2000000, pink.rd = 2000000;

					if (redm[23 - (pink.y / 40)][pink.x / 40] != 1)
					{
						pink.ud = uDist;
					}
					if (redm[25 - (pink.y / 40)][pink.x / 40] != 1)
					{
						pink.dd = dDist;
					}
					if (redm[24 - (pink.y / 40)][(pink.x / 40) + 1] != 1)
					{
						pink.rd = rDist;
					}
					int *p = shortest(&pink.ud, &pink.dd, &pink.rd);

					if (*p == pink.ud)
					{
						pink.stop = 2;

						pink.y += 10;
					}
					else if (*p == pink.rd)
					{
						pink.stop = 0;

						pink.x += 10;
					}
					else if (*p == pink.dd)
					{
						pink.stop = 3;

						pink.y -= 10;
					}

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}

				else if (pink.x % 40 != 0)
				{
					pink.x += 10;

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}

			}
		}

		else if (pink.stop == 2)
		{
			if (pink.x % 40 == 0 && (redm[24 - (pink.y / 40)][pink.x / 40] != 1))
			{
				if (pink.y % 40 == 0)
				{
					pink.ud = 2000000, pink.dd = 2000000, pink.ld = 2000000, pink.rd = 2000000;

					if (redm[24 - (pink.y / 40)][(pink.x / 40) - 1] != 1)
					{
						pink.ld = lDist;
					}
					if (redm[24 - (pink.y / 40)][(pink.x / 40) + 1] != 1)
					{
						pink.rd = rDist;
					}
					if (redm[23 - (pink.y / 40)][pink.x / 40] != 1)
					{
						pink.ud = uDist;
					}
					int *p = shortest(&pink.ud, &pink.ld, &pink.rd);

					if (*p == pink.ud)
					{
						pink.stop = 2;

						pink.y += 10;
					}
					else if (*p == pink.rd)
					{
						pink.stop = 0;

						pink.x += 10;
					}
					else if (*p == pink.ld)
					{
						pink.stop = 1;

						pink.x -= 10;
					}

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}

				}
				else if (pink.y % 40 != 0)
				{
					pink.y += 10;

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}

			}
		}

		else if (pink.stop == 3)
		{
			if (pink.x % 40 == 0 && (redm[24 - (pink.y / 40)][pink.x / 40] != 1))
			{
				if (pink.y % 40 == 0 && redm[25 - (pink.y / 40)][pink.x / 40] != 1)
				{
					pink.ud = 2000000, pink.dd = 2000000, pink.ld = 2000000, pink.rd = 2000000;

					if (redm[24 - (pink.y / 40)][(pink.x / 40) - 1] != 1)
					{
						pink.ld = lDist;
					}
					if (redm[24 - (pink.y / 40)][(pink.x / 40) + 1] != 1)
					{
						pink.rd = rDist;
					}
					if (redm[25 - (pink.y / 40)][pink.x / 40] != 1)
					{
						pink.dd = dDist;
					}
					int *p = shortest(&pink.ld, &pink.dd, &pink.rd);

					if (*p == pink.dd)
					{
						pink.stop = 3;

						pink.y -= 10;
					}
					else if (*p == pink.rd)
					{
						pink.stop = 0;

						pink.x += 10;
					}
					else if (*p == pink.ld)
					{
						pink.stop = 1;

						pink.x -= 10;
					}

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}

				else if (pink.y % 40 == 0)
				{
					pink.ud = 2000000, pink.dd = 2000000, pink.ld = 2000000, pink.rd = 2000000;

					if (redm[24 - (pink.y / 40)][(pink.x / 40) - 1] != 1)
					{
						pink.ld = lDist;
					}
					if (redm[24 - (pink.y / 40)][(pink.x / 40) + 1] != 1)
					{
						pink.rd = rDist;
					}

					int *p = shortest(&pink.ld, &pink.dd, &pink.rd);


					if (*p == pink.rd)
					{
						pink.stop = 0;

						pink.x += 10;
					}
					else if (*p == pink.ld)
					{
						pink.stop = 1;

						pink.x -= 10;
					}

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}

				else if (pink.y % 40 != 0)
				{
					pink.y -= 10;

					if (pink.scsmode == 1)
					{
						pink.cs++;
					}
					else if (pink.scsmode == 0)
					{
						pink.sc++;
					}
				}

			}
		}

	}


	F2.x = pink.x, F2.y = pink.y;

	if (pink.stop == 0)
	{
		F2.stop = 1;
	}
	else if (pink.stop == 1)
	{
		F2.stop = 0;
	}
	else if (pink.stop == 2)
	{
		F2.stop = 3;
	}
	else if (pink.stop == 3)
	{
		F2.stop = 2;
	}
}

////////////////////////Blue Ghost Creation//////////////////
void bluemove()
{
	if (currPage == 1 && start == 0)
	{
		if (blue.scsmode == 0)
		{
			if (blue.sc >= 87)
			{
				blue.cs = 0;
				blue.scsmode = 1;
				if (blue.stop == 0)
				{
					blue.stop = 1;
				}
				else if (blue.stop == 1)
				{
					blue.stop = 0;
				}
				else if (blue.stop == 2)
				{
					blue.stop = 3;
				}
				else if (blue.stop == 3)
				{
					blue.stop = 2;
				}
			}
			else
			{
				blue.tx = 40, blue.ty = 100;
			}
		}
		else if (blue.scsmode == 1)
		{
			if (blue.cs >= 250)
			{
				blue.sc = 0;
				blue.scsmode = 0;
				if (blue.stop == 0)
				{
					blue.stop = 1;
				}
				else if (blue.stop == 1)
				{
					blue.stop = 0;
				}
				else if (blue.stop == 2)
				{
					blue.stop = 3;
				}
				else if (blue.stop == 3)
				{
					blue.stop = 2;
				}
			}
			else
			{
				blue.tx = (2 * pac.x) - red.x, blue.ty = (2 * pac.y) - red.y;
			}
		}






		int uDist = dist(blue.tx, blue.x, blue.ty, blue.y + 40);

		int dDist = dist(blue.tx, blue.x, blue.ty, blue.y - 40);

		int rDist = dist(blue.tx, blue.x + 40, blue.ty, blue.y);

		int lDist = dist(blue.tx, blue.x - 40, blue.ty, blue.y);


		if (blue.stop == 1)
		{
			if (blue.y % 40 == 0 && (redm[24 - (blue.y / 40)][blue.x / 40] != 1))
			{
				if (blue.x % 40 == 0 && (redm[24 - (blue.y / 40)][(blue.x / 40) - 1] != 1))
				{

					blue.ud = 2000000, blue.dd = 2000000, blue.ld = 2000000, blue.rd = 2000000;

					if (redm[23 - (blue.y / 40)][blue.x / 40] != 1)
					{
						blue.ud = uDist;
					}
					if (redm[25 - (blue.y / 40)][blue.x / 40] != 1)
					{
						blue.dd = dDist;
					}
					if (redm[24 - (blue.y / 40)][(blue.x / 40) - 1] != 1)
					{
						blue.ld = lDist;
					}
					int *p = shortest(&blue.ud, &blue.ld, &blue.dd);

					if (*p == blue.ud)
					{
						blue.stop = 2;

						blue.y += 10;
					}
					else if (*p == blue.ld)
					{
						blue.stop = 1;

						blue.x -= 10;
					}
					else if (*p == blue.dd)
					{
						blue.stop = 3;

						blue.y -= 10;
					}

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}
				else if (blue.x % 40 == 0 && (redm[24 - (blue.y / 40)][(blue.x / 40) - 1] == 1))
				{
					blue.ud = 2000000, blue.dd = 2000000, blue.ld = 2000000, blue.rd = 2000000;

					if (redm[23 - (blue.y / 40)][blue.x / 40] != 1)
					{
						blue.ud = uDist;
					}
					if (redm[25 - (blue.y / 40)][blue.x / 40] != 1)
					{
						blue.dd = dDist;
					}

					int *p = shortest(&blue.ud, &blue.ld, &blue.dd);

					if (*p == blue.ud)
					{
						blue.stop = 2;

						blue.y += 10;
					}
					else if (*p == blue.dd)
					{
						blue.stop = 3;

						blue.y -= 10;
					}

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}

				else if (blue.x % 40 != 0)
				{
					blue.x -= 10;

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}

			}
		}

		else if (blue.stop == 0)
		{
			if (blue.y % 40 == 0 && (redm[24 - (blue.y / 40)][blue.x / 40] != 1))
			{
				if (blue.x % 40 == 0)
				{
					blue.ud = 2000000, blue.dd = 2000000, blue.ld = 2000000, blue.rd = 2000000;

					if (redm[23 - (blue.y / 40)][blue.x / 40] != 1)
					{
						blue.ud = uDist;
					}
					if (redm[25 - (blue.y / 40)][blue.x / 40] != 1)
					{
						blue.dd = dDist;
					}
					if (redm[24 - (blue.y / 40)][(blue.x / 40) + 1] != 1)
					{
						blue.rd = rDist;
					}
					int *p = shortest(&blue.ud, &blue.dd, &blue.rd);

					if (*p == blue.ud)
					{
						blue.stop = 2;

						blue.y += 10;
					}
					else if (*p == blue.rd)
					{
						blue.stop = 0;

						blue.x += 10;
					}
					else if (*p == blue.dd)
					{
						blue.stop = 3;

						blue.y -= 10;
					}

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}

				else if (blue.x % 40 != 0)
				{
					blue.x += 10;

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}

			}
		}

		else if (blue.stop == 2)
		{
			if (blue.x % 40 == 0 && (redm[24 - (blue.y / 40)][blue.x / 40] != 1))
			{
				if (blue.y % 40 == 0)
				{
					blue.ud = 2000000, blue.dd = 2000000, blue.ld = 2000000, blue.rd = 2000000;

					if (redm[24 - (blue.y / 40)][(blue.x / 40) - 1] != 1)
					{
						blue.ld = lDist;
					}
					if (redm[24 - (blue.y / 40)][(blue.x / 40) + 1] != 1)
					{
						blue.rd = rDist;
					}
					if (redm[23 - (blue.y / 40)][blue.x / 40] != 1)
					{
						blue.ud = uDist;
					}
					int *p = shortest(&blue.ud, &blue.ld, &blue.rd);

					if (*p == blue.ud)
					{
						blue.stop = 2;

						blue.y += 10;
					}
					else if (*p == blue.rd)
					{
						blue.stop = 0;

						blue.x += 10;
					}
					else if (*p == blue.ld)
					{
						blue.stop = 1;

						blue.x -= 10;
					}

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}

				}
				else if (blue.y % 40 != 0)
				{
					blue.y += 10;

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}

			}
		}

		else if (blue.stop == 3)
		{
			if (blue.x % 40 == 0 && (redm[24 - (blue.y / 40)][blue.x / 40] != 1))
			{
				if (blue.y % 40 == 0 && redm[25 - (blue.y / 40)][blue.x / 40] != 1)
				{
					blue.ud = 2000000, blue.dd = 2000000, blue.ld = 2000000, blue.rd = 2000000;

					if (redm[24 - (blue.y / 40)][(blue.x / 40) - 1] != 1)
					{
						blue.ld = lDist;
					}
					if (redm[24 - (blue.y / 40)][(blue.x / 40) + 1] != 1)
					{
						blue.rd = rDist;
					}
					if (redm[25 - (blue.y / 40)][blue.x / 40] != 1)
					{
						blue.dd = dDist;
					}
					int *p = shortest(&blue.ld, &blue.dd, &blue.rd);

					if (*p == blue.dd)
					{
						blue.stop = 3;

						blue.y -= 10;
					}
					else if (*p == blue.rd)
					{
						blue.stop = 0;

						blue.x += 10;
					}
					else if (*p == blue.ld)
					{
						blue.stop = 1;

						blue.x -= 10;
					}

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}

				else if (blue.y % 40 == 0)
				{
					blue.ud = 2000000, blue.dd = 2000000, blue.ld = 2000000, blue.rd = 2000000;

					if (redm[24 - (blue.y / 40)][(blue.x / 40) - 1] != 1)
					{
						blue.ld = lDist;
					}
					if (redm[24 - (blue.y / 40)][(blue.x / 40) + 1] != 1)
					{
						blue.rd = rDist;
					}

					int *p = shortest(&blue.ld, &blue.dd, &blue.rd);


					if (*p == blue.rd)
					{
						blue.stop = 0;

						blue.x += 10;
					}
					else if (*p == blue.ld)
					{
						blue.stop = 1;

						blue.x -= 10;
					}

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}

				else if (blue.y % 40 != 0)
				{
					blue.y -= 10;

					if (blue.scsmode == 1)
					{
						blue.cs++;
					}
					else if (blue.scsmode == 0)
					{
						blue.sc++;
					}
				}

			}
		}

	}


	F3.x = blue.x, F3.y = blue.y;

	if (blue.stop == 0)
	{
		F3.stop = 1;
	}
	else if (blue.stop == 1)
	{
		F3.stop = 0;
	}
	else if (blue.stop == 2)
	{
		F3.stop = 3;
	}
	else if (blue.stop == 3)
	{
		F3.stop = 2;
	}
}



/////////////////////////////////////Frightened Ghost Movement//////////////////////////////////

/////////////Combined FGhost function//////////////////////////
void Fmove()
{
	if (game.level >= 1)
	{
		if (F1.isDead == 0)
		{
			F1move();
		}

	}
	if (game.level >= 2)
	{
		if (F2.isDead == 0)
		{
			F2move();
		}
	}
	if (game.level >= 3)
	{
		if (F3.isDead == 0)
		{
			F3move();
		}
	}
}

void F1move()
{
	if (currPage == 1 && start == 0)
	{
		if (F1.crmode == 0)
		{
			if (F1.cr >= 50)
			{
				F1.color = 1;

				F1.crmode = 1;
			}
		}
		else if (F1.crmode == 1)
		{
			if (F1.rc >= 25)
			{

				red.x = F1.x + (F1.x % 10), red.y = F1.y + (F1.y % 10);

				red.stop = F1.stop;

				red.ud = 20000000, red.dd = 20000000, red.ld = 20000000, red.rd = 20000000;
				red.scsmode = 0, red.cs = 0, red.sc = 0;


				F1.crmode = 0, F1.cr = 0, F1.rc = 0;
				F1.color = 0, F1.state = 0;

				red.isF = 0;

				if (game.level == 1)
				{
					ghost_isF = 0;

					playMusic();
				}
				else if (game.level == 2)
				{
					if (pink.isF == 0)
					{
						ghost_isF = 0;

						playMusic();
					}
				}
				else if (game.level == 3)
				{
					if (pink.isF == 0 && blue.isF == 0)
					{
						ghost_isF = 0;

						playMusic();
					}
				}
			}
		}


		if (F1.stop == 1)
		{

			if (F1.y % 40 == 0 && (fm[24 - (F1.y / 40)][F1.x / 40] != 1))
			{

				if (F1.x % 40 == 0 && (fm[24 - (F1.y / 40)][(F1.x / 40) - 1] != 1))
				{

					F1.ud = 5; F1.dd = 5; F1.ld = 5; F1.rd = 5;
					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[23 - (F1.y / 40)][F1.x / 40] != 1)
					{
						F1.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F1.y / 40)][F1.x / 40] != 1)
					{
						F1.dd = 3;

						dc = 5;
					}
					if (fm[24 - (F1.y / 40)][(F1.x / 40) - 1] != 1)
					{
						F1.ld = 1;

						lc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 1) + 1;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F1.dd)
					{
						F1.stop = 3;

						F1.y -= 5;
					}
					else if (r >= F1.ud)
					{
						F1.stop = 2;

						F1.y += 5;
					}
					else if (r >= F1.ld)
					{
						F1.stop = 1;

						F1.x -= 5;
					}



					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}

				}
				else if (F1.x % 40 == 0 && (fm[24 - (F1.y / 40)][(F1.x / 40) - 1] == 1))
				{
					F1.ud = 5; F1.dd = 5; F1.ld = 5; F1.rd = 5;
					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[23 - (F1.y / 40)][F1.x / 40] != 1)
					{
						F1.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F1.y / 40)][F1.x / 40] != 1)
					{
						F1.dd = 3;

						dc = 5;
					}

					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 2) + 2;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F1.dd)
					{
						F1.stop = 3;

						F1.y -= 5;
					}
					else if (r >= F1.ud)
					{
						F1.stop = 2;

						F1.y += 5;
					}

					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}

				}
				else if (F1.x % 40 == 0 && (fm[24 - (F1.y / 40)][(F1.x / 40)] == 4))
				{
					F1.stop = 0;
				}
				else if (fm[24 - (F1.y / 40)][(F1.x / 40)] == 3)
				{
					F1.x -= 5;
				}
				else if (F1.x % 40 != 0)
				{
					F1.x -= 5;

					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}
				}

			}
		}

		else if (F1.stop == 0)
		{
			if (F1.y % 40 == 0 && (fm[24 - (F1.y / 40)][F1.x / 40] != 1))
			{
				if (F1.x % 40 == 0)
				{
					F1.ud = 5; F1.dd = 5; F1.ld = 5; F1.rd = 5;

					int lc = 1, rc = 0, uc = 2, dc = 3;

					if (fm[23 - (F1.y / 40)][F1.x / 40] != 1)
					{
						F1.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F1.y / 40)][F1.x / 40] != 1)
					{
						F1.dd = 3;

						dc = 5;
					}
					if (fm[24 - (F1.y / 40)][(F1.x / 40) + 1] != 1)
					{
						F1.rd = 0;

						rc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 0) + 0;

					} while (r == 1 || r == lc || r == rc || r == uc || r == dc);

					if (r >= F1.dd)
					{
						F1.stop = 3;

						F1.y -= 5;
					}
					else if (r >= F1.ud)
					{
						F1.stop = 2;

						F1.y += 5;
					}
					else if (r >= F1.rd)
					{
						F1.stop = 0;

						F1.x += 5;
					}

					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}
				}
				else if (F1.x % 40 == 0 && (fm[24 - (F1.y / 40)][(F1.x / 40)] == 3))
				{
					F1.stop = 1;
				}
				else if (fm[24 - (F1.y / 40)][(F1.x / 40)] == 4)
				{
					F1.x += 5;
				}
				else if (F1.x % 40 != 0)
				{
					F1.x += 5;

					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}
				}

			}
		}

		else if (F1.stop == 2)
		{

			if (F1.x % 40 == 0 && (fm[24 - (F1.y / 40)][F1.x / 40] != 1))
			{
				if (F1.y % 40 == 0)
				{


					F1.ud = 5, F1.dd = 5, F1.ld = 5, F1.rd = 5;

					int lc = 1, rc = 0, uc = 2, dc = 3;

					if (fm[24 - (F1.y / 40)][(F1.x / 40) - 1] != 1)
					{
						F1.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F1.y / 40)][(F1.x / 40) + 1] != 1)
					{
						F1.rd = 0;

						rc = 5;
					}
					if (fm[23 - (F1.y / 40)][F1.x / 40] != 1)
					{
						F1.ud = 2;

						uc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (3 - 0) + 0;

					} while (r == lc || r == rc || r == uc || r == dc);


					if (r >= F1.ud)
					{
						F1.stop = 2;

						F1.y += 5;
					}
					else if (r >= F1.ld)
					{
						F1.stop = 1;

						F1.x -= 5;
					}
					else if (r >= F1.rd)
					{
						F1.stop = 0;

						F1.x += 5;
					}

					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}

				}
				else if (F1.y % 40 != 0)
				{
					F1.y += 5;



					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}
				}

			}
		}

		else if (F1.stop == 3)
		{
			if (F1.x % 40 == 0 && (fm[24 - (F1.y / 40)][F1.x / 40] != 1))
			{
				if (F1.y % 40 == 0 && fm[25 - (F1.y / 40)][F1.x / 40] != 1)
				{
					F1.ud = 5, F1.dd = 5, F1.ld = 5, F1.rd = 5;

					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[24 - (F1.y / 40)][(F1.x / 40) - 1] != 1)
					{
						F1.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F1.y / 40)][(F1.x / 40) + 1] != 1)
					{
						F1.rd = 0;

						rc = 5;
					}
					if (fm[25 - (F1.y / 40)][F1.x / 40] != 1)
					{
						F1.dd = 3;

						dc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 0) + 0;

					} while (r == 2 || r == lc || r == rc || r == uc || r == dc);



					if (r >= F1.dd)
					{
						F1.stop = 3;

						F1.y -= 5;
					}
					else if (r >= F1.ld)
					{
						F1.stop = 1;

						F1.x -= 5;
					}
					else if (r >= F1.rd)
					{
						F1.stop = 0;

						F1.x += 5;
					}

					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}
				}

				else if (F1.y % 40 == 0 && fm[25 - (F1.y / 40)][F1.x / 40] == 1)
				{
					F1.ud = 5, F1.dd = 5, F1.ld = 5, F1.rd = 5;

					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[24 - (F1.y / 40)][(F1.x / 40) - 1] != 1)
					{
						F1.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F1.y / 40)][(F1.x / 40) + 1] != 1)
					{
						F1.rd = 0;

						rc = 5;
					}

					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (2 - 0) + 0;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F1.ld)
					{
						F1.stop = 1;

						F1.x -= 5;
					}
					else if (r >= F1.rd)
					{
						F1.stop = 0;

						F1.x += 5;
					}

					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}
				}

				else if (F1.y % 40 != 0)
				{
					F1.y -= 5;



					if (F1.crmode == 1)
					{
						F1.rc++;
					}
					else if (F1.crmode == 0)
					{
						F1.cr++;
					}
				}

			}
		}
	}

	E1.x = F1.x + (F1.x % 10), E1.y = F1.y + (F1.y % 10), E1.stop = F1.stop;

}



void F2move()
{
	if (currPage == 1 && start == 0)
	{
		if (F2.crmode == 0)
		{
			if (F2.cr >= 50)
			{
				F2.color = 1;

				F2.crmode = 1;
			}
		}
		else if (F2.crmode == 1)
		{
			if (F2.rc >= 25)
			{

				pink.x = F2.x + (F2.x % 10), pink.y = F2.y + (F2.y % 10);

				pink.stop = F2.stop;

				pink.ud = 20000000, pink.dd = 20000000, pink.ld = 20000000, pink.rd = 20000000;
				pink.scsmode = 0, pink.cs = 0, pink.sc = 0;


				F2.crmode = 0, F2.cr = 0, F2.rc = 0;
				F2.color = 0, F2.state = 0;

				pink.isF = 0;

				if (game.level == 2)
				{
					if (red.isF == 0)
					{
						ghost_isF = 0;

						playMusic();
					}
				}
				else if (game.level == 3)
				{
					if (red.isF == 0 && blue.isF == 0)
					{
						ghost_isF = 0;

						playMusic();
					}
				}
			}
		}








		if (F2.stop == 1)
		{

			if (F2.y % 40 == 0 && (fm[24 - (F2.y / 40)][F2.x / 40] != 1))
			{

				if (F2.x % 40 == 0 && (fm[24 - (F2.y / 40)][(F2.x / 40) - 1] != 1))
				{

					F2.ud = 5; F2.dd = 5; F2.ld = 5; F2.rd = 5;
					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[23 - (F2.y / 40)][F2.x / 40] != 1)
					{
						F2.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F2.y / 40)][F2.x / 40] != 1)
					{
						F2.dd = 3;

						dc = 5;
					}
					if (fm[24 - (F2.y / 40)][(F2.x / 40) - 1] != 1)
					{
						F2.ld = 1;

						lc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 1) + 1;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F2.dd)
					{
						F2.stop = 3;

						F2.y -= 5;
					}
					else if (r >= F2.ud)
					{
						F2.stop = 2;

						F2.y += 5;
					}
					else if (r >= F2.ld)
					{
						F2.stop = 1;

						F2.x -= 5;
					}



					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}

				}
				else if (F2.x % 40 == 0 && (fm[24 - (F2.y / 40)][(F2.x / 40) - 1] == 1))
				{
					F2.ud = 5; F2.dd = 5; F2.ld = 5; F2.rd = 5;
					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[23 - (F2.y / 40)][F2.x / 40] != 1)
					{
						F2.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F2.y / 40)][F2.x / 40] != 1)
					{
						F2.dd = 3;

						dc = 5;
					}

					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 2) + 2;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F2.dd)
					{
						F2.stop = 3;

						F2.y -= 5;
					}
					else if (r >= F2.ud)
					{
						F2.stop = 2;

						F2.y += 5;
					}

					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}

				}
				else if (F2.x % 40 == 0 && (fm[24 - (F2.y / 40)][(F2.x / 40)] == 4))
				{
					F2.stop = 0;
				}
				else if (fm[24 - (F2.y / 40)][(F2.x / 40)] == 3)
				{
					F2.x -= 5;
				}
				else if (F2.x % 40 != 0)
				{
					F2.x -= 5;

					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}
				}

			}
		}

		else if (F2.stop == 0)
		{
			if (F2.y % 40 == 0 && (fm[24 - (F2.y / 40)][F2.x / 40] != 1))
			{
				if (F2.x % 40 == 0)
				{
					F2.ud = 5; F2.dd = 5; F2.ld = 5; F2.rd = 5;

					int lc = 1, rc = 0, uc = 2, dc = 3;

					if (fm[23 - (F2.y / 40)][F2.x / 40] != 1)
					{
						F2.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F2.y / 40)][F2.x / 40] != 1)
					{
						F2.dd = 3;

						dc = 5;
					}
					if (fm[24 - (F2.y / 40)][(F2.x / 40) + 1] != 1)
					{
						F2.rd = 0;

						rc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 0) + 0;

					} while (r == 1 || r == lc || r == rc || r == uc || r == dc);

					if (r >= F2.dd)
					{
						F2.stop = 3;

						F2.y -= 5;
					}
					else if (r >= F2.ud)
					{
						F2.stop = 2;

						F2.y += 5;
					}
					else if (r >= F2.rd)
					{
						F2.stop = 0;

						F2.x += 5;
					}

					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}
				}
				else if (F2.x % 40 == 0 && (fm[24 - (F2.y / 40)][(F2.x / 40)] == 3))
				{
					F2.stop = 1;
				}
				else if (fm[24 - (F2.y / 40)][(F2.x / 40)] == 4)
				{
					F2.x += 5;
				}
				else if (F2.x % 40 != 0)
				{
					F2.x += 5;

					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}
				}

			}
		}

		else if (F2.stop == 2)
		{

			if (F2.x % 40 == 0 && (fm[24 - (F2.y / 40)][F2.x / 40] != 1))
			{
				if (F2.y % 40 == 0)
				{


					F2.ud = 5, F2.dd = 5, F2.ld = 5, F2.rd = 5;

					int lc = 1, rc = 0, uc = 2, dc = 3;

					if (fm[24 - (F2.y / 40)][(F2.x / 40) - 1] != 1)
					{
						F2.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F2.y / 40)][(F2.x / 40) + 1] != 1)
					{
						F2.rd = 0;

						rc = 5;
					}
					if (fm[23 - (F2.y / 40)][F2.x / 40] != 1)
					{
						F2.ud = 2;

						uc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (3 - 0) + 0;

					} while (r == lc || r == rc || r == uc || r == dc);


					if (r >= F2.ud)
					{
						F2.stop = 2;

						F2.y += 5;
					}
					else if (r >= F2.ld)
					{
						F2.stop = 1;

						F2.x -= 5;
					}
					else if (r >= F2.rd)
					{
						F2.stop = 0;

						F2.x += 5;
					}

					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}

				}
				else if (F2.y % 40 != 0)
				{
					F2.y += 5;



					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}
				}

			}
		}

		else if (F2.stop == 3)
		{
			if (F2.x % 40 == 0 && (fm[24 - (F2.y / 40)][F2.x / 40] != 1))
			{
				if (F2.y % 40 == 0 && fm[25 - (F2.y / 40)][F2.x / 40] != 1)
				{
					F2.ud = 5, F2.dd = 5, F2.ld = 5, F2.rd = 5;

					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[24 - (F2.y / 40)][(F2.x / 40) - 1] != 1)
					{
						F2.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F2.y / 40)][(F2.x / 40) + 1] != 1)
					{
						F2.rd = 0;

						rc = 5;
					}
					if (fm[25 - (F2.y / 40)][F2.x / 40] != 1)
					{
						F2.dd = 3;

						dc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 0) + 0;

					} while (r == 2 || r == lc || r == rc || r == uc || r == dc);



					if (r >= F2.dd)
					{
						F2.stop = 3;

						F2.y -= 5;
					}
					else if (r >= F2.ld)
					{
						F2.stop = 1;

						F2.x -= 5;
					}
					else if (r >= F2.rd)
					{
						F2.stop = 0;

						F2.x += 5;
					}

					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}
				}

				else if (F2.y % 40 == 0 && fm[25 - (F2.y / 40)][F2.x / 40] == 1)
				{
					F2.ud = 5, F2.dd = 5, F2.ld = 5, F2.rd = 5;

					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[24 - (F2.y / 40)][(F2.x / 40) - 1] != 1)
					{
						F2.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F2.y / 40)][(F2.x / 40) + 1] != 1)
					{
						F2.rd = 0;

						rc = 5;
					}

					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (2 - 0) + 0;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F2.ld)
					{
						F2.stop = 1;

						F2.x -= 5;
					}
					else if (r >= F2.rd)
					{
						F2.stop = 0;

						F2.x += 5;
					}

					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}
				}

				else if (F2.y % 40 != 0)
				{
					F2.y -= 5;



					if (F2.crmode == 1)
					{
						F2.rc++;
					}
					else if (F2.crmode == 0)
					{
						F2.cr++;
					}
				}

			}
		}
	}

	E2.x = F2.x + (F2.x % 10), E2.y = F2.y + (F2.y % 10), E2.stop = F2.stop;

}


void F3move()
{
	if (currPage == 1 && start == 0)
	{
		if (F3.crmode == 0)
		{
			if (F3.cr >= 50)
			{
				F3.color = 1;

				F3.crmode = 1;
			}
		}
		else if (F3.crmode == 1)
		{
			if (F3.rc >= 25)
			{

				blue.x = F3.x + (F3.x % 10), blue.y = F3.y + (F3.y % 10);

				blue.stop = F3.stop;

				blue.ud = 20000000, blue.dd = 20000000, blue.ld = 20000000, blue.rd = 20000000;
				blue.scsmode = 0, blue.cs = 0, blue.sc = 0;


				F3.crmode = 0, F3.cr = 0, F3.rc = 0;
				F3.color = 0, F3.state = 0;

				blue.isF = 0;

				if (game.level == 3)
				{
					if (red.isF == 0 && pink.isF == 0)
					{
						ghost_isF = 0;

						playMusic();
					}
				}
			}
		}








		if (F3.stop == 1)
		{

			if (F3.y % 40 == 0 && (fm[24 - (F3.y / 40)][F3.x / 40] != 1))
			{

				if (F3.x % 40 == 0 && (fm[24 - (F3.y / 40)][(F3.x / 40) - 1] != 1))
				{

					F3.ud = 5; F3.dd = 5; F3.ld = 5; F3.rd = 5;
					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[23 - (F3.y / 40)][F3.x / 40] != 1)
					{
						F3.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F3.y / 40)][F3.x / 40] != 1)
					{
						F3.dd = 3;

						dc = 5;
					}
					if (fm[24 - (F3.y / 40)][(F3.x / 40) - 1] != 1)
					{
						F3.ld = 1;

						lc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 1) + 1;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F3.dd)
					{
						F3.stop = 3;

						F3.y -= 5;
					}
					else if (r >= F3.ud)
					{
						F3.stop = 2;

						F3.y += 5;
					}
					else if (r >= F3.ld)
					{
						F3.stop = 1;

						F3.x -= 5;
					}



					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}

				}
				else if (F3.x % 40 == 0 && (fm[24 - (F3.y / 40)][(F3.x / 40) - 1] == 1))
				{
					F3.ud = 5; F3.dd = 5; F3.ld = 5; F3.rd = 5;
					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[23 - (F3.y / 40)][F3.x / 40] != 1)
					{
						F3.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F3.y / 40)][F3.x / 40] != 1)
					{
						F3.dd = 3;

						dc = 5;
					}

					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 2) + 2;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F3.dd)
					{
						F3.stop = 3;

						F3.y -= 5;
					}
					else if (r >= F3.ud)
					{
						F3.stop = 2;

						F3.y += 5;
					}

					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}

				}
				else if (F3.x % 40 == 0 && (fm[24 - (F3.y / 40)][(F3.x / 40)] == 4))
				{
					F3.stop = 0;
				}
				else if (fm[24 - (F3.y / 40)][(F3.x / 40)] == 3)
				{
					F3.x -= 5;
				}
				else if (F3.x % 40 != 0)
				{
					F3.x -= 5;

					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}
				}

			}
		}

		else if (F3.stop == 0)
		{
			if (F3.y % 40 == 0 && (fm[24 - (F3.y / 40)][F3.x / 40] != 1))
			{
				if (F3.x % 40 == 0)
				{
					F3.ud = 5; F3.dd = 5; F3.ld = 5; F3.rd = 5;

					int lc = 1, rc = 0, uc = 2, dc = 3;

					if (fm[23 - (F3.y / 40)][F3.x / 40] != 1)
					{
						F3.ud = 2;

						uc = 5;
					}
					if (fm[25 - (F3.y / 40)][F3.x / 40] != 1)
					{
						F3.dd = 3;

						dc = 5;
					}
					if (fm[24 - (F3.y / 40)][(F3.x / 40) + 1] != 1)
					{
						F3.rd = 0;

						rc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 0) + 0;

					} while (r == 1 || r == lc || r == rc || r == uc || r == dc);

					if (r >= F3.dd)
					{
						F3.stop = 3;

						F3.y -= 5;
					}
					else if (r >= F3.ud)
					{
						F3.stop = 2;

						F3.y += 5;
					}
					else if (r >= F3.rd)
					{
						F3.stop = 0;

						F3.x += 5;
					}

					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}
				}
				else if (F3.x % 40 == 0 && (fm[24 - (F3.y / 40)][(F3.x / 40)] == 3))
				{
					F3.stop = 1;
				}
				else if (fm[24 - (F3.y / 40)][(F3.x / 40)] == 4)
				{
					F3.x += 5;
				}
				else if (F3.x % 40 != 0)
				{
					F3.x += 5;

					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}
				}

			}
		}

		else if (F3.stop == 2)
		{

			if (F3.x % 40 == 0 && (fm[24 - (F3.y / 40)][F3.x / 40] != 1))
			{
				if (F3.y % 40 == 0)
				{


					F3.ud = 5, F3.dd = 5, F3.ld = 5, F3.rd = 5;

					int lc = 1, rc = 0, uc = 2, dc = 3;

					if (fm[24 - (F3.y / 40)][(F3.x / 40) - 1] != 1)
					{
						F3.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F3.y / 40)][(F3.x / 40) + 1] != 1)
					{
						F3.rd = 0;

						rc = 5;
					}
					if (fm[23 - (F3.y / 40)][F3.x / 40] != 1)
					{
						F3.ud = 2;

						uc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (3 - 0) + 0;

					} while (r == lc || r == rc || r == uc || r == dc);


					if (r >= F3.ud)
					{
						F3.stop = 2;

						F3.y += 5;
					}
					else if (r >= F3.ld)
					{
						F3.stop = 1;

						F3.x -= 5;
					}
					else if (r >= F3.rd)
					{
						F3.stop = 0;

						F3.x += 5;
					}

					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}

				}
				else if (F3.y % 40 != 0)
				{
					F3.y += 5;



					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}
				}

			}
		}

		else if (F3.stop == 3)
		{
			if (F3.x % 40 == 0 && (fm[24 - (F3.y / 40)][F3.x / 40] != 1))
			{
				if (F3.y % 40 == 0 && fm[25 - (F3.y / 40)][F3.x / 40] != 1)
				{
					F3.ud = 5, F3.dd = 5, F3.ld = 5, F3.rd = 5;

					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[24 - (F3.y / 40)][(F3.x / 40) - 1] != 1)
					{
						F3.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F3.y / 40)][(F3.x / 40) + 1] != 1)
					{
						F3.rd = 0;

						rc = 5;
					}
					if (fm[25 - (F3.y / 40)][F3.x / 40] != 1)
					{
						F3.dd = 3;

						dc = 5;
					}
					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (4 - 0) + 0;

					} while (r == 2 || r == lc || r == rc || r == uc || r == dc);



					if (r >= F3.dd)
					{
						F3.stop = 3;

						F3.y -= 5;
					}
					else if (r >= F3.ld)
					{
						F3.stop = 1;

						F3.x -= 5;
					}
					else if (r >= F3.rd)
					{
						F3.stop = 0;

						F3.x += 5;
					}

					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}
				}

				else if (F3.y % 40 == 0 && fm[25 - (F3.y / 40)][F3.x / 40] == 1)
				{
					F3.ud = 5, F3.dd = 5, F3.ld = 5, F3.rd = 5;

					int lc = 1, dc = 3, uc = 2, rc = 0;

					if (fm[24 - (F3.y / 40)][(F3.x / 40) - 1] != 1)
					{
						F3.ld = 1;

						lc = 5;
					}
					if (fm[24 - (F3.y / 40)][(F3.x / 40) + 1] != 1)
					{
						F3.rd = 0;

						rc = 5;
					}

					int r;

					srand(time(NULL));

					do
					{
						r = rand() % (2 - 0) + 0;

					} while (r == lc || r == rc || r == uc || r == dc);

					if (r >= F3.ld)
					{
						F3.stop = 1;

						F3.x -= 5;
					}
					else if (r >= F3.rd)
					{
						F3.stop = 0;

						F3.x += 5;
					}

					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}
				}

				else if (F3.y % 40 != 0)
				{
					F3.y -= 5;



					if (F3.crmode == 1)
					{
						F3.rc++;
					}
					else if (F3.crmode == 0)
					{
						F3.cr++;
					}
				}

			}
		}
	}

	E3.x = F3.x + (F3.x % 10), E3.y = F3.y + (F3.y % 10), E3.stop = F3.stop;

}


////////////////////////////////////////Eaten Ghosts Movement//////////////////////////////////////


void Emove()
{

	if (game.level >= 1)
	{
		if (red.isF == 1)
		{
			E1move();
		}
	}
	if (game.level >= 2)
	{
		if (pink.isF == 1)
		{
			E2move();
		}
	}
	if (game.level >= 3)
	{
		if (blue.isF == 1)
		{
			E3move();
		}
	}

	if (game.level == 1)
	{
		if (red.isF == 0)
		{
			ghost_isF = 0;

			playMusic();
		}
	}
	else if (game.level == 2)
	{
		if (red.isF == 0 && pink.isF == 0)
		{
			ghost_isF = 0;

			playMusic();
		}
	}
	else if (game.level == 3)
	{
		if (red.isF == 0 && pink.isF == 0 && blue.isF == 0)
		{
			ghost_isF = 0;

			playMusic();
		}
	}
}



void E1move()
{
	if (E1.x == 400 && E1.y == 520)
	{
		red.x = 360, red.y = 560;
		red.stop = 1, red.state = 0;
		red.ud = 20000000, red.dd = 20000000, red.ld = 20000000, red.rd = 20000000;
		red.scsmode = 0, red.cs = 0, red.sc = 0;

		F1.isDead = 0;

		red.isF = 0;
	}


	if (currPage == 1 && start == 0)
	{
		E1.tx = 400, E1.ty = 520;


		int uDist = dist(E1.tx, E1.x, E1.ty, E1.y + 40);

		int dDist = dist(E1.tx, E1.x, E1.ty, E1.y - 40);

		int rDist = dist(E1.tx, E1.x + 40, E1.ty, E1.y);

		int lDist = dist(E1.tx, E1.x - 40, E1.ty, E1.y);


		if (E1.stop == 1)
		{
			if (E1.y % 40 == 0 && (em[24 - (E1.y / 40)][E1.x / 40] != 1))
			{
				if (E1.x % 40 == 0 && (em[24 - (E1.y / 40)][(E1.x / 40) - 1] != 1))
				{

					E1.ud = 2000000, E1.dd = 2000000, E1.ld = 2000000, E1.rd = 2000000;

					if (em[23 - (E1.y / 40)][E1.x / 40] != 1)
					{
						E1.ud = uDist;
					}
					if (em[25 - (E1.y / 40)][E1.x / 40] != 1)
					{
						E1.dd = dDist;
					}
					if (em[24 - (E1.y / 40)][(E1.x / 40) - 1] != 1)
					{
						E1.ld = lDist;
					}
					int *p = shortest(&E1.ud, &E1.ld, &E1.dd);

					if (*p == E1.ud)
					{
						E1.stop = 2;

						E1.y += 10;
					}
					else if (*p == E1.ld)
					{
						E1.stop = 1;

						E1.x -= 10;
					}
					else if (*p == E1.dd)
					{
						E1.stop = 3;

						E1.y -= 10;
					}


				}
				else if (E1.x % 40 == 0 && (em[24 - (E1.y / 40)][(E1.x / 40) - 1] == 1))
				{
					E1.ud = 2000000, E1.dd = 2000000, E1.ld = 2000000, E1.rd = 2000000;

					if (em[23 - (E1.y / 40)][E1.x / 40] != 1)
					{
						E1.ud = uDist;
					}
					if (em[25 - (E1.y / 40)][E1.x / 40] != 1)
					{
						E1.dd = dDist;
					}

					int *p = shortest(&E1.ud, &E1.ld, &E1.dd);

					if (*p == E1.ud)
					{
						E1.stop = 2;

						E1.y += 10;
					}
					else if (*p == E1.dd)
					{
						E1.stop = 3;

						E1.y -= 10;
					}


				}

				else if (E1.x % 40 != 0)
				{
					E1.x -= 10;


				}

			}
		}

		else if (E1.stop == 0)
		{
			if (E1.y % 40 == 0 && (em[24 - (E1.y / 40)][E1.x / 40] != 1))
			{
				if (E1.x % 40 == 0)
				{
					E1.ud = 2000000, E1.dd = 2000000, E1.ld = 2000000, E1.rd = 2000000;

					if (em[23 - (E1.y / 40)][E1.x / 40] != 1)
					{
						E1.ud = uDist;
					}
					if (em[25 - (E1.y / 40)][E1.x / 40] != 1)
					{
						E1.dd = dDist;
					}
					if (em[24 - (E1.y / 40)][(E1.x / 40) + 1] != 1)
					{
						E1.rd = rDist;
					}
					int *p = shortest(&E1.ud, &E1.dd, &E1.rd);

					if (*p == E1.ud)
					{
						E1.stop = 2;

						E1.y += 10;
					}
					else if (*p == E1.rd)
					{
						E1.stop = 0;

						E1.x += 10;
					}
					else if (*p == E1.dd)
					{
						E1.stop = 3;

						E1.y -= 10;
					}


				}

				else if (E1.x % 40 != 0)
				{
					E1.x += 10;


				}

			}
		}

		else if (E1.stop == 2)
		{
			if (E1.x % 40 == 0 && (em[24 - (E1.y / 40)][E1.x / 40] != 1))
			{
				if (E1.y % 40 == 0)
				{
					E1.ud = 2000000, E1.dd = 2000000, E1.ld = 2000000, E1.rd = 2000000;

					if (em[24 - (E1.y / 40)][(E1.x / 40) - 1] != 1)
					{
						E1.ld = lDist;
					}
					if (em[24 - (E1.y / 40)][(E1.x / 40) + 1] != 1)
					{
						E1.rd = rDist;
					}
					if (em[23 - (E1.y / 40)][E1.x / 40] != 1)
					{
						E1.ud = uDist;
					}
					int *p = shortest(&E1.ud, &E1.ld, &E1.rd);

					if (*p == E1.ud)
					{
						E1.stop = 2;

						E1.y += 10;
					}
					else if (*p == E1.rd)
					{
						E1.stop = 0;

						E1.x += 10;
					}
					else if (*p == E1.ld)
					{
						E1.stop = 1;

						E1.x -= 10;
					}



				}
				else if (E1.y % 40 != 0)
				{
					E1.y += 10;


				}

			}
		}

		else if (E1.stop == 3)
		{
			if (E1.x % 40 == 0 && (em[24 - (E1.y / 40)][E1.x / 40] != 1))
			{
				if (E1.y % 40 == 0 && em[25 - (E1.y / 40)][E1.x / 40] != 1)
				{
					E1.ud = 2000000, E1.dd = 2000000, E1.ld = 2000000, E1.rd = 2000000;

					if (em[24 - (E1.y / 40)][(E1.x / 40) - 1] != 1)
					{
						E1.ld = lDist;
					}
					if (em[24 - (E1.y / 40)][(E1.x / 40) + 1] != 1)
					{
						E1.rd = rDist;
					}
					if (em[25 - (E1.y / 40)][E1.x / 40] != 1)
					{
						E1.dd = dDist;
					}
					int *p = shortest(&E1.ld, &E1.dd, &E1.rd);

					if (*p == E1.dd)
					{
						E1.stop = 3;

						E1.y -= 10;
					}
					else if (*p == E1.rd)
					{
						E1.stop = 0;

						E1.x += 10;
					}
					else if (*p == E1.ld)
					{
						E1.stop = 1;

						E1.x -= 10;
					}


				}

				else if (E1.y % 40 == 0)
				{
					E1.ud = 2000000, E1.dd = 2000000, E1.ld = 2000000, E1.rd = 2000000;

					if (em[24 - (E1.y / 40)][(E1.x / 40) - 1] != 1)
					{
						E1.ld = lDist;
					}
					if (em[24 - (E1.y / 40)][(E1.x / 40) + 1] != 1)
					{
						E1.rd = rDist;
					}

					int *p = shortest(&E1.ld, &E1.dd, &E1.rd);


					if (*p == E1.rd)
					{
						E1.stop = 0;

						E1.x += 10;
					}
					else if (*p == E1.ld)
					{
						E1.stop = 1;

						E1.x -= 10;
					}


				}

				else if (E1.y % 40 != 0)
				{
					E1.y -= 10;


				}

			}
		}
	}
}

void E2move()
{
	if (E2.x == 400 && E2.y == 520)
	{
		pink.x = 440, pink.y = 560;
		pink.stop = 0, pink.state = 0;
		pink.ud = 20000000, pink.dd = 20000000, pink.ld = 20000000, pink.rd = 20000000;
		pink.scsmode = 0, pink.cs = 0, pink.sc = 0;

		F2.isDead = 0;

		pink.isF = 0;
	}


	if (currPage == 1 && start == 0)
	{
		E2.tx = 400, E2.ty = 520;


		int uDist = dist(E2.tx, E2.x, E2.ty, E2.y + 40);

		int dDist = dist(E2.tx, E2.x, E2.ty, E2.y - 40);

		int rDist = dist(E2.tx, E2.x + 40, E2.ty, E2.y);

		int lDist = dist(E2.tx, E2.x - 40, E2.ty, E2.y);


		if (E2.stop == 1)
		{
			if (E2.y % 40 == 0 && (em[24 - (E2.y / 40)][E2.x / 40] != 1))
			{
				if (E2.x % 40 == 0 && (em[24 - (E2.y / 40)][(E2.x / 40) - 1] != 1))
				{

					E2.ud = 2000000, E2.dd = 2000000, E2.ld = 2000000, E2.rd = 2000000;

					if (em[23 - (E2.y / 40)][E2.x / 40] != 1)
					{
						E2.ud = uDist;
					}
					if (em[25 - (E2.y / 40)][E2.x / 40] != 1)
					{
						E2.dd = dDist;
					}
					if (em[24 - (E2.y / 40)][(E2.x / 40) - 1] != 1)
					{
						E2.ld = lDist;
					}
					int *p = shortest(&E2.ud, &E2.ld, &E2.dd);

					if (*p == E2.ud)
					{
						E2.stop = 2;

						E2.y += 10;
					}
					else if (*p == E2.ld)
					{
						E2.stop = 1;

						E2.x -= 10;
					}
					else if (*p == E2.dd)
					{
						E2.stop = 3;

						E2.y -= 10;
					}


				}
				else if (E2.x % 40 == 0 && (em[24 - (E2.y / 40)][(E2.x / 40) - 1] == 1))
				{
					E2.ud = 2000000, E2.dd = 2000000, E2.ld = 2000000, E2.rd = 2000000;

					if (em[23 - (E2.y / 40)][E2.x / 40] != 1)
					{
						E2.ud = uDist;
					}
					if (em[25 - (E2.y / 40)][E2.x / 40] != 1)
					{
						E2.dd = dDist;
					}

					int *p = shortest(&E2.ud, &E2.ld, &E2.dd);

					if (*p == E2.ud)
					{
						E2.stop = 2;

						E2.y += 10;
					}
					else if (*p == E2.dd)
					{
						E2.stop = 3;

						E2.y -= 10;
					}


				}

				else if (E2.x % 40 != 0)
				{
					E2.x -= 10;


				}

			}
		}

		else if (E2.stop == 0)
		{
			if (E2.y % 40 == 0 && (em[24 - (E2.y / 40)][E2.x / 40] != 1))
			{
				if (E2.x % 40 == 0)
				{
					E2.ud = 2000000, E2.dd = 2000000, E2.ld = 2000000, E2.rd = 2000000;

					if (em[23 - (E2.y / 40)][E2.x / 40] != 1)
					{
						E2.ud = uDist;
					}
					if (em[25 - (E2.y / 40)][E2.x / 40] != 1)
					{
						E2.dd = dDist;
					}
					if (em[24 - (E2.y / 40)][(E2.x / 40) + 1] != 1)
					{
						E2.rd = rDist;
					}
					int *p = shortest(&E2.ud, &E2.dd, &E2.rd);

					if (*p == E2.ud)
					{
						E2.stop = 2;

						E2.y += 10;
					}
					else if (*p == E2.rd)
					{
						E2.stop = 0;

						E2.x += 10;
					}
					else if (*p == E2.dd)
					{
						E2.stop = 3;

						E2.y -= 10;
					}


				}

				else if (E2.x % 40 != 0)
				{
					E2.x += 10;


				}

			}
		}

		else if (E2.stop == 2)
		{
			if (E2.x % 40 == 0 && (em[24 - (E2.y / 40)][E2.x / 40] != 1))
			{
				if (E2.y % 40 == 0)
				{
					E2.ud = 2000000, E2.dd = 2000000, E2.ld = 2000000, E2.rd = 2000000;

					if (em[24 - (E2.y / 40)][(E2.x / 40) - 1] != 1)
					{
						E2.ld = lDist;
					}
					if (em[24 - (E2.y / 40)][(E2.x / 40) + 1] != 1)
					{
						E2.rd = rDist;
					}
					if (em[23 - (E2.y / 40)][E2.x / 40] != 1)
					{
						E2.ud = uDist;
					}
					int *p = shortest(&E2.ud, &E2.ld, &E2.rd);

					if (*p == E2.ud)
					{
						E2.stop = 2;

						E2.y += 10;
					}
					else if (*p == E2.rd)
					{
						E2.stop = 0;

						E2.x += 10;
					}
					else if (*p == E2.ld)
					{
						E2.stop = 1;

						E2.x -= 10;
					}



				}
				else if (E2.y % 40 != 0)
				{
					E2.y += 10;


				}

			}
		}

		else if (E2.stop == 3)
		{
			if (E2.x % 40 == 0 && (em[24 - (E2.y / 40)][E2.x / 40] != 1))
			{
				if (E2.y % 40 == 0 && em[25 - (E2.y / 40)][E2.x / 40] != 1)
				{
					E2.ud = 2000000, E2.dd = 2000000, E2.ld = 2000000, E2.rd = 2000000;

					if (em[24 - (E2.y / 40)][(E2.x / 40) - 1] != 1)
					{
						E2.ld = lDist;
					}
					if (em[24 - (E2.y / 40)][(E2.x / 40) + 1] != 1)
					{
						E2.rd = rDist;
					}
					if (em[25 - (E2.y / 40)][E2.x / 40] != 1)
					{
						E2.dd = dDist;
					}
					int *p = shortest(&E2.ld, &E2.dd, &E2.rd);

					if (*p == E2.dd)
					{
						E2.stop = 3;

						E2.y -= 10;
					}
					else if (*p == E2.rd)
					{
						E2.stop = 0;

						E2.x += 10;
					}
					else if (*p == E2.ld)
					{
						E2.stop = 1;

						E2.x -= 10;
					}


				}

				else if (E2.y % 40 == 0)
				{
					E2.ud = 2000000, E2.dd = 2000000, E2.ld = 2000000, E2.rd = 2000000;

					if (em[24 - (E2.y / 40)][(E2.x / 40) - 1] != 1)
					{
						E2.ld = lDist;
					}
					if (em[24 - (E2.y / 40)][(E2.x / 40) + 1] != 1)
					{
						E2.rd = rDist;
					}

					int *p = shortest(&E2.ld, &E2.dd, &E2.rd);


					if (*p == E2.rd)
					{
						E2.stop = 0;

						E2.x += 10;
					}
					else if (*p == E2.ld)
					{
						E2.stop = 1;

						E2.x -= 10;
					}


				}

				else if (E2.y % 40 != 0)
				{
					E2.y -= 10;


				}

			}
		}
	}
}

void E3move()
{
	if (E3.x == 400 && E3.y == 520)
	{
		blue.x = 400, blue.y = 560;
		blue.stop = 1, blue.state = 0;
		blue.ud = 20000000, blue.dd = 20000000, blue.ld = 20000000, blue.rd = 20000000;
		blue.scsmode = 0, blue.cs = 0, blue.sc = 0;

		F3.isDead = 0;

		blue.isF = 0;
	}


	if (currPage == 1 && start == 0)
	{
		E3.tx = 400, E3.ty = 520;


		int uDist = dist(E3.tx, E3.x, E3.ty, E3.y + 40);

		int dDist = dist(E3.tx, E3.x, E3.ty, E3.y - 40);

		int rDist = dist(E3.tx, E3.x + 40, E3.ty, E3.y);

		int lDist = dist(E3.tx, E3.x - 40, E3.ty, E3.y);


		if (E3.stop == 1)
		{
			if (E3.y % 40 == 0 && (em[24 - (E3.y / 40)][E3.x / 40] != 1))
			{
				if (E3.x % 40 == 0 && (em[24 - (E3.y / 40)][(E3.x / 40) - 1] != 1))
				{

					E3.ud = 2000000, E3.dd = 2000000, E3.ld = 2000000, E3.rd = 2000000;

					if (em[23 - (E3.y / 40)][E3.x / 40] != 1)
					{
						E3.ud = uDist;
					}
					if (em[25 - (E3.y / 40)][E3.x / 40] != 1)
					{
						E3.dd = dDist;
					}
					if (em[24 - (E3.y / 40)][(E3.x / 40) - 1] != 1)
					{
						E3.ld = lDist;
					}
					int *p = shortest(&E3.ud, &E3.ld, &E3.dd);

					if (*p == E3.ud)
					{
						E3.stop = 2;

						E3.y += 10;
					}
					else if (*p == E3.ld)
					{
						E3.stop = 1;

						E3.x -= 10;
					}
					else if (*p == E3.dd)
					{
						E3.stop = 3;

						E3.y -= 10;
					}


				}
				else if (E3.x % 40 == 0 && (em[24 - (E3.y / 40)][(E3.x / 40) - 1] == 1))
				{
					E3.ud = 2000000, E3.dd = 2000000, E3.ld = 2000000, E3.rd = 2000000;

					if (em[23 - (E3.y / 40)][E3.x / 40] != 1)
					{
						E3.ud = uDist;
					}
					if (em[25 - (E3.y / 40)][E3.x / 40] != 1)
					{
						E3.dd = dDist;
					}

					int *p = shortest(&E3.ud, &E3.ld, &E3.dd);

					if (*p == E3.ud)
					{
						E3.stop = 2;

						E3.y += 10;
					}
					else if (*p == E3.dd)
					{
						E3.stop = 3;

						E3.y -= 10;
					}


				}

				else if (E3.x % 40 != 0)
				{
					E3.x -= 10;


				}

			}
		}

		else if (E3.stop == 0)
		{
			if (E3.y % 40 == 0 && (em[24 - (E3.y / 40)][E3.x / 40] != 1))
			{
				if (E3.x % 40 == 0)
				{
					E3.ud = 2000000, E3.dd = 2000000, E3.ld = 2000000, E3.rd = 2000000;

					if (em[23 - (E3.y / 40)][E3.x / 40] != 1)
					{
						E3.ud = uDist;
					}
					if (em[25 - (E3.y / 40)][E3.x / 40] != 1)
					{
						E3.dd = dDist;
					}
					if (em[24 - (E3.y / 40)][(E3.x / 40) + 1] != 1)
					{
						E3.rd = rDist;
					}
					int *p = shortest(&E3.ud, &E3.dd, &E3.rd);

					if (*p == E3.ud)
					{
						E3.stop = 2;

						E3.y += 10;
					}
					else if (*p == E3.rd)
					{
						E3.stop = 0;

						E3.x += 10;
					}
					else if (*p == E3.dd)
					{
						E3.stop = 3;

						E3.y -= 10;
					}


				}

				else if (E3.x % 40 != 0)
				{
					E3.x += 10;


				}

			}
		}

		else if (E3.stop == 2)
		{
			if (E3.x % 40 == 0 && (em[24 - (E3.y / 40)][E3.x / 40] != 1))
			{
				if (E3.y % 40 == 0)
				{
					E3.ud = 2000000, E3.dd = 2000000, E3.ld = 2000000, E3.rd = 2000000;

					if (em[24 - (E3.y / 40)][(E3.x / 40) - 1] != 1)
					{
						E3.ld = lDist;
					}
					if (em[24 - (E3.y / 40)][(E3.x / 40) + 1] != 1)
					{
						E3.rd = rDist;
					}
					if (em[23 - (E3.y / 40)][E3.x / 40] != 1)
					{
						E3.ud = uDist;
					}
					int *p = shortest(&E3.ud, &E3.ld, &E3.rd);

					if (*p == E3.ud)
					{
						E3.stop = 2;

						E3.y += 10;
					}
					else if (*p == E3.rd)
					{
						E3.stop = 0;

						E3.x += 10;
					}
					else if (*p == E3.ld)
					{
						E3.stop = 1;

						E3.x -= 10;
					}



				}
				else if (E3.y % 40 != 0)
				{
					E3.y += 10;


				}

			}
		}

		else if (E3.stop == 3)
		{
			if (E3.x % 40 == 0 && (em[24 - (E3.y / 40)][E3.x / 40] != 1))
			{
				if (E3.y % 40 == 0 && em[25 - (E3.y / 40)][E3.x / 40] != 1)
				{
					E3.ud = 2000000, E3.dd = 2000000, E3.ld = 2000000, E3.rd = 2000000;

					if (em[24 - (E3.y / 40)][(E3.x / 40) - 1] != 1)
					{
						E3.ld = lDist;
					}
					if (em[24 - (E3.y / 40)][(E3.x / 40) + 1] != 1)
					{
						E3.rd = rDist;
					}
					if (em[25 - (E3.y / 40)][E3.x / 40] != 1)
					{
						E3.dd = dDist;
					}
					int *p = shortest(&E3.ld, &E3.dd, &E3.rd);

					if (*p == E3.dd)
					{
						E3.stop = 3;

						E3.y -= 10;
					}
					else if (*p == E3.rd)
					{
						E3.stop = 0;

						E3.x += 10;
					}
					else if (*p == E3.ld)
					{
						E3.stop = 1;

						E3.x -= 10;
					}


				}

				else if (E3.y % 40 == 0)
				{
					E3.ud = 2000000, E3.dd = 2000000, E3.ld = 2000000, E3.rd = 2000000;

					if (em[24 - (E3.y / 40)][(E3.x / 40) - 1] != 1)
					{
						E3.ld = lDist;
					}
					if (em[24 - (E3.y / 40)][(E3.x / 40) + 1] != 1)
					{
						E3.rd = rDist;
					}

					int *p = shortest(&E3.ld, &E3.dd, &E3.rd);


					if (*p == E3.rd)
					{
						E3.stop = 0;

						E3.x += 10;
					}
					else if (*p == E3.ld)
					{
						E3.stop = 1;

						E3.x -= 10;
					}
				}

				else if (E3.y % 40 != 0)
				{
					E3.y -= 10;


				}

			}
		}
	}
}



/////////////////////////////////////////////////////Other Activities/////////////////////////////////////////////////////////////

///////////////Pellet Remove and Score Update///////////////////////
void rmpellet()
{
	if (pac.x % 40 == 0 && pac.y % 40 == 0 && pellets[24 - (pac.y / 40)][pac.x / 40] == 0)
	{
		pellets[24 - (pac.y / 40)][pac.x / 40] = 3;

		game.score += 10;

		pellet++;
	}
	if (pac.x % 40 == 0 && pac.y % 40 == 0 && pellets[24 - (pac.y / 40)][pac.x / 40] == 4)
	{
		pellets[24 - (pac.y / 40)][pac.x / 40] = 3;

		game.score += 50;

		pellet++;

		ghost_isF = 1;

		playMusic();

		if (game.level >= 1)
		{
			red.isF = 1;
		}
		if (game.level >= 2)
		{
			pink.isF = 1;
		}
		if (game.level >= 3)
		{
			blue.isF = 1;
		}

	}

	if (pellet == 162 && game.level < 3)
	{
		if (game.isLevelUp == 0)
		{
			pellet = 0;

			game.isLevelUp = 1;

			playMusic();

			game.level++;
		}



		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				pellets[i][j] = pelletscp[i][j];
			}
		}


	}
	else if (pellet == 162 && game.level == 3)
	{
		if (game.isWon == 0)
		{
			pellet = 0;

			game.isWon = 1;

			restartLevel();

			currPage = 11;

			playMusic();
		}
	}
	else if (game.isOver == 1)
	{
		game.isLevelUp = 0;

		game.level = 1;

		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				pellets[i][j] = pelletscp[i][j];
			}
		}
	}
	else if (game.isWon == 1)
	{
		game.isLevelUp = 0;

		game.level = 1;

		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				pellets[i][j] = pelletscp[i][j];
			}
		}
	}
	else if (pellet == 0)
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				pellets[i][j] = pelletscp[i][j];
			}
		}
	}

	if (game.isPlaying == 1)
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				pellets[i][j] = pelletscp[i][j];
			}
		}
	}
}


/////////////////////Display Score in-game///////////////////////////////
void showScore()
{
	char str[30] = { 0 };

	sprintf(str, "%i", game.score);

	char num[10][20] = { "Pics\\Numbers\\0.bmp", "Pics\\Numbers\\1.bmp", "Pics\\Numbers\\2.bmp", "Pics\\Numbers\\3.bmp", "Pics\\Numbers\\4.bmp",
		"Pics\\Numbers\\5.bmp", "Pics\\Numbers\\6.bmp", "Pics\\Numbers\\7.bmp", "Pics\\Numbers\\8.bmp", "Pics\\Numbers\\9.bmp" };

	if (game.score == 0)
	{
		iShowBMP2(500, 905, num[0], 0);
		iShowBMP2(540, 905, num[0], 0);
		iShowBMP2(580, 905, num[0], 0);
		iShowBMP2(620, 905, num[0], 0);
		iShowBMP2(660, 905, num[0], 0);
	}


	int a = game.score;

	int n4 = a / pow(10.0, 4);

	a = a % (int)pow(10.0, 4);

	iShowBMP2(500, 905, num[n4], 0);

	int n3 = a / pow(10.0, 3);

	a = a % (int)pow(10.0, 3);

	iShowBMP2(540, 905, num[n3], 0);

	int n2 = a / pow(10.0, 2);

	a = a % (int)pow(10.0, 2);

	iShowBMP2(580, 905, num[n2], 0);

	int n1 = a / pow(10.0, 1);

	a = a % (int)pow(10.0, 1);

	iShowBMP2(620, 905, num[n1], 0);

	int n0 = a;

	iShowBMP2(660, 905, num[n0], 0);
}


//////////////////Life depletion and Display////////////////////////
void lifeLoss()
{
	if (game.level >= 1)
	{
		if (red.isF == 0)
		{
			fcount = 0;

			if ((abs(pac.x - red.x) <= 30 && pac.y == red.y) || (pac.x == red.x && abs(pac.y - red.y) <= 30))
			{

				if (game.isPaused == 0)
				{
					game.life -= 1;

					game.isPaused = 1;
				}

				if (game.life == 0)
				{
					game.isOver = 1;

					restartLevel();

					currPage = 6;

					playMusic();
				}
			}
		}
		else if (red.isF == 1)
		{
			if ((abs(pac.x - F1.x) <= 35 && pac.y == F1.y) || (pac.x == F1.x && abs(pac.y - F1.y) <= 35))
			{
				if (F1.isDead == 0)
				{
					F1.crmode = 0, F1.cr = 0, F1.rc = 0;

					F1.state = 0, F1.color = 0;

					F1.isDead = 1;

					game.score += (200 * (fcount + 1));

					fcount++;
				}
			}
		}
	}
	if (game.level >= 2)
	{
		if (pink.isF == 0)
		{
			fcount = 0;

			if ((abs(pac.x - pink.x) <= 30 && pac.y == pink.y) || (pac.x == pink.x && abs(pac.y - pink.y) <= 30))
			{


				if (game.isPaused == 0)
				{
					game.life -= 1;

					game.isPaused = 1;
				}

				if (game.life == 0)
				{
					game.isOver = 1;

					writeScoreFile();

					restartLevel();

					currPage = 6;
				}
			}
		}
		else if (pink.isF == 1)
		{
			if ((abs(pac.x - F2.x) <= 35 && pac.y == F2.y) || (pac.x == F2.x && abs(pac.y - F2.y) <= 35))
			{
				if (F2.isDead == 0)
				{
					F2.crmode = 0, F2.cr = 0, F2.rc = 0;

					F2.state = 0, F2.color = 0;

					F2.isDead = 1;

					game.score += (200 * (fcount + 1));

					fcount++;
				}
			}
		}
	}
	if (game.level >= 3)
	{
		if (blue.isF == 0)
		{
			fcount = 0;

			if ((abs(pac.x - blue.x) <= 30 && pac.y == blue.y) || (pac.x == blue.x && abs(pac.y - blue.y) <= 30))
			{


				if (game.isPaused == 0)
				{
					game.life -= 1;

					game.isPaused = 1;
				}

				if (game.life == 0)
				{
					game.isOver = 1;

					writeScoreFile();

					restartLevel();

					currPage = 6;
				}
			}
		}
		else if (blue.isF == 1)
		{
			if ((abs(pac.x - F3.x) <= 35 && pac.y == F3.y) || (pac.x == F3.x && abs(pac.y - F3.y) <= 35))
			{
				if (F3.isDead == 0)
				{
					F3.crmode = 0, F3.cr = 0, F3.rc = 0;

					F3.state = 0, F3.color = 0;

					F3.isDead = 1;

					game.score += (200 * (fcount + 1));

					fcount++;
				}
			}
		}
	}
}


void showLives()
{
	for (int life = 0; life < game.life; life++)
	{
		if (game.mode == 1)
			iShowBMP2(220 - 40 * life, 60, "Pics\\Pac\\paclife.bmp", 0);
		else if (game.mode == 2)
			iShowBMP2(220 - 40 * life, 60, "Pics\\CM\\CMlife.bmp", 0);
		else if (game.mode == 3)
			iShowBMP2(220 - 40 * life, 50, "Pics\\Raiyan\\railife.bmp", 0);
	}
}


///////////////////Intro Video///////////////
void playIntro()
{
	iShowBMP(0, 0, Intro[introframe]);
	if (introframe == 417)
	{
		currPage = 0;
		playMusic();
		iPauseTimer(7);
		introframe = 0;
	}
}

void change()
{
	introframe++;

	if (die == 1)
	{
		dii++;
	}
}


////////////////////////////////////////////////////////////////////File Operations/////////////////////////////////////////////////////////////////////


//////////////////Score File/////////////////////
void readScoreFile()
{
	FILE* fp;

	fp = fopen("Files\\highscore.txt", "rb");

	if (fp == NULL)
	{
		printf("Cannot open file.\n");
		exit(0);
	}

	for (int i = 0; i < 10; i++)
	{
		fread(&high_score[i], sizeof(high_score[i]), 1, fp);
	}

	fclose(fp);
}

void writeScoreFile()
{
	if (game.isOver == 1 || game.isWon == 1)
	{
		high_score[10].score = game.score;
		game.score = 0;
		high_score[10].level = game.level;

		game.isPlaying = 1;
	}



	if (namedone == 1)
	{
		namedone = 0;



		for (int s = 0; s < 11; s++)
		{
			int m = s;

			for (int i = s + 1; i < 11; i++)
			{
				if (high_score[m].score < high_score[i].score)
				{
					m = i;
				}
			}

			temp = high_score[s];
			high_score[s] = high_score[m];
			high_score[m] = temp;
		}

		FILE* fpp;

		fpp = fopen("Files\\highscore.txt", "wb");

		if (fpp == NULL)
		{
			printf("Cannot open file.\n");
			exit(0);
		}

		for (int i = 0; i < 10; i++)
		{
			fwrite(&high_score[i], sizeof(high_score[i]), 1, fpp);
		}

		fclose(fpp);
	}

}



/////////////////////Savefile////////////////////////////////
void readSavefile()
{
	FILE* rsvf;

	rsvf = fopen("Files\\Savefile.txt", "rb");

	if (rsvf == NULL)
	{
		printf("Cannot open file.\n");
		exit(0);
	}

	fread(&game, sizeof(game), 1, rsvf);
	fread(&pac, sizeof(pac), 1, rsvf);
	fread(&red, sizeof(red), 1, rsvf);
	fread(&pink, sizeof(pink), 1, rsvf);
	fread(&blue, sizeof(blue), 1, rsvf);
	fread(&F1, sizeof(F1), 1, rsvf);
	fread(&F2, sizeof(F2), 1, rsvf);
	fread(&F3, sizeof(F2), 1, rsvf);
	fread(&E1, sizeof(E1), 1, rsvf);
	fread(&E2, sizeof(E2), 1, rsvf);
	fread(&E3, sizeof(E2), 1, rsvf);
	fread(&ghost_isF, sizeof(ghost_isF), 1, rsvf);
	fread(&pellet, sizeof(pellet), 1, rsvf);
	fread(&pellets, sizeof(pellets), 1, rsvf);


	fclose(rsvf);
}


void writeSavefile()
{
	FILE* svf;

	svf = fopen("Files\\Savefile.txt", "wb");

	if (svf == NULL)
	{
		printf("Cannot open file.\n");
		exit(0);
	}

	fwrite(&game, sizeof(game), 1, svf);
	fwrite(&pac, sizeof(pac), 1, svf);
	fwrite(&red, sizeof(red), 1, svf);
	fwrite(&pink, sizeof(pink), 1, svf);
	fwrite(&blue, sizeof(blue), 1, svf);
	fwrite(&F1, sizeof(F1), 1, svf);
	fwrite(&F2, sizeof(F2), 1, svf);
	fwrite(&F3, sizeof(F3), 1, svf);
	fwrite(&E1, sizeof(E1), 1, svf);
	fwrite(&E2, sizeof(E2), 1, svf);
	fwrite(&E3, sizeof(E3), 1, svf);
	fwrite(&ghost_isF, sizeof(ghost_isF), 1, svf);
	fwrite(&pellet, sizeof(pellet), 1, svf);
	fwrite(&pellets, sizeof(pellets), 1, svf);


	fclose(svf);
}



