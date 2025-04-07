#pragma once
#include"cons.h"
void iniciarTablero(char tablero[BOARD_SIZE][BOARD_SIZE]);
void verTablero(char tablero[BOARD_SIZE][BOARD_SIZE]);
posicion obtenerPieza(char tablero[BOARD_SIZE][BOARD_SIZE], bool turnoBlanca);
void elegirPieza();
