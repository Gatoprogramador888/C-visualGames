#pragma once
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<direct.h>
#include<string>
#include<string.h>
#include<list>
#include<typeinfo>
#include<type_traits>
#define up 72
#define down 80
#define right 77
#define left 75
#define espace 32
#define enter 13
#define esc 27

using namespace std;

class Game{
public:
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void deleteDraw() = 0;
};

class Draw {
public:
	inline void draw(int x, int y) {
		HANDLE input = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(input, coord);
	}
}; Draw draw;

class Input {
public:
    int* GetKey(int* tecla) {
        if (_kbhit()) {
            *tecla = _getch();
        }
        return tecla;
    }

    int GetKey(int tecla) {
        if (_kbhit()) {
            tecla = _getch();
        }
        return tecla;
    }

    void Tecla(int tecla) {
        if (_kbhit()) {
            tecla = _getch();
        }
        cout << tecla << endl;
    }

    char* GetKey(char* tecla) {
        if (_kbhit()) {
            *tecla = _getch();
        }
        return tecla;
    }

    char GetKey(char tecla) {
        if (_kbhit()) {
            tecla = _getch();
        }
        return tecla;
    }
}; Input input;

class Objecto {
public:
    template<typename object>
    inline void InstansObject(list<object*>& obj) {
        obj.push_back(new object());
    }

    template<typename object>
    inline object* Object(int pos, list<object*> obj) {
        if (pos < obj.size()) {
            auto i = obj.begin();
            advance(i, pos);
            if (i != obj.end())return (*i);
            else return nullptr;
        }
    }

    template<typename object>
    inline void DeleteObject(list<object*>& obj,int pos) {
        int j = 0;
        for (auto i = obj.begin(); i != obj.end();i++) {
            if (j == pos) {
                delete (*i);
                i = obj.erase(i);
            }
            j++;
        }
    }

};Objecto Object;


struct GameP {
    bool aplication_close = false;
}; GameP game;
