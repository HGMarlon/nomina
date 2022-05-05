#ifndef CLSEMPLEADOS_H
#define CLSEMPLEADOS_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class Clsempleados
{
    public:
        Clsempleados(int=0, string = "");

        mmenuEmpleados();
        mcrearEmpleados();

        int mobtenerIndicador( const char * const );

        void mnuevoEmpleado(fstream &archivoEmpleados);

        void mconsultarRegistroEmpleados(fstream &archivoEmpleados);

        void mostrarLineaEmpleado( const Clsempleados &registro );

        void mmodificarRegistroEmpleados( fstream &archivoEmpleados );

        void mmostrarLineaRegistroEmpleados( ostream &salida, const Clsempleados &registro );

        void mimprimirRegistroEmpleados(fstream &archivoEmpleado);

        void meliminarRegistroEmpleados(fstream &archivoEmpleados);

        void mbuscarEmpleados(fstream &archivoEmpleados);

        void mestablecerClave( int ) ;
        int mobtenerClave() const;

        void mestablecerNombre( string );
        string mobtenerNombre() const;

        virtual ~Clsempleados();

    protected:

    private:
        int m_iclaveEmpleado;
        char m_snombreEmpleado[20];
};

#endif // CLSEMPLEADOS_H
