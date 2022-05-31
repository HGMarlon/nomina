#include "ClsReporte.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>


using namespace std;
//Karla Sofia Gómez Tobar 9959-21-1896

ClsReporte::ClsReporte(int iClaveReporte, int iDiasTrabajados, int iHorasExtra, float fBonificacion, float fAnticipo )
{
    //ctor
    mestablecerClaveRepo(iClaveReporte);
    mestablecerDiasTrab(iDiasTrabajados);
    mestablecerHorasExtra(iHorasExtra);
    mestablecerBonificacion(fBonificacion);
    mestablecerBonificacion(fAnticipo);
}

//Karla Sofia Gómez Tobar 9959-21-1896
int ClsReporte::mobtenerClaveRepo() const
{
    return m_iClaveReporte;
}

void ClsReporte::mestablecerClaveRepo (int ienteroClave)
{
    m_iClaveReporte = ienteroClave;
}

int ClsReporte::mobtenerDiasTrab() const
{
    return m_iDiasTrabajados;
}

void ClsReporte::mestablecerDiasTrab (int ienteroDias)
{
    m_iDiasTrabajados = ienteroDias;
}

int ClsReporte::mobtenerHorasExtra() const
{
    return m_iHorasExtra;
}

void ClsReporte::mestablecerHorasExtra (int ienteroHoras)
{
    m_iHorasExtra = ienteroHoras;
}


float ClsReporte::mobtenerBonificacion() const
{
    return m_fBonificacion;
}

void ClsReporte::mestablecerBonificacion (float fflotanteBonificacion)
{
    m_fBonificacion = fflotanteBonificacion;
}

float ClsReporte::mobtenerAnticipo() const
{
    return m_fAnticipo;
}

void ClsReporte::mestablecerAnticipo (float fflotanteAnticipo)
{
    m_fAnticipo = fflotanteAnticipo;
}

ClsReporte::mcrearReporte()
{
    ofstream archivoReporte("registrosreporte.dat", ios::out | ios::binary);
    if(!archivoReporte)
    {
        cerr<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    ClsReporte reporteEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoReporte.write(reinterpret_cast<const char * > (&reporteEnBlanco), sizeof(ClsReporte));
    }
}

int ClsReporte::mobtenerIndicadorRep(const char * const iindicador)
{
    int m_iClaveReporte;

   // obtener el valor del número de reporte
   do {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iClaveReporte;

   } while ( m_iClaveReporte < 1 || m_iClaveReporte > 100 );

   return m_iClaveReporte;
}

void ClsReporte::mnuevoReporte(fstream &archivoReporte)
{
   ClsReporte reporte;
   int m_iClaveReporte = mobtenerIndicadorRep( "Escriba el numero de reporte" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoReporte.seekg(
      ( m_iClaveReporte - 1 ) * sizeof( ClsReporte ) );

   // leer el registro del archivo
   archivoReporte.read( reinterpret_cast< char * >( &reporte ),
      sizeof( ClsReporte ) );

    // crear el registro, si éste no existe ya
   if ( reporte.mobtenerClaveRepo() == 0 )
    {
      //Atributos a ingresar
      int m_iDiasTrabajados=0;
      int m_iHorasExtra=0;
      float m_fBonificacion=0;
      float m_fAnticipo=0;

      // el usuario introduce el nombre
      cout << "Escriba la cantidad de dias trabajados: " << endl;
      cin >> setw( 5 ) >> m_iDiasTrabajados;
      cout << "Escriba las horas extras:" << endl;
      cin >> setw( 5 ) >> m_iHorasExtra;
      cout << "Escriba la cantidad de bonificacion a percibir:" << endl;
      cin >> setw( 10 ) >>m_fBonificacion ;
      cout << "Escriba la cantidad de anticipo a percibir:" << endl;
      cin >> setw( 10 ) >>m_fAnticipo;

      // usar valores para llenar los valores de la clave
        reporte.mestablecerClaveRepo(m_iClaveReporte);
        reporte.mestablecerDiasTrab( m_iDiasTrabajados );
        reporte.mestablecerHorasExtra(m_iHorasExtra);
        reporte.mestablecerBonificacion(m_fBonificacion);
        reporte.mestablecerAnticipo(m_fAnticipo);

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoReporte.seekp( ( m_iClaveReporte - 1 ) *
         sizeof( ClsReporte ) );

     // insertar el registro en el archivo
        archivoReporte.write(
           reinterpret_cast< const char * >( &reporte ),
           sizeof( ClsReporte ) );

           cout << "Reporte agregado con exito.";
   }

   // mostrar error si la clave ya esta ocupada
   else
   {
       cerr << "La clave #" << m_iClaveReporte << " ya contiene informacion." << endl;
       getch();
   }

}

void ClsReporte::mostrarLineaReporte( const ClsReporte &registro )
{
       cout << left << setw( 5 ) << registro.mobtenerClaveRepo()
          << setw( 5 ) << registro.mobtenerDiasTrab()
          << setw( 10 ) << registro.mobtenerHorasExtra()
          << setw( 10 ) << registro.mobtenerBonificacion()
          << setw( 10 ) << registro.mobtenerAnticipo()
          << endl;
}

void ClsReporte::mconsultarRegistroReporte(fstream &archivoReporte)
{
    //Creando encabezado de la tabla
    cout << left << setw( 5 ) << "Clave"
    << setw( 5 ) << "Dias trabajados"
    << setw( 5 ) << "Horas extra"
    << setw( 10 ) << "Bonificacion"
    << setw( 10 ) << "Anticipo"
    << endl;

    // colocar el apuntador de posición de archivo al principio del archivo de registros
    archivoReporte.seekg( 0 );

    // leer el primer registro del archivo de registros
    ClsReporte reporte;
    archivoReporte.read( reinterpret_cast< char * >( &reporte ),
    sizeof( ClsReporte ) );

    // copiar todos los registros del archivo de registros en el archivo de texto
    while ( !archivoReporte.eof() )
    {
        // escribir un registro individual en el archivo de texto
        if ( reporte.mobtenerClaveRepo() != 0 )
        mostrarLineaReporte(reporte);

        // leer siguiente registro del archivo de registros
        archivoReporte.read( reinterpret_cast< char * >( &reporte ),
        sizeof( ClsReporte ) );
    }
}

void ClsReporte::mmostrarLineaRegistroReporte( ostream &salida, const ClsReporte &registro )
{
       salida << left << setw( 5 ) << registro.mobtenerClaveRepo()
          << setw( 5 ) << registro.mobtenerDiasTrab()
          << setw( 5 ) << registro.mobtenerHorasExtra()
          << setw( 10 ) << registro.mobtenerBonificacion()
          << setw( 10 ) << registro.mobtenerAnticipo()
          << endl;
}

void ClsReporte::mmodificarRegistroReporte( fstream &archivoReporte )
{
    ClsReporte reporte;
    int m_iClaveReporte = mobtenerIndicadorRep("Ingrese la clave del reporte");

    archivoReporte.seekg(
    ( m_iClaveReporte - 1 ) * sizeof( ClsReporte ) );

    // leer el primer registro del archivo
    archivoReporte.read( reinterpret_cast< char * >( &reporte ),
    sizeof( ClsReporte ) );

   // actualizar el registro
   if ( reporte.mobtenerClaveRepo() != 0 ) {
      mmostrarLineaRegistroReporte( cout, reporte );

      cout << "Escriba la cantidad de dias trabajados: ";
      int m_iDiasTrabajados;
      cin >> m_iDiasTrabajados;

      cout << "Escriba la cantidad de horas extras:";
      int m_iHorasExtra;
      cin >> m_iHorasExtra;

      cout << "Escriba la cantidad de bonificacion a percibir:";
      float m_fBonificacion;
      cin >> m_fBonificacion;

      cout << "Escriba la cantidad de anticipos a percibir:";
      float m_fAnticipo;
      cin >> m_fAnticipo;

      // actualizar el saldo del registro
      reporte.mestablecerClaveRepo( m_iClaveReporte);
      mmostrarLineaRegistroReporte( cout, reporte );

       // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
        archivoReporte.seekp(
        ( m_iClaveReporte - 1 ) * sizeof( ClsReporte ) );

        // escribir el registro actualizado sobre el registro anterior en el archivo
        archivoReporte.write(
        reinterpret_cast< const char * >( &reporte ),
        sizeof( ClsReporte ) );

        cout << "Reporte modificado con éxito.";

    } // fin de instrucción if

   // mostrar error si la clave no contiene informacion
    else
        cerr << "La la clave #" << m_iClaveReporte
         << " no tiene informacion." << endl;
}

void ClsReporte::mimprimirRegistroReporte(fstream &archivoReporte)
{
    ClsReporte reporte;
    ofstream imprimir("registrodereporte.txt", ios::out);

    // salir del programa si ofstream no puede crear el archivo
    if ( !imprimir )
    {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    }

    imprimir << left << setw( 5 ) << "Clave"
    << setw( 5 ) << "Dias trabajados"
    << setw( 5 ) << "Horas extra"
    << setw( 10 ) << "Bonificacion"
    << setw( 10 ) << "Anticipo"
    << endl;

    // colocar el apuntador de posición de archivo al principio del archivo de registros
    archivoReporte.seekg( 0 );

    // leer el primer registro del archivo de registros
    archivoReporte.read( reinterpret_cast< char * >( &reporte),
    sizeof( ClsReporte));

    // copiar todos los registros del archivo de registros en el archivo de texto
    while ( !archivoReporte.eof() )
    {
        // escribir un registro individual en el archivo de texto
        if ( reporte.mobtenerClaveRepo() != 0 )
        mmostrarLineaRegistroReporte( imprimir, reporte);

        // leer siguiente registro del archivo de registros
        archivoReporte.read( reinterpret_cast< char * >( &reporte),
        sizeof( ClsReporte));
   }
   cout << "archivo creado con éxito con el nombre de: registrodereporte.txt";
}

void ClsReporte::meliminarRegistroReporte(fstream &archivoReporte)
{
    int iindicador= mobtenerIndicadorRep( "Escriba la clave a eliminar" );

    // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
    archivoReporte.seekg(
    ( iindicador - 1 ) * sizeof( ClsReporte) );

    // leer el registro del archivo
    ClsReporte reporte;
    archivoReporte.read( reinterpret_cast< char * >( &reporte),
    sizeof( ClsReporte) );

    // eliminar el registro, si es que existe en el archivo
    if ( reporte.mobtenerClaveRepo() != 0 )
    {
        ClsReporte reporteEnBlanco;

        // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
        archivoReporte.seekp( ( iindicador - 1 ) *
        sizeof( ClsReporte ) );

        // reemplazar el registro existente con un registro en blanco
        archivoReporte.write(
        reinterpret_cast< const char * >( &reporteEnBlanco ),
        sizeof( ClsReporte) );

        cout << "Registro clave #" << iindicador << " eliminado correctamente.\n";
   }

   // mostrar error si el registro esta vacio
   else
   {
       cerr << "Registro clave #" << iindicador << " esta vacia.\n";
   }
   getch();
}

void ClsReporte::mbuscarReporte(fstream &archivoReporte)
{
    int iindicador = mobtenerIndicadorRep( "Escriba la clave que desea buscar" );

    // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
    archivoReporte.seekg(
    ( iindicador - 1 ) * sizeof( ClsReporte) );

    // leer el primer registro del archivo
    ClsReporte reporte;
    archivoReporte.read( reinterpret_cast< char * >( &reporte),
    sizeof( ClsReporte) );

    // actualizar el registro
    if ( reporte.mobtenerClaveRepo() != 0 )
    {
        mmostrarLineaRegistroReporte( cout, reporte);
    }

    // mostrar error si la clave esta vacia
    else
    {
        cerr << "La clave #" << iindicador
        << " no tiene informacion." << endl;
    }
    getch();
}

ClsReporte::mmenuReporte()
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


    int iseleccionMenuReporte;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoReporte("registrosreporte.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoReporte )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearReporte();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION REPORTE  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Reporte"<<endl;
        cout<<"2. Despliegue Reporte"<<endl;
        cout<<"3. Modifica Reporte"<<endl;
        cout<<"4. Imprimir Reporte"<<endl;
        cout<<"5. Borra Reporte"<<endl;
        cout<<"6. Buscar Reporte"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuReporte;
        switch(iseleccionMenuReporte)
        {
        case 1:
            {
                accion = "Ingreso a Agre. Reporte";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mnuevoReporte(archivoReporte);
                getch();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Cons. Reporte";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mconsultarRegistroReporte(archivoReporte);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                accion = "Ingreso a Mod. Reporte";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mmodificarRegistroReporte(archivoReporte);
                getch();
            }
            break;
        case 4:
            {
                accion = "Ingreso a Impri. Reporte";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mimprimirRegistroReporte(archivoReporte);
                getch();
            }
            break;
        case 5:
            {
                accion = "Ingreso a Elim. Reporte";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                meliminarRegistroReporte(archivoReporte);
            }
            break;
        case 6:
            {
                accion = "Ingreso a Buscar. Reporte";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mbuscarReporte(archivoReporte);
            }
            break;
        case 0:
            {
                accion = "Salio de Gestion Reporte";

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
    }while(iseleccionMenuReporte!=0);
}

ClsReporte::~ClsReporte()
{
    //dtor
}
