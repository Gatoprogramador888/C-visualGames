#include "Games.h"

class Game
{
public:
    void Loop(int delay);
    void Menu();
    void Collision(Personaje Per,list<Bala*>::iterator i,list<Enemigo*>::iterator I);
    void GameOver(){
        system("cls");
        UI.gotoxy(20,10);cout<<"!!!GAME OVER!!!";
        UI.gotoxy(20,13);cout<<"Presione cualquier tecla para ir al menu";
        getch();
        system("cls");
    }
    ~Game(){};
};
Game juego;