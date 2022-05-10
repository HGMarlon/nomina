#include "ClsPuestos.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

#include "ClsmenuMantenimientos.h"

using namespace std;

ClsPuestos::ClsPuestos(int inumeroPuesto, string snombreCargo , string sDepartamento, string sSalario, string sNivelAcademico, string sHoraEntrada, string sHoraSalida )
{
    //ctor
    mestablecerNumero(inumeroPuesto);
    mestablecerCargo(snombreCargo);
    mestablecerDepaPuesto(sDepartamento);
    mestablecerSalario(sSalario);
    mestablecerNivelAc(sNivelAcademico);
    mestablecerHoraEntrada(sHoraEntrada);
    mestablecerHoraSalida(sHoraSalida);
}

int ClsPuestos::mobtenerNumero() const
{
    return m_inumeroPuesto;
}

void ClsPuestos::mestablecerNumero (int ienteroNumero)
{
    m_inumeroPuesto = ienteroNumero;
}

//Funciones del nombre del Puesto
string ClsPuestos::mobtenerCargo() const
{
    return m_snombreCargo;
}

void ClsPuestos::mestablecerCargo( string scadenaCargo )
{
   // copiar a lo m�s 20 caracteres de la cadena en nombree
   const char *svalorCargo = scadenaCargo.data();
   int ilongitud = strlen( svalorCargo );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreCargo, svalorCargo, ilongitud );

   // anexar caracter nulo al final del nombre
   m_snombreCargo[ ilongitud ] = '\0';

}

string ClsPuestos::mobtenerDepaPuesto() const
{
    return m_sDepartamento;
}

void ClsPuestos::mestablecerDepaPuesto( string scadenaDepartamento )
{

   const char *svalorDepa = scadenaDepartamento.data();
   int ilongitud = strlen( svalorDepa );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sDepartamento, svalorDepa, ilongitud );


   m_sDepartamento[ ilongitud ] = '\0';

}

string ClsPuestos::mobtenerSalario() const
{
    return m_sSalario;
}

void ClsPuestos::mestablecerSalario( string scadenaSalario )
{

   const char *svalorSalario = scadenaSalario.data();
   int ilongitud = strlen( svalorSalario );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sSalario, svalorSalario, ilongitud );


   m_sSalario[ ilongitud ] = '\0';

}

string ClsPuestos::mobtenerNivelAc() const
{
    return m_sNivelAcademico;
}

void ClsPuestos::mestablecerNivelAc( string scadenaNivel )
{

   const char *svalorNivel = scadenaNivel.data();
   int ilongitud = strlen( svalorNivel );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNivelAcademico, svalorNivel, ilongitud );


   m_sNivelAcademico[ ilongitud ] = '\0';

}

string ClsPuestos::mobtenerHoaraEntrada() const
{
    return m_sHoraEntrada;
}

void ClsPuestos::mestablecerHoraEntrada( string scadenaEntrada )
{

   const char *svalorEntrada = scadenaEntrada.data();
   int ilongitud = strlen( svalorEntrada );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sHoraEntrada, svalorEntrada, ilongitud );


   m_sHoraEntrada[ ilongitud ] = '\0';

}

string ClsPuestos::mobtenerHoaraSalida() const
{
    return m_sHoraSalida;
}

void ClsPuestos::mestablecerHoraSalida( string scadenaSalida )
{

   const char *svalorSalida = scadenaSalida.data();
   int ilongitud = strlen( svalorSalida );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sHoraSalida, svalorSalida, ilongitud );


   m_sHoraSalida[ ilongitud ] = '\0';

}

ClsPuestos::mcrearPuestos()
{
    ofstream archivoPuestos("registrospuestos.dat", ios::out | ios::binary);
    if(!archivoPuestos)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    ClsPuestos puestoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoPuestos.write(reinterpret_cast<const char * > (&puestoEnBlanco), sizeof(ClsPuestos));
    }
}

int ClsPuestos::mobtenerIndicadorP(const char * const iindicador)
{
    int m_inumeroPuesto;

   // obtener el valor del n�mero de puesto
   do {
      cout << iindicador << " (1 - 100): ";
      cin >> m_inumeroPuesto;

   } while ( m_inumeroPuesto < 1 || m_inumeroPuesto > 100 );

   return m_inumeroPuesto;
}

void ClsPuestos::mnuevoPuestos(fstream &archivoPuestos)
{
   ClsPuestos puesto;
   int m_inumeroPuesto = mobtenerIndicadorP( "Escriba el numero del puesto" );

   // desplazar el apuntador de posici�n del archivo hasta el registro correcto en el archivo
   archivoPuestos.seekg(
      ( m_inumeroPuesto - 1 ) * sizeof( ClsPuestos ) );

   // leer el registro del archivo
   archivoPuestos.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // crear el registro, si �ste no existe ya
   if ( puesto.mobtenerNumero() == 0 ) {

      char m_snombreCargo[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba el cargo del puesto: " << endl;
      cin >> setw( 20 ) >> m_snombreCargo;

      char m_sDepartamento[ 20 ];

      cout << "Escriba el departamento al que pertenece: " << endl;
      cin >> setw( 20 ) >> m_sDepartamento;

      char m_sSalario[ 20 ];

      cout << "Escriba el monto total del salario: " << endl;
      cin >> setw( 20 ) >> m_sSalario;

      char m_sNivelAcademico[ 20 ];

      cout << "Escriba el nivel academico requerido para el puesto: " << endl;
      cin >> setw( 20 ) >> m_sNivelAcademico;

      char m_sHoraEntrada[ 20 ];

      cout << "Escriba la hora de entada: " << endl;
      cin >> setw( 20 ) >> m_sHoraEntrada;

      char m_sHoraSalida[ 20 ];

      cout << "Escriba la hora de salida: " << endl;
      cin >> setw( 20 ) >> m_sHoraSalida;

      // usar valores para llenar los valores de la clave
      puesto.mestablecerCargo( m_snombreCargo );
      puesto.mestablecerNumero( m_inumeroPuesto );
      puesto.mestablecerDepaPuesto(m_sDepartamento);
      puesto.mestablecerSalario(m_sSalario);
      puesto.mestablecerNivelAc(m_sNivelAcademico);
      puesto.mestablecerHoraEntrada(m_sHoraEntrada);
      puesto.mestablecerHoraSalida(m_sHoraSalida);

      // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
      archivoPuestos.seekp( ( m_inumeroPuesto - 1 ) *
         sizeof( ClsPuestos ) );

      // insertar el registro en el archivo
      archivoPuestos.write(
         reinterpret_cast< const char * >( &puesto ),
         sizeof( ClsPuestos ) );

        cout << "Puesto agregado con exito.";

   }

   // mostrar error si la cuenta ya existe
   else
   {
       cerr << "El numero  #" << m_inumeroPuesto << " ya contiene informacion." << endl;
       getch();
   }
}

void ClsPuestos::mostrarLineaPuestos( const ClsPuestos &registroP )
{
       cout << left << setw( 10 ) << registroP.mobtenerCargo()
          << setw( 20 ) << registroP.mobtenerCargo().data()
          << setw( 20 ) << registroP.mobtenerDepaPuesto().data()
          << setw( 20 ) << registroP.mobtenerSalario().data()
          << setw( 20 ) << registroP.mobtenerNivelAc().data()
          << setw( 20 ) << registroP.mobtenerHoaraEntrada().data()
          << setw( 20 ) << registroP.mobtenerHoaraSalida().data()
          << endl;
}

void ClsPuestos::mconsultarRegistroPuestos(fstream &archivoPuestos)
{
   cout << left << setw( 10 ) << "Numero" << setw( 20 )
       << "Cargo" << setw( 20 )
       << "Departamento" << setw( 20 )
       << "Salario" << setw ( 20 )
       << "Nivel academico" << setw ( 20 )
       << "Hora de entrada" << setw ( 20 )
       << "Hora de salida"<< endl;

   // colocar el apuntador de posici�n de archivo al principio del archivo de registros
   archivoPuestos.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsPuestos puesto;
   archivoPuestos.read( reinterpret_cast< char * >( &puesto),
      sizeof( ClsPuestos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoPuestos.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( puesto.mobtenerNumero() != 0 )
         mostrarLineaPuestos(puesto);

      // leer siguiente registro del archivo de registros
      archivoPuestos.read( reinterpret_cast< char * >( &puesto ),
         sizeof( ClsPuestos ) );

   }
}

void ClsPuestos::mmostrarLineaRegistroPuestos( ostream &salida, const ClsPuestos &registropuesto )
{
       salida << left << setw( 10 ) << registropuesto.mobtenerCargo()
          << setw( 20 ) << registropuesto.mobtenerCargo().data()
          << setw( 20 ) << registropuesto.mobtenerDepaPuesto().data()
          << setw( 20 ) << registropuesto.mobtenerSalario().data()
          << setw( 20 ) << registropuesto.mobtenerNivelAc().data()
          << setw( 20 ) << registropuesto.mobtenerHoaraEntrada().data()
          << setw( 20 ) << registropuesto.mobtenerHoaraSalida().data()
          << endl;

}

void ClsPuestos::mmodificarRegistroPuestos( fstream &archivoPuestos )
{

   ClsPuestos puesto;
   int m_inumeroPuesto = mobtenerIndicadorP("Ingrese el numero del puesto");

   archivoPuestos.seekg(
      ( m_inumeroPuesto - 1 ) * sizeof( ClsPuestos ) );

   // leer el primer registro del archivo
   archivoPuestos.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // actualizar el registro
   if ( puesto.mobtenerNumero() != 0 ) {
      mmostrarLineaRegistroPuestos( cout, puesto );

      cout << "\nEscriba el nombre del cargo: ";
      char m_snombreCargo [ 20 ];
      cin >> m_snombreCargo;

      cout << "\nEscriba el departamento al que pertence: ";
      char m_sDepartamento [ 20 ];
      cin >> m_sDepartamento;

      cout << "\nEscriba el monto total del salario: ";
      char m_sSalario [ 20 ];
      cin >> m_sSalario;

      cout << "\nEscriba el nivel academico requerido: ";
      char m_sNivelAcademico [ 20 ];
      cin >> m_sNivelAcademico;

      cout << "\nEscriba la hora de entrada: ";
      char m_sHoraEntrada [ 20 ];
      cin >> m_sHoraEntrada;

      cout << "\nEscriba la hora de salida: ";
      char m_sHoraSalida [ 20 ];
      cin >> m_sHoraSalida;

      // actualizar el saldo del registro
      puesto.mestablecerCargo( m_snombreCargo );
      puesto.mestablecerNumero( m_inumeroPuesto );
      puesto.mestablecerDepaPuesto(m_sDepartamento);
      puesto.mestablecerSalario(m_sSalario);
      puesto.mestablecerNivelAc(m_sNivelAcademico);
      puesto.mestablecerHoraEntrada(m_sHoraEntrada);
      puesto.mestablecerHoraSalida(m_sHoraSalida);
      mmostrarLineaRegistroPuestos( cout, puesto );

      // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
      archivoPuestos.seekp(
         ( m_inumeroPuesto - 1 ) * sizeof( ClsPuestos ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      archivoPuestos.write(
         reinterpret_cast< const char * >( &puesto ),
         sizeof( ClsPuestos ) );

        cout << "Puesto modificado con �xito.";

   } // fin de instrucci�n if

   // mostrar error si la cuenta no existe
   else
      cerr << "El numero #" << m_inumeroPuesto
         << " no tiene informacion." << endl;
}

void ClsPuestos::mimprimirRegistroPuestos(fstream &archivoPuesto)
{
    ClsPuestos puesto;
    ofstream imprimir("registrodepuestos.txt", ios::out);

   // salir del programa si ofstream no puede crear el archivo
   if ( !imprimir ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucci�n if

   imprimir << left << setw( 10 ) << "Numero" << setw( 20 )
       << "Cargo" << setw( 20 )
       << "Departamento" << setw( 20 )
       << "Salario" << setw( 20 )
       << "Nivel academico" <<setw( 20 )
       << "Hora de entrada" << setw( 20 )
       << "Hora de salida"<< endl;
   // colocar el apuntador de posici�n de archivo al principio del archivo de registros
   archivoPuesto.seekg( 0 );

   // leer el primer registro del archivo de registros
   archivoPuesto.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoPuesto.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( puesto.mobtenerNumero() != 0 )
         mmostrarLineaRegistroPuestos( imprimir, puesto );

      // leer siguiente registro del archivo de registros
      archivoPuesto.read( reinterpret_cast< char * >( &puesto ),
         sizeof( ClsPuestos ) );

   }
   cout << "archivo creado con �xito con el nombre de: regisrodepuestos";
}

void ClsPuestos::meliminarRegistroPuestos(fstream &archivoPuestos)
{
    int iindicador= mobtenerIndicadorP( "Escriba el numero de puesto a eliminar" );

   // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
   archivoPuestos.seekg(
      ( iindicador - 1 ) * sizeof( ClsPuestos ) );

   // leer el registro del archivo
   ClsPuestos puesto;
   archivoPuestos.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( puesto.mobtenerNumero() != 0 ) {
      ClsPuestos puestoEnBlanco;

      // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
      archivoPuestos.seekp( ( iindicador - 1 ) *
         sizeof( ClsPuestos ) );

      // reemplazar el registro existente con un registro en blanco
      archivoPuestos.write(
         reinterpret_cast< const char * >( &puestoEnBlanco ),
         sizeof( ClsPuestos ) );

      cout << "Puesto numero #" << iindicador << " eliminado correctamente.\n";

   }

   // mostrar error si el registro no existe
   else
   {
       cerr << "Puesto numero #" << iindicador << " esta vacia.\n";
   }
   getch();
}

void ClsPuestos::mbuscarPuestos(fstream &archivoPuestos)
{
    int iindicador = mobtenerIndicadorP( "Escriba el numero que desea buscar" );

   // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
   archivoPuestos.seekg(
      ( iindicador - 1 ) * sizeof( ClsPuestos ) );

   // leer el primer registro del archivo
   ClsPuestos puesto;
   archivoPuestos.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( puesto.mobtenerNumero() != 0 ) {
      mmostrarLineaRegistroPuestos( cout, puesto );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "El numero #" << iindicador
         << " no tiene informacion." << endl;
   }
   getch();
}

ClsPuestos::mmenuPuestos()
{
    int iseleccionMenuPuestos;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoPuestos("registrospuestos.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoPuestos )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearPuestos();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION PUESTOS   |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso de Puestos"<<endl;
        cout<<"2. Despliegue de Puestos"<<endl;
        cout<<"3. Modifica Puestos"<<endl;
        cout<<"4. Imprimir Regisro de Puestos"<<endl;
        cout<<"5. Borra Puestos"<<endl;
        cout<<"6. Buscar Puestos"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuPuestos;
        switch(iseleccionMenuPuestos)
        {
        case 1:
            {
                system("cls");
                mnuevoPuestos(archivoPuestos);
                getch();
            }
            break;
        case 2:
            {
                system("cls");
                mconsultarRegistroPuestos(archivoPuestos);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                system("cls");
                mmodificarRegistroPuestos(archivoPuestos);
                getch();
            }
            break;
        case 4:
            {
                system("cls");
                mimprimirRegistroPuestos(archivoPuestos);
                getch();
            }
            break;
        case 5:
            {
                system("cls");
                meliminarRegistroPuestos(archivoPuestos);
            }
            break;
        case 6:
            {
                system("cls");
                mbuscarPuestos(archivoPuestos);
            }
            break;
        case 0:
            break;
        default:
            cout<<"Opci�n invalida, intenta de nuevo";
            getch();
            break;
        }
    }while(iseleccionMenuPuestos!=0);
}


ClsPuestos::~ClsPuestos()
{
    //dtor
}
