//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include <string.h>

//Clases
#include "ClsmenuMantenimientos.h"
#include "Clsempleados.h"
#include "Clsnomina.h"
#include "ClsConceptos.h"
#include "ClsPuestos.h"
#include "ClsEmpresa.h"
#include "Clsencabezado.h"
#include "ClsReporte.h"

#define ENTER 13
#define BACKSPACE 8
using namespace std;


typedef struct {
    char usuario[10],contrasenia[10];
} tlogin;

void pausa();

void continuar(){
    printf("Presione una tecla para continuar\n\n");
    getch();
}


void crear(){
    FILE *arch;
    arch=fopen("login.dat","wb");
    if (arch==NULL)
        exit(1);
    fclose(arch);
}

void cargar(){
    FILE *arch;
    arch=fopen("login.dat","ab");
    if (arch==NULL){
        void crear();
    }else{
        tlogin login;
        printf("Ingrese usuario: ");
        scanf("%s",&login.usuario);
        fflush(stdin);
        printf("Ingrese password: ");
        scanf("%s",&login.contrasenia);
        fwrite(&login, sizeof(tlogin), 1, arch);
        fclose(arch);
    }
}

void listado(){

    FILE *arch;
    arch=fopen("login.dat","rb");
    if (arch==NULL)
        exit(1);
    tlogin login;
    fread(&login, sizeof(tlogin), 1, arch);

    printf("%s %s\n", "USUARIO", "PASSW0RD");

    while(!feof(arch))
    {
        printf("%s %s\n", login.usuario, login.contrasenia);
        fread(&login, sizeof(tlogin), 1, arch);
    }
    fclose(arch);
}



void login(){

    //Bitacora
    string codigo="";
    string accion="";

    //tiempo
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    FILE *arch;
    arch=fopen("login.dat","rb");
    if (arch==NULL)
        exit(1);

    char pusuario[10],pcontrasenia[10];
    cout<<"Ingrese usuario: ";
    cin>>pusuario;

    cout<<"Ingrese password: ";
    //cin>>pcontrasenia;

    char caracter;
    caracter = getch();

     string   password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

    strcpy(pcontrasenia, password.c_str());


    tlogin login;

    fread(&login, sizeof(tlogin), 1, arch);
    bool usuarioExiste = false;
    bool passwordCorrecto = false;

    while(!feof(arch)){

        if(strcmp(pusuario,login.usuario)==0){
            usuarioExiste = true;
        }

        if(strcmp(pcontrasenia,login.contrasenia)==0){
            passwordCorrecto = true;
        }
        fread(&login, sizeof(tlogin), 1, arch);

    }

    if (!usuarioExiste){
        cout<<endl<<endl<<"El usuario ingresado no existe";
    }
    if (!passwordCorrecto){
        cout<<endl<<endl<<"Password incorrecto";
    }

    if((usuarioExiste)&&(passwordCorrecto)){
        cout<<endl<<endl<<"Realizo login exitoso"<<endl;
        getch();
        int imenuPrincipal=0;

        //Bitacora
        codigo = pusuario;
        accion = "Ingreso al sistema";
        //escribirBitacora(codigo, accion);

        ofstream bitacora("Bitacora.txt", ios::app | ios::out);
        if (!bitacora)
        {
            cerr << "No se pudo abrir el archivo." << endl;
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 3 );
        }

        bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
        <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
        <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
        <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
        bitacora.close();

        //////////////////////////////////////////////////////////////////////
        ofstream usuario("Usuario.txt", ios::out);
        if (!usuario)
        {
            cerr << "No se pudo abrir el archivo." << endl;
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 3 );
        }

        usuario<<left<<setw(10)<< codigo;
        usuario.close();
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
                accion = "Ingreso a Mantenimiento";
                ofstream bitacora("Bitacora.txt", ios::app | ios::out);
                if (!bitacora)
                {
                    cerr << "No se pudo abrir el archivo." << endl;
                    cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                    exit ( 3 );
                }

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                bitacora.close();

                ClsmenuMantenimientos menuMantenimientos;
                menuMantenimientos.mmenuMantimientos();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Gen. Nomina";
                ofstream bitacora("Bitacora.txt", ios::app | ios::out);
                if (!bitacora)
                {
                    cerr << "No se pudo abrir el archivo." << endl;
                    cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                    exit ( 3 );
                }
                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                bitacora.close();
                system("cls");
                //Creando objetos
                Clsnomina nomina;
                Clsempleados empleado;
                ClsPuestos puesto;
                ClsConceptos concepto;
                ClsEmpresa empresa;
                Clsencabezado encabezado;
                ClsReporte reporte;
                // abrir el archivo en modo de lectura y escritura
                fstream archivoNomina("registronominas.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoNomina )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        nomina.mcrearNominas();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                // abrir el archivo en modo de lectura y escritura
                fstream archivoEmpleados("registrosempleados.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoEmpleados )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        empleado.mcrearEmpleados();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                fstream archivoPuestos("registrospuestos.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoPuestos )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        puesto.mcrearPuestos();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                fstream archivoEmpresa("registrosempresa.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoEmpresa )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        empresa.mcrearEmpresa();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                fstream archivoEncabezado("registroEncabezado.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoEncabezado )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        encabezado.mcrearEncabezado();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                fstream archivoConcepto("RegistrosConceptos.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoConcepto )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        encabezado.mcrearEncabezado();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                fstream archivoReporte("registrosreporte.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoReporte )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        reporte.mcrearReporte();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                nomina.mnuevaNomina(archivoNomina, archivoEmpleados, archivoPuestos, archivoEmpresa, archivoEncabezado, archivoConcepto, archivoReporte);
                archivoNomina.close();
                archivoEmpleados.close();
                archivoPuestos.close();
                archivoEmpresa.close();
                archivoEncabezado.close();
                archivoConcepto.close();
            }
            break;
        case 3:
            {
                accion = "Ingreso a Info. Nomina";
                ofstream bitacora("Bitacora.txt", ios::app | ios::out);
                if (!bitacora)
                {
                    cerr << "No se pudo abrir el archivo." << endl;
                    cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                    exit ( 3 );
                }
                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                bitacora.close();
                //Creando objetos
                Clsnomina nomina;
                Clsencabezado encabezado;
                // abrir el archivo en modo de lectura y escritura
                fstream archivoNomina("registronominas.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoNomina )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        nomina.mcrearNominas();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                fstream archivoEncabezado("registroEncabezado.dat", ios::in | ios::out | ios::binary);
                // salir del programa si fstream no puede abrir el archivo
                if ( !archivoEncabezado )
                    {
                        cerr << "No se pudo abrir el archivo." << endl;
                        encabezado.mcrearEncabezado();
                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                        exit ( 1 );
                    }
                nomina.mleerNomina(archivoNomina, archivoEncabezado);
                archivoNomina.close();
                archivoEncabezado.close();
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
            {
                accion = "Salio del Menu Principal";
                ofstream bitacora("Bitacora.txt", ios::app | ios::out);
                if (!bitacora)
                {
                    cerr << "No se pudo abrir el archivo." << endl;
                    cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                    exit ( 3 );
                }

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                bitacora.close();
            }
            break;
        default:
            cout<<"Valor ingresado no v�dido, intente de nuevo";
            getch();
            break;
        }
    }while(imenuPrincipal!=0);
    }

    fclose(arch);

}

int main(){
    bool bandera=false;
    char tecla;

    do
    {
        system("cls");
        cin.clear();
        cout<<"----------------------------------------"<<endl;
        cout<<"|----------BIENVENIDO AL LOGIN---------|"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout << "\t1 .- REGISTRAR USUARIOS" << endl;
        cout << "\t2 .- LISTAR USUARIOS" << endl;
        cout << "\t3 .- LOGIN" << endl;
        cout << "\t0 .- SALIR" << endl << endl;
        cout << "Elije una opcion: ";

        cin >> tecla;

		switch(tecla)
		{
			case '1':
				system("cls");
				cargar();
				pausa();
				break;

			case '2':
				system("cls");
				listado();
				pausa();
				break;

            case '3':
				system("cls");
				login();
				pausa();
				break;

			case '0':
				bandera=true;
				break;

			default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				pausa();
				break;
		}
    }while(bandera!=true);

    return 0;
}

void pausa()
{
    cout <<endl<<"Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}
