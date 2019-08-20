#include <iostream>
#include "ListaDIas.h"
#include "conio.h"
#include "string.h"
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ListaDIas *nueva = new ListaDIas();

    string dia,actividad;
    while(true){
        cout<<"         Ingrese un dia: ";
        cin>>dia;
        transform(dia.begin(), dia.end(), dia.begin(), ::tolower);
        cout<<"         Ingrese una actividad: ";
        cin>>actividad;
        cout<<endl;
        nueva->agregarA(dia,actividad);
        nueva->imprimir();
        cout<<endl;
    }

    //transform(str.begin(), str.end(), str.begin(), ::toupper);

    //cin.getline();

    getch();
    return 0;
}
