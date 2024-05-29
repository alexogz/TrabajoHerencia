#include "Enemigo.h"

// Constructor de la clase Enemigo
Enemigo::Enemigo(int pHp, std::string pName, int pAttack, int pPosX, int pPosY)
    : Personaje(pHp, pName, pAttack, pPosX, pPosY) {}
