#ifndef CLSCONCEPTOS_H
#define CLSCONCEPTOS_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsConceptos
{
    public:
        ClsConceptos(int = 0, int = 0, string = "", string = "", int = 0, float = 0);
        void mestablecerCodigo( int ) ;
        int mobtenerCodigo() const;

        void mestablecerBonoDescuento( int ) ;
        int mobtenerBonoDescuento() const;

        void mestablecerNombreEmpleado( string );
        string mobtenerNombreEmpleado() const;

        void mestablecerConcepto( string );
        string mobtenerConcepto() const;

        void mestablecerCantidadPorcentaje( int ) ;
        int mobtenerCantidadPorcentaje() const;

        void mestablecerPorcentaje( float );
        float mobtenerPorcentaje() const;

        float mdescuento() const;

        mmenuConceptos();
        mcrearConceptos();

        void nuevoConcepto( fstream& );
        void consultarRegistroConcepto(fstream&);
        void mostrarLineaPantallaConcepto(const ClsConceptos &);
        void actualizarRegistroConcepto(fstream&);
        void mostrarLineaConcepto( ostream&, const ClsConceptos & );
        void imprimirRegistroConcepto( fstream& );
        void eliminarRegistroConcepto( fstream& );
        void buscarEmpleadoConcepto( fstream& );
        int mobtenerIndicador( const char * const );


        virtual ~ClsConceptos();

    protected:

    private:
        int m_iBonoDescuento;
        int m_icodigoEmpleadoConcepto;
        char m_sEmpleado[ 20 ];
        char m_sConcepto[ 20 ];
        int m_iCantidadPorcentaje;
        float m_sPorcentaje;
};

#endif // CLSCONCEPTOS_H
