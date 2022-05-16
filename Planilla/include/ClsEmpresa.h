#ifndef CLSEMPRESA_H
#define CLSEMPRESA_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsEmpresa
{
    public:
        ClsEmpresa(int=0, string = "", string = "", string = "", string = "", string = "", string = "", string = "");

        mmenuEmpresa();
        mcrearEmpresa();

        int mobtenerIndicadorE( const char * const );

        void mnuevaEmpresa(fstream &archivoEmpresa);

        void mconsultarRegistroEmpresa(fstream &archivoEmpresa);

        void mostrarLineaEmpresa( const ClsEmpresa &registro );

        void mmodificarRegistroEmpresa( fstream &archivoEmpresa );

        void mmostrarLineaRegistroEmpresa( ostream &salida, const ClsEmpresa &registro );

        void mimprimirRegistroEmpresa(fstream &archivoEmpresa);

        void meliminarRegistroEmpresa(fstream &archivoEmpresa);

        void mbuscarEmpresa(fstream &archivoEmpresa);

        void mestablecerClaveEmpresa( int ) ;
        int mobtenerClaveE() const;

        void mestablecerNombreEmpresa( string );
        string mobtenerNombreE() const;

        void mestablecerCorreoE(string);
        string mobtenerCorreoE()const;

        void mestablecerActividadE(string);
        string mobtenerActividadE()const;

        void mestablecerNitE(string);
        string mobtenerNitE()const;

        void mestablecerDireccionE(string);
        string mobtenerDireccionE()const;

        void mestablecerTelefonoE(string);
        string mobtenerTelefonoE()const;

        void mestablecerNumeroEmpleadosE(string);
        string mobtenerNumeroEmpleadosE()const;

        virtual ~ClsEmpresa();

    protected:

    private:
        int m_iclaveEmpresa;
        char m_snombreEmpresa[20];
        char m_sCorreoEmpresa[20];
        char m_sActividadEconomica[20];
        char m_sNitEmpresa[14];
        char m_sDireccionEmpresa[20];
        char m_sTelefonoEmpresa[9];
        char m_sNumeroEmpleados[20];



};

#endif // CLSEMPRESA_H
