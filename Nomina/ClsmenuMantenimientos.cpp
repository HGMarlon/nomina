#include "ClsmenuMantenimientos.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<cstring>
//Clases auxiliares
#include "Clsempleados.h"
#include "ClsBancos.h"
#include "ClsEmpresa.h"
#include "ClsPuestos.h"
#include "Clsdepartamentos.h"


using namespace std;

ClsmenuMantenimientos::ClsmenuMantenimientos()
{
    //ctor
}

ClsmenuMantenimientos::mmenuMantimientos()
{
    int choice2;
    do
    {
        system("cls");
        //Menu segundo nivel
        cout<<"-------------------------------"<<endl;
        cout<<" |   SISTEMA DE MANTENIMIENTO |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. CRUD empleados"<<endl;
        cout<<"2. CRUD empresa"<<endl;
        cout<<"3. CRUD puestos"<<endl;
        cout<<"4. CRUD departamentos"<<endl;
        cout<<"5. CRUD bancos"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/0]"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>choice2;
        switch(choice2)
        {
        case 1:
            {
                Clsempleados empleado;
                empleado.mmenuEmpleados();
            }
            break;
        case 2:
            {
                ClsEmpresa empresa;
                empresa.mmenuEmpresa();
            }
            break;
        case 3:
            {
                ClsPuestos puesto;
                puesto.mmenuPuestos();
            }
            break;
        case 4:
            {
                ClsDepartamentos departamento;
                departamento.mmenuDepartamentos();
            }
            break;
        case 5:
            {
                ClsBancos banco;
                banco.mmenuBancos();
            }
            break;
        case 0:
            break;
        default:
            cout<<"numero ingresado no válido, intente de nuevo.";
            getch();
            break;
        }
    }while(choice2!=0);
}

ClsmenuMantenimientos::~ClsmenuMantenimientos()
{
    //dtor
}
