#include "Clsnomina.h"
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

Clsnomina::Clsnomina(int iclaveNomina, string snombreNomina, int iclaveEmpleado, string snombreEmpelado, string scargoNomina, float fsalarioNomina, float fdiasTrabNomina, float fsueldoOrNomina, float fhoraExtraNomina, float fsueldoExtraNomina, float fbonificacionincNomina, float ftotaldevenNomina, float fIGGNomina, float fISRNomina, float fanticipoNomina, float ftotaldescuentNomina, float fliquidoNomina)
{
    //ctor
    mestablecerIdNomina(iclaveNomina);
    mestablecerNombreNomina(snombreNomina);
    mestablecerClaveEnomina(iclaveEmpleado);
    mestablecerNombreENomina(snombreEmpelado);
//Karla Gómez 9959-21-1896
    mestablecerCargoNomina(scargoNomina);
    mestablecerSalarioNomina(fsalarioNomina);
    mestablecerDiasTrabNomina(fdiasTrabNomina);
    mestablecerSueldoOrNomina(fsueldoOrNomina);
    mestablecerHoraExtras(fhoraExtraNomina);
    mestablecersueldoExtraNomina(fsueldoExtraNomina);
    mestablecerbonificacionincNomina(fbonificacionincNomina);
    mestablecertotaldevenNomina(ftotaldevenNomina);
    mestablecerIGGNomina(fIGGNomina);
    mestablecerISRNomina(fISRNomina);
    mestableceranticipoNomina(fanticipoNomina);
    mestablecertotaldescuentNomina(ftotaldescuentNomina);
    mestablecerliquidoNomina(fliquidoNomina);
}

//Metodos del atributo clase nominas
int Clsnomina::mobtenerIdNomina() const
{
    return m_iclaveNominas;
}

void Clsnomina::mestablecerIdNomina (int ienteroClave)
{
    m_iclaveNominas = ienteroClave;
}

//Metodos atributo nombre de la nomina
string Clsnomina::mobtenerNombreNomina() const
{
    return m_snombreNomina;
}

void Clsnomina::mestablecerNombreNomina( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_snombreNomina, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snombreNomina[ ilongitud ] = '\0';
}

//Metodos del atributo clase empelados
int Clsnomina::mobtenerClaveEnomina() const
{
    return m_iclaveEmpleadoNomina;
}

void Clsnomina::mestablecerClaveEnomina (int ienteroClave)
{
    m_iclaveEmpleadoNomina = ienteroClave;
}

//Metodos atributo nombre del empleado
string Clsnomina::mobtenerNombreENomina() const
{
    return m_snombreEmpleadoNomina;
}

void Clsnomina::mestablecerNombreENomina( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_snombreEmpleadoNomina, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snombreEmpleadoNomina[ ilongitud ] = '\0';
}

//Karla gómez 9959-21-1896
string Clsnomina::mobtenerCargoNomina() const
{
    return m_scargoNomina;
}

void Clsnomina::mestablecerCargoNomina( string scadenaCargo )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorCargo = scadenaCargo.data();
   int ilongitud = strlen( svalorCargo );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_scargoNomina, svalorCargo, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_scargoNomina[ ilongitud ] = '\0';
}

float Clsnomina::mobtenerSalarioNomina() const
{
    return m_fsalarioNomina;
}

void Clsnomina::mestablecerSalarioNomina (float fdecimalSalario)
{
    m_fsalarioNomina = fdecimalSalario;
}


float Clsnomina::mobtenerDiasTrabNomina() const
{
    return m_fdiasTrabNomina;
}

void Clsnomina::mestablecerDiasTrabNomina (float fdecimaldias)
{
    m_fdiasTrabNomina = fdecimaldias;
}


float Clsnomina::mobtenerSueldoOrNomina() const
{
    return m_fsueldoOrNomina;
}

void Clsnomina::mestablecerSueldoOrNomina (float fdecimalSueldoOrd)
{
    m_fsueldoOrNomina = fdecimalSueldoOrd;
}


float Clsnomina::mobtenerHoraExtra() const
{
    return m_fhoraExtraNomina;
}

void Clsnomina::mestablecerHoraExtras (float fdecimalhotasEx)
{
    m_fhoraExtraNomina = fdecimalhotasEx;
}


float Clsnomina::mobtenersueldoExtraNomina() const
{
    return m_fsueldoExtraNomina;
}

void Clsnomina::mestablecersueldoExtraNomina (float fdecimalsueldoExtrao)
{
    m_fsueldoExtraNomina = fdecimalsueldoExtrao;
}


float Clsnomina::mobtenerbonificacionincNomina() const
{
    return m_fbonificacionincNomina;
}

void Clsnomina::mestablecerbonificacionincNomina (float fdecimalboniincent)
{
    m_fbonificacionincNomina = fdecimalboniincent;
}


float Clsnomina::mobtenertotaldevenNomina() const
{
    return m_ftotaldevenNomina;
}

void Clsnomina::mestablecertotaldevenNomina (float fdecimaltotaldeven)
{
    m_ftotaldevenNomina = fdecimaltotaldeven;
}


float Clsnomina::mobtenerIGGNomina() const
{
    return m_fIGGNomina;
}

void Clsnomina::mestablecerIGGNomina (float fdecimalIGSS)
{
    m_fIGGNomina = fdecimalIGSS;
}

float Clsnomina::mobtenerISRNomina() const
{
    return m_fISRNomina;
}

void Clsnomina::mestablecerISRNomina (float fdecimalISR)
{
    m_fISRNomina = fdecimalISR;
}


float Clsnomina::mobteneranticipoNomina() const
{
    return m_fanticipoNomina;
}

void Clsnomina::mestableceranticipoNomina (float fdecimalanticipo)
{
    m_fanticipoNomina = fdecimalanticipo;
}


float Clsnomina::mobtenertotaldescuentNomina() const
{
    return m_ftotaldescuentNomina;
}

void Clsnomina::mestablecertotaldescuentNomina (float fdecimalAnticipo)
{
    m_ftotaldescuentNomina = fdecimalAnticipo;
}


float Clsnomina::mobtenerliquidoNomina() const
{
    return m_fliquidoNomina;
}

void Clsnomina::mestablecerliquidoNomina (float fdecimalLiquido)
{
    m_fliquidoNomina = fdecimalLiquido;
}


//Metodos del CRUD de Nominas
Clsnomina::mcrearNominas()
{
    ofstream archivoNomina("registronominas.dat", ios::out | ios::binary);
    if(!archivoNomina)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    Clsnomina nominaEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoNomina.write(reinterpret_cast<const char * > (&nominaEnBlanco), sizeof(Clsnomina));
    }
}

int Clsnomina::mobtenerIndicador(const char * const iindicador)
{
    int m_iclaveNominas;
   // obtener el valor de la clave
   do
    {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iclaveNominas;
    } while ( m_iclaveNominas < 1 || m_iclaveNominas > 100 );
   return m_iclaveNominas;
}

void Clsnomina::mnuevaNomina(fstream &archivoNomina, fstream &archivoEmpleados)
{
   Clsnomina nomina;
   int m_iclaveNominas = mobtenerIndicador( "Escriba el numero de nomina" );
   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoNomina.seekg(
      ( m_iclaveNominas - 1 ) * sizeof( Clsnomina ) );
   // leer el registro del archivo
   archivoNomina.read( reinterpret_cast< char * >( &nomina ),
      sizeof( Clsnomina ) );
   // crear el registro, si éste no existe ya
   if ( nomina.mobtenerIdNomina() == 0 )
   {
        //Atributos a ingresar
        char m_snombreNomina[10];
        int m_iclaveEmpleado = 0;
        string m_snombreEmpleado = "";
//karla Gómez 9959-21-1896
        char m_scargoNomina[10];
        float m_fsalarioNomina = 0;
        float m_fdiasTrabNomina = 0;
        float m_fsueldoOrNomina = 0;
        float m_fhoraExtraNomina = 0;
        float m_fsueldoExtraNomina = 0;
        float m_fbonificacionincNomina = 0;
        float m_ftotaldevenNomina = 0;
        float m_fIGGNomina = 0;
        float m_fISRNomina = 0;
        float m_fanticipoNomina = 0;
        float m_ftotaldescuentNomina = 0;
        float m_fliquidoNomina = 0;
        //Solicitud al usuario de llenar los atributos
        cout << "Escriba el nombre de la nomina: " << endl;
        cin >> setw( 10 ) >> m_snombreNomina;

        cout << "Escriba el nombre del cargo: " << endl;
        cin >> setw( 10 ) >> m_scargoNomina;

        cout << "Escriba el monto del salario: " << endl;
        cin >> setw( 10 ) >> m_fsalarioNomina;

        cout << "Escriba el numero de dias trabajados: " << endl;
        cin >> setw( 10 ) >> m_fdiasTrabNomina;

        cout << "Escriba las horas extra trabajadas: " << endl;
        cin >> setw( 10 ) >> m_fhoraExtraNomina;

        cout << "Escriba el monto de bono incentivo: " << endl;
        cin >> setw( 10 ) >> m_fbonificacionincNomina;

        cout << "Escriba el monto del anticipo: " << endl;
        cin >> setw( 10 ) >> m_fanticipoNomina;


        //leer empleado
        Clsempleados empleado;
        m_iclaveEmpleado = mobtenerIndicador("Ingrese la clave del empleado a agregar");
        archivoEmpleados.seekg(
        ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );
        // leer el primer registro del archivo
        archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
        sizeof( Clsempleados ) );
        // actualizar el registro
        if ( empleado.mobtenerClave() != 0 )
        {
            m_iclaveEmpleado = empleado.mobtenerClave();
            m_snombreEmpleado = empleado.mobtenerNombre();
            cout << endl;
        }
        // mostrar error si la clave no contiene informacion
        else
        {
            cerr << "La la clave #" << m_iclaveEmpleado
            << " no tiene informacion." << endl;
        }
        // usar valores para llenar los valores de la clave
        nomina.mestablecerNombreNomina( m_snombreNomina );
        nomina.mestablecerClaveEnomina( m_iclaveEmpleado );
        nomina.mestablecerNombreENomina(m_snombreEmpleado);
//Karla Gómez 9959-21-1896
        nomina.mestablecerCargoNomina(m_scargoNomina);
        nomina.mestablecerSalarioNomina(m_fsalarioNomina);
        nomina.mestablecerDiasTrabNomina(m_fdiasTrabNomina);
        nomina.mestablecerSueldoOrNomina(m_fsueldoOrNomina);
        nomina.mestablecerHoraExtras(m_fhoraExtraNomina);
        nomina.mestablecersueldoExtraNomina(m_fsueldoExtraNomina);
        nomina.mestablecerbonificacionincNomina(m_fbonificacionincNomina);
        nomina.mestablecertotaldevenNomina(m_ftotaldevenNomina);
        nomina.mestablecerIGGNomina(m_fIGGNomina);
        nomina.mestablecerISRNomina(m_fISRNomina);
        nomina.mestableceranticipoNomina(m_fanticipoNomina);
        nomina.mestablecertotaldescuentNomina(m_ftotaldescuentNomina);
        nomina.mestablecerliquidoNomina(m_fliquidoNomina);
        // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
        archivoNomina.seekp( ( m_iclaveNominas - 1 ) *
        sizeof( Clsnomina ) );
        // insertar el registro en el archivo
        archivoNomina.write(
         reinterpret_cast< const char * >( &nomina ),
         sizeof( Clsnomina ) );
        cout << "Empleado agregado con exito.";
   }
   // mostrar error si la clave ya esta ocupada
   else
   {
       cerr << "La clave #" << m_iclaveNominas << " ya contiene informacion." << endl;
       getch();
   }
}

void Clsnomina::mostrarLineaNomina( const Clsnomina &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerIdNomina()
          << setw( 10 ) << registro.mobtenerNombreNomina().data()
          << setw( 10 ) << registro.mobtenerClaveEnomina()
          << setw( 10 ) << registro.mobtenerNombreENomina().data()
    //Karla Gomez 9959-21-1896
          << setw( 10 ) << registro.mobtenerCargoNomina().data()
          << setw( 10 ) << registro.mobtenerSalarioNomina()
          << setw( 10 ) << registro.mobtenerDiasTrabNomina()
          << setw( 10 ) << registro.mobtenerSueldoOrNomina()
          << setw( 10 ) << registro.mobtenerHoraExtra()
          << setw( 10 ) << registro.mobtenersueldoExtraNomina()
          << setw( 10 ) << registro.mobtenerbonificacionincNomina()
          << setw( 10 ) << registro.mobtenertotaldevenNomina()
          << setw( 10 ) << registro.mobtenerIGGNomina()
          << setw( 10 ) << registro.mobtenerISRNomina()
          << setw( 10 ) << registro.mobteneranticipoNomina()
          << setw( 10 ) << registro.mobtenertotaldescuentNomina()
          << setw( 10 ) << registro.mobtenerliquidoNomina()
          << endl;
}

void Clsnomina::mconsultarRegistroNomina(fstream &archivoNomina)
{
    //Creando encabezado de la tabla
    cout << left << setw( 10 ) << "Clave Nomina"
    << setw( 10 ) << "Nombre nomina"
    << setw( 10 ) << "Clave empleado"
    << setw( 10 ) << "Nombre empleado"
    << endl;
    // colocar el apuntador de posición de archivo al principio del archivo de registros
    archivoNomina.seekg( 0 );
    // leer el primer registro del archivo de registros
    Clsnomina nomina;
    archivoNomina.read( reinterpret_cast< char * >( &nomina ),
    sizeof( Clsnomina ) );
    // copiar todos los registros del archivo de registros en el archivo de texto
    while ( !archivoNomina.eof() )
    {
        // escribir un registro individual en el archivo de texto
        if ( nomina.mobtenerIdNomina() != 0 )
        mostrarLineaNomina(nomina);
        // leer siguiente registro del archivo de registros
        archivoNomina.read( reinterpret_cast< char * >( &nomina ),
        sizeof( Clsnomina ) );
    }
}
/*
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
*/

Clsnomina::mmenuNominas()
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

    Clsempleados empleado;
    int iseleccionMenuNomina;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoNomina("registronominas.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoNomina )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearNominas();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );
            }
        // abrir el archivo en modo de lectura y escritura
        fstream archivoEmpleados("registrosempleados.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoEmpleados )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                empleado.mcrearEmpleados();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );
            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION NOMINA  |"<<endl;
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
        cin>>iseleccionMenuNomina;
        switch(iseleccionMenuNomina)
        {
        case 1:
            {
                accion = "Ingreso a Agre. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mnuevaNomina(archivoNomina, archivoEmpleados);
                getch();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Cons. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mconsultarRegistroNomina(archivoNomina);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        /*case 3:
            {
                system("cls");
                mmodificarRegistroEmpleados(archivoEmpleados);
                getch();
            }
            break;
        case 4:
            {
                system("cls");
                mimprimirRegistroEmpleados(archivoEmpleados);
                getch();
            }
            break;
        case 5:
            {
                system("cls");
                meliminarRegistroEmpleados(archivoEmpleados);
            }
            break;
        case 6:
            {
                system("cls");
                mbuscarEmpleados(archivoEmpleados);
            }
            break;*/
        case 0:
            {
                accion = "Salio de Gestion Nomina";

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
    }while(iseleccionMenuNomina!=0);
}

Clsnomina::~Clsnomina()
{
    //dtor
}
