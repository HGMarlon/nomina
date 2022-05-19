#include "Clsempleados.h"

//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

//Otras clases
#include "ClsmenuMantenimientos.h"

using namespace std;

//Constructor de la clase
Clsempleados::Clsempleados(int iclaveEmpleado, string snombreEmpelado, string snombresEmpleado, string sapellidoEmpleado, string sapellidosEmpleado, string sedadEmpleado,
                           string sdireccionEmpleado, string stelefonoEmpleado, string scorreoEmpleado, string ssexoEmpleado, string snacionalidadEmpleado, string snacimientoEmpleado)
{
    //ctor
    mestablecerClave(iclaveEmpleado);
    mestablecerNombre(snombreEmpelado);
    mestablecerNombres(snombresEmpleado);
    mestablecerApellido(sapellidoEmpleado);
    mestablecerApellidos(sapellidosEmpleado);
    mestablecerEdad(sedadEmpleado);
    mestablecerDireccion(sdireccionEmpleado);
    mestablecerTelefono(stelefonoEmpleado);
    mestablecerCorreo(scorreoEmpleado);
    mestablecerSexo(ssexoEmpleado);
    mestablecerNacionalidad(snacionalidadEmpleado);
    mestablecerNacimiento(snacimientoEmpleado);
}

//Metodos del atributo clase empelados
int Clsempleados::mobtenerClave() const
{
    return m_iclaveEmpleado;
}

void Clsempleados::mestablecerClave (int ienteroClave)
{
    m_iclaveEmpleado = ienteroClave;
}

//Metodos atributo nombre del empleado
string Clsempleados::mobtenerNombre() const
{
    return m_snombreEmpleado;
}

void Clsempleados::mestablecerNombre( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_snombreEmpleado, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snombreEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo nombres del empleado
string Clsempleados::mobtenerNombres() const
{
    return m_snombresEmpleado;
}

void Clsempleados::mestablecerNombres( string scadenaNombres )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombres = scadenaNombres.data();
   int ilongitud = strlen( svalorNombres );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombresEmpleado, svalorNombres, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snombresEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo apellido del empleado
string Clsempleados::mobtenerApellido() const
{
    return m_sapellidoEmpleado;
}

void Clsempleados::mestablecerApellido( string scadenaApellido )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorApellido = scadenaApellido.data();
   int ilongitud = strlen( svalorApellido );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_sapellidoEmpleado, svalorApellido, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sapellidoEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo apellidos del empleado
string Clsempleados::mobtenerApellidos() const
{
    return m_sapellidosEmpleado;
}

void Clsempleados::mestablecerApellidos( string scadenaApellidos )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorApellidos = scadenaApellidos.data();
   int ilongitud = strlen( svalorApellidos );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sapellidosEmpleado, svalorApellidos, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sapellidosEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo edad del empleado
string Clsempleados::mobtenerEdad() const
{
    return m_sedadEmpleado;
}

void Clsempleados::mestablecerEdad( string scadenaEdad )
{
   // copiar a lo más 5 caracteres de la cadena
   const char *svalorEdad = scadenaEdad.data();
   int ilongitud = strlen( svalorEdad );
   ilongitud = ( ilongitud < 5 ? ilongitud : 4 );
   strncpy( m_sedadEmpleado, svalorEdad, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sedadEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo direccion del empleado
string Clsempleados::mobtenerDireccion() const
{
    return m_sdireccionEmpleado;
}

void Clsempleados::mestablecerDireccion( string scadenaDireccion )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorDireccion = scadenaDireccion.data();
   int ilongitud = strlen( svalorDireccion );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sdireccionEmpleado, svalorDireccion, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sdireccionEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo telefono del empleado
string Clsempleados::mobtenerTelefono() const
{
    return m_stelefonoEmpleado;
}

void Clsempleados::mestablecerTelefono( string scadenaTelefono )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorTelefono = scadenaTelefono.data();
   int ilongitud = strlen( svalorTelefono );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_stelefonoEmpleado, svalorTelefono, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_stelefonoEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo correo del empleado
string Clsempleados::mobtenerCorreo() const
{
    return m_scorreoEmpleado;
}

void Clsempleados::mestablecerCorreo( string scadenaCorreo )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorCorreo = scadenaCorreo.data();
   int ilongitud = strlen( svalorCorreo );
   ilongitud = ( ilongitud < 30 ? ilongitud : 29 );
   strncpy( m_scorreoEmpleado, svalorCorreo, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_scorreoEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo sexo del empleado
string Clsempleados::mobtenerSexo() const
{
    return m_ssexoEmpleado;
}

void Clsempleados::mestablecerSexo( string scadenaSexo )
{
   // copiar a lo más 10 caracteres de la cadena
   const char *svalorSexo = scadenaSexo.data();
   int ilongitud = strlen( svalorSexo );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_ssexoEmpleado, svalorSexo, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_ssexoEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo nacionalidad del empleado
string Clsempleados::mobtenerNacionalidad() const
{
    return m_snacionalidadEmpleado;
}

void Clsempleados::mestablecerNacionalidad( string scadenaNacionalidad )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNacionalidad = scadenaNacionalidad.data();
   int ilongitud = strlen( svalorNacionalidad );
   ilongitud = ( ilongitud < 15 ? ilongitud : 14 );
   strncpy( m_snacionalidadEmpleado, svalorNacionalidad, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snacionalidadEmpleado[ ilongitud ] = '\0';
}

//Metodos atributo nacimiento del empleado
string Clsempleados::mobtenerNacimiento() const
{
    return m_snacimientoEmpleado;
}

void Clsempleados::mestablecerNacimiento( string scadenaNacimiento )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNacimiento = scadenaNacimiento.data();
   int ilongitud = strlen( svalorNacimiento );
   ilongitud = ( ilongitud < 15 ? ilongitud : 14 );
   strncpy( m_snacimientoEmpleado, svalorNacimiento, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snacimientoEmpleado[ ilongitud ] = '\0';
}

//Metodos del CRUD de Empleados
Clsempleados::mcrearEmpleados()
{
    ofstream archivoEmpleados("registrosempleados.dat", ios::out | ios::binary);
    if(!archivoEmpleados)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    Clsempleados empleadoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEmpleados.write(reinterpret_cast<const char * > (&empleadoEnBlanco), sizeof(Clsempleados));
    }
}

int Clsempleados::mobtenerIndicador(const char * const iindicador)
{
    int m_iclaveEmpleado;
   // obtener el valor de la clave
   do
    {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iclaveEmpleado;
    } while ( m_iclaveEmpleado < 1 || m_iclaveEmpleado > 100 );
   return m_iclaveEmpleado;
}

void Clsempleados::mnuevoEmpleado(fstream &archivoEmpleados)
{
   Clsempleados empleado;
   int m_iclaveEmpleado = mobtenerIndicador( "Escriba el numero de empleado" );
   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoEmpleados.seekg(
      ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );
   // leer el registro del archivo
   archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );
   // crear el registro, si éste no existe ya
   if ( empleado.mobtenerClave() == 0 )
   {
        //Atributos a ingresar
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
        //Solicitud al usuario de llenar los atributos
        cout << "Escriba el primer nombre del empleado: " << endl;
        cin >> setw( 10 ) >> m_snombreEmpleado;
        cout << "Escriba segundo y/o tercer nombre del empleado: " << endl;
        cin >> setw( 20 ) >> m_snombresEmpleado;
        cout << "Escriba el primer apellido del empleado: " << endl;
        cin >> setw( 10 ) >> m_sapellidoEmpleado;
        cout << "Escriba segundo y/o tercer apellido del empleado: " << endl;
        cin >> setw( 20 ) >> m_sapellidosEmpleado;
        cout << "Escriba la edad del empleado: " << endl;
        cin >> setw( 5 ) >> m_sedadEmpleado;
        cout << "Escriba la direccion del empleado: " << endl;
        cin >> setw( 20 ) >> m_sdireccionEmpleado;
        cout << "Escriba el telefono del empleado: " << endl;
        cin >> setw( 10 ) >> m_stelefonoEmpleado;
        cout << "Escriba el correo del empleado: " << endl;
        cin >> setw( 30 ) >> m_scorreoEmpleado;
        cout << "Escriba el sexo del empleado: " << endl;
        cin >> setw( 10 ) >> m_ssexoEmpleado;
        cout << "Escriba la nacionalidad del empleado: " << endl;
        cin >> setw( 15 ) >> m_snacionalidadEmpleado;
        cout << "Escriba la fecha de nacimiento del empleado: " << endl;
        cin >> setw( 15 ) >> m_snacimientoEmpleado;
        // usar valores para llenar los valores de la clave
        empleado.mestablecerClave( m_iclaveEmpleado );
        empleado.mestablecerNombre( m_snombreEmpleado );
        empleado.mestablecerNombres(m_snombresEmpleado);
        empleado.mestablecerApellido(m_sapellidoEmpleado);
        empleado.mestablecerApellidos(m_sapellidosEmpleado);
        empleado.mestablecerEdad(m_sedadEmpleado);
        empleado.mestablecerDireccion(m_sdireccionEmpleado);
        empleado.mestablecerTelefono(m_stelefonoEmpleado);
        empleado.mestablecerCorreo(m_scorreoEmpleado);
        empleado.mestablecerSexo(m_ssexoEmpleado);
        empleado.mestablecerNacionalidad(m_snacionalidadEmpleado);
        empleado.mestablecerNacimiento(m_snacimientoEmpleado);
        // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
        archivoEmpleados.seekp( ( m_iclaveEmpleado - 1 ) *
        sizeof( Clsempleados ) );
        // insertar el registro en el archivo
        archivoEmpleados.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Clsempleados ) );
        cout << "Empleado agregado con exito.";
   }
   // mostrar error si la clave ya esta ocupada
   else
   {
       cerr << "La clave #" << m_iclaveEmpleado << " ya contiene informacion." << endl;
       getch();
   }
}

void Clsempleados::mostrarLineaEmpleado( const Clsempleados &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerClave()
          << setw( 10 ) << registro.mobtenerNombre().data()
          << setw( 20 ) << registro.mobtenerNombres().data()
          << setw( 10 ) << registro.mobtenerApellido().data()
          << setw( 20 ) << registro.mobtenerApellidos().data()
          << setw( 5 ) << registro.mobtenerEdad().data()
          << setw( 20 ) << registro.mobtenerDireccion().data()
          << setw( 10 ) << registro.mobtenerTelefono().data()
          << setw( 30 ) << registro.mobtenerCorreo().data()
          << setw( 10 ) << registro.mobtenerSexo().data()
          << setw( 15 ) << registro.mobtenerNacionalidad().data()
          << setw( 15 ) << registro.mobtenerNacimiento().data()
          << endl;
}

void Clsempleados::mconsultarRegistroEmpleados(fstream &archivoEmpleados)
{
    //Creando encabezado de la tabla
    cout << left << setw( 10 ) << "Clave"
    << setw( 10 ) << "Nombre"
    << setw( 20 ) << "Nombres"
    << setw( 10 ) << "Apellido"
    << setw( 20 ) << "Apellidos"
    << setw( 5 ) << "Edad"
    << setw( 20 ) << "Direccion"
    << setw( 10 ) << "Telefono"
    << setw( 30 ) << "Correo"
    << setw( 10 ) << "Sexo"
    << setw( 15 ) << "Nacionalidad"
    << setw( 15 ) << "Fecha de nacimiento"
    << endl;
    // colocar el apuntador de posición de archivo al principio del archivo de registros
    archivoEmpleados.seekg( 0 );
    // leer el primer registro del archivo de registros
    Clsempleados empleado;
    archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    // copiar todos los registros del archivo de registros en el archivo de texto
    while ( !archivoEmpleados.eof() )
    {
        // escribir un registro individual en el archivo de texto
        if ( empleado.mobtenerClave() != 0 )
        mostrarLineaEmpleado(empleado);
        // leer siguiente registro del archivo de registros
        archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
        sizeof( Clsempleados ) );
    }
}

void Clsempleados::mmostrarLineaRegistroEmpleados( ostream &salida, const Clsempleados &registro )
{
       salida << left << setw( 10 ) << registro.mobtenerClave()
          << setw( 10 ) << registro.mobtenerNombre().data()
          << setw( 20 ) << registro.mobtenerNombres().data()
          << setw( 10 ) << registro.mobtenerApellido().data()
          << setw( 20 ) << registro.mobtenerApellidos().data()
          << setw( 5 ) << registro.mobtenerEdad().data()
          << setw( 20 ) << registro.mobtenerDireccion().data()
          << setw( 10 ) << registro.mobtenerTelefono().data()
          << setw( 30 ) << registro.mobtenerCorreo().data()
          << setw( 10 ) << registro.mobtenerSexo().data()
          << setw( 15 ) << registro.mobtenerNacionalidad().data()
          << setw( 15 ) << registro.mobtenerNacimiento().data()
          << endl;
}

void Clsempleados::mmodificarRegistroEmpleados( fstream &archivoEmpleados )
{
    Clsempleados empleado;
    int m_iclaveEmpleado = mobtenerIndicador("Ingrese la clave del empleado");
    archivoEmpleados.seekg(
    ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );
    // leer el primer registro del archivo
    archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    // actualizar el registro
    if ( empleado.mobtenerClave() != 0 )
    {
        mmostrarLineaRegistroEmpleados( cout, empleado );
        cout << endl    ;
        //Atributos a ingresar
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
        //Solicitud al usuario de llenar los atributos
        cout << "Escriba el primer nombre del empleado: " << endl;
        cin >> setw( 20 ) >> m_snombreEmpleado;
        cout << "Escriba segundo y/o tercer nombre del empleado: " << endl;
        cin >> setw( 20 ) >> m_snombresEmpleado;
        cout << "Escriba el primer apellido del empleado: " << endl;
        cin >> setw( 20 ) >> m_sapellidoEmpleado;
        cout << "Escriba segundo y/o tercer apellido del empleado: " << endl;
        cin >> setw( 20 ) >> m_sapellidosEmpleado;
        cout << "Escriba la edad del empleado: " << endl;
        cin >> setw( 5 ) >> m_sedadEmpleado;
        cout << "Escriba la direccion del empleado: " << endl;
        cin >> setw( 20 ) >> m_sdireccionEmpleado;
        cout << "Escriba el telefono del empleado: " << endl;
        cin >> setw( 20 ) >> m_stelefonoEmpleado;
        cout << "Escriba el correo del empleado: " << endl;
        cin >> setw( 20 ) >> m_scorreoEmpleado;
        cout << "Escriba el sexo del empleado: " << endl;
        cin >> setw( 10 ) >> m_ssexoEmpleado;
        cout << "Escriba la nacionalidad del empleado: " << endl;
        cin >> setw( 20 ) >> m_snacionalidadEmpleado;
        cout << "Escriba la fecha de nacimiento del empleado: " << endl;
        cin >> setw( 20 ) >> m_snacimientoEmpleado;
        // usar valores para llenar los valores de la clave
        empleado.mestablecerClave( m_iclaveEmpleado );
        empleado.mestablecerNombre( m_snombreEmpleado );
        empleado.mestablecerNombres(m_snombresEmpleado);
        empleado.mestablecerApellido(m_sapellidoEmpleado);
        empleado.mestablecerApellidos(m_sapellidosEmpleado);
        empleado.mestablecerEdad(m_sedadEmpleado);
        empleado.mestablecerDireccion(m_sdireccionEmpleado);
        empleado.mestablecerTelefono(m_stelefonoEmpleado);
        empleado.mestablecerCorreo(m_scorreoEmpleado);
        empleado.mestablecerSexo(m_ssexoEmpleado);
        empleado.mestablecerNacionalidad(m_snacionalidadEmpleado);
        empleado.mestablecerNacimiento(m_snacimientoEmpleado);
        mmostrarLineaRegistroEmpleados( cout, empleado );
        // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
        archivoEmpleados.seekp(
        ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );
        // escribir el registro actualizado sobre el registro anterior en el archivo
        archivoEmpleados.write(
        reinterpret_cast< const char * >( &empleado ),
        sizeof( Clsempleados ) );
        cout << "Empleado modificado con éxito.";
    }
    // mostrar error si la clave no contiene informacion
    else
    cerr << "La la clave #" << m_iclaveEmpleado
         << " no tiene informacion." << endl;
}

void Clsempleados::mimprimirRegistroEmpleados(fstream &archivoEmpleado)
{
    Clsempleados empleado;
    ofstream imprimir("registrodeempleados.txt", ios::out);
    // salir del programa si ofstream no puede crear el archivo
    if ( !imprimir )
    {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    }
    imprimir << left << setw( 10 ) << "Clave"
    << setw( 10 ) << "Nombre"
    << setw( 20 ) << "Nombres"
    << setw( 10 ) << "Apellido"
    << setw( 20 ) << "Apellidos"
    << setw( 5 ) << "Edad"
    << setw( 20 ) << "Direccion"
    << setw( 10 ) << "Telefono"
    << setw( 30 ) << "Correo"
    << setw( 10 ) << "Sexo"
    << setw( 15 ) << "Nacionalidad"
    << setw( 15 ) << "Fecha de nacimiento"
    << endl;
    // colocar el apuntador de posición de archivo al principio del archivo de registros
    archivoEmpleado.seekg( 0 );
    // leer el primer registro del archivo de registros
    archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    // copiar todos los registros del archivo de registros en el archivo de texto
    while ( !archivoEmpleado.eof() )
    {
        // escribir un registro individual en el archivo de texto
        if ( empleado.mobtenerClave() != 0 )
        mmostrarLineaRegistroEmpleados( imprimir, empleado );
        // leer siguiente registro del archivo de registros
        archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
        sizeof( Clsempleados ) );
   }
   cout << "archivo creado con éxito con el nombre de: registrodeempleados.txt";
}

void Clsempleados::meliminarRegistroEmpleados(fstream &archivoEmpleados)
{
    int iindicador= mobtenerIndicador( "Escriba la clave a eliminar" );
    // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
    archivoEmpleados.seekg(
    ( iindicador - 1 ) * sizeof( Clsempleados ) );
    // leer el registro del archivo
    Clsempleados empleado;
    archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    // eliminar el registro, si es que existe en el archivo
    if ( empleado.mobtenerClave() != 0 )
    {
        Clsempleados empleadoEnBlanco;
        // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
        archivoEmpleados.seekp( ( iindicador - 1 ) *
        sizeof( Clsempleados ) );
        // reemplazar el registro existente con un registro en blanco
        archivoEmpleados.write(
        reinterpret_cast< const char * >( &empleadoEnBlanco ),
        sizeof( Clsempleados ) );
        cout << "Empleado clave #" << iindicador << " eliminado correctamente.\n";
   }
   // mostrar error si el registro esta vacio
   else
   {
       cerr << "Empleado clave #" << iindicador << " esta vacia.\n";
   }
   getch();
}

void Clsempleados::mbuscarEmpleados(fstream &archivoEmpleados)
{
    int iindicador = mobtenerIndicador( "Escriba la clave que desea buscar" );
    // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
    archivoEmpleados.seekg(
    ( iindicador - 1 ) * sizeof( Clsempleados ) );
    // leer el primer registro del archivo
    Clsempleados empleado;
    archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    if ( empleado.mobtenerClave() != 0 )
    {
        mmostrarLineaRegistroEmpleados( cout, empleado );
    }
    // mostrar error si la clave esta vacia
    else
    {
        cerr << "La clave #" << iindicador
        << " no tiene informacion." << endl;
    }
    getch();
}

Clsempleados::mmenuEmpleados()
{
     string accion="";
    //tiempo
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    string codigo;
    fstream abrir;
    int found=0;
    abrir.open("Usuario.txt", ios::in);
    if (!abrir)
    {
        cerr << "Archivo Usuario no Encontrado" << endl;
        exit ( 3 );
    }
    else
    {
        abrir>>codigo;
    }

    ofstream bitacora("Bitacora.txt", ios::app | ios::out);
    if (!bitacora)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
        exit ( 3 );
    }

    int iseleccionMenuEmpleados;
    do
    {

        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoEmpleados("registrosempleados.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoEmpleados )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearEmpleados();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );
            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION EMPLEADOS  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Empleados"<<endl;
        cout<<"2. Despliegue Empleados"<<endl;
        cout<<"3. Modifica Empleados"<<endl;
        cout<<"4. Imprimir Regisro de Empleados"<<endl;
        cout<<"5. Borra Empleados"<<endl;
        cout<<"6. Buscar Empleados"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuEmpleados;
        switch(iseleccionMenuEmpleados)
        {
        case 1:
            {
                accion = "Ingreso a Agregar Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mnuevoEmpleado(archivoEmpleados);
                getch();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Des. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mconsultarRegistroEmpleados(archivoEmpleados);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                accion = "Ingreso a Mod. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mmodificarRegistroEmpleados(archivoEmpleados);
                getch();
            }
            break;
        case 4:
            {
                accion = "Imprimio Reg. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mimprimirRegistroEmpleados(archivoEmpleados);
                getch();
            }
            break;
        case 5:
            {
                accion = "Ingreso a Elim. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                meliminarRegistroEmpleados(archivoEmpleados);
            }
            break;
        case 6:
            {
                accion = "Ingreso a Buscar Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mbuscarEmpleados(archivoEmpleados);
            }
            break;
        case 0:
            {
                accion = "Salio de Gestion Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/
            }
            break;
        default:
            cout<<"Opción invalida, intenta de nuevo";
            getch();
            break;
        }
    }while(iseleccionMenuEmpleados!=0);
}

//Destructor
Clsempleados::~Clsempleados()
{
    //dtor
}
