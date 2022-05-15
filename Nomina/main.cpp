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
#include "Clsempleados.h"

using namespace std;

void escribirBitacora(int, string);

int main()
Clsbitacora bitacora;
    string accion="";


    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    // todoBitacora
    codigo = numeroUsuario;
    accion = "Ingreso al sistema";

    //escribirBitacora(codigo, accion);
ofstream bitacora("bitacora.txt", ios::app | ios::out);
    if (!bitacora)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
        exit ( 3 );
    }

	bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
	<<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
	<<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
	<<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
	bitacora.close();


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
                menuMantenimientos.mmenuMantimientos();
            }
            break;
        case 2:
            {
                cout<<"Usted esta en el apartado Generación nomina";
                getch();
            }
            break;
        case 3:
            {
                cout<<"Usted esta en el apartado informes nomina";
                getch();
            }
            break;
        case 4:
            {
                cout<<"Usted esta en el apartado Transferencia Bancaria";
                getch();
            }
            break;
        case 5:
            {
               cout<<"Usted esta en el apartado Generacion Poliza";
               getch();
            }
            break;
        case 6:
            {
                cout<<"Usted esta en el apartado Impuestos";
            }
            break;
        case 0:
            break;
        default:
            cout<<"Valor ingresado no vádido, intente de nuevo";
            getch();
            break;
        }
    }while(imenuPrincipal!=0);


    return 0;
}
