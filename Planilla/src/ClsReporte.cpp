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
//Karla Sofia G�mez Tobar 9959-21-1896

ClsReporte::ClsReporte(int iClaveReporte, int iDiasTrabajados, int iHorasExtra, float fBonificacion, float fAnticipo )
{
    //ctor
    mestablecerClaveRepo(iClaveReporte);
    mestablecerDiasTrab(iDiasTrabajados);
    mestablecerHorasExtra(iHorasExtra);
    mestablecerBonificacion(fBonificacion);
    mestablecerBonificacion(fAnticipo);
}

//Karla Sofia G�mez Tobar 9959-21-1896
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

   // obtener el valor del n�mero de reporte
   do {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iClaveReporte;

   } while ( m_iClaveReporte < 1 || m_iClaveReporte > 100 );

   return m_iClaveReporte;
}


ClsReporte::~ClsReporte()
{
    //dtor
}
