#include "Input.h"
#include "_Game.h"
#include "fnafcamera.h"
#include "fnafanimatronicos.h"

typedef int map;

class Mapa : public Game{
protected:
bool gameover = false;
int Mapita[20][40] = {{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0},
{1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1},
{0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,1,1,1,1,0,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0}};
int Posiciones[2][2] = {{chica.GetX(),15},{chica.GetY(),37}};
int count;
void Dibujarmapa(){
    for(int i=0;i<20;i++){
        for(int j=0;j<40;j++){
            if(Mapita[i][j]==1)printf("%C",219);
            else if(chica.GetX()==i&&chica.GetY()==j){
                Mapita[i][j]=2;
            }else if(Mapita[i][j]==2&&count==chica.GetCount()){
                printf("%C",64);
            }else if(Mapita[i][j]==2&&count!=chica.GetCount()){
                Mapita[i][j]=0;
                count = chica.GetCount();
            }
            else cout<<" ";
        }
        cout<<"\n";
    }
}

void Perder(){
    if(chica.GetX()==3&&chica.GetY()==8&&count != chica.GetCount()&&camera.Puerta()!=true){
        GameOver();
        gameover = true;
    }
}

public:

bool Perdiste(){
    return gameover;
}

void Dibujar(bool Encendido){
    if(Encendido == true)Dibujarmapa();
    else return;
}

void start(){
count = chica.GetCount();
Mapita[2][28]=2;
}

void loop(){
Dibujar(camera.GetOn());
Perder();
}

};Mapa mapa;