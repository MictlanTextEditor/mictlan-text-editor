/*  ---------------------------------------------------------------------- 
 * |                                                                      |
 * | Mictlan is free software: you can redistribute it and/or modify      |
 * | it under the terms of the GNU General Public License as published by |
 * | the Free Software Foundation, either version 3 of the License, or    |
 * | (at your option) any later version.                                  |
 * |                                                                      |
 * | Mictlan is distributed in the hope that it will be useful,           |
 * | but WITHOUT ANY WARRANT; without even the implied warranty of        |
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         |
 * | GNU General Public License for more details.                         |
 * |                                                                      |
 *  ----------------------------------------------------------------------
 *
 * Last modification: 2021-06-05
 *
 * The Xolotl FOSS Project Team 2021
 *
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

/*Structure that contains the original attributes of the terminal*/
struct termios original_attr;

/*rawModeOn function prototype*/
void rawModeOn();

/*rawModeOff function prototype*/
void rawModeOff();

/*Turn down all necessesary flags to enter the raw mode*/
void rawModeOn() {
  tcgetattr(STDIN_FILENO, &original_attr);
  atexit(rawModeOff);

  struct termios raw = original_attr;
  raw.c_oflag &= ~OPOST;
  raw.c_lflag &= ~(ICANON);
  //raw.c_cc[VMIN] = 0;
  //raw.c_cc[VTIME] = 1;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/*Set terminal attributes as they are before execute the program*/
void rawModeOff() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_attr);
}
