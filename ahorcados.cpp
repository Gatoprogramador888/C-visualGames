//crear un juego de ahorcados
#include"DrawConsole.h"
#include"_Game.h"
#include"Input.h"

class Ahorcado{
private:
string palabra1,palabra2,palabra3,palabraEle;
string palabras[3];
int errores = 0,intentos = 0,aciertos = 0;
char tecla = '0';
bool cierto = false;
bool perder,win;
public:
Ahorcado(string palabra1,string palabra2,string palabra3){
    this->palabra1 = palabra1;
    this->palabra2 = palabra2;
    this->palabra3 = palabra3;
    palabras[0]=palabra1;
    palabras[1]=palabra2;
    palabras[2]=palabra3;
}
void eleccion(){
int i = rand()%3;
palabraEle = palabras[i];
}

void IntPers(){
    UI.gotoxy(8,2);cout<<"Aciertos: "<<aciertos<<" de "<<GetTamPal();
    UI.gotoxy(8,1);cout<<"Intentos: "<<intentos;
}

void DrawOrca(){
    UI.gotoxy(1,2);printf("%c",218);UI.gotoxy(2,2);printf("%c",196);UI.gotoxy(3,2);printf("%c",196);UI.gotoxy(4,2);printf("%c",196);UI.gotoxy(5,2);printf("%c",191);
    UI.gotoxy(1,3);printf("%c",179);
    UI.gotoxy(1,4);printf("%c",179);
    UI.gotoxy(1,5);printf("%c",179);
    UI.gotoxy(1,6);printf("%c",193);
}

void DrawMonito(){
//x=5,y=3
switch(errores){
    case 1:UI.gotoxy(5,3);cout<<"O";break;
    case 2:UI.gotoxy(5,4);cout<<"|";break;
    case 3:UI.gotoxy(4,4);cout<<"/";break;
    case 4:UI.gotoxy(6,4);printf("%c",92);break;
    case 5:UI.gotoxy(4,5);cout<<"/";break;
    case 6:UI.gotoxy(6,5);printf("%c",92);Sleep(1000);juego.GameOver();errores = 0;perder = true;break;
}
}

void DrawPalabra(int ini,int finish){
static int j;
for(int i=ini;i<finish;i++){
UI.gotoxy(i,8);cout<<"-";
}
}

int GetTamPal(){
    int a = palabraEle.length();
    return a;
}

void verificacion(){
if(Input.GetKey(&tecla)){
    for(int i = 0;i<GetTamPal();i++){
        if(tecla==palabraEle[i]){
                cierto = true;
                UI.gotoxy(i,8);cout<<tecla;
                aciertos++;
                intentos++;
            }
        Sleep(100);
        }
    }
    if(cierto == false&&tecla != '0'){
        errores++;
        intentos++;
        }
    DrawMonito();
        cierto = false;
        tecla = '0';
}

void Verify(){
    if(aciertos == GetTamPal()){
        Win();
        aciertos = 0;
}
}

void Win(){
    system("cls");
    UI.gotoxy(20,10);cout<<"!!!YOU WIN!!!";
    UI.gotoxy(20,13);cout<<"Presione cualquier tecla para ir al menu";
    getch();
    system("cls");
    win = true;
}

bool Gameover(){
    return perder;
}

bool GetWin(){
    return win;
}

void drawPal(){
    UI.gotoxy(15,0);cout<<palabraEle;
}

};
Ahorcado jueguito("print('hola_mundo')","while(condicion)","telefono");

void Game::Interface(){
jueguito.IntPers();
}

void Game::Loop(int delay){
    while(jueguito.Gameover() != true&&jueguito.GetWin()!=true){
        Interface();
    jueguito.verificacion();
    jueguito.Verify();
    Sleep(delay);
    }
}

int main(){
    jueguito.eleccion();
    jueguito.DrawPalabra(0,jueguito.GetTamPal());
    jueguito.DrawOrca();
juego.Loop(30);
    return 0;
}