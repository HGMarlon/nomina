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
                cout<<"Usted esta en el apartado Generaci�n nomina";
                Clsnomina nomina;
                nomina.mmenuNominas();
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
        cout << "\t4 .- SALIR" << endl << endl;
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

			case '4':
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
