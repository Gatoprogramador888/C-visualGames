#pragma once
#include "_Game.h"
#include "DrawConsole.h"
#include "fnafcamera.h"


class Energia : public Game{
private:
int energia = 100,contador = 0;

void DesgasteEnergia(){
    if(contador == 100){
    if(camera.GetOn()==true)energia--;
    if(camera.Puerta()==true)energia--;
    energia--;
    reinicio(&contador);
    }
}

void reinicio(int* n){
    *n = 0;
}

void MostrarEnergia(){
    UI.gotoxy(70,5);cout<<"Energia: "<<energia;
}
public:
void start(){}

void Loop(){
    contador++;
    DesgasteEnergia();
    MostrarEnergia();
}
};
Energia energy;