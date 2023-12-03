#include"DrawConsole.h"
#include"_Game.h"
#include"Input.h"
#include"archivos.h"
#include <ctime>

int j;
// 4 de ancho 3 de alto
class Coche{
private:
int velocidad = 75,puntos = 0,X=40,Y=10,tecla,dinero = 100;
public:
void DrawCar(){
    UI.gotoxy(X-1,Y-1);printf("%C",254);UI.gotoxy(X,Y-1);printf("%C",219);UI.gotoxy(X+1,Y-1);printf("%C",219);UI.gotoxy(X+2,Y-1);printf("%C",254);
    UI.gotoxy(X-1,Y);printf("%C",254);UI.gotoxy(X,Y);printf("%C",219);UI.gotoxy(X+1,Y);printf("%C",219);UI.gotoxy(X+2,Y);printf("%C",254);
    UI.gotoxy(X-1,Y+1);printf("%C",196);UI.gotoxy(X,Y+1);printf("%C",193);UI.gotoxy(X+1,Y+1);printf("%C",193);UI.gotoxy(X+2,Y+1);printf("%C",196);
}
void Teclas(){
switch(Input.GetKey(&tecla)){
case left:if(X>=5)X-=2;break;
case right:if(X<=75)X+=2;break;
case up:if (velocidad <= 124)velocidad++;
break;
case down:if(velocidad > 10)velocidad--;
break;
default:tecla=0;break;
}
tecla = 0;
}

int GetX(){
    return X;
}

int GetY(){
    return Y;
}

int GetVelocidad(){
    return velocidad;
}

void SetDinero(int dineros){
    dinero = dineros;
}

int GetDinero(){
    return dinero;
}
void Velocidad(){
    UI.gotoxy(78,1);cout<<"Velocidad: "<<velocidad;
    UI.gotoxy(78,3);cout<<"Dinero: "<<dinero;
}

void Record(){
    UI.gotoxy(78,8);cout<<"Record: "<<j;
}

~Coche(){};

};Coche player;

class Trafico{
private:
int velocidad,Y,X = rand()%40;
bool agresivo,pasivo;
public:
void DrawTrafico(){
    UI.gotoxy(X-1,Y-1);printf("%C",254);UI.gotoxy(X,Y-1);printf("%C",219);UI.gotoxy(X+1,Y-1);printf("%C",219);UI.gotoxy(X+2,Y-1);printf("%C",254);
    UI.gotoxy(X-1,Y);printf("%C",254);UI.gotoxy(X,Y);printf("%C",219);UI.gotoxy(X+1,Y);printf("%C",219);UI.gotoxy(X+2,Y);printf("%C",254);
    UI.gotoxy(X-1,Y+1);printf("%C",196);UI.gotoxy(X,Y+1);printf("%C",193);UI.gotoxy(X+1,Y+1);printf("%C",193);UI.gotoxy(X+2,Y+1);printf("%C",196);
    if(Y!=0)Y--;
    else{
        Y = 20;
        X = rand()%75+5;
    }
}

void IA(){
    if(X<player.GetX()-1){//derecha
        X-=3;
    }else if(X>player.GetX()+1){//izquierda
        X+=3;
    }
    else{
        int m=rand()%2;
        if(m==0)X+=3;//derecha 
        else X-=3;//izquierda
    }

}

int GetY(){
    return Y;
}

int GetX(){
return X;
}

void Desicion(){
    if((Y>=player.GetY()-1&&Y<=player.GetY()+3)&&(X>=player.GetX()-4&&X<=player.GetX()+4)){
        IA();
    }
}

};Trafico c1;
list<Trafico*>c2;
list<Trafico*>::iterator iterador;

void Calle(){
    for(int i = 0;i<30;i++){
        UI.gotoxy(0,i);printf("%C",219);
    }for(int i = 0;i<30;i+=2){
        UI.gotoxy(20,i);printf("%C",219);
    }for(int i = 0;i<30;i+=2){
        UI.gotoxy(40,i);printf("%C",219);
    }for(int i = 0;i<30;i+=2){
        UI.gotoxy(60,i);printf("%C",219);
    }for(int i = 0;i<30;i++){
        UI.gotoxy(80,i);printf("%C",219);
    }

}

void crearCoches(){
    for(int i=0;i<5;i++){
        c2.push_back(new Trafico());
    }
}

void movercoche(){
    for(iterador = c2.begin();iterador != c2.end();iterador++){
        (*iterador)->DrawTrafico();
        (*iterador)->Desicion();
    }
}

void Borrar(){
    for(iterador = c2.begin();iterador != c2.end();iterador++){
        delete(*iterador);
        iterador = c2.erase(iterador);
    }
}

typedef int infraccion;
class infracciones{
private:
infraccion excesovelocidad = 100,choque = 50;
int n = rand()%120,velocidadMax = rand()%120+10;
float i,j,k;
public:
void tiempos(){
    i += 0.3;
    if(i>=n){n = rand()%120;i=0;velocidadMax = rand()%120+10;}
    UI.gotoxy(78,5);cout<<"Velocidad Maxima: "<<velocidadMax;
}

void Costos(){
if(player.GetVelocidad()>velocidadMax){
    j+=0.3;
    k+=0.3;
    UI.gotoxy(78,6);cout<<"Tiempo en exceso de velocidad:"<<j<<" "<<k;
    if(j>3&&k>5){
        j=0;
        k=0;
        player.SetDinero(player.GetDinero()-velocidadMax);
    }
}else k=0;
}

int GetChoque(){
    return choque;
}
};infracciones infra;

void Game::Interface(){
    player.Velocidad();
}

void Game::Collision(){
    for(iterador = c2.begin();iterador != c2.end();iterador++){
            if((*iterador)->GetY()==player.GetY()-3){
        player.SetDinero(player.GetDinero()+5);
    }
    if(((*iterador)->GetY()>=player.GetY()-1&&(*iterador)->GetY()<=player.GetY()+1)&&((*iterador)->GetX()>=player.GetX()-3&&(*iterador)->GetX()<=player.GetX()+3)){player.SetDinero(player.GetDinero()-infra.GetChoque());}
    }
}

void Game::Loop(int delay){
    int i;
    while(player.GetDinero()>=1){
    Calle();
    player.Record();
    Collision();
    Interface();
    infra.tiempos();
    player.Teclas();
    player.DrawCar();
    movercoche();
    infra.Costos();
    if(player.GetDinero()>j)j=player.GetDinero();
    Sleep(delay);
    system("CLS");
    i++;
    }
}

int main(){
    string Contenido;
    Abrir("Record.txt",&Contenido);
    j = stoi(Contenido);
    cout<<"Presione cualquier tecla para jugar";
    getch();
    crearCoches();
juego.Loop(30);
Record(j,"Record.txt");
juego.GameOver();
juego.~Game();
player.~Coche();
Borrar();
getch();
    return 0;
}