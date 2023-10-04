#include <iostream>
#include "Input.h"

int main(){
while(true){
    char tecla;
    Input.GetKey(&tecla);
    cout<<tecla<<endl;
    if(tecla == 'e')cout<<"e\n";
}
    return 0;
}