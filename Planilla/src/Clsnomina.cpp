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
#include "ClsReporte.h"

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

void Clsnomina::mnuevaNomina(fstream &archivoNomina, fstream &archivoEmpleados, fstream &archivoPuestos, fstream &archivoEmpresa, fstream &archivoEncabezado, fstream &archivoConcepto,
                             fstream &archivoReporte)
{
    Clsnomina nomina;
    Clsempleados empleado;
    ClsPuestos puesto;
    ClsConceptos concepto;
    ClsEmpresa empresa;
    Clsencabezado encabezado;
    ClsReporte reporte;
    int m_iclaveNominas = 1;
    // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
    archivoNomina.seekg(
    ( m_iclaveNominas - 1 ) * sizeof( Clsnomina ) );
    // leer el registro del archivo
    archivoNomina.read( reinterpret_cast< char * >( &nomina ),
    sizeof( Clsnomina ) );
    // colocar el apuntador de posición de archivo al principio del archivo de registros
    archivoEmpleados.seekg( 0 );
    mcrearNominas();
    encabezado.mcrearEncabezado();
    //Atributos a ingresar
    int m_iclaveEmpleado = 0;
    int m_iClaveReporte = 0;
    string m_snombreEmpleado = "";
    int m_iclaveEncabezado=0;
    int m_iclaveCantidad = 0;
    string m_snombreEncabezado = "";
    string m_sencabezadoEmpresa= "";
    string m_sfechaEncabezado= "";
    string m_smonedaEncabezado= "";
    string m_snota= "";
    int ipuesto=0;
    int ireporte=0;
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
    Ingreso de atributos*/
    cout << "Ingrese el nombre de la nomina: " << endl;
    cin >> setw(20) >> m_snombreEncabezado;
    cout << "Ingrese la cantidad de empleados a ingresar: " << endl;
    cin >> m_iclaveCantidad;
    cout << "Ingrese la fecha de la nomina: " << endl;
    cin >> setw(15) >> m_sfechaEncabezado;
    cout << "Ingrese la moneda a utilizar: " << endl;
    cin >> setw(20) >> m_smonedaEncabezado;
    cout << "Ingrese el nombre de la empresa: " << endl;
    cin >> setw(20) >> m_sencabezadoEmpresa;
    cout << "Ingrese una nota (f-omitir): " << endl;
    cin >> setw(30) >> m_snota;
    //Guardar nominas
    m_iclaveNominas = 0;
    int iciclo=0;
    while ( iciclo < m_iclaveCantidad )
        {
        ++iciclo;
        archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
        sizeof( Clsempleados ) );
        // actualizar el registro
        if ( empleado.mobtenerClave() != 0 )
        {
            m_iclaveEmpleado = empleado.mobtenerClave();
            m_snombreEmpleado = empleado.mobtenerNombre();
            ipuesto = empleado.mobtenerCPuesto();
            ireporte = m_iclaveEmpleado;
        }
        // mostrar error si la clave no contiene informacion
        else
        {
            cerr << "La la clave #" << m_iclaveEmpleado
            << " no tiene informacion." << endl;
            exit (4);
        }
        // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
        archivoPuestos.seekg(
        ( ipuesto - 1 ) * sizeof( ClsPuestos ) );
        // leer el primer registro del archivo
        archivoPuestos.read( reinterpret_cast< char * >( &puesto ),
        sizeof( ClsPuestos ) );
        // actualizar el registro
        if ( puesto.mobtenerNumero() != 0 ) {
        }
        // mostrar error si la cuenta no existe
        else
        {
                cerr<< "El numero #" << ipuesto
                << " no tiene informacion." << endl;
                exit(5);
        }
        m_scargoNomina=puesto.mobtenerCargo();
        m_fsalarioNomina=puesto.mobtenerSalario();
        //reportes
        // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
        archivoReporte.seekg(
        ( ireporte - 1 ) * sizeof( ClsReporte ) );
        // leer el primer registro del archivo
        archivoReporte.read( reinterpret_cast< char * >( &reporte ),
        sizeof( ClsReporte ) );
        // actualizar el registro
        if ( reporte.mobtenerClaveRepo() != 0 ) {
        }
        // mostrar error si la cuenta no existe
        else
        {
                cerr<< "El numero #" << ireporte
                << " no tiene informacion." << endl;
                exit(8);
        }
        m_fdiasTrabNomina=reporte.mobtenerDiasTrab();
        m_fhoraExtraNomina=reporte.mobtenerHorasExtra();
        m_fbonificacionincNomina=reporte.mobtenerBonificacion();
        m_fanticipoNomina=reporte.mobtenerAnticipo();
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
        }
        // mostrar error si la clave no contiene informacion
        else
        {
            cerr << "El descuento #" << m_icodigoEmpleadoConcepto
            << " no tiene informacion." << endl;
            exit(6);
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
        }
        // mostrar error si la clave no contiene informacion
        else
        {
            cerr << "El descuento #" << m_icodigoEmpleadoConcepto
            << " no tiene informacion." << endl;
            exit(7);
        }
//Alyson Rodriguez 9959-21-829
        m_fsueldoOrNomina=(m_fsalarioNomina/30)*m_fdiasTrabNomina;
        m_fIGGNomina=m_fsueldoOrNomina*descuentoA;
        m_fISRNomina=m_fsueldoOrNomina*descuentoB;
        m_ftotaldescuentNomina=m_fIGGNomina+m_fISRNomina+m_fanticipoNomina;
        m_fsueldoExtraNomina= (m_fsalarioNomina/720)*m_fhoraExtraNomina;
        m_ftotaldevenNomina=m_fsueldoOrNomina+m_fbonificacionincNomina+m_fsueldoExtraNomina;
        m_fliquidoNomina=m_ftotaldevenNomina-m_ftotaldescuentNomina;
// Josué Rivas 9491-21-3133
        // usar valores para llenar los valores de la clave
        m_iclaveNominas=m_iclaveEmpleado;
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
    }
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
    cout << "Nomina creada con éxito.";
    getch();
}
//Alyson Rodriguez 9959-21-829
void Clsnomina::mostrarLineaNomina( const Clsnomina &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerClaveEnomina()
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
//Alyson Rodriguez 9959-21-829
void Clsnomina::mleerNomina(fstream &archivoNomina, fstream &archivoEncabezado)
{
    //Creando encabezado de la tabla
    cout << left << setw( 10 ) << "Clave N.:"
    << setw( 20 ) << "Nombre nomina:"
    << setw( 20 ) << "Nombre Empresa:"
    << setw( 15 ) << "Fecha:"
    << setw( 20 ) << "Moneda:"
    << setw( 30 ) << "Nota:"
    << endl;
    Clsencabezado encabezado;
    // colocar el apuntador de posición de archivo al principio del archivo de registros
    archivoEncabezado.seekg( 0 );
    // leer el primer registro del archivo de registros
    archivoEncabezado.read( reinterpret_cast< char * >( &encabezado ),
    sizeof( Clsencabezado ) );
    // copiar todos los registros del archivo de registros en el archivo de texto
    while ( !archivoEncabezado.eof() )
    {
        if ( encabezado.mobtenerClaveEncabezado() != 0 )
        encabezado.mmostrarEncabezado(encabezado);
        // leer siguiente registro del archivo de registros
        archivoEncabezado.read( reinterpret_cast< char * >( &encabezado ),
        sizeof( Clsencabezado ) );
    }
    cout << left << setw( 10 ) << "clave:"
    << setw( 10 ) << "Nombre:"
//Karla Gómez 9959-21-1896
    << setw( 10 ) << "Cargo"
    << setw( 10 ) << "Salario"
    << setw( 10 ) << "Dias"
    << setw( 10 ) << "Ordinario"
    << setw( 10 ) << "H.E."
    << setw( 10 ) << "S. Extra."
    << setw( 10 ) << "Bon.In."
    << setw( 10 ) << "Devengado"
    << setw( 10 ) << "Impuesto"
    << setw( 10 ) << "Impuesto"
    << setw( 10 ) << "Anticipo"
    << setw( 10 ) << "T. Desc."
    << setw( 10 ) << "T. Liq."
    << endl;
//Alyson Rodriguez 9959-21-829
        int m_iclaveNominas = 1;
        // colocar el apuntador de posición de archivo al principio del archivo de registros
        archivoNomina.seekg(
        ( m_iclaveNominas - 1 ) * sizeof( Clsnomina ) );
        // leer el primer registro del archivo de registros
        Clsnomina nomina;
        archivoNomina.read( reinterpret_cast< char * >( &nomina ),
        sizeof( Clsnomina ) );
        // copiar todos los registros del archivo de registros en el archivo de texto
        while ( !archivoNomina.eof() )
        {
            // escribir un registro individual en el archivo de texto
            if ( nomina.mobtenerClaveEnomina() != 0 )
            mostrarLineaNomina(nomina);
            // leer siguiente registro del archivo de registros
            archivoNomina.read( reinterpret_cast< char * >( &nomina ),
            sizeof( Clsnomina ) );
        }
    /*}while(ciclo>0)*/
    getch();
}
Clsnomina::~Clsnomina()
{
    //dtor
}
