#include "ClsBancos.h"

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

ClsBancos::ClsBancos(string snombreBanco, int iclaveBanco, string snombreUsuarioBancos, string ssaldoCuentaBancos, string stipoCuentaBancos)
{
    //ctor
    mestablecerNombreBancos(snombreBanco);
    mestablecerClaveBancos(iclaveBanco);
    mestablecerNombreUsuarioBancos(snombreUsuarioBancos);
    mestablecerSaldoCuentaBancos(ssaldoCuentaBancos);
    mestablecerTipoCuentaBancos(stipoCuentaBancos);
}

int ClsBancos::mobtenerClaveBancos() const
{
    return m_iNumeroCuenta;
}

void ClsBancos::mestablecerClaveBancos (int ienteroClaveBancos)
{
    m_iNumeroCuenta = ienteroClaveBancos;
}

string ClsBancos::mobtenerNombreBancos() const
{
    return m_sNombreBanco;
}

void ClsBancos::mestablecerNombreBancos( string scadenaNombreBancos )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreBancos = scadenaNombreBancos.data();
   int ilongitudBancos = strlen( svalorNombreBancos );
   ilongitudBancos = ( ilongitudBancos < 20 ? ilongitudBancos : 19 );
   strncpy( m_sNombreBanco, svalorNombreBancos, ilongitudBancos );

   // anexar caracter nulo al final del nombre
   m_sNombreBanco[ ilongitudBancos ] = '\0';

}

string ClsBancos::mobtenerNombreUsuarioBancos() const
{
    return m_sNombreUsuario;
}

void ClsBancos::mestablecerNombreUsuarioBancos( string scadenaNombreUsuarioBancos )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreUsuarioBancos = scadenaNombreUsuarioBancos.data();
   int ilongitudUsuarioBancos = strlen( svalorNombreUsuarioBancos );
   ilongitudUsuarioBancos = ( ilongitudUsuarioBancos < 20 ? ilongitudUsuarioBancos : 19 );
   strncpy( m_sNombreUsuario, svalorNombreUsuarioBancos, ilongitudUsuarioBancos );

   // anexar caracter nulo al final del nombre
   m_sNombreUsuario[ ilongitudUsuarioBancos ] = '\0';

}

string ClsBancos::mobtenerSaldoCuentaBancos() const
{
    return m_iSaldoCuenta;
}

void ClsBancos::mestablecerSaldoCuentaBancos( string scadenaSaldoCuentaBancos )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorSaldoCuentaBancos = scadenaSaldoCuentaBancos.data();
   int ilongitudSaldoCuentaBancos = strlen( svalorSaldoCuentaBancos );
   ilongitudSaldoCuentaBancos = ( ilongitudSaldoCuentaBancos < 20 ? ilongitudSaldoCuentaBancos : 19 );
   strncpy( m_iSaldoCuenta, svalorSaldoCuentaBancos, ilongitudSaldoCuentaBancos );

   // anexar caracter nulo al final del nombre
   m_iSaldoCuenta[ ilongitudSaldoCuentaBancos ] = '\0';

}

string ClsBancos::mobtenerTipoCuentaBancos() const
{
    return m_iTipoCuenta;
}

void ClsBancos::mestablecerTipoCuentaBancos( string scadenaTipoCuentaBancos )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorTipoCuentaBancos = scadenaTipoCuentaBancos.data();
   int ilongitudTipoCuentaBancos = strlen( svalorTipoCuentaBancos );
   ilongitudTipoCuentaBancos = ( ilongitudTipoCuentaBancos < 20 ? ilongitudTipoCuentaBancos : 19 );
   strncpy( m_iTipoCuenta, svalorTipoCuentaBancos, ilongitudTipoCuentaBancos );

   // anexar caracter nulo al final del nombre
   m_iTipoCuenta[ ilongitudTipoCuentaBancos ] = '\0';

}

ClsBancos::mcrearBancos()
{
    ofstream archivoBancos("registrosbancos.dat", ios::out | ios::binary);
    if(!archivoBancos)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    ClsBancos bancosEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoBancos.write(reinterpret_cast<const char * > (&bancosEnBlanco), sizeof(ClsBancos));
    }
}

int ClsBancos::mobtenerIndicadorBancos(const char * const iindicadorBancos)
{
    int m_iNumeroCuenta;

   // obtener el valor del número de cuenta
   do {
      cout << iindicadorBancos << " (1 - 100): ";
      cin >> m_iNumeroCuenta;

   } while ( m_iNumeroCuenta < 1 || m_iNumeroCuenta > 100 );

   return m_iNumeroCuenta;
}


void ClsBancos::mnuevoBancos(fstream &archivoBancos)
{
   ClsBancos banco;
   int m_iNumeroCuenta = mobtenerIndicadorBancos( "Escriba el numero de cuenta del banco" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoBancos.seekg(
      ( m_iNumeroCuenta - 1 ) * sizeof( ClsBancos ) );

   // leer el registro del archivo
   archivoBancos.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // crear el registro, si éste no existe ya
   if ( banco.mobtenerClaveBancos() == 0 ) {

      char m_sNombreBanco[ 20 ];
      char m_sNombreUsuario[20];
      char m_iSaldoCuenta[20];
      char m_iTipoCuenta[20];

      // el usuario introduce el nombre
      cout << "Escriba el nombre del Banco: " << endl;
      cin >> setw( 20 ) >> m_sNombreBanco;
      cout << "Escriba el nombre del Usuario: " << endl;
      cin >> setw( 20 ) >> m_sNombreUsuario;
      cout << "Escriba el saldo de la Cuenta: " << endl;
      cin >> setw( 20 ) >> m_iSaldoCuenta;
      cout << "Escriba el Tipo de la Cuenta: " << endl;
      cin >> setw( 20 ) >> m_iTipoCuenta;

      // usar valores para llenar los valores de la clave
      banco.mestablecerNombreBancos( m_sNombreBanco );
      banco.mestablecerClaveBancos( m_iNumeroCuenta );
      banco.mestablecerNombreUsuarioBancos( m_sNombreUsuario );
      banco.mestablecerSaldoCuentaBancos( m_iSaldoCuenta );
      banco.mestablecerTipoCuentaBancos( m_iTipoCuenta );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoBancos.seekp( ( m_iNumeroCuenta - 1 ) *
         sizeof( ClsBancos ) );

      // insertar el registro en el archivo
      archivoBancos.write(
         reinterpret_cast< const char * >( &banco ),
         sizeof( ClsBancos ) );

        cout << "Banco agregado con exito.";

   }

   // mostrar error si la cuenta ya existe
   else
   {
       cerr << "La cuenta #" << m_iNumeroCuenta << " ya contiene informacion." << endl;
       getch();
   }
}

void ClsBancos::mostrarLineaBancos( const ClsBancos &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerClaveBancos()
          << setw( 20 ) << registro.mobtenerNombreBancos().data()
          << setw( 20 ) << registro.mobtenerNombreUsuarioBancos().data()
          << setw( 20 ) << registro.mobtenerSaldoCuentaBancos().data()
          << setw( 20 ) << registro.mobtenerTipoCuentaBancos().data()
          << endl;
}

void ClsBancos::mconsultarRegistroBancos(fstream &archivoBancos)
{
   cout << left << setw( 20 ) << "Nombre del Banco" << setw( 10 )
   << "Numero de Cuenta" << setw( 20 )
   << "Nombre del Usuario" << setw( 20 )
   << "Saldo en la Cuenta" << setw( 20 )
   << "Tipo de Cuenta"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoBancos.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsBancos banco;
   archivoBancos.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoBancos.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( banco.mobtenerClaveBancos() != 0 )
         mostrarLineaBancos(banco);

      // leer siguiente registro del archivo de registros
      archivoBancos.read( reinterpret_cast< char * >( &banco ),
         sizeof( ClsBancos ) );

   }
}

void ClsBancos::mmostrarLineaRegistroBancos( ostream &salida, const ClsBancos &registro )
{
       salida << left << setw( 10 ) << registro.mobtenerClaveBancos()
          << setw( 20 ) << registro.mobtenerNombreBancos().data()
          << setw( 20 ) << registro.mobtenerNombreUsuarioBancos().data()
          << setw( 20 ) << registro.mobtenerSaldoCuentaBancos().data()
          << setw( 20 ) << registro.mobtenerTipoCuentaBancos().data()
          << endl;
}

void ClsBancos::mmodificarRegistroBancos( fstream &archivoBancos )
{

   ClsBancos banco;
   int m_iNumeroCuenta = mobtenerIndicadorBancos("Ingrese el nombre del Banco");

   archivoBancos.seekg(
      ( m_iNumeroCuenta - 1 ) * sizeof( ClsBancos ) );

   // leer el primer registro del archivo
   archivoBancos.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // actualizar el registro
   if ( banco.mobtenerClaveBancos() != 0 ) {
      mmostrarLineaRegistroBancos( cout, banco );

      cout << "\nEscriba el Nombre del Banco: ";
      char m_sNombreBanco[20];
      cin >> m_sNombreBanco;
      cout << "\nEscriba el Nombre del Usuario: ";
      char m_sNombreUsuario[20];
      cin >> m_sNombreUsuario;
      cout << "\nEscriba el Saldo de la Cuenta ";
      char m_iSaldoCuenta[20];
      cin >> m_iSaldoCuenta;
      cout << "\nEscriba el Tipo de la Cuenta ";
      char m_iTipoCuenta[20];
      cin >> m_iTipoCuenta;



      // actualizar el saldo del registro
      banco.mestablecerNombreBancos( m_sNombreBanco );
      banco.mestablecerNombreUsuarioBancos( m_sNombreUsuario );
      banco.mestablecerSaldoCuentaBancos( m_iSaldoCuenta );
      banco.mestablecerTipoCuentaBancos( m_iTipoCuenta );
      mmostrarLineaRegistroBancos( cout, banco );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoBancos.seekp(
         ( m_iNumeroCuenta - 1 ) * sizeof( ClsBancos ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      archivoBancos.write(
         reinterpret_cast< const char * >( &banco ),
         sizeof( ClsBancos ) );

        cout << "Banco modificado con éxito.";

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La Cuenta #" << m_iNumeroCuenta
         << " no tiene informacion." << endl;
}

void ClsBancos::mimprimirRegistroBancos(fstream &archivoBanco)
{
    ClsBancos banco;
    ofstream imprimirBancos("registrodebancos.txt", ios::out);

   // salir del programa si ofstream no puede crear el archivo
   if ( !imprimirBancos ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   imprimirBancos << left << setw( 20 ) << "Nombre del Banco" << setw( 10 )
   << "Numero de Cuenta" << setw( 20 )
   << "Nombre del Usuario" << setw( 20 )
   << "Saldo en la Cuenta" << setw( 20 )
   << "Tipo de Cuenta"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoBanco.seekg( 0 );

   // leer el primer registro del archivo de registros
   archivoBanco.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoBanco.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( banco.mobtenerClaveBancos() != 0 )
         mmostrarLineaRegistroBancos( imprimirBancos, banco );

      // leer siguiente registro del archivo de registros
      archivoBanco.read( reinterpret_cast< char * >( &banco ),
         sizeof( ClsBancos ) );

   }
   cout << "archivo creado con éxito con el nombre de: regisrodebancos";
}

void ClsBancos::meliminarRegistroBancos(fstream &archivoBancos)
{
    int iindicadorBancos= mobtenerIndicadorBancos( "Escriba la Cuenta a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoBancos.seekg(
      ( iindicadorBancos - 1 ) * sizeof( ClsBancos ) );

   // leer el registro del archivo
   ClsBancos banco;
   archivoBancos.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( banco.mobtenerClaveBancos() != 0 ) {
      ClsBancos bancosEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoBancos.seekp( ( iindicadorBancos - 1 ) *
         sizeof( ClsBancos ) );

      // reemplazar el registro existente con un registro en blanco
      archivoBancos.write(
         reinterpret_cast< const char * >( &bancosEnBlanco ),
         sizeof( ClsBancos ) );

      cout << "La Cuenta #" << iindicadorBancos << " eliminada correctamente.\n";

   }

   // mostrar error si el registro no existe
   else
   {
       cerr << "La Cuenta #" << iindicadorBancos << " esta vacia.\n";
   }
   getch();
}

void ClsBancos::mbuscarBancos(fstream &archivoBancos)
{
    int iindicadorBancos = mobtenerIndicadorBancos( "Escriba la Cuenta que desea buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoBancos.seekg(
      ( iindicadorBancos - 1 ) * sizeof( ClsBancos ) );

   // leer el primer registro del archivo
   ClsBancos banco;
   archivoBancos.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( banco.mobtenerClaveBancos() != 0 ) {
      mmostrarLineaRegistroBancos( cout, banco );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "La Cuenta #" << iindicadorBancos
         << " no tiene informacion." << endl;
   }
   getch();
}

ClsBancos::mmenuBancos()
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

    int iseleccionMenuBancos;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoBancos("registrosbancos.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoBancos )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearBancos();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION BANCOS  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Bancos"<<endl;
        cout<<"2. Despliegue Bancos"<<endl;
        cout<<"3. Modifica Bancos"<<endl;
        cout<<"4. Imprimir Regisro de Bancos"<<endl;
        cout<<"5. Borra Bancos"<<endl;
        cout<<"6. Buscar Bancos"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuBancos;
        switch(iseleccionMenuBancos)
        {
        case 1:
            {
                accion = "Ingreso a Agre. Banco";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mnuevoBancos(archivoBancos);
                getch();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Cons. Banco";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mconsultarRegistroBancos(archivoBancos);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                accion = "Ingreso a Mod. Banco";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mmodificarRegistroBancos(archivoBancos);
                getch();
            }
            break;
        case 4:
            {
                accion = "Ingreso a Impri. Banco";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mimprimirRegistroBancos(archivoBancos);
                getch();
            }
            break;
        case 5:
            {
                accion = "Ingreso a Elim. Banco";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                meliminarRegistroBancos(archivoBancos);
                getch();
            }
            break;
        case 6:
            {
                accion = "Ingreso a Buscar Banco";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mbuscarBancos(archivoBancos);
                getch();
            }
            break;
        case 0:
            {
                accion = "Salio de Gestion Banco";

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
    }while(iseleccionMenuBancos!=0);
}

ClsBancos::~ClsBancos()
{
    //dtor
}
