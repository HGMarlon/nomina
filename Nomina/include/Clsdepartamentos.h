#ifndef CLSDEPARTAMENTOS_H
#define CLSDEPARTAMENTOS_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsDepartamentos
{
    public:
        ClsDepartamentos(int = 0, string = "", string = "", string = "");

        mmenuDepartamentos();
        mcrearDepartamentos();

        void mestablecerCodigo( int ) ;
        int mobtenerCodigo() const;

        void mestablecerNombreEmpleado( string );
        string mobtenerNombreEmpleado() const;

        void mestablecerDepartamento( string );
        string mobtenerDepartamento() const;

        void mestablecerPuesto( string );
        string mobtenerPuesto() const;

        void nuevoEmpleado( fstream& );
        void consultarRegistroDepartamentos(fstream&);
        void mostrarLineaPantallaDepartamentos(const ClsDepartamentos &);
        void actualizarRegistroDepartamentos(fstream&);
        void mostrarLineaDepartamentos( ostream&, const ClsDepartamentos & );
        void imprimirRegistroDepartamentos( fstream& );
        void eliminarRegistroDepartamento( fstream& );
        void buscarEmpleadoDepartamento( fstream& );

        int obtenerSueldo( const char * const );
        virtual ~ClsDepartamentos();

    protected:

    private:
        int m_icodigoEmpleadoDepartamento;
        char m_sEmpleado[ 20 ];
        char m_sDepartamento[ 20 ];
        char m_sPuesto[ 20 ];
};

#endif // CLSDEPARTAMENTOS_H
