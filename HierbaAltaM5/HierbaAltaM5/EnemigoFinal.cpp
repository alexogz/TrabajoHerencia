#include "EnemigoFinal.h"
#include <iostream>

// Constructor de la clase EnemigoFinal
EnemigoFinal::EnemigoFinal(int pHp, std::string pName, int pAttack, int pPosX, int pPosY, bool pFireAttack, int pFrozenAttack)
    : Enemigo(pHp, pName, pAttack, pPosX, pPosY), fireAttack(pFireAttack), frozenAttack(pFrozenAttack) {}

// Implementación de los getters y setters
bool EnemigoFinal::getFireAttack() { return fireAttack; }
int EnemigoFinal::getFrozenAttack() { return frozenAttack; }
void EnemigoFinal::setFireAttack(bool pFireAttack) { fireAttack = pFireAttack; }
void EnemigoFinal::setFrozenAttack(int pFrozenAttack) { frozenAttack = pFrozenAttack; }

// Método para imprimir todas las estadísticas del enemigo final
void EnemigoFinal::printAllStats() {
    std::cout << "El nombre del enemigo final es " << getName() << std::endl;
    std::cout << "La vida del enemigo final es " << getHp() << std::endl;
    std::cout << "El ataque normal del enemigo final es " << getAttack() << std::endl;
    std::cout << "El ataque de fuego del enemigo final es " << getFireAttack() << std::endl;
    std::cout << "El ataque de hielo del enemigo final es " << getFrozenAttack() << std::endl;
}
