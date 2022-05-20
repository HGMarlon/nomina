#include "Clsnomina.h"
#include "Clsempleados.h"

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
#include<ctime>
#include<string.h>

Clsnomina::Clsnomina(int iclaveNomina, int iclaveEmpleado, string snombreEmpelado, int iclaveCantidad, string scargoNomina, float fsalarioNomina,
                     float fdiasTrabNomina, float fsueldoOrNomina, float fhoraExtraNomina, float fsueldoExtraNomina, float fbonificacionincNomina, float ftotaldevenNomina,
                     float fIGGNomina, float fISRNomina, float fanticipoNomina, float ftotaldescuentNomina, float fliquidoNomina)
{
    //ctor
    /*mestablecerIdNomina(iclaveNomina);*/
    mestablecerClaveEnomina(iclaveEmpleado);
    mestablecerNombreENomina(snombreEmpelado);
    mestablecerCantidadNomina(iclaveCantidad);
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
/*Josué Rivas - 9491-21-3133
Metodos del atributo clave nomina*/
int Clsnomina::mobtenerIdNomina() const
{
    return m_iclaveNominas;
}

void Clsnomina::mestablecerIdNomina (int ienteroClave)
{
    m_iclaveNominas = ienteroClave;
}

//Metodos del atributo clave empleados
int Clsnomina::mobtenerClaveEnomina() const
{
    return m_iclaveEmpleadoNomina;
}

void Clsnomina::mestablecerClaveEnomina (int ienteroClave)
{
    m_iclaveEmpleadoNomina = ienteroClave;
}

//Metodos del atributo nombre del empleado
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

//Metodos del atributo cantidad nomina
int Clsnomina::mobtenerCantidadNomina() const
{
    return m_icantidadNomina;
}

void Clsnomina::mestablecerCantidadNomina (int ienteroClave)
{
    m_icantidadNomina = ienteroClave;
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

/*Josue Rivas - 9491-21-3133
Metodos de Nominas*/
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

int Clsnomina::mobtenerNomina(const char * const iindicador)
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

void Clsnomina::mnuevaNomina(fstream &archivoNomina, fstream &archivoEmpleados, fstream &archivoPuestos, fstream &archivoEmpresa, fstream &archivoEncabezado, fstream &archivoConcepto)
{
    Clsnomina nomina;
    Clsempleados empleado;
    ClsPuestos puesto;
    ClsConceptos concepto;
    ClsEmpresa empresa;
    Clsencabezado encabezado;
    int m_iclaveNominas = 1;
    // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
    archivoNomina.seekg(
    ( m_iclaveNominas - 1 ) * sizeof( Clsnomina ) );
    // leer el registro del archivo
    archivoNomina.read( reinterpret_cast< char * >( &nomina ),
    sizeof( Clsnomina ) );
    /* crear el registro, si éste no existe ya
    if ( nomina.mobtenerIdNomina() == 0 )
    {*/
        m_iclaveNominas =0;
        //Atributos a ingresar
        int m_iclaveEmpleado = 0;
        string m_snombreEmpleado = "";
        int m_iclaveEncabezado=0;
        int m_iclaveCantidad = 0;
        string m_snombreEncabezado = "";
        string m_sencabezadoEmpresa= "";
        string m_sfechaEncabezado= "";
        string m_smonedaEncabezado= "";
        string m_snota= "";
        int ciclo=0;
        int iempleado=1;
        m_iclaveEncabezado=m_iclaveNominas;
//karla Gómez 9959-21-1896
        string m_scargoNomina= "";
        float m_fsalarioNomina = 0;
        float m_fdiasTrabNomina = 0;
        float m_fsueldoOrNomina = 0;
        float m_fhoraExtraNomina = 0;
        float m_fsueldoExtraNomina = 0;
        float m_fbonificacionincNomina = 0;
        float m_fanticipoNomina = 0;
        float m_ftotaldevenNomina = 0;
        float m_fIGGNomina = 0;
        float m_fISRNomina = 0;
        float m_ftotaldescuentNomina = 0;
        float m_fliquidoNomina = 0;
/* Josué Rivas 9491-21-3133
        Solicitud al usuario de llenar los atributos*/
        cout << "Ingrese el nombre de la nomina: " << endl;
        cin >> setw(20) >> m_snombreEncabezado;
        cout << "Ingrese la cantidad de empleados a ingresar: " << endl;
        cin >> m_iclaveCantidad;
        ciclo=m_iclaveCantidad;
        cout << "Ingrese la fecha de la nomina: " << endl;
        cin >> setw(15) >> m_sfechaEncabezado;
        cout << "Ingrese la moneda a utilizar: " << endl;
        cin >> setw(20) >> m_smonedaEncabezado;
        cout << "Ingrese el nombre de la empresa: " << endl;
        cin >> setw(20) >> m_sencabezadoEmpresa;
        cout << "Ingrese una nota (f-omitir): " << endl;
        cin >> setw(30) >> m_snota;
        //Guardar nominas
        while (ciclo>0)
        {
            ++m_iclaveNominas;
            --ciclo;
            //leer empleado
            m_iclaveEmpleado = empleado.mobtenerIndicador("Ingrese la clave del empleado a agregar");
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
//karla Gómez 9959-21-1896
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
//Alyson Rodriguez 9959-21-829
            m_ftotaldevenNomina=m_fsalarioNomina+m_fbonificacionincNomina+m_fanticipoNomina;
            int m_icodigoEmpleadoConcepto = 1;
            double descuentoA=0;
            archivoConcepto.seekg(
            ( m_icodigoEmpleadoConcepto - 1 ) * sizeof( ClsConceptos ) );
            // leer el primer registro del archivo
            archivoConcepto.read( reinterpret_cast< char * >( &concepto ),
            sizeof( ClsConceptos ) );
            // actualizar el registro
            if ( concepto.mobtenerCodigo() != 0 )
            {
                descuentoA = concepto.mdescuento();
                cout << endl;
            }
            // mostrar error si la clave no contiene informacion
            else
            {
                cerr << "El descuento #" << m_icodigoEmpleadoConcepto
                << " no tiene informacion." << endl;
            }
            m_icodigoEmpleadoConcepto = 2;
            double descuentoB=0;
            archivoConcepto.seekg(
            ( m_icodigoEmpleadoConcepto - 1 ) * sizeof( ClsConceptos ) );
            // leer el primer registro del archivo
            archivoConcepto.read( reinterpret_cast< char * >( &concepto ),
            sizeof( ClsConceptos ) );
            // actualizar el registro
            if ( concepto.mobtenerCodigo() != 0 )
            {
                descuentoB = concepto.mdescuento();
                cout << endl;
            }
            // mostrar error si la clave no contiene informacion
            else
            {
                cerr << "El descuento #" << m_icodigoEmpleadoConcepto
                << " no tiene informacion." << endl;
            }
            m_fIGGNomina=m_ftotaldevenNomina*descuentoA;
            m_fISRNomina=m_ftotaldevenNomina*descuentoB;
            m_ftotaldescuentNomina=m_fIGGNomina+m_fISRNomina;
            m_fliquidoNomina=m_ftotaldescuentNomina-m_ftotaldescuentNomina;
            // usar valores para llenar los valores de la clave
            nomina.mestablecerIdNomina(m_iclaveNominas);
            nomina.mestablecerClaveEnomina(m_iclaveEmpleado);
            nomina.mestablecerNombreENomina(m_snombreEmpleado);
            nomina.mestablecerCantidadNomina(m_iclaveCantidad);
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
//Josue Rivas 9491-21-3133
            // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
            archivoNomina.seekp( ( m_iclaveNominas - 1 ) *
            sizeof( Clsnomina ) );
            // insertar el registro en el archivo
            archivoNomina.write(
            reinterpret_cast< const char * >( &nomina ),
            sizeof( Clsnomina ) );
            cout << "Empleado agregado con exito.";
            /*}
            // mostrar error si la clave ya esta ocupada
            else
            {
                cerr << "La clave #" << m_iclaveNominas << " ya contiene informacion." << endl;
                getch();
            }*/
            encabezado.mestablecerClaveEncabezado(m_iclaveEncabezado);
            encabezado.mestablecerClaveCantidad(m_iclaveCantidad);
            encabezado.mestablecerNombreEncabezado(m_snombreEncabezado);
            encabezado.mestablecerEncabezadoEmpresa(m_sencabezadoEmpresa);
            encabezado.mestablecerFechaEncabezado(m_sfechaEncabezado);
            encabezado.mestablecerMonedaEncabezado(m_smonedaEncabezado);
            encabezado.mestableceNota(m_snota);
            // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
            archivoEncabezado.seekp( ( m_iclaveEncabezado - 1 ) *
            sizeof( Clsencabezado ) );
            // insertar el registro en el archivo
            archivoEncabezado.write(
            reinterpret_cast< const char * >( &encabezado ),
            sizeof( Clsencabezado ) );
        }
}
/*
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
//Karla Gómez 9959-21-1896
    << setw( 10 ) << "Nombre Cargo"
    << setw( 10 ) << "Monto Sueldo Asignado"
    << setw( 10 ) << "Numero Dias Laborados"
    << setw( 10 ) << "Monto Sueldo Ordinario"
    << setw( 10 ) << "Numero Horas Extra"
    << setw( 10 ) << "Monto Sueldo Extraordinario"
    << setw( 10 ) << "Monto Bonificacion Incentivo"
    << setw( 10 ) << "Monto Total Devengado"
    << setw( 10 ) << "Monto IGSS"
    << setw( 10 ) << "Monto ISR"
    << setw( 10 ) << "Monto anticipos"
    << setw( 10 ) << "Monto Total Descuentos"
    << setw( 10 ) << "Monto Liquido a Recibir"
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
}*/
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


Clsnomina::~Clsnomina()
{
    //dtor
}
