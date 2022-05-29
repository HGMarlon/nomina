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


ClsReporte::~ClsReporte()
{
    //dtor
}
