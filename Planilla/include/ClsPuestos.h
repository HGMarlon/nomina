#ifndef CLSPUESTOS_H
#define CLSPUESTOS_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsPuestos
{
    public:
        ClsPuestos(int=0, string = "", string = "", float=0, string = "", string = "", string = "");

        mmenuPuestos();
        mcrearPuestos();

        int mobtenerIndicadorP( const char * const );

        void mnuevoPuestos(fstream &archivoPuestos);

        void mconsultarRegistroPuestos(fstream &archivoPuestos);

        void mostrarLineaPuestos( const ClsPuestos &registroPuesto );

        void mmodificarRegistroPuestos( fstream &archivoPuestos );

        void mmostrarLineaRegistroPuestos( ostream &salida, const ClsPuestos &registroPuesto );

        void mimprimirRegistroPuestos(fstream &archivoPuestos);

        void meliminarRegistroPuestos(fstream &archivoPuestos);

        void mbuscarPuestos(fstream &archivoPuestos);

        void mestablecerNumero( int ) ;
        int mobtenerNumero() const;

        void mestablecerCargo( string );
        string mobtenerCargo() const;

        void mestablecerDepaPuesto( string );
        string mobtenerDepaPuesto() const;

        void mestablecerSalario( float );
        float mobtenerSalario() const;

        void mestablecerNivelAc( string );
        string mobtenerNivelAc() const;

        void mestablecerHoraEntrada( string );
        string mobtenerHoaraEntrada() const;

        void mestablecerHoraSalida( string );
        string mobtenerHoaraSalida() const;

        virtual ~ClsPuestos();

    protected:

    private:
        int m_inumeroPuesto;
        char m_snombreCargo[20];
        char m_sDepartamento[20];
        float m_fSalario;
        char m_sNivelAcademico[20];
        char m_sHoraEntrada[20];
        char m_sHoraSalida[20];
};

#endif // CLSPUESTOS_H
