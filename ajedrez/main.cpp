#include"cons.h"
#include"tablero.h"
int main() {
	char tablero[BOARD_SIZE][BOARD_SIZE];
	bool gameOver = false;
	bool esTurnoBlanca = true;
	iniciarTablero(tablero);
	do {
		verTablero(tablero);
		posicion origen = obtenerPieza(tablero, esTurnoBlanca);
		posicion destino;
		std::cout << "Elige destino (X Y): ";
		std::cin >> destino.x;
		std::cin>> destino.y;
		destino.x--; destino.y--;
		destino.y = BOARD_SIZE - destino.y;

		if (moverPieza(tablero, origen, destino, esTurnoBlanca)) {
			esTurnoBlanca = !esTurnoBlanca;
		}
		
		
		system("cls");
	} while (!gameOver);
	

}