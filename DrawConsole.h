#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<list>

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