#ifndef GAMEFUNC_H_INCLUDED
#define GAMEFUNC_H_INCLUDED

#include <stdio.h>

void startGame();
void restartLevel();
void PauseGame();




void playMusic();




void drawHome();
void drawMaze();
void drawPause();
void drawLearn();
void drawPoints();
void gameover();
void drawWin();
void drawCreds();
void drawMode();

void drawPellets();

void writeName(unsigned char key);
void drawName();
void drawLead();
void drawHScores();
void drawLead2();
void drawHScoresUpd();
void drawLead3();

void drawPac();
void drawRed();
void drawPink();
void drawBlue();

void drawF1();
void drawF2();
void drawF3();

void drawE1();
void drawE2();
void drawE3();




void pac_move();
void ghostmove();
void redmove();
void pinkmove();
void bluemove();

void Fmove();
void F1move();
void F2move();
void F3move();

void Emove();
void E1move();
void E2move();
void E3move();




void rmpellet();
void showScore();
void lifeLoss();
void showLives();




void readScoreFile();
void writeScoreFile();
void readSavefile();
void writeSavefile();




void playIntro();
void change();




typedef struct High_score {
    char name[30];
    int level;
    int score;
} High_score;
High_score high_score[11];
High_score temp;



typedef struct Ghost {
    int x;
    int y;
    int tx;
    int ty;
    int stop;
    int state;
    int ud, rd, ld, dd;
    int scsmode;
    int sc, cs;
    char isF;
} Ghost;
Ghost red, pink, blue;


typedef struct FGhost {
    int x;
    int y;
    int stop;
    int state;
    int color;
    int ud, rd, ld, dd;
    int cr, rc;
    int crmode;
    char isDead;
} FGhost;
FGhost F1, F2, F3;

typedef struct Ghost_eyes {
    int x;
    int y;
    int stop;
    int ud, rd, ld, dd;
    int tx;
    int ty;
    char isDead;
} Ghost_eyes;
Ghost_eyes E1, E2, E3;

typedef struct Pac_man {
    int x;
    int y;
    int stop;
    int state;
} Pac_man;
Pac_man pac;

typedef struct Game_state{
    char isPaused, isOver, isLevelUp, isWon, isPlaying;
    int score;
    int life;
    int level;
    char isLoad;
    int lvupstate;
    int mode;
    bool existsave;
} Game_state;
Game_state game = {0, 0, 0, 0, 1, 0, 3, 1, 0, 0, 1, false};



#endif // GAMEFUNC_H_INCLUDED
