#include "cons.h"

void iniciarTablero(char tablero[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            tablero[i][j] = VACIO;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        tablero[1][i] = PEON_BLANCO;
        tablero[6][i] = PEON_NEGRO;
    }

    tablero[0][0] = TORRE_BLANCA;
    tablero[0][1] = CABALLO_BLANCA;
    tablero[0][2] = ALFIL_BLANCA;
    tablero[0][3] = DAMA_BLANCA;
    tablero[0][4] = REY_BLANCA;
    tablero[0][5] = ALFIL_BLANCA;
    tablero[0][6] = CABALLO_BLANCA;
    tablero[0][7] = TORRE_BLANCA;

    tablero[7][0] = TORRE_NEGRO;
    tablero[7][1] = CABALLO_NEGRO;
    tablero[7][2] = ALFIL_NEGRO;
    tablero[7][3] = DAMA_NEGRO;
    tablero[7][4] = REY_NEGRO;
    tablero[7][5] = ALFIL_NEGRO;
    tablero[7][6] = CABALLO_NEGRO;
    tablero[7][7] = TORRE_NEGRO;
}

void verTablero(char tablero[BOARD_SIZE][BOARD_SIZE]) {
    std::cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++)
        std::cout << i + 1 << " ";
    std::cout << std::endl;

    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

posicion obtenerPieza(char tablero[BOARD_SIZE][BOARD_SIZE], bool esTurnoBlanca) {
    posicion p;
    std::cout << "Elige una pieza (X Y): ";
    std::cin >> p.x >> p.y;

    p.x--;
    p.y--;

    return p;
}

bool moverPieza(char tablero[BOARD_SIZE][BOARD_SIZE], posicion origen, posicion destino, bool esTurnoBlanca) {
    char pieza = tablero[origen.y][origen.x];
    char destinoPieza = tablero[destino.y][destino.x];

    if (pieza == VACIO || (esTurnoBlanca && !isupper(pieza)) || (!esTurnoBlanca && !islower(pieza))) {
        std::cout << "Movimiento inválido: no es tu pieza." << std::endl;
        return false;
    }

    if (destinoPieza != VACIO && ((isupper(pieza) && isupper(destinoPieza)) || (islower(pieza) && islower(destinoPieza)))) {
        std::cout << "Movimiento inválido: no puedes comer tus propias piezas." << std::endl;
        return false;
    }

    int dx = destino.x - origen.x;
    int dy = destino.y - origen.y;

    char piezaTipo = toupper(pieza);
    bool movimientoValido = false;

    switch (piezaTipo) {
    case 'P':
        if (esTurnoBlanca) {
            if (dx == 0 && dy == 1 && destinoPieza == VACIO) movimientoValido = true;
            else if (abs(dx) == 1 && dy == 1 && destinoPieza != VACIO) movimientoValido = true;
        }
        else {
            if (dx == 0 && dy == -1 && destinoPieza == VACIO) movimientoValido = true;
            else if (abs(dx) == 1 && dy == -1 && destinoPieza != VACIO) movimientoValido = true;
        }
        break;
    case 'T':
        if ((dx == 0 || dy == 0)) movimientoValido = true;
        break;
    case 'C':
        if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) movimientoValido = true;
        break;
    case 'A':
        if (abs(dx) == abs(dy)) movimientoValido = true;
        break;
    case 'D':
        if (abs(dx) == abs(dy) || dx == 0 || dy == 0) movimientoValido = true;
        break;
    case 'R':
        if (abs(dx) <= 1 && abs(dy) <= 1) movimientoValido = true;
        break;
    }

    if (!movimientoValido) {
        std::cout << "Movimiento no permitido para esa pieza." << std::endl;
        return false;
    }

    if (destinoPieza == REY_BLANCA || destinoPieza == REY_NEGRO) {
        std::cout << "¡Rey eliminado! Fin del juego." << std::endl;
        if (esTurnoBlanca) {
            std::cout << "Han ganado las blancas." << std::endl;
        }
        else {
            std::cout << "Han ganado las negras." << std::endl;
        }
        exit(0);
    }

    tablero[destino.y][destino.x] = pieza;
    tablero[origen.y][origen.x] = VACIO;
    return true;
}