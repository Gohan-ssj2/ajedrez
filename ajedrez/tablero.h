#pragma once
#include "cons.h"

void iniciarTablero(char tablero[BOARD_SIZE][BOARD_SIZE]);
void verTablero(char tablero[BOARD_SIZE][BOARD_SIZE]);
posicion obtenerPieza(char tablero[BOARD_SIZE][BOARD_SIZE], bool esTurnoBlanca);
bool moverPieza(char tablero[BOARD_SIZE][BOARD_SIZE], posicion origen, posicion destino, bool esTurnoBlanca);