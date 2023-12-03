#pragma once
#include "_Game.h"
#include "DrawConsole.h"
#include "archivos.h"
#include <String>

class Noches : public Game{
    private:
    int noche = 1,contador;
    string contenido;
    bool PasoNoche = false;
    int noche2 = noche;

    void Inicio(){
        Abrir("Noches.txt",&contenido);
        noche = stoi(contenido);
    }

    void Guardado(int n){
    Record(n,"Noches.txt");
    }

    void DuracionNoche(){
        if(contador >= 3500){
            noche++;
            Guardado(noche);
        }
        if(noche2 != noche){
            PasoNoche = true;
        }
    }

    public:

    bool GetPasoNoche(){
        return PasoNoche;
    }

    void start(){
        Inicio();
    }

    void Loop(){
        contador++;
        DuracionNoche();
    }
};Noches noches;