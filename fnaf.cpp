#include "fnafcamera.h"
#include "fnafanimatronicos.h"
#include "fanfmapa.h"
#include "fnafEnergia.h"
#include "fnafDias.h"


class Principal : public Game{
public:
void start(){
    noches.start();
    camera.start();
    chica.start();
    mapa.start();
}

void Loop(){
    camera.Loop();
    mapa.loop();
    chica.Loop();
    energy.Loop();
    noches.Loop();
Sleep(17);
system("cls");
if(mapa.Perdiste()!=true||noches.GetPasoNoche()!= true)Loop();
}

};
Principal p;

int main(){
    p.start();
    p.Loop();
    getch();
    return 0;
}