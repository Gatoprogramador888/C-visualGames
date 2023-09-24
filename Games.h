#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<list>

#define up 72
#define down 80
#define right 77
#define left 75
#define espace 32
#define enter 13
#define esc 27

using namespace std;

class interfaz1{
    public:
void gotoxy(int x,int y){//ancho 80 alto 25 gotoxy puede actualizarse con una variable
	HANDLE input = GetStdHandle(STD_OUTPUT_HANDLE);//hcon es una variable se le puede manipular el nombre
	COORD coord;//lo mismo con dwPos
	coord.X = x;
	coord.Y = y;  
SetConsoleCursorPosition(input,coord);
}
void CLS(){
    for(int i=0;i<80;i++){
    for(int j=0;j<25;j++){
        gotoxy(i,j);cout<<" ";
    }
}
gotoxy(0,0);
}
};
interfaz1 UI;

class input{
public:
int GetKey(int* tecla){
    if(kbhit()){
        *tecla = getch(); 
    }
    return *tecla;
}

void Tecla(int tecla){
    if(kbhit()){
        tecla = getch(); 
    }
    cout<<tecla<<endl;
}
};
input Input;

class Pistola{
private:
int balas,reservas,balas2;
int PosPX,PosPY;
bool Gatillo = true;
public:
Pistola(int Balas,int reservas,int PosXJ,int PosYJ){
    this->balas = Balas;
    this->reservas = reservas;
    this->balas2 = balas;
    this->PosPX = PosXJ;
    this->PosPY = PosYJ;
}

~Pistola(){}

int GetPX(){return PosPX;}
int GetPY(){return PosPY;}
void SetBalas(int Balas){
balas=Balas;
}
int GetBalas(){
    return balas;
}
int Getbalas(){
    return balas2;
}
void SetReservas(int reservas){
reservas = reservas;
}
int GetReservas(){
    return reservas;
}
void SetRecarga(int Balas,int Reservas){
if(reservas>=1&&balas != Balas){
while(balas != Balas){
    balas++;
    reservas--;
    if(reservas<=0)break;
}
Gatillo = true;
}
if(reservas<=0){
    UI.gotoxy(70,18);cout<<"Nose puede recargar";
}
}

void Disparo(){
    if(balas <= 0)Gatillo = false;
}

void Municion(){
    UI.gotoxy(40,0);cout<<"Cargador: "<<balas<<"    Reservas: "<<reservas;
}

bool GetGatillo(){
    return Gatillo;
}

};
Pistola m4(30,210,0,0);


class Personaje{
private:
int vida,escudo,XP,XPR;
int XPer = 1,YPer = 2;
public:
int tecla1,tecla2;
Personaje(int vida,int escudo){
    this->vida = vida;
    this->escudo = escudo;
}

~Personaje(){}

//vidas personaje
void SetDanios(int danio){
    if(GetEscudo()<=0)SetVida(danio);
    else SetEscudo(danio);
}
void SetEscudo(int danio){escudo-=danio;}
int GetEscudo(){return escudo;}
void SetVida(int danio){vida-=danio;}
int GetVida(){return vida;}

//Experiencia
void SetXP(int puntos){XP+=puntos;}
int GetXP(){return XP;}

void SetVidas(int danio){
    if(escudo<=0)vida-=danio;
    else escudo-=danio;
}

//posicion
void Movimiento(){
    if(Input.GetKey(&tecla1)){
        switch(tecla1){
            case up:YPer-=2;break;
            case down:YPer+=2;break;
            case right:XPer+=2;break;
            case left:XPer-=2;break;
            case 82:m4.SetRecarga(m4.Getbalas(),m4.GetReservas());break;
            case 114:m4.SetRecarga(m4.Getbalas(),m4.GetReservas());break;
        }
        tecla1 = 0;
    }
}

//posicion 
int GetPosX(){return XPer;}
int GetPosY(){return YPer;}
//Dibujo
//centro sea lo principal
void DrawPerson(){
UI.gotoxy(XPer,YPer-1);printf("%c",79);
UI.gotoxy(XPer,YPer);printf("%c",76);UI.gotoxy(XPer+1,YPer);printf("%c",62);
UI.gotoxy(XPer-1,YPer+1);printf("%c",47);
UI.gotoxy(XPer+1,YPer+1);printf("%c",92);
}

void BorrarPerson(){
UI.gotoxy(XPer,YPer-1);cout<<"  ";
UI.gotoxy(XPer,YPer);cout<<"   ";
UI.gotoxy(XPer-1,YPer+1);cout<<"  ";
UI.gotoxy(XPer+1,YPer+1);cout<<"  ";
}

void DrawEstadisticas(){
    UI.gotoxy(0,0);cout<<"Escudo: "<<GetEscudo()<<"  Vida: "<<GetVida()<<"    Puntos: "<<GetXP();
}

void SetXPR(int record){XPR=record;}
void record(){
if(XP>XPR)XPR=XP;
}
int GetXPR(){return XPR;}
};
Personaje J1(100,150);


class Bala{
int velocidad,danio,X,Y;
public:
int tecla1;
Bala(int velocidad,int danio,int posx,int posy){
this->velocidad = velocidad;
this->danio = danio;
this->X = posx;
this->Y = posy;
}

int GetDanio(){
    return danio;
}

int GetX(){return X;}

int GetY(){return Y;}

bool fuera(){
    return X>=79;
}

void DrawBullet(){
    UI.gotoxy(X,Y);cout<<"-";
    X+=velocidad;
}
void BorraBullet(){
    UI.gotoxy(X,Y);cout<<" ";
}
};
list<Bala*> balas;
list<Bala*>::iterator i;
Bala M556(0,50,0,0);

class Enemigo{
private:
int vida,danio,X,Y;
public:
Enemigo(){
    this->vida = rand()%151+30;
    this->danio = vida-20;
    this->X = 75;
    this->Y = rand()%19;
}
void drawEnemy(){
UI.gotoxy(X,Y-1);printf("%c",79);
UI.gotoxy(X,Y);printf("%c",217);
UI.gotoxy(X-1,Y+1);printf("/");
UI.gotoxy(X+1,Y+1);printf("%C",92);
}

void BorrarEnemy(){
UI.gotoxy(X,Y-1);printf(" ");
UI.gotoxy(X,Y);printf(" ");
UI.gotoxy(X-1,Y+1);printf(" ");
UI.gotoxy(X+1,Y+1);printf(" ");
}

void SeguirEnemy(Personaje n){
if(X<n.GetPosX())X++;
if(X>n.GetPosX())X--;
if(Y<n.GetPosY())Y++;
if(Y>n.GetPosY())Y--;
}

int GetX(){return X;}
int GetY(){return Y;}
int GetLife(){return vida;}

void SetVida(Bala i){
vida -= i.GetDanio();
}

int GetDanio(){return danio;}

};
list<Enemigo*> Enemy;
list<Enemigo*>::iterator I;

void CrearEnemys(int e){
    for(int i=0;i<e;i++){
        Enemy.push_back(new Enemigo());
    }
}

void MoverEnemys(){
    for(I = Enemy.begin();I!=Enemy.end();I++){
        (*I)->drawEnemy();
        (*I)->SeguirEnemy(J1);
    }
}


void disparo(){
    int tecla1;
if(Input.GetKey(&tecla1)){
            if(tecla1 == 68||tecla1 == 100&&m4.GetGatillo()==true){
            m4.SetBalas(m4.GetBalas()-1);UI.gotoxy(75,18);cout<<"pium";
            balas.push_back(new Bala(1,50,J1.GetPosX()+1,J1.GetPosY()));
        }
        tecla1 = 0;
}
}

void MoveBullet(){
        for(i = balas.begin();i!=balas.end();i++){
        (*i)->DrawBullet();
        if((*i)->fuera()==true){
            (*i)->BorraBullet();
            delete(*i);
            i = balas.erase(i);
        }
    }
}
