#include "Clsencabezado.h"

/*Josué Rivas - 9491-21-3133
Clases*/
#include "Clsempleados.h"
#include "Clsnomina.h"
#include "ClsConceptos.h"
#include "ClsPuestos.h"
#include "ClsEmpresa.h"

//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

Clsencabezado::Clsencabezado(int iclave, int icantidad, string snombre, string empresa, string fecha, string smoneda, string snota)
{
    //ctor
    mestablecerClaveEncabezado(iclave);
    mestablecerClaveCantidad(icantidad);
    mestablecerNombreEncabezado(snombre);
    mestablecerEncabezadoEmpresa(empresa);
    mestablecerFechaEncabezado(fecha);
    mestablecerMonedaEncabezado(smoneda);
    mestableceNota(snota);
}

int Clsencabezado::mobtenerClaveEncabezado() const
{
    return m_iclaveEncabezado;
}

void Clsencabezado::mestablecerClaveEncabezado (int ienteroClave)
{
    m_iclaveEncabezado = ienteroClave;
}


int Clsencabezado::mobtenerClaveCantidad() const
{
    return m_iclaveCantidad;
}

void Clsencabezado::mestablecerClaveCantidad (int ienteroClave)
{
    m_iclaveCantidad = ienteroClave;
}

string Clsencabezado::mobtenerNombreEncabezado() const
{
    return m_snombreEncabezado;
}

void Clsencabezado::mestablecerNombreEncabezado( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreEncabezado, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snombreEncabezado[ ilongitud ] = '\0';
}

string Clsencabezado::mobtenerEncabezadoEmpresa() const
{
    return m_sencabezadoEmpresa;
}

void Clsencabezado::mestablecerEncabezadoEmpresa( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sencabezadoEmpresa, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sencabezadoEmpresa[ ilongitud ] = '\0';
}

string Clsencabezado::mobtenerFechaEncabezado() const
{
    return m_sfechaEncabezado;
}

void Clsencabezado::mestablecerFechaEncabezado( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 15 ? ilongitud : 14 );
   strncpy( m_sfechaEncabezado, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sfechaEncabezado[ ilongitud ] = '\0';
}

string Clsencabezado::mobtenerMonedaEncabezado() const
{
    return m_smonedaEncabezado;
}

void Clsencabezado::mestablecerMonedaEncabezado( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_smonedaEncabezado, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_smonedaEncabezado[ ilongitud ] = '\0';
}

string Clsencabezado::mobtenerNota() const
{
    return m_snota;
}

void Clsencabezado::mestableceNota( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_snota, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snota[ ilongitud ] = '\0';
}

Clsencabezado::mcrearEncabezado()
{
    ofstream archivoEncabezado("registroEncabezado.dat", ios::out | ios::binary);
    if(!archivoEncabezado)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    Clsencabezado encabezadoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEncabezado.write(reinterpret_cast<const char * > (&encabezadoEnBlanco), sizeof(Clsencabezado));
    }
}

Clsencabezado::~Clsencabezado()
{
    //dtor
}
