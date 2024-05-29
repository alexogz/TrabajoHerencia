#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

// Definici�n de la clase base Personaje
class Personaje {
protected:
    int hp; // Puntos de vida del personaje
    std::string name; // Nombre del personaje
    int attack; // Puntos de ataque del personaje
    int posX; // Posici�n X del personaje en el tablero
    int posY; // Posici�n Y del personaje en el tablero

public:
    // Constructor
    Personaje(int pHp, std::string pName, int pAttack, int pPosX, int pPosY);

    // Getters
    int getHp();
    std::string getName();
    int getAttack();
    int getPosX();
    int getPosY();

    // Setters
    void setHp(int php);
    void setName(std::string pname);
    void setAttack(int pattack);
    void setPosX(int pPosX);
    void setPosY(int pPosY);

    // M�todo para imprimir el estado del personaje
    virtual void printStatus();
};

#endif // PERSONAJE_H

