#include "Game.h"
#include "archivos.h"


void Game::Collision(Personaje Per,list<Bala*>::iterator i,list<Enemigo*>::iterator I){
    for(i = balas.begin();i != balas.end();i++){
        for(I = Enemy.begin();I!=Enemy.end();I++){
            if((*i)->GetX()==(*I)->GetX()&&((*i)->GetY()==(*I)->GetY()||(*i)->GetY()-1==(*I)->GetY()||(*i)->GetY()+1==(*I)->GetY())){
            (*I)->SetVida(M556);
                if((*I)->GetLife()<=0){
                    (*I)->BorrarEnemy();
                    delete(*I);
                    I = Enemy.erase(I);
                    CrearEnemys(1);
                    J1.SetXP(1);
                }
            }
        }
    }

for(I = Enemy.begin();I!=Enemy.end();I++){
    if(J1.GetPosX()==(*I)->GetX()&&((*I)->GetY()-1==J1.GetPosY()||(*I)->GetY()==J1.GetPosY()||(*I)->GetY()+1==J1.GetPosY())){
        J1.SetVidas((*I)->GetDanio());
    }
}
}

void Game::Loop(int delay){
while(J1.GetVida()>0){
    Collision(J1,i,I);
    disparo();
    MoveBullet();
    MoverEnemys();
    m4.Disparo();
    J1.DrawPerson();
    J1.Movimiento();
    J1.Movimiento();
    J1.record();
    J1.DrawEstadisticas();
    m4.Municion();
    Sleep(delay);
    system("cls");
}
GameOver();
}

void Game::Menu(){
    int tecla3 = 0;
    bool exit=false;
    UI.gotoxy(15,0);cout<<"Juego de zombies\n mata a la mayor de zombies que puedas...\n sobreviviras??";
    UI.gotoxy(15,10);cout<<"1-para entrar";
    UI.gotoxy(15,12);cout<<"2-Para salir";
    UI.gotoxy(15,14);cout<<"Esc-Para salir";
    while(exit != true){
    UI.gotoxy(15,0);cout<<"Juego de zombies\n mata a la mayor de zombies que puedas...\n sobreviviras??";
    UI.gotoxy(15,10);cout<<"1-para entrar";
    UI.gotoxy(15,12);cout<<"2-Para salir";
    UI.gotoxy(15,14);cout<<"Esc-Para salir";
    UI.gotoxy(32,14);cout<<"Tu record: "<<J1.GetXPR();
        if(Input.GetKey(&tecla3)){
        switch (tecla3){
        case 49:
            tecla3 = 0;
            system("cls");
            Sleep(500);
            Loop(30);
            break;
        case 50:Record(J1.GetXPR(),"Record.json");
        exit = true;
        break;
        case esc:Record(J1.GetXPR(),"Record.json");
        exit = true;
        break;
        case 0:break;
        default:
            tecla3 = 0;
            system("cls");
            UI.gotoxy(15,20);cout<<"Opcion inexistente";
            Sleep(2000);
            system("cls");
            break;
        }
        }
        Sleep(30);
    }
}

int main(){
    string con;
    Abrir("Record.json",&con);
    J1.SetXPR(stoi(con));
    CrearEnemys(3);
    juego.Menu();
    J1.~Personaje();
    m4.~Pistola();
return 0;
}