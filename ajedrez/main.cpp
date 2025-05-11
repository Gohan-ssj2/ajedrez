#include "cons.h"
#include "tablero.h"

int main() {
    char tablero[BOARD_SIZE][BOARD_SIZE];
    bool esTurnoBlanca = true;

    iniciarTablero(tablero);

    while (true) {
        system("cls");
        verTablero(tablero);

        std::cout << (esTurnoBlanca ? "Turno de BLANCAS (mayúsculas)" : "Turno de NEGRAS (minúsculas)") << std::endl;

        posicion origen = obtenerPieza(tablero, esTurnoBlanca);
        posicion destino;

        std::cout << "Elige destino (X Y): ";
        std::cin >> destino.x >> destino.y;

        destino.x--;
        destino.y--;

        if (moverPieza(tablero, origen, destino, esTurnoBlanca)) {
            esTurnoBlanca = !esTurnoBlanca;
        }
    }
}