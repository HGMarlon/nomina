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


ClsReporte::~ClsReporte()
{
    //dtor
}
