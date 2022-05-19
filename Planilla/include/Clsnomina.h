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

//Karla Gómez 9959-21-1896
        //Metodos atributo cargo del empleado
        void mestablecerCargoNomina( string );
        string mobtenerCargoNomina() const;

        //Metodos atributo salario del empelado
        void mestablecerSalarioNomina( float );
        float mobtenerSalarioNomina() const;

        //Metodos atributo dias laborados
        void mestablecerDiasTrabNomina(float);
        float mobtenerDiasTrabNomina() const;

        //Metodos atributo sueldo ordinario
        void mestablecerSueldoOrNomina(float);
        float mobtenerSueldoOrNomina() const;

        //Metodos atributo horas extra laboradas
        void mestablecerHoraExtras(float);
        float mobtenerHoraExtra()const;

        //Metodos atributo sueldo extraordinario
        void mestablecersueldoExtraNomina(float);
        float mobtenersueldoExtraNomina()const;

        //Metodos atributo bonificacion  incentivo
        void mestablecerbonificacionincNomina(float);
        float mobtenerbonificacionincNomina()const;

        //Metodos atributo total devengado
        void mestablecertotaldevenNomina(float);
        float mobtenertotaldevenNomina()const;

        //Metodos atributo descuento IGSS
        void mestablecerIGGNomina( float );
        float mobtenerIGGNomina() const;

        //Metodos atributo descuento ISR
        void mestablecerISRNomina( float );
        float mobtenerISRNomina() const;

        //Metodos atributo anticipos
        void mestableceranticipoNomina( float );
        float mobteneranticipoNomina() const;

        //Metodos atributo total descuentos
        void mestablecertotaldescuentNomina( float );
        float mobtenertotaldescuentNomina() const;

        //Metodos atributo liquido a recibir
        void mestablecerliquidoNomina( float );
        float mobtenerliquidoNomina() const;

        virtual ~Clsnomina();

    protected:

    private:
        int m_iclaveNominas;
        char m_snombreNomina[10];
        int m_iclaveEmpleadoNomina;
        char m_snombreEmpleadoNomina[10];
//Karla Gómez 9959-21-1896
        char m_scargoNomina[10];
        float m_fsalarioNomina;
        float m_fdiasTrabNomina;
        float m_fsueldoOrNomina;
        float m_fhoraExtraNomina;
        float m_fsueldoExtraNomina;
        float m_fbonificacionincNomina;
        float m_ftotaldevenNomina;
        float m_fIGGNomina;
        float m_fISRNomina;
        float m_fanticipoNomina;
        float m_ftotaldescuentNomina;
        float m_fliquidoNomina;
};

#endif // CLSNOMINA_H
