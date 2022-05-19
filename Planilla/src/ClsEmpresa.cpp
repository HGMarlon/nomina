#include "ClsEmpresa.h"

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

ClsEmpresa::ClsEmpresa(int iclaveEmpresa, string snombreEmpresa, string sCorreoEmpresa, string sActividadEconomica, string sNitEmpresa, string sDireccionEmpresa, string sTelefonoEmpresa, string sNumeroEmpleados)
{
    //ctor
    mestablecerClaveEmpresa(iclaveEmpresa);
    mestablecerNombreEmpresa(snombreEmpresa);
    mestablecerCorreoE(sCorreoEmpresa);
    mestablecerActividadE(sActividadEconomica);
    mestablecerNitE(sNitEmpresa);
    mestablecerDireccionE(sDireccionEmpresa);
    mestablecerTelefonoE(sTelefonoEmpresa);
    mestablecerNumeroEmpleadosE(sNumeroEmpleados);
}

int ClsEmpresa::mobtenerClaveE() const
{
    return m_iclaveEmpresa;
}

void ClsEmpresa::mestablecerClaveEmpresa (int ienteroClaveE)
{
    m_iclaveEmpresa = ienteroClaveE;
}

//Funciones del nombre de la empresa
string ClsEmpresa::mobtenerNombreE() const
{
    return m_snombreEmpresa;
}

void ClsEmpresa::mestablecerNombreEmpresa( string scadenaNombreE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreE = scadenaNombreE.data();
   int ilongitud = strlen( svalorNombreE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreEmpresa, svalorNombreE , ilongitud );

   // anexar caracter nulo al final del nombre
   m_snombreEmpresa[ ilongitud ] = '\0';

}

//Funciones del correo electronico de la empresa
string ClsEmpresa::mobtenerCorreoE() const
{
    return m_sCorreoEmpresa;
}

void ClsEmpresa::mestablecerCorreoE( string sCorreoE )
{
    // copiar a lo más 20 caracteres de la cadena del telefono
   const char *svalorCorreoE = sCorreoE.data();
   int ilongitud = strlen( svalorCorreoE );
   ilongitud = ( ilongitud< 20 ? ilongitud : 19 );
   strncpy( m_sCorreoEmpresa, svalorCorreoE, ilongitud );

   // anexar caracter nulo al final de la cadena de la direccion
   m_sCorreoEmpresa[ ilongitud ] = '\0';
}

//Funciones actividad de la empresa
string ClsEmpresa::mobtenerActividadE() const
{
    return m_sActividadEconomica;
}

void ClsEmpresa::mestablecerActividadE( string sActividadE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorActividadE = sActividadE.data();
   int ilongitud = strlen( svalorActividadE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sActividadEconomica, svalorActividadE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sActividadEconomica[ ilongitud ] = '\0';

}

//Funciones nit de la empresa
string ClsEmpresa::mobtenerNitE() const
{
    return m_sNitEmpresa;
}

void ClsEmpresa::mestablecerNitE( string sNitE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNitE = sNitE.data();
   int ilongitud = strlen( svalorNitE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNitEmpresa, svalorNitE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sNitEmpresa[ ilongitud ] = '\0';

}

//Funciones direccion de la empresa
string ClsEmpresa::mobtenerDireccionE() const
{
    return m_sDireccionEmpresa;
}

void ClsEmpresa::mestablecerDireccionE( string sDireccionE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorDireccionE = sDireccionE.data();
   int ilongitud = strlen( svalorDireccionE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sDireccionEmpresa, svalorDireccionE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sDireccionEmpresa[ ilongitud ] = '\0';

}

//Funciones telefono de la empresa
string ClsEmpresa::mobtenerTelefonoE() const
{
    return m_sTelefonoEmpresa;
}

void ClsEmpresa::mestablecerTelefonoE( string sTelefonoE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorTelefonoE = sTelefonoE.data();
   int ilongitud = strlen( svalorTelefonoE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sTelefonoEmpresa, svalorTelefonoE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sTelefonoEmpresa[ ilongitud ] = '\0';

}

//Funciones numero de empleados de la empresa
string ClsEmpresa::mobtenerNumeroEmpleadosE() const
{
    return m_sNumeroEmpleados;
}

void ClsEmpresa::mestablecerNumeroEmpleadosE( string sEmpleadosE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorEmpleadosE = sEmpleadosE.data();
   int ilongitud = strlen( svalorEmpleadosE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNumeroEmpleados, svalorEmpleadosE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sNumeroEmpleados[ ilongitud ] = '\0';

}

ClsEmpresa::mcrearEmpresa()
{
    ofstream archivoEmpresa("registrosempresa.dat", ios::out | ios::binary);
    if(!archivoEmpresa)
    {
        cerr<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    ClsEmpresa empresaEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEmpresa.write(reinterpret_cast<const char * > (&empresaEnBlanco), sizeof(ClsEmpresa));
    }
}

int ClsEmpresa::mobtenerIndicadorE(const char * const iindicador)
{
    int m_iclaveEmpresa;

   // obtener el valor del número de empresa
   do {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iclaveEmpresa;

   } while ( m_iclaveEmpresa < 1 || m_iclaveEmpresa > 100 );

   return m_iclaveEmpresa;
}

void ClsEmpresa::mnuevaEmpresa(fstream &archivoEmpresa)
{
   ClsEmpresa empresa;
   int m_iclaveEmpresa = mobtenerIndicadorE( "Escriba el numero de empresa" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoEmpresa.seekg(
      ( m_iclaveEmpresa - 1 ) * sizeof( ClsEmpresa ) );

   // leer el registro del archivo
   archivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );

    // crear el registro, si éste no existe ya
   if ( empresa.mobtenerClaveE() == 0 ) {

      char m_snombreEmpresa[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba el nombre de la Empresa: " << endl;
      cin >> setw( 20 ) >> m_snombreEmpresa;
      cout << "Escriba el correo electronico de la empresa:" << endl;
      cin >> setw( 20 ) >> m_sCorreoEmpresa;
      cout << "Escriba actividad economica de la empresa:" << endl;
      cin >> setw( 20 ) >>m_sActividadEconomica ;
      cout << "Escriba el nit de la empresa:" << endl;
      cin >> setw( 14 ) >>m_sNitEmpresa;
      cout << "Escriba la direccion de la empresa:" << endl;
      cin >> setw( 20 ) >>m_sDireccionEmpresa;
      cout << "Escriba el telefono de la empresa:" << endl;
      cin >> setw( 9 ) >>m_sTelefonoEmpresa;
      cout << "Escriba el numero de empleados:" << endl;
      cin >> setw( 20 ) >>m_sNumeroEmpleados;

      // usar valores para llenar los valores de la clave
      empresa.mestablecerNombreEmpresa( m_snombreEmpresa );
      empresa.mestablecerClaveEmpresa( m_iclaveEmpresa );
      empresa.mestablecerCorreoE(m_sCorreoEmpresa);
      empresa.mestablecerActividadE(m_sActividadEconomica);
      empresa.mestablecerNitE(m_sNitEmpresa);
      empresa.mestablecerDireccionE(m_sDireccionEmpresa);
      empresa.mestablecerTelefonoE(m_sTelefonoEmpresa);
      empresa.mestablecerNumeroEmpleadosE(m_sNumeroEmpleados);

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEmpresa.seekp( ( m_iclaveEmpresa - 1 ) *
         sizeof( ClsEmpresa ) );

      // insertar el registro en el archivo
      archivoEmpresa.write(
         reinterpret_cast< const char * >( &empresa ),
         sizeof( ClsEmpresa ) );

        cout << "Empresa agregada con exito.";

   }
}
void ClsEmpresa::mostrarLineaEmpresa( const ClsEmpresa &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerClaveE()
          << setw( 20 ) << registro.mobtenerNombreE().data()
          << setw( 20 ) << registro.mobtenerCorreoE().data()
          << setw( 20 ) << registro.mobtenerActividadE().data()
          << setw( 14 ) << registro.mobtenerNitE().data()
          << setw( 20 ) << registro.mobtenerDireccionE().data()
          << setw( 9 ) << registro.mobtenerTelefonoE().data()
          << setw( 20 ) << registro.mobtenerNumeroEmpleadosE().data()
          << endl;
}

void ClsEmpresa::mconsultarRegistroEmpresa(fstream &archivoEmpresa)
{
   cout << left << setw( 10 ) << "Clave" << setw( 20 )
       << "Nombre" << setw( 20 ) << "Correo"<<setw( 20 )<<
       "Actividad"<<setw( 14 )<< "Nit "<<
        setw( 20 )<< "Direccion"<< setw( 9 )<< "Telefono "
        << setw( 20 )<< "Empleados " << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoEmpresa.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsEmpresa empresa;
   archivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoEmpresa.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empresa.mobtenerClaveE() != 0 )
         mostrarLineaEmpresa(empresa);

      // leer siguiente registro del archivo de registros
      archivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
         sizeof( ClsEmpresa ) );

   }
}

void ClsEmpresa::mmostrarLineaRegistroEmpresa( ostream &salida, const ClsEmpresa &registro )
{
       salida << left << setw( 10 ) << registro.mobtenerClaveE()
          << setw( 20 ) << registro.mobtenerNombreE().data()
          << setw( 20 ) << registro.mobtenerCorreoE().data()
          << setw( 20 ) << registro.mobtenerActividadE().data()
          << setw( 14 ) << registro.mobtenerNitE().data()
          << setw( 20 ) << registro.mobtenerDireccionE().data()
          << setw( 9 )  << registro.mobtenerTelefonoE().data()
          << setw( 20 ) << registro.mobtenerNumeroEmpleadosE().data()
          << endl;
}


void ClsEmpresa::mmodificarRegistroEmpresa( fstream &archivoEmpresa )
{

   ClsEmpresa empresa;
   int m_iclaveEmpresa= mobtenerIndicadorE("Ingrese el nombre de la empresa");

   archivoEmpresa.seekg(
      ( m_iclaveEmpresa - 1 ) * sizeof( ClsEmpresa ) );

   // leer el primer registro del archivo
   archivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );

   // actualizar el registro
   if ( empresa.mobtenerClaveE() != 0 ) {
      mmostrarLineaRegistroEmpresa( cout, empresa );

      cout << "\nEscriba el nombre: ";
      char m_snombreEmpresa [ 20 ];
      cin >> m_snombreEmpresa;

      cout << "Escriba el correo electronico de la empresa:";
      char m_sCorreoEmpresa [ 20 ];
      cin >> m_snombreEmpresa;

      cout << "Escriba actividad economica de la empresa:";
      char m_sActividadEconomica [ 20 ];
      cin >> m_sActividadEconomica;

      cout << "Escriba el nit de la empresa:";
      char m_sNitEmpresa [ 14 ];
      cin >> m_sActividadEconomica;

      cout << "Escriba la direccion de la empresa:";
      char m_sDireccionEmpresa [ 20 ];
      cin >> m_sDireccionEmpresa;

      cout << "Escriba el telefono de la empresa:";
      char m_sTelefonoEmpresa[ 9 ];
      cin >> m_sTelefonoEmpresa;

      cout << "Escriba el numero de empleados:";
      char m_sNumeroEmpleados [ 20 ];
      cin >> m_sNumeroEmpleados;

      // actualizar el saldo del registro
      empresa.mestablecerNombreEmpresa( m_snombreEmpresa );
      mmostrarLineaRegistroEmpresa( cout, empresa );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEmpresa.seekp(
         ( m_iclaveEmpresa - 1 ) * sizeof( ClsEmpresa ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      archivoEmpresa.write(
         reinterpret_cast< const char * >( &empresa ),
         sizeof( ClsEmpresa ) );

        cout << "Empresa modificada con éxito.";

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La clave #" << m_iclaveEmpresa
         << " no tiene informacion." << endl;
}

void ClsEmpresa::mimprimirRegistroEmpresa(fstream &archivoEmpresa)
{
    ClsEmpresa empresa;
    ofstream imprimir("registrodeempresa.txt", ios::out);

   // salir del programa si ofstream no puede crear el archivo
   if ( !imprimir ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   imprimir << left << setw( 10 ) << "Clave" << setw( 20 )
       << "Nombre: " << setw( 20 ) << "Correo"<<setw( 20 )<<
       "Actividad"<<setw( 14 )<< "Nit "<<
        setw( 20 )<< "Direccion"<< setw( 9 )<< "Telefono "
        << setw( 20 )<< "Empleados " << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoEmpresa.seekg( 0 );

   // leer el primer registro del archivo de registros
   archivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoEmpresa.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empresa.mobtenerClaveE() != 0 )
         mmostrarLineaRegistroEmpresa( imprimir, empresa );

      // leer siguiente registro del archivo de registros
      archivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
         sizeof( ClsEmpresa ) );

   }
   cout << "archivo creado con éxito con el nombre de: registroempresa";
}

void ClsEmpresa::meliminarRegistroEmpresa(fstream &archivoEmpresa)
{
    int iindicador= mobtenerIndicadorE( "Escriba la clave de la Empresa a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoEmpresa.seekg(
      ( iindicador - 1 ) * sizeof( ClsEmpresa ) );

   // leer el registro del archivo
   ClsEmpresa empresa;
   archivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );

   // eliminar el registro, si es que existe en el archivo
   if ( empresa.mobtenerClaveE() != 0 ) {
      ClsEmpresa empresaEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEmpresa.seekp( ( iindicador - 1 ) *
         sizeof( ClsEmpresa ) );

      // reemplazar el registro existente con un registro en blanco
      archivoEmpresa.write(
         reinterpret_cast< const char * >( &empresaEnBlanco ),
         sizeof( ClsEmpresa ) );

      cout << "Empresa clave #" << iindicador << " eliminado correctamente.\n";

   }
}
void ClsEmpresa::mbuscarEmpresa(fstream &archivoEmpresa)
{
    int iindicador = mobtenerIndicadorE( "Escriba la clave de la Empresa que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoEmpresa.seekg(
      ( iindicador - 1 ) * sizeof( ClsEmpresa ) );

   // leer el primer registro del archivo
   ClsEmpresa empresa;
   archivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( empresa.mobtenerClaveE() != 0 ) {
      mmostrarLineaRegistroEmpresa( cout, empresa );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "La clave #" << iindicador
         << " no tiene informacion." << endl;
   }
   getch();
}

ClsEmpresa::mmenuEmpresa()
{
    string accion="";
    //tiempo
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    string codigo;
    fstream abrir;
    int found=0;
    abrir.open("Usuario.txt", ios::in);
    if (!abrir)
    {
        cerr << "Archivo Usuario no Encontrado" << endl;
        exit ( 3 );
    }
    else
    {
        abrir>>codigo;
    }

    ofstream bitacora("Bitacora.txt", ios::app | ios::out);
    if (!bitacora)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
        exit ( 3 );
    }


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
        cout<<"|   SISTEMA GESTION EMPRESA  |"<<endl;
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
                accion = "Ingreso a Agre. Empresa";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mnuevaEmpresa(archivoEmpresa);
                getch();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Cons. Empresa";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mconsultarRegistroEmpresa(archivoEmpresa);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                accion = "Ingreso a Mod. Empresa";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mmodificarRegistroEmpresa(archivoEmpresa);
                getch();
            }
            break;
        case 4:
            {
                accion = "Ingreso a Impri. Empresa";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mimprimirRegistroEmpresa(archivoEmpresa);
                getch();
            }
            break;
        case 5:
            {
                accion = "Ingreso a Elim. Empresa";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                meliminarRegistroEmpresa(archivoEmpresa);
            }
            break;
        case 6:
            {
                accion = "Ingreso a Buscar. Empresa";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mbuscarEmpresa(archivoEmpresa);
            }
            break;
        case 0:
            {
                accion = "Salio de Gestion Empresa";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/
            }
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

