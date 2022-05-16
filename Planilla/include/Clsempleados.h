#ifndef CLSEMPLEADOS_H
#define CLSEMPLEADOS_H

//Librerias
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
        //Constructor clase
        Clsempleados(int=0, string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "");

        //Menu de los empleados
        mmenuEmpleados();

        //Crear registro en blanco
        mcrearEmpleados();

        //Metodos del CRUD de empleados
        int mobtenerIndicador( const char * const );

        void mnuevoEmpleado(fstream &archivoEmpleados);

        void mconsultarRegistroEmpleados(fstream &archivoEmpleados);

        void mostrarLineaEmpleado( const Clsempleados &registro );

        void mmodificarRegistroEmpleados( fstream &archivoEmpleados );

        void mmostrarLineaRegistroEmpleados( ostream &salida, const Clsempleados &registro );

        void mimprimirRegistroEmpleados(fstream &archivoEmpleado);

        void meliminarRegistroEmpleados(fstream &archivoEmpleados);

        void mbuscarEmpleados(fstream &archivoEmpleados);

        //Metodos atributo clase empelados
        void mestablecerClave( int ) ;
        int mobtenerClave() const;

        //Metodos atributo nombre del empleado
        void mestablecerNombre( string );
        string mobtenerNombre() const;

        //Metodos atributo nombres del empleado
        void mestablecerNombres( string );
        string mobtenerNombres() const;

        //Metodos atributo apellido del empleado
        void mestablecerApellido( string );
        string mobtenerApellido() const;

        //Metodos atributo apellidos del empleado
        void mestablecerApellidos( string );
        string mobtenerApellidos() const;

        //Metodos atributo edad del empleado
        void mestablecerEdad( string );
        string mobtenerEdad() const;

        //Metodos atributo direccion del empleado
        void mestablecerDireccion( string );
        string mobtenerDireccion() const;

        //Metodos atributo telefono del empleado
        void mestablecerTelefono( string );
        string mobtenerTelefono() const;

        //Metodos atributo correo del empleado
        void mestablecerCorreo( string );
        string mobtenerCorreo() const;

        //Metodos atributo sexo del empleado
        void mestablecerSexo( string );
        string mobtenerSexo() const;

        //Metodos atributo nacionalidad del empleado
        void mestablecerNacionalidad( string );
        string mobtenerNacionalidad() const;

        //Metodos atributo fecha de nacimiento del empleado
        void mestablecerNacimiento( string );
        string mobtenerNacimiento() const;

        //Destructor de la clase empleado
        virtual ~Clsempleados();

    protected:

    private:
        int m_iclaveEmpleado;
        char m_snombreEmpleado[10];
        char m_snombresEmpleado[20];
        char m_sapellidoEmpleado[10];
        char m_sapellidosEmpleado[20];
        char m_sedadEmpleado[5];
        char m_sdireccionEmpleado[20];
        char m_stelefonoEmpleado[10];
        char m_scorreoEmpleado[30];
        char m_ssexoEmpleado[10];
        char m_snacionalidadEmpleado[15];
        char m_snacimientoEmpleado[15];
};

#endif // CLSEMPLEADOS_H
