#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Personaje.h"
#include "Enemigo.h"
#include "EnemigoFinal.h"

using namespace std;

const int TAMANO_TABLERO_FILAS = 10; // Número de filas del tablero
const int TAMANO_TABLERO_COLUMNAS = 5; // Número de columnas del tablero
const char VACIO = '*'; // Representación de una casilla vacía
const char ENTRENADOR = 'E'; // Representación del entrenador pokemon
const char POKEMON = '*'; // Representación de un pokemon
const char SALIDA = 'S'; // Representación de la salida

// Estructura para almacenar una posición en el tablero
struct Posicion {
    int x, y;
};

// Esto pone el tablero con *
void inicializarTablero(vector<vector<char>>& tablero) {
    for (int i = 0; i < TAMANO_TABLERO_FILAS; ++i) {
        for (int j = 0; j < TAMANO_TABLERO_COLUMNAS; ++j) {
            tablero[i][j] = VACIO;
        }
    }
}

// Esto imprime el estado actual del tablero
void imprimirTablero(const vector<vector<char>>& tablero) {
    for (int i = 0; i < TAMANO_TABLERO_FILAS; ++i) {
        for (int j = 0; j < TAMANO_TABLERO_COLUMNAS; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

// Verifica si una posición es válida dentro del tablero
bool posicionValida(int x, int y) {
    return x >= 0 && x < TAMANO_TABLERO_FILAS && y >= 0 && y < TAMANO_TABLERO_COLUMNAS;
}

// Genera una posición aleatoria dentro del tablero
Posicion generarPosicionAleatoria() {
    return { rand() % TAMANO_TABLERO_FILAS, rand() % TAMANO_TABLERO_COLUMNAS };
}

// Mueve al entrenador en la dirección indicada (w, a, s, d)
void moverEntrenador(Personaje& heroe, char direccion) {
    int nuevaX = heroe.getPosX();
    int nuevaY = heroe.getPosY();

    switch (direccion) {
    case 'w': nuevaX--; break; // Mover hacia arriba
    case 's': nuevaX++; break; // Mover hacia abajo
    case 'a': nuevaY--; break; // Mover hacia la izquierda
    case 'd': nuevaY++; break; // Mover hacia la derecha
    default: cout << "Movimiento invalido" << endl; return;
    }

    if (posicionValida(nuevaX, nuevaY)) {
        heroe.setPosX(nuevaX);
        heroe.setPosY(nuevaY);
    }
    else {
        cout << "Movimiento fuera del tablero" << endl;
    }
}

// Simula una batalla por turnos entre el Entrenador y un pokemon
bool batalla(Personaje& entrenador, Enemigo& enemigo) {
    while (entrenador.getHp() > 0 && enemigo.getHp() > 0) {
        cout << "Entrenador Pokemon ataca a " << enemigo.getName() << " y causa " << entrenador.getAttack() << " de daño." << endl;
        enemigo.setHp(enemigo.getHp() - entrenador.getAttack()); // El entrenador ataca al pokemon
        if (enemigo.getHp() > 0) {
            cout << enemigo.getName() << " ataca a Entrenador y causa " << enemigo.getAttack() << " de daño." << endl;
            entrenador.setHp(entrenador.getHp() - enemigo.getAttack()); // El pokemon ataca al entrenador si sigue vivo
        }
    }
    return entrenador.getHp() > 0; // Devuelve true si el entrenador gana, false si pierde
}

// Simula una batalla por turnos entre el héroe y el enemigo final
bool batallaFinal(Personaje& entrenador, EnemigoFinal& enemigo) {
    while (entrenador.getHp() > 0 && enemigo.getHp() > 0) {
        cout << "Entrenador Pokemon ataca a " << enemigo.getName() << " y causa " << entrenador.getAttack() << " de daño." << endl;
        enemigo.setHp(enemigo.getHp() - entrenador.getAttack()); // El entrenador ataca al pokemon
        if (enemigo.getHp() > 0) {
            // El pokemon final tiene un 50% de probabilidad de usar un ataque especial
            if (rand() % 2 == 0) {
                cout << enemigo.getName() << " usa un ataque de fuego y causa " << enemigo.getFireAttack() << " de daño." << endl;
                entrenador.setHp(entrenador.getHp() - enemigo.getFireAttack());
            }
            else {
                cout << enemigo.getName() << " usa un ataque de hielo y causa " << enemigo.getFrozenAttack() << " de daño." << endl;
                entrenador.setHp(entrenador.getHp() - enemigo.getFrozenAttack());
            }
        }
    }
    return entrenador.getHp() > 0; // Devuelve true si el Entrenador gana, false si pierde
}









int main() {
    srand(time(0)); // Esto inicializa los números aleatorios

    // Crea e inicializa el tablero
    vector<vector<char>> tablero(TAMANO_TABLERO_FILAS, vector<char>(TAMANO_TABLERO_COLUMNAS, VACIO));

    // Crea al personaje principal y a los enemigos que se va a enfrentar el entrenador
    Personaje entrenador(100, "Entrenador Pokemon", 20, 0, 0);
    Enemigo enemigo1(50, "Rattata", 10, generarPosicionAleatoria().x, generarPosicionAleatoria().y);
    Enemigo enemigo2(50, "Weedle", 10, generarPosicionAleatoria().x, generarPosicionAleatoria().y);
    Enemigo enemigo3(50, "Mankey", 10, generarPosicionAleatoria().x, generarPosicionAleatoria().y);
    EnemigoFinal enemigoFinal(100, "Kyurem Blanco", 20, TAMANO_TABLERO_FILAS - 1, rand() % TAMANO_TABLERO_COLUMNAS, 15, 30);

    // Coloca al héroe y a los enemigos en el tablero
    tablero[entrenador.getPosX()][entrenador.getPosY()] = ENTRENADOR;
    tablero[enemigo1.getPosX()][enemigo1.getPosY()] = POKEMON;
    tablero[enemigo2.getPosX()][enemigo2.getPosY()] = POKEMON;
    tablero[enemigo3.getPosX()][enemigo3.getPosY()] = POKEMON;
    tablero[enemigoFinal.getPosX()][enemigoFinal.getPosY()] = SALIDA;

    // Bucle del juego
    while (true) {
        imprimirTablero(tablero);

        char movimiento;
        cout << "Ingrese el movimiento (w/a/s/d): ";
        cin >> movimiento;

        // Actualiza la posición del héroe en el tablero
        tablero[entrenador.getPosX()][entrenador.getPosY()] = VACIO;
        moverEntrenador(entrenador, movimiento);
        tablero[entrenador.getPosX()][entrenador.getPosY()] = ENTRENADOR;

        // Verifica si el héroe se encuentra con un enemigo o la salida
        for (auto& enemigo : { &enemigo1, &enemigo2, &enemigo3 }) {
            if (entrenador.getPosX() == enemigo->getPosX() && entrenador.getPosY() == enemigo->getPosY()) {
                cout << "¡Batalla con " << enemigo->getName() << "!" << endl;

                if (batalla(entrenador, *enemigo)) {
                    cout << "¡Has derrotado a " << enemigo->getName() << "!" << endl;
                    tablero[enemigo->getPosX()][enemigo->getPosY()] = VACIO;
                }
                else {
                    cout << "El entrenador se a quedado sin Pokemon... El entrenador sale corriendo hacia el centro Pokemon" << endl;
                    return 0;
                }
            }
        }

        if (entrenador.getPosX() == enemigoFinal.getPosX() && entrenador.getPosY() == enemigoFinal.getPosY()) {
            cout << "¡Batalla con " << enemigoFinal.getName() << "!" << endl;

            if (batallaFinal(entrenador, enemigoFinal)) {
                cout << "Kyurem a sido derrotado" << endl;
                return 0;
            }
            else {
                cout << "El entrenador se a quedado sin Pokemon... El entrenador sale corriendo hacia el centro Pokemon" << endl;
                return 0;
            }
        }
        //Esto sirve para ir limpiando la consola
        system("CLS");

    }

    return 0;
}
