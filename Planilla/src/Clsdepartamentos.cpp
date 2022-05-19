#include "Clsdepartamentos.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

#include "ClsmenuMantenimientos.h"

ClsDepartamentos::ClsDepartamentos(int valorCodigo, string txtEmpleado, string txtDepartamento, string txtPuesto)
{
    mestablecerCodigo(valorCodigo);
    mestablecerNombreEmpleado(txtEmpleado);
    mestablecerDepartamento(txtDepartamento);
    mestablecerPuesto(txtPuesto);
}

int ClsDepartamentos::mobtenerCodigo() const
{
    return m_icodigoEmpleadoDepartamento;
}

void ClsDepartamentos::mestablecerCodigo (int ienteroCodigo)
{
    m_icodigoEmpleadoDepartamento = ienteroCodigo;
}

//Funciones del nombre del empleado
string ClsDepartamentos::mobtenerNombreEmpleado() const
{
    return m_sEmpleado;
}

void ClsDepartamentos::mestablecerNombreEmpleado( string scadenaNombreEmpleado )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreEmpleado = scadenaNombreEmpleado.data();
   int ilongitud = strlen( svalorNombreEmpleado );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sEmpleado, svalorNombreEmpleado, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sEmpleado[ ilongitud ] = '\0';

}

string ClsDepartamentos::mobtenerDepartamento() const
{
    return m_sDepartamento;
}

void ClsDepartamentos::mestablecerDepartamento( string scadenaDepartamento )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorDepartamento = scadenaDepartamento.data();
   int ilongitud = strlen( svalorDepartamento );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sDepartamento, svalorDepartamento, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sDepartamento[ ilongitud ] = '\0';

}

string ClsDepartamentos::mobtenerPuesto() const
{
    return m_sPuesto;
}

void ClsDepartamentos::mestablecerPuesto( string scadenaPuesto )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorPuesto = scadenaPuesto.data();
   int ilongitud = strlen( svalorPuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sPuesto, svalorPuesto, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sPuesto[ ilongitud ] = '\0';

}

int obtenerCuenta( const char * const indicador )
{
   int m_icodigoEmpleadoDepartamento;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 100): ";
      cin >> m_icodigoEmpleadoDepartamento;

   } while ( m_icodigoEmpleadoDepartamento < 1 || m_icodigoEmpleadoDepartamento > 100 );

   return m_icodigoEmpleadoDepartamento;

} // fin de la función obtenerCuenta

void ClsDepartamentos::nuevoEmpleado( fstream &insertarEnArchivoDepartamento )
{
   // obtener el número de cuenta a crear
   int m_icodigoEmpleadoDepartamento = obtenerCuenta( "Escriba el nuevo numero de cuenta" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivoDepartamento.seekg(
      ( m_icodigoEmpleadoDepartamento - 1 ) * sizeof( ClsDepartamentos ) );

   // leer el registro del archivo
   ClsDepartamentos departametos;
   insertarEnArchivoDepartamento.read( reinterpret_cast< char * >( &departametos ),
      sizeof( ClsDepartamentos ) );

   // crear el registro, si éste no existe ya
   if ( departametos.mobtenerCodigo() == 0 ) {

      char m_sEmpleado[ 20 ];
      char m_sDepartamento[20];
      char m_sPuesto[20];

      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 20 ) >> m_sEmpleado;
      cout << "Escriba el Departamento: " << endl;
      cin >> setw( 20 ) >> m_sDepartamento;
      cout << "Escriba el Puesto: " << endl;
      cin >> setw( 20 ) >> m_sPuesto;

      // usar valores para llenar los valores de la cuenta
      departametos.mestablecerNombreEmpleado( m_sEmpleado );
      departametos.mestablecerCodigo( m_icodigoEmpleadoDepartamento );
      departametos.mestablecerDepartamento( m_sDepartamento );
      departametos.mestablecerPuesto( m_sPuesto );


      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivoDepartamento.seekp( ( m_icodigoEmpleadoDepartamento - 1 ) *
         sizeof( ClsDepartamentos ) );

      // insertar el registro en el archivo
      insertarEnArchivoDepartamento.write(
         reinterpret_cast< const char * >( &departametos ),
         sizeof( ClsDepartamentos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "La cuenta #" << m_icodigoEmpleadoDepartamento
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro

void ClsDepartamentos::consultarRegistroDepartamentos( fstream &leerDeArchivoDepartamentos )
{

   cout << left << setw( 9 ) << "Codigo" << setw( 20 )
       << "Nombre" << setw( 20 ) << "Departamento"
       << setw( 20 ) << "Puesto" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoDepartamentos.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsDepartamentos departamentos;
   leerDeArchivoDepartamentos.read( reinterpret_cast< char * >( &departamentos ),
      sizeof( ClsDepartamentos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoDepartamentos.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( departamentos.mobtenerCodigo() != 0 )
         mostrarLineaPantallaDepartamentos(departamentos);

      // leer siguiente registro del archivo de registros
      leerDeArchivoDepartamentos.read( reinterpret_cast< char * >( &departamentos ),
         sizeof( ClsDepartamentos ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

void ClsDepartamentos::mostrarLineaPantallaDepartamentos( const ClsDepartamentos &registroDepartamentos )
{
   cout << left << setw( 10 ) << registroDepartamentos.mobtenerCodigo()
          << setw( 20 ) << registroDepartamentos.mobtenerNombreEmpleado().data()
          << setw( 20 ) << registroDepartamentos.mobtenerDepartamento().data()
          << setw( 20 ) << registroDepartamentos.mobtenerPuesto().data() << endl;

} // fin de la función mostrarLineaPantalla

void ClsDepartamentos::actualizarRegistroDepartamentos( fstream &actualizarArchivoDepartamentos )
{
   // obtener el número de cuenta a actualizar
   int numeroCodigo = obtenerCuenta( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivoDepartamentos.seekg(
      ( numeroCodigo - 1 ) * sizeof( ClsDepartamentos ) );

   // leer el primer registro del archivo
   ClsDepartamentos departamentos;
   actualizarArchivoDepartamentos.read( reinterpret_cast< char * >( &departamentos ),
      sizeof( ClsDepartamentos ) );

   // actualizar el registro
   if ( departamentos.mobtenerCodigo() != 0 ) {
      mostrarLineaDepartamentos( cout, departamentos );

      // solicitar al usuario que especifique la transacción
      cout << "\nEscriba el nombre: ";
      char m_sEmpleado [ 20 ];
      cin >> m_sEmpleado;

      cout << "\nEscriba el Departamento: ";
      char m_sDepartamento [ 20 ];
      cin >> m_sDepartamento;

      cout << "\nEscriba el Puesto: ";
      char m_sPuesto [ 20 ];
      cin >> m_sPuesto;

      // actualizar el saldo del registro
      departamentos.mestablecerNombreEmpleado( m_sEmpleado );
      mostrarLineaDepartamentos( cout, departamentos );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivoDepartamentos.seekp(
         ( numeroCodigo - 1 ) * sizeof( ClsDepartamentos ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivoDepartamentos.write(
         reinterpret_cast< const char * >( &departamentos ),
         sizeof( ClsDepartamentos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << numeroCodigo
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro

void ClsDepartamentos::mostrarLineaDepartamentos( ostream &salidaDepartamento, const ClsDepartamentos &registroDepartamentos )
{
   salidaDepartamento << left << setw( 9 ) << registroDepartamentos.mobtenerCodigo()
          << setw( 20 ) << registroDepartamentos.mobtenerNombreEmpleado().data()
          << setw( 20 ) << registroDepartamentos.mobtenerDepartamento().data()
          << setw( 20 ) << registroDepartamentos.mobtenerPuesto().data()
          << endl;

} // fin de la función mostrarLinea

void ClsDepartamentos::imprimirRegistroDepartamentos( fstream &leerDeArchivoDepartamentos )
{
   // crear archivo de texto
   ofstream archivoImprimirSalidaDepartamentos( "ImprimirRegistroDepartamentos.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalidaDepartamentos ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if
   else{
    cout<<"Se creo el archivo Departamentos"<<endl;
   }

   archivoImprimirSalidaDepartamentos << left << setw( 9 ) << "Codigo" << setw( 20 )
       << "Nombre: " << setw( 20 ) << "Departamento:" << setw( 20 ) << "Puesto:" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoDepartamentos.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsDepartamentos departamentos;
   leerDeArchivoDepartamentos.read( reinterpret_cast< char * >( &departamentos ),
      sizeof( ClsDepartamentos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoDepartamentos.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( departamentos.mobtenerCodigo() != 0 )
         mostrarLineaDepartamentos( archivoImprimirSalidaDepartamentos, departamentos );

      // leer siguiente registro del archivo de registros
      leerDeArchivoDepartamentos.read( reinterpret_cast< char * >( &departamentos ),
         sizeof( ClsDepartamentos ) );

   } // fin de instrucción while

} // fin de la función imprimirRegistro

void ClsDepartamentos::eliminarRegistroDepartamento( fstream &eliminarDeArchivoDepartamento )
{
   // obtener número de cuenta a eliminar
   int numeroCodigo= obtenerCuenta( "Escriba la cuenta a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivoDepartamento.seekg(
      ( numeroCodigo - 1 ) * sizeof( ClsDepartamentos ) );

   // leer el registro del archivo
   ClsDepartamentos departamentos;
   eliminarDeArchivoDepartamento.read( reinterpret_cast< char * >( &departamentos ),
      sizeof( ClsDepartamentos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( departamentos.mobtenerCodigo() != 0 ) {
      ClsDepartamentos empleadoEnBlancoDepartamento;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivoDepartamento.seekp( ( numeroCodigo - 1 ) *
         sizeof( ClsDepartamentos ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivoDepartamento.write(
         reinterpret_cast< const char * >( &empleadoEnBlancoDepartamento ),
         sizeof( ClsDepartamentos ) );

      cout << "Empleado clave #" << numeroCodigo << " eliminado correctamente.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
   {
       cerr << "Empleado clave #" << numeroCodigo << " esta vacia.\n";
   }
   getch();

} // fin de eliminarRegistro

void ClsDepartamentos::buscarEmpleadoDepartamento( fstream &leerDeArchivoDepartamento)
{

   // obtener el número de cuenta a buscar
   int numeroCodigo = obtenerCuenta( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   leerDeArchivoDepartamento.seekg(
      ( numeroCodigo - 1 ) * sizeof( ClsDepartamentos ) );

   // leer el primer registro del archivo
   ClsDepartamentos departamentos;
   leerDeArchivoDepartamento.read( reinterpret_cast< char * >( &departamentos ),
      sizeof( ClsDepartamentos ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( departamentos.mobtenerCodigo() != 0 ) {
      mostrarLineaDepartamentos( cout, departamentos );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "La cuenta #" << numeroCodigo
         << " no tiene informacion." << endl;
   }
   getch();

} // fin de la función consultarRegistro

ClsDepartamentos::mcrearDepartamentos()
{
    ofstream archivoDepartamentos("RegistrosDepartamentos.dat", ios::out | ios::binary);
    if(!archivoDepartamentos)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    ClsDepartamentos departamentosEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoDepartamentos.write(reinterpret_cast<const char * > (&departamentosEnBlanco), sizeof(ClsDepartamentos));
    }
}

ClsDepartamentos::mmenuDepartamentos()
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

    int iseleccionMenuDepartamentos;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoDepartamentos("RegistrosDepartamentos.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoDepartamentos )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearDepartamentos();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|SISTEMA GESTION DEPARTAMENTOS|"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Departamento"<<endl;
        cout<<"2. Despliegue Departamentos"<<endl;
        cout<<"3. Modifica Departamento"<<endl;
        cout<<"4. Imprimir Regisro de Departamentos"<<endl;
        cout<<"5. Borra Departamento"<<endl;
        cout<<"6. Buscar Departamento"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuDepartamentos;
        switch(iseleccionMenuDepartamentos)
        {
        case 1:
            {
                accion = "Ingreso a Agre. Departa.";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                nuevoEmpleado(archivoDepartamentos);
                getch();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Cons. Departa.";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                consultarRegistroDepartamentos(archivoDepartamentos);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                accion = "Ingreso a Mod. Departa.";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                actualizarRegistroDepartamentos(archivoDepartamentos);
                getch();
            }
            break;
        case 4:
            {
                accion = "Ingreso a Impri. Departa.";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                imprimirRegistroDepartamentos(archivoDepartamentos);
                getch();
            }
            break;
        case 5:
            {
                accion = "Ingreso a Elim. Departa.";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                eliminarRegistroDepartamento(archivoDepartamentos);
                getch();
            }
            break;
        case 6:
            {
                accion = "Ingreso a Buscar. Departa.";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                buscarEmpleadoDepartamento(archivoDepartamentos);
                getch();
            }
            break;
        case 0:
            {
                accion = "Salio de Gestion Departa.";

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
    }while(iseleccionMenuDepartamentos!=0);
}

ClsDepartamentos::~ClsDepartamentos()
{
    //dtor
}
