#include "Personaje.h"
#include <iostream>

// Constructor de la clase Personaje
Personaje::Personaje(int pHp, std::string pName, int pAttack, int pPosX, int pPosY)
    : hp(pHp), name(pName), attack(pAttack), posX(pPosX), posY(pPosY) {}

// Implementación de los getters
int Personaje::getHp() { return hp; }
std::string Personaje::getName() { return name; }
int Personaje::getAttack() { return attack; }
int Personaje::getPosX() { return posX; }
int Personaje::getPosY() { return posY; }

// Implementación de los setters
void Personaje::setHp(int php) { hp = php; }
void Personaje::setName(std::string pname) { name = pname; }
void Personaje::setAttack(int pattack) { attack = pattack; }
void Personaje::setPosX(int pPosX) { posX = pPosX; }
void Personaje::setPosY(int pPosY) { posY = pPosY; }

// Método para imprimir el estado del personaje
void Personaje::printStatus() {
    std::cout << "El nombre del personaje es " << name << " y tiene una vida de " << hp << std::endl;
}
