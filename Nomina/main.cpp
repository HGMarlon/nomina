//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>

//Clases
#include "ClsmenuMantenimientos.h"

using namespace std;

int main()
{
    int imenuPrincipal=0;
    //Menu principal
	do
    {
        system("cls");

        cout<<"----------------------------------------"<<endl;
        cout<<"|---BIENVENIDO AL SISTEMA DE NOMINAS---|"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"1. MANTENIMIENTOS"<<endl;
        cout<<"2. GENERACION NOMINA"<<endl;
        cout<<"3. INFORMES NOMINAS"<<endl;
        cout<<"4. TRANSFERENCIA BANCARIA"<<endl;
        cout<<"5. GENERACION POLIZA"<<endl;
        cout<<"6. IMPUESTOS"<<endl;
        cout<<"0. EXIT"<<endl;

        cout<<"-------------------------------"<<endl;
        cout<<"OPCIONES A ESCOGER :     [1/2/3/4/5/6/0]"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"INGRESA TU OPCION : ";
        cin>>imenuPrincipal;
        switch (imenuPrincipal)
        {
        case 1:
            {
                ClsmenuMantenimientos menuMantenimientos;
            }
            break;
        }
    }while(imenuPrincipal!=0);


    return 0;
}
