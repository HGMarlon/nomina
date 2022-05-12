#include "ClsEmpresa.h"

ClsEmpresa::ClsEmpresa()
{
    //ctor
}

ClsEmpresa::mmenuEmpresa()
{
    int iseleccionMenuEmpresa;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoEmpresa("registrosempresa.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoEmpresa )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearEmpresa();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION EMPLEADOS  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Empresa"<<endl;
        cout<<"2. Despliegue Empresa"<<endl;
        cout<<"3. Modifica Empresa"<<endl;
        cout<<"4. Imprimir Regisro de Empresa"<<endl;
        cout<<"5. Borra Empresa"<<endl;
        cout<<"6. Buscar Empresa"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuEmpresa;
        switch(iseleccionMenuEmpresa)
        {
        case 1:
            {
                system("cls");
                mnuevaEmpresa(archivoEmpresa);
                getch();
            }
            break;
        case 2:
            {
                system("cls");
                mconsultarRegistroEmpresa(archivoEmpresa);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                system("cls");
                mmodificarRegistroEmpresa(archivoEmpresa);
                getch();
            }
            break;
        case 4:
            {
                system("cls");
                mimprimirRegistroEmpresa(archivoEmpresa);
                getch();
            }
            break;
        case 5:
            {
                system("cls");
                meliminarRegistroEmpresa(archivoEmpresa);
            }
            break;
        case 6:
            {
                system("cls");
                mbuscarEmpresa(archivoEmpresa);
            }
            break;
        case 0:
            break;
        default:
            cout<<"Opción invalida, intenta de nuevo";
            getch();
            break;
        }
    }while(iseleccionMenuEmpresa!=0);
}

ClsEmpresa::~ClsEmpresa()
{
    //dtor
}
