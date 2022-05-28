#ifndef CLSREPORTE_H
#define CLSREPORTE_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsReporte
{
    public:
        ClsPuestos(int=0, int=0, int=0, float=0, float=0 );

        mmenuReporte();
        mcrearReporte();

        int mobtenerIndicadorRep( const char * const );

        void mnuevoReporte(fstream &archivoReporte);

        void mconsultarRegistroReporte(fstream &archivoReporte);

        void mostrarLineaReporte( const ClsPuestos &registroReporte );

        void mmodificarRegistroReporte( fstream &archivoReporte );

        void mmostrarLineaRegistroReporte( ostream &salida, const ClsReporte &registroReporte );

        void mimprimirRegistroReporte(fstream &archivoReporte);

        void meliminarRegistroReporte(fstream &archivoReporte);

        void mbuscarReporte(fstream &archivoReporte);


        virtual ~ClsReporte();

    protected:

    private:
};

#endif // CLSREPORTE_H
