#pragma once
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
//#define left 75
#define espace 32
#define enter 13
#define esc 27

using namespace std;

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

char *GetKey(char* tecla){
    if(kbhit()){
        *tecla = getch(); 
    }
    return tecla;
}
};
input Input;