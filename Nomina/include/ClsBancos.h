#ifndef CLSBANCOS_H
#define CLSBANCOS_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsBancos
{
    public:
        ClsBancos(string = "", int = 0, string = "", string = "", string = "");

        mmenuBancos();
        mcrearBancos();

        int mobtenerIndicadorBancos( const char * const );

        void mnuevoBancos(fstream &archivoBancos);

        void mconsultarRegistroBancos(fstream &archivoBancos);

        void mostrarLineaBancos( const ClsBancos &registro );

        void mmodificarRegistroBancos( fstream &archivoBancos );

        void mmostrarLineaRegistroBancos( ostream &salida, const ClsBancos &registro );

        void mimprimirRegistroBancos(fstream &archivoBancos);

        void meliminarRegistroBancos(fstream &archivoBancos);

        void mbuscarBancos(fstream &archivoBancos);

        void mestablecerNombreBancos( string );
        string mobtenerNombreBancos() const;

        void mestablecerClaveBancos( int ) ;
        int mobtenerClaveBancos() const;

        void mestablecerNombreUsuarioBancos( string );
        string mobtenerNombreUsuarioBancos() const;

        void mestablecerSaldoCuentaBancos( string );
        string mobtenerSaldoCuentaBancos() const;

        void mestablecerTipoCuentaBancos( string );
        string mobtenerTipoCuentaBancos() const;

        virtual ~ClsBancos();

    protected:

    private:
        char m_sNombreBanco[20];
        int m_iNumeroCuenta;
        char m_sNombreUsuario[20];
        char m_iSaldoCuenta[20];
        char m_iTipoCuenta[20];
};

#endif // CLSBANCOS_H
