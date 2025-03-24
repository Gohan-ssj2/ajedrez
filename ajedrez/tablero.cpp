#include"cons.h"
void iniciarTablero(char tablero[BOARD_SIZE][BOARD_SIZE]) {

	for (int i = 0;i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (j == BOARD_SIZE-2) tablero[j][i] = PEON_NEGRO;
			else if (j == 1) tablero[j][i] = PEON_BLANCO;
			else tablero[j][i] = '*';
		}
	}
}
void verTablero(char tablero[BOARD_SIZE][BOARD_SIZE]) {
	std::cout << ' ' << ' ';
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << i + 1 << ' ';
	}
	std::cout << std::endl;
	for (int i = 0;i < BOARD_SIZE; i++) {
		std::cout << BOARD_SIZE - i << ' ';
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << tablero[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}