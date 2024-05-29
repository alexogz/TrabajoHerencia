#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"

// Definición de la clase Enemigo que hereda de Personaje
class Enemigo : public Personaje {
public:
    // Constructor
    Enemigo(int pHp, std::string pName, int pAttack, int pPosX, int pPosY);
};

#endif // ENEMIGO_H
