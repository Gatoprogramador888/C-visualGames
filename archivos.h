#include<fstream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

bool Crear(string nombre,string contenido){
    ofstream archivo(nombre,ios::out);
    archivo<<contenido;
    archivo.close();
    return archivo.fail();
}

bool Abrir(string nombre,string *contenido){
    string Contenido;
    ifstream archivo(nombre);
    bool retorno = archivo.fail();
    while(getline(archivo,Contenido)){
        *contenido = Contenido;
    }
    return retorno;
}

bool Record(int record,string nombrearchivo){
ofstream archivo(nombrearchivo,ios::out);
string rec = to_string(record);
archivo<<rec;
archivo.close();
return archivo.fail();
}