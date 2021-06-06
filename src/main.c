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

#include <stdio.h>
#include "raw_mode.h"

int main() {

  /*Enter the raw mode*/
  rawModeOn();

  char c;
  while(read(STDIN_FILENO, &c, 1) == 1 && c != 'q');

  return 0;

}
