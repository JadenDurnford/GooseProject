/*
gooseEscapeGamePlay.hpp
Jaden Durnford and Dennis Li
*/
#ifndef GOOSE_ESCAPE_GAMEPLAY
#define GOOSE_ESCAPE_GAMEPLAY
#include "gooseEscapeUtil.hpp"
#include "gooseEscapeActor.hpp"
#include "gooseEscapeConsole.hpp"

/*
    This file is all about the game world.  You will modify this to add
    constants and function prototypes.  Modify gooseGamePlay.cpp to
	actually add functionality.
*/

/*
    Declare constants to indicate various game world features in the board
    array.  Modify them to fit what you would like to do in the game.
*/
const int yTotal = 20;
const int xTotal = 70;
const int NUMBCOINS = 3;
// Going further:  Learn how to use an enum for these values
const int EMPTY = 0;
const int SHALL_NOT_PASS = 1;
const int WINNER = 2;
const int COIN = 3;
const int SPEED_BOOST = 4;
const int INVULNERABLE = 5;
/*
    A few examples of characters both for actors and for the game board itself
    are shown.
*/
//display characters
const int PLAYER_CHAR = int('@');
const int MONSTER_CHAR = int('G');
const int WALL_CHAR = int('o');
const int WIN_CHAR = int('%'); //% sign, a special character used in the ancient game "Rogue"
const int COIN_CHAR = int('$');
const int SPEED_BOOST_CHAR = int('>');
const int INVULNERABLE_CHAR = int('*');

/*
Colours have the format "brightness hue" or "hue", e.g. "white" "light green"
Values for brightness are: lightest, lighter, light, dark, darker, darkest
Hue may be specified in many ways, see http://foo.wyrd.name/en:bearlibterminal:reference
  hue names are: grey, gray, red, flame, orange, amber, yellow, lime, chartreuse
                 green, sea, turquoise, cyan, sky, azure, blue, han, violet,
                 purple, fushsia, magenta, pink, crimson, transparent
*/
/*
  Declare a character array with the colour name, the size is set based on the
  number of character used to initialize the array.
  
  DRAW_COLOUR is already defined as white.
*/

const char PLAYER_COLOUR[] = "light sky";
const char GOOSE_COLOUR[] = "yellow";
const char SPEED_COLOUR[] = "green";
const char INVULNERABLE_COLOUR[] = "pink";
/*
		Add coins to game world
*/
void addCoins(int gameBoard[yTotal][xTotal]);

/*
		Print the game world
*/
void printBoard(int gameBoard[yTotal][xTotal]);

/*
    Do something when the goose captures the player
*/
bool captured(Actor const & player, Actor const & monster);

/*
		Update coins collected
*/
void coinUpdate(int gameBoard[yTotal][xTotal], Actor & player, int & coinCount, int yMove, int xMove);


/*
	The user changes colour and moves 2 tiles at once
*/
void speedBoostHit(int gameBoard[yTotal][xTotal], Actor & player, int yMove, int xMove);


/*
	The user changes colour, moves 2 tiles at once, and can not die
*/
void invulnerableHit(int gameBoard[yTotal][xTotal], Actor & player, int yMove, int xMove);

/*
	Every turn, the remaining turns for the power ups are reduc
*/
void powerUpUpdate(Actor & player);

/*
    Move the player to a new location based on the user input
*/
void movePlayer(int key, Actor & player, int gameBoard[yTotal][xTotal], int & coinCount);

/*
    Move the goose to a new location based on where the player is
*/
void moveGoose(Actor & player, Actor & monster, int gameBoard[yTotal][xTotal]);

#endif
