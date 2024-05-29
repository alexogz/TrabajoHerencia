#ifndef ENEMIGOFINAL_H
#define ENEMIGOFINAL_H

#include "Enemigo.h"

// Definici�n de la clase EnemigoFinal que hereda de Enemigo
class EnemigoFinal : public Enemigo {
private:
    bool fireAttack; // Atributo para el ataque de fuego
    int frozenAttack; // Atributo para el ataque de hielo

public:
    // Constructor
    EnemigoFinal(int pHp, std::string pName, int pAttack, int pPosX, int pPosY, bool pFireAttack, int pFrozenAttack);

    // Getters y setters

    bool getFireAttack();
    int getFrozenAttack();
    void setFireAttack(bool pFireAttack);
    void setFrozenAttack(int pFrozenAttack);

    // M�todo para imprimir todas las estad�sticas
    void printAllStats();
};

#endif // ENEMIGOFINAL_H
