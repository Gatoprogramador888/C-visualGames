#pragma once
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<direct.h>

using namespace std;

class File {
    public:
        string txt = ".txt",json = ".json",cpp = ".cpp",libreria = ".h";
    bool Crear(string nombre, string contenido) {
        ofstream archivo(nombre, ios::out);
        archivo << contenido;
        archivo.close();
        return archivo.fail();
    }

    bool Abrir(string nombre, string* contenido) {
        string Contenido;
        ifstream archivo(nombre);
        bool retorno = archivo.fail();
        while (archivo >> Contenido) {
            *contenido = Contenido;
        }
        return retorno;
    }

    bool Record(int record, string nombrearchivo) {
        ofstream archivo(nombrearchivo, ios::out);
        string rec = to_string(record);
        archivo << rec;
        archivo.close();
        return archivo.fail();
    }
}; File file;