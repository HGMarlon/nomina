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

ClsReporte::~ClsReporte()
{
    //dtor
}
