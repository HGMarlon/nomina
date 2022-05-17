#ifndef CLSNOMINA_H
#define CLSNOMINA_H

#include "Clsempleados.h"
//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

class Clsnomina
{
    public:
        //Constructor de la clase nominas
        Clsnomina(int=0, string = "", int=0, string = "");

         //Menu de nominas
        mmenuNominas();

        //Crear registro en blanco
        mcrearNominas();

        //Metodos del CRUD de empleados
        int mobtenerIndicador( const char * const );

        void mnuevaNomina(fstream &archivoNomina, fstream &archivoEmpleados);

        void mconsultarRegistroNomina(fstream &archivoNomina);

        void mostrarLineaNomina( const Clsnomina &registro );

        void mmodificarRegistroNomina( fstream &archivoNomina );

        void mmostrarLineaRegistroNomina( ostream &salida, const Clsempleados &registro );

        void mimprimirRegistroNomina(fstream &archivoEmpleado);

        void meliminarRegistroNomina(fstream &archivoNomina);

        void mbuscarNomina(fstream &archivoNomina);

        //Metodos atributo clase empelados
        void mestablecerIdNomina( int ) ;
        int mobtenerIdNomina() const;

        //Metodos atributo nombre del empleado
        void mestablecerNombreNomina( string );
        string mobtenerNombreNomina() const;

        //Metodos atributo clase empelados
        void mestablecerClaveEnomina( int ) ;
        int mobtenerClaveEnomina() const;

        //Metodos atributo nombre del empleado
        void mestablecerNombreENomina( string );
        string mobtenerNombreENomina() const;

        virtual ~Clsnomina();

    protected:

    private:
        int m_iclaveNominas;
        char m_snombreNomina[10];
        int m_iclaveEmpleadoNomina;
        char m_snombreEmpleadoNomina[10];
};

#endif // CLSNOMINA_H
