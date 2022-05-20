#ifndef CLSENCABEZADO_H
#define CLSENCABEZADO_H

//Clases
#include "Clsnomina.h"
#include "ClsEmpresa.h"

//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

class Clsencabezado
{
    public:
        //Metodos de Encabezado
        Clsencabezado(int=0, int=0, string = "", string = "", string = "", string = "", string = "");
        mcrearEncabezado();
        int mobtenerEncabezado( const char * const );
        void mnuevoEncabezado(fstream &archivoEncabezado);
        void mleerEncabezado(fstream &archivoEncabezado);
        void mostrarLineaEncabezado( const Clsencabezado &registro );
        /*void mmodificarRegistroNomina( fstream &archivoNomina );
        void mmostrarLineaRegistroNomina( ostream &salida, const Clsempleados &registro );
        void mimprimirRegistroNomina(fstream &archivoEmpleado);
        void meliminarRegistroNomina(fstream &archivoNomina);
        void mbuscarNomina(fstream &archivoNomina);*/
        //Metodos atributo clase empelados
        void mestablecerClaveEncabezado( int ) ;
        int mobtenerClaveEncabezado() const;
        //Metodos atributo clase empelados
        void mestablecerClaveCantidad( int ) ;
        int mobtenerClaveCantidad() const;
        //Metodos atributo nombre del empleado
        void mestablecerNombreEncabezado( string );
        string mobtenerNombreEncabezado() const;
        //Metodos atributo nombre del empleado
        void mestablecerEncabezadoEmpresa( string );
        string mobtenerEncabezadoEmpresa() const;
        //Metodos atributo nombre del empleado
        void mestablecerFechaEncabezado( string );
        string mobtenerFechaEncabezado() const;
        //Metodos atributo nombre del empleado
        void mestablecerMonedaEncabezado( string );
        string mobtenerMonedaEncabezado() const;
        //Metodos atributo nombre del empleado
        void mestableceNota( string );
        string mobtenerNota() const;
        virtual ~Clsencabezado();

    protected:
        int m_iclaveEncabezado;
        int m_iclaveCantidad;
        char m_snombreEncabezado[20];
        char m_sencabezadoEmpresa[20];
        char m_sfechaEncabezado[15];
        char m_smonedaEncabezado[20];
        char m_snota[30];

    private:
};

#endif // CLSENCABEZADO_H
