#include "Clsempleados.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

#include "ClsmenuMantenimientos.h"

using namespace std;

Clsempleados::Clsempleados(int iclaveEmpleado, string snombreEmpelado)
{
    //ctor
    mestablecerClave(iclaveEmpleado);
    mestablecerNombre(snombreEmpelado);
}

int Clsempleados::mobtenerClave() const
{
    return m_iclaveEmpleado;
}

void Clsempleados::mestablecerClave (int ienteroClave)
{
    m_iclaveEmpleado = ienteroClave;
}

//Funciones del nombre del empleado
string Clsempleados::mobtenerNombre() const
{
    return m_snombreEmpleado;
}

void Clsempleados::mestablecerNombre( string scadenaNombre )
{
   // copiar a lo m�s 20 caracteres de la cadena en nombree
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreEmpleado, svalorNombre, ilongitud );

   // anexar caracter nulo al final del nombre
   m_snombreEmpleado[ ilongitud ] = '\0';

}

Clsempleados::mcrearEmpleados()
{
    ofstream archivoEmpleados("registrosempleados.dat", ios::out | ios::binary);
    if(!archivoEmpleados)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    Clsempleados empleadoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEmpleados.write(reinterpret_cast<const char * > (&empleadoEnBlanco), sizeof(Clsempleados));
    }
}

int Clsempleados::mobtenerIndicador(const char * const iindicador)
{
    int m_iclaveEmpleado;

   // obtener el valor del n�mero de cuenta
   do {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iclaveEmpleado;

   } while ( m_iclaveEmpleado < 1 || m_iclaveEmpleado > 100 );

   return m_iclaveEmpleado;
}

void Clsempleados::mnuevoEmpleado(fstream &archivoEmpleados)
{
   Clsempleados empleado;
   int m_iclaveEmpleado = mobtenerIndicador( "Escriba el numero de empleado" );

   // desplazar el apuntador de posici�n del archivo hasta el registro correcto en el archivo
   archivoEmpleados.seekg(
      ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );

   // leer el registro del archivo
   archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );

   // crear el registro, si �ste no existe ya
   if ( empleado.mobtenerClave() == 0 ) {

      char m_snombreEmpleado[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 20 ) >> m_snombreEmpleado;

      // usar valores para llenar los valores de la clave
      empleado.mestablecerNombre( m_snombreEmpleado );
      empleado.mestablecerClave( m_iclaveEmpleado );

      // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
      archivoEmpleados.seekp( ( m_iclaveEmpleado - 1 ) *
         sizeof( Clsempleados ) );

      // insertar el registro en el archivo
      archivoEmpleados.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Clsempleados ) );

        cout << "Empleado agregado con exito.";

   }

   // mostrar error si la cuenta ya existe
   else
   {
       cerr << "La cuenta #" << m_iclaveEmpleado << " ya contiene informacion." << endl;
       getch();
   }
}

void Clsempleados::mostrarLineaEmpleado( const Clsempleados &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerClave()
          << setw( 20 ) << registro.mobtenerNombre().data()
          << endl;
}

void Clsempleados::mconsultarRegistroEmpleados(fstream &archivoEmpleados)
{
   cout << left << setw( 10 ) << "Clave" << setw( 20 )
       << "Nombre" << endl;

   // colocar el apuntador de posici�n de archivo al principio del archivo de registros
   archivoEmpleados.seekg( 0 );

   // leer el primer registro del archivo de registros
   Clsempleados empleado;
   archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoEmpleados.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.mobtenerClave() != 0 )
         mostrarLineaEmpleado(empleado);

      // leer siguiente registro del archivo de registros
      archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Clsempleados ) );

   }
}

void Clsempleados::mmostrarLineaRegistroEmpleados( ostream &salida, const Clsempleados &registro )
{
       salida << left << setw( 10 ) << registro.mobtenerClave()
          << setw( 20 ) << registro.mobtenerNombre().data()
          << endl;
}



void Clsempleados::mmodificarRegistroEmpleados( fstream &archivoEmpleados )
{

   Clsempleados empleado;
   int m_iclaveEmpleado = mobtenerIndicador("Ingrese el nombre del empleado");

   archivoEmpleados.seekg(
      ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );

   // leer el primer registro del archivo
   archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );

   // actualizar el registro
   if ( empleado.mobtenerClave() != 0 ) {
      mmostrarLineaRegistroEmpleados( cout, empleado );

      cout << "\nEscriba el nombre: ";
      char m_snombreEmpleado [ 20 ];
      cin >> m_snombreEmpleado;

      // actualizar el saldo del registro
      empleado.mestablecerNombre( m_snombreEmpleado );
      mmostrarLineaRegistroEmpleados( cout, empleado );

      // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
      archivoEmpleados.seekp(
         ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      archivoEmpleados.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Clsempleados ) );

        cout << "Empleado modificado con �xito.";

   } // fin de instrucci�n if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << m_iclaveEmpleado
         << " no tiene informacion." << endl;
}

void Clsempleados::mimprimirRegistroEmpleados(fstream &archivoEmpleado)
{
    Clsempleados empleado;
    ofstream imprimir("registrodeempleados.txt", ios::out);

   // salir del programa si ofstream no puede crear el archivo
   if ( !imprimir ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucci�n if

   imprimir << left << setw( 10 ) << "Clave" << setw( 20 )
       << "nombre: "<< endl;
   // colocar el apuntador de posici�n de archivo al principio del archivo de registros
   archivoEmpleado.seekg( 0 );

   // leer el primer registro del archivo de registros
   archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoEmpleado.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.mobtenerClave() != 0 )
         mmostrarLineaRegistroEmpleados( imprimir, empleado );

      // leer siguiente registro del archivo de registros
      archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Clsempleados ) );

   }
   cout << "archivo creado con �xito con el nombre de: regisrodeempleados";
}

Clsempleados::mmenuEmpleados()
{
    int iseleccionMenuEmpleados;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoEmpleados("registrosempleados.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoEmpleados )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearEmpleados();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION EMPLEADOS  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Empleados"<<endl;
        cout<<"2. Despliegue Empleados"<<endl;
        cout<<"3. Modifica Empleados"<<endl;
        cout<<"4. Imprimir Regisro de Empleados"<<endl;
        cout<<"5. Borra Empleados"<<endl;
        cout<<"6. Buscar Empleados"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuEmpleados;
        switch(iseleccionMenuEmpleados)
        {
        case 1:
            {
                system("cls");
                mnuevoEmpleado(archivoEmpleados);
                getch();
            }
            break;
        case 2:
            {
                system("cls");
                mconsultarRegistroEmpleados(archivoEmpleados);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                system("cls");
                mmodificarRegistroEmpleados(archivoEmpleados);
                getch();
            }
            break;
        case 4:
            {
                system("cls");
                mimprimirRegistroEmpleados(archivoEmpleados);
                getch();
            }
            break;
        }
    }while(iseleccionMenuEmpleados!=0);
}

Clsempleados::~Clsempleados()
{
    //dtor
}
