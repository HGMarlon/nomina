#ifndef CLSNOMINA_H
#define CLSNOMINA_H

/*Josué Rivas - 9491-21-3133
Clases*/
#include "Clsempleados.h"
#include "Clsnomina.h"
#include "ClsConceptos.h"
#include "ClsPuestos.h"
#include "ClsEmpresa.h"
#include "Clsencabezado.h"
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
        //Metodos de nominas
        Clsnomina(int=0, int=0, string = "", int=0, string = "", float =0,
                     float =0, float =0, float =0, float =0, float =0, float =0,
                     float =0, float =0, float =0, float =0, float =0);
        mcrearNominas();
        int mobtenerNomina( const char * const );
        void mnuevaNomina(fstream &archivoNomina, fstream &archivoEmpleados, fstream &archivoPuestos, fstream &archivoEmpresa, fstream &archivoEncabezado, fstream &archivoConcepto,
                          fstream &archivoReporte);
        void mleerNomina(fstream &archivoNomina, fstream &archivoEncabezado);
        void mostrarLineaNomina( const Clsnomina &registro );
        //Metodos atributo clave nomina
        void mestablecerIdNomina( int ) ;
        int mobtenerIdNomina() const;
        //Metodos atributo clave empleado
        void mestablecerClaveEnomina( int ) ;
        int mobtenerClaveEnomina() const;
        //Metodos atributo nombre del empleado
        void mestablecerNombreENomina( string );
        string mobtenerNombreENomina() const;
        //Metodos atributo clave empleado
        void mestablecerCantidadNomina( int ) ;
        int mobtenerCantidadNomina() const;
/*Karla Gómez 9959-21-1896
        Metodos atributo cargo del empleado*/
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
//Josué Rivas - 9491-21-3133
        virtual ~Clsnomina();

    protected:

    private:
        int m_iclaveNominas;
        int m_iclaveEmpleadoNomina;
        char m_snombreEmpleadoNomina[10];
        int m_icantidadNomina;
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
