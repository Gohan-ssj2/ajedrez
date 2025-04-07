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
	//Definimos posiciones de piezas eje x
	const short torreL = 0;
	const short torreR = BOARD_SIZE - 1;
	const short caballoL = 1;
	const short caballoR = BOARD_SIZE-2;
	const short alfilerL = 2;
	const short alfilerR = BOARD_SIZE - 3;
	const short dama = 3;
	const short rey = 4;
	//Creamos las piezas en el tablero (BLANCAS)
	tablero[BOARD_SIZE-8][torreL] = TORRE_BLANCA;
	tablero[BOARD_SIZE - 8][torreR] = TORRE_BLANCA;
	tablero[BOARD_SIZE - 8][caballoL] = CABALLO_BLANCO;
	tablero[BOARD_SIZE - 8][caballoR] = CABALLO_BLANCO;
	tablero[BOARD_SIZE - 8][alfilerL] = ALFILER_BLANCO;
	tablero[BOARD_SIZE - 8][alfilerR] = ALFILER_BLANCO;
	tablero[BOARD_SIZE - 8][dama] = DAMA_BLANCA;
	tablero[BOARD_SIZE - 8][rey] = REY_BLANCO;
	//Creamos las piezas en el tablero (NEGRAS)
	tablero[BOARD_SIZE - 1][torreL] = TORRE_NEGRO;
	tablero[BOARD_SIZE - 1][torreR] = TORRE_NEGRO;
	tablero[BOARD_SIZE - 1][caballoL] = CABALLO_NEGRO;
	tablero[BOARD_SIZE - 1][caballoR] = CABALLO_NEGRO;
	tablero[BOARD_SIZE - 1][alfilerL] = ALFILER_NEGRO;
	tablero[BOARD_SIZE - 1][alfilerR] = ALFILER_NEGRO;
	tablero[BOARD_SIZE - 1][dama] = DAMA_NEGRO;
	tablero[BOARD_SIZE - 1][rey] = REY_NEGRO;
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

posicion obtenerPieza(char tablero[BOARD_SIZE][BOARD_SIZE], bool turnoBlanca) {
	posicion obtenerPiezaUsuario;
	
	bool pillePieza = true;
	do
	{
		pillePieza = true;
		std::cout << "-----------------" << std::endl;
		std::cout << " Elige una pieza: " << std::endl;
		std::cout << " X: ";
		std::cin >> obtenerPiezaUsuario.x;
		std::cout << " Y: ";
		std::cin >> obtenerPiezaUsuario.y;
		
		obtenerPiezaUsuario.x--;
		obtenerPiezaUsuario.y--;
		obtenerPiezaUsuario.y = BOARD_SIZE - obtenerPiezaUsuario.y;
		if (obtenerPiezaUsuario.x<1 || obtenerPiezaUsuario.x>BOARD_SIZE || obtenerPiezaUsuario.y<1 || obtenerPiezaUsuario.y>BOARD_SIZE) {
			std::cout << "INPUT INVALIDO" << std::endl;
			continue;
		}
		/*else if(turnoBlanca&&tablero[obtenerPiezaUsuario.x][obtenerPiezaUsuario.y]>) {
			
				pillePieza = false;


			}*/
	} while (!pillePieza);

	
}