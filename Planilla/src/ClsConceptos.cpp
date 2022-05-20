#include "ClsConceptos.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include<math.h>

#include "ClsmenuMantenimientos.h"

ClsConceptos::ClsConceptos(int valorDesBono, int valorCodigo, string txtEmpleado, string txtConcepto, int valorCantPorce, float txtPorcentaje)
{
    mestablecerBonoDescuento(valorDesBono);
    mestablecerCodigo(valorCodigo);
    mestablecerNombreEmpleado(txtEmpleado);
    mestablecerConcepto(txtConcepto);
    mestablecerCantidadPorcentaje(valorCantPorce);
    mestablecerPorcentaje(txtPorcentaje);
}

int ClsConceptos::mobtenerCodigo() const
{
    return m_icodigoEmpleadoConcepto;
}

void ClsConceptos::mestablecerCodigo (int ienteroCodigo)
{
    m_icodigoEmpleadoConcepto = ienteroCodigo;
}

int ClsConceptos::mobtenerBonoDescuento() const
{
    return m_iBonoDescuento;
}

void ClsConceptos::mestablecerBonoDescuento (int ienteroBonoDescuento)
{
    m_iBonoDescuento = ienteroBonoDescuento;
}

string ClsConceptos::mobtenerNombreEmpleado() const
{
    return m_sEmpleado;
}

void ClsConceptos::mestablecerNombreEmpleado( string scadenaNombreEmpleado )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreEmpleado = scadenaNombreEmpleado.data();
   int ilongitud = strlen( svalorNombreEmpleado );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sEmpleado, svalorNombreEmpleado, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sEmpleado[ ilongitud ] = '\0';

}

string ClsConceptos::mobtenerConcepto() const
{
    return m_sConcepto;
}

void ClsConceptos::mestablecerConcepto( string scadenaConcepto )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorConcepto = scadenaConcepto.data();
   int ilongitud = strlen( svalorConcepto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sConcepto, svalorConcepto, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sConcepto[ ilongitud ] = '\0';

}

int ClsConceptos::mobtenerCantidadPorcentaje() const
{
    return m_iCantidadPorcentaje;
}

void ClsConceptos::mestablecerCantidadPorcentaje (int ienteroCantidadPorcentaje)
{
    m_iCantidadPorcentaje = ienteroCantidadPorcentaje;
}

float ClsConceptos::mobtenerPorcentaje() const
{
    int ent;
    ent = m_sPorcentaje;

    if(m_sPorcentaje - ent)
    {
        return m_sPorcentaje*100;
    }
    else
    {
        return m_sPorcentaje;
    }
}

float ClsConceptos::mdescuento() const
{
    return m_sPorcentaje;
}

void ClsConceptos::mestablecerPorcentaje (float fFloatPorcentaje)
{
    m_sPorcentaje = fFloatPorcentaje;
}

int ClsConceptos::mobtenerIndicador(const char * const iindicador)
{
    int m_icodigoEmpleadoConcepto;
   // obtener el valor de la clave
   do
    {
      cout << iindicador << " (1 - 100): ";
      cin >> m_icodigoEmpleadoConcepto;
    } while ( m_icodigoEmpleadoConcepto < 1 || m_icodigoEmpleadoConcepto > 100 );
   return m_icodigoEmpleadoConcepto;
}

void ClsConceptos::nuevoConcepto( fstream &insertarEnArchivoConcepto )
{
    int m_iBonoDescuento;
    cout<<"Descuento(1) o Abono(0): ";
    cin>>m_iBonoDescuento;
    if( m_iBonoDescuento == 1)
    {
        // obtener el número de cuenta a crear
       int m_icodigoEmpleadoConcepto = mobtenerIndicador( "Escriba el nuevo numero de cuenta" );

       // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
       insertarEnArchivoConcepto.seekg(
          ( m_icodigoEmpleadoConcepto - 1 ) * sizeof( ClsConceptos ) );

       // leer el registro del archivo
       ClsConceptos conceptos;
       insertarEnArchivoConcepto.read( reinterpret_cast< char * >( &conceptos ),
          sizeof( ClsConceptos ) );

       // crear el registro, si éste no existe ya
       if ( conceptos.mobtenerCodigo() == 0 )
        {

          char m_sEmpleado[ 20 ];
          char m_sConcepto[20];
          int m_iCantidadPorcentaje;
          float m_sPorcentaje;

          // el usuario introduce el apellido, primer nombre y saldo
          cout << "Escriba el nombre: ";
          cin >> setw( 20 ) >> m_sEmpleado;
          cout << "Escriba el Concepto: ";
          cin >> setw( 20 ) >> m_sConcepto;
          cout<<"Cantidad(1) o Porcentaje(0): ";
          cin>>m_iCantidadPorcentaje;
          if(m_iCantidadPorcentaje == 1)
          {
              cout << "Escriba el Cantidad: ";
              cin >> setw( 20 ) >>m_sPorcentaje;

              conceptos.mestablecerPorcentaje( m_sPorcentaje );
          }
          else if(m_iCantidadPorcentaje == 0)
          {
              cout << "Escriba el Porcentaje: ";
              cin >> setw( 20 ) >>m_sPorcentaje;

              m_sPorcentaje=m_sPorcentaje/100;

              conceptos.mestablecerPorcentaje( m_sPorcentaje );
          }

          // usar valores para llenar los valores de la cuenta
          conceptos.mestablecerBonoDescuento( m_iBonoDescuento );
          conceptos.mestablecerCodigo( m_icodigoEmpleadoConcepto );
          conceptos.mestablecerNombreEmpleado( m_sEmpleado );
          conceptos.mestablecerConcepto( m_sConcepto );
          conceptos.mestablecerCantidadPorcentaje( m_iCantidadPorcentaje );


          // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
          insertarEnArchivoConcepto.seekp( ( m_icodigoEmpleadoConcepto - 1 ) *
             sizeof( ClsConceptos ) );

          // insertar el registro en el archivo
          insertarEnArchivoConcepto.write(
             reinterpret_cast< const char * >( &conceptos ),
             sizeof( ClsConceptos ) );

       } // fin de instrucción if

       // mostrar error si la cuenta ya existe
       else
       {
           cerr << "La cuenta #" << m_icodigoEmpleadoConcepto
               << " ya contiene informacion." << endl;
       }
    }

    if(m_iBonoDescuento == 0)
    {
        // obtener el número de cuenta a crear
       int m_icodigoEmpleadoConcepto = mobtenerIndicador( "Escriba el nuevo numero de cuenta" );

       // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
       insertarEnArchivoConcepto.seekg(
          ( m_icodigoEmpleadoConcepto - 1 ) * sizeof( ClsConceptos ) );

       // leer el registro del archivo
       ClsConceptos conceptos;
       insertarEnArchivoConcepto.read( reinterpret_cast< char * >( &conceptos ),
          sizeof( ClsConceptos ) );

       // crear el registro, si éste no existe ya
       if ( conceptos.mobtenerCodigo() == 0 ) {

          char m_sEmpleado[ 20 ];
          char m_sConcepto[20];
          int m_iCantidadPorcentaje;
          float m_sPorcentaje;

          // el usuario introduce el apellido, primer nombre y saldo
          cout << "Escriba el nombre: ";
          cin >> setw( 20 ) >> m_sEmpleado;
          cout << "Escriba el Concepto: ";
          cin >> setw( 20 ) >> m_sConcepto;
          cout<<"Cantidad(1) o Porcentaje(0)";
          cin>>m_iCantidadPorcentaje;
          if(m_iCantidadPorcentaje == 1)
          {
              cout << "Escriba el Cantidad: ";
              cin >> setw( 20 ) >>m_sPorcentaje;

              conceptos.mestablecerPorcentaje( m_sPorcentaje );
          }
          else if(m_iCantidadPorcentaje == 0)
          {
              cout << "Escriba el Porcentaje: ";
              cin >> setw( 20 ) >>m_sPorcentaje;

              m_sPorcentaje=m_sPorcentaje/100;

              conceptos.mestablecerPorcentaje( m_sPorcentaje );
          }

          // usar valores para llenar los valores de la cuenta
          conceptos.mestablecerBonoDescuento( m_iBonoDescuento );
          conceptos.mestablecerCodigo( m_icodigoEmpleadoConcepto );
          conceptos.mestablecerNombreEmpleado( m_sEmpleado );
          conceptos.mestablecerConcepto( m_sConcepto );
          conceptos.mestablecerCantidadPorcentaje( m_iCantidadPorcentaje );


          // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
          insertarEnArchivoConcepto.seekp( ( m_icodigoEmpleadoConcepto - 1 ) *
             sizeof( ClsConceptos ) );

          // insertar el registro en el archivo
          insertarEnArchivoConcepto.write(
             reinterpret_cast< const char * >( &conceptos ),
             sizeof( ClsConceptos ) );

       } // fin de instrucción if

       // mostrar error si la cuenta ya existe
       else
       {
           cerr << "La cuenta #" << m_icodigoEmpleadoConcepto
               << " ya contiene informacion." << endl;
       }
    }
    else
    {
        cout<<"Ingrese una opcion validad";
    }
}

////////////////////////////////////////////DESPLIEGE DE CONCEPTOS
void ClsConceptos::consultarRegistroConcepto( fstream &leerDeArchivoConceptos )
{

   cout << left << setw( 15 ) << "Bono/Des." << setw( 15 ) << "Codigo" << setw( 20 )
       << "Nombre" << setw( 20 ) << "Concepto" << setw( 20 ) << "Cant/Porcen." << setw( 20 ) << "Monto." << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoConceptos.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsConceptos conceptos;
   leerDeArchivoConceptos.read( reinterpret_cast< char * >( &conceptos ),
      sizeof( ClsConceptos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoConceptos.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( conceptos.mobtenerCodigo() != 0 )
         mostrarLineaPantallaConcepto(conceptos);

      // leer siguiente registro del archivo de registros
      leerDeArchivoConceptos.read( reinterpret_cast< char * >( &conceptos ),
         sizeof( ClsConceptos ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

void ClsConceptos::mostrarLineaPantallaConcepto( const ClsConceptos &registroConceptos )
{
   cout << left << setw( 15) << registroConceptos.mobtenerBonoDescuento()
          << setw( 15 ) << registroConceptos.mobtenerCodigo()
          << setw( 20 ) << registroConceptos.mobtenerNombreEmpleado().data()
          << setw( 20 ) << registroConceptos.mobtenerConcepto().data()
          << setw( 20 ) << registroConceptos.mobtenerCantidadPorcentaje()
          <<               registroConceptos.mobtenerPorcentaje()<<endl;

}

////////////////////////////////////////////MODIFICAR/ACTUALIZAR CONCEPTO
void ClsConceptos::mostrarLineaConcepto( ostream &salidaConcepto, const ClsConceptos &registroConcepto )
{
   salidaConcepto << left << setw( 9 ) << registroConcepto.mobtenerCodigo()
          << setw( 20 ) << registroConcepto.mobtenerNombreEmpleado().data()
          << setw( 20 ) << registroConcepto.mobtenerConcepto().data()
          << registroConcepto.mobtenerPorcentaje()<< endl;

}

void ClsConceptos::actualizarRegistroConcepto( fstream &actualizarArchivoConcepto )
{
   // obtener el número de cuenta a actualizar
   int numeroConcepto = mobtenerIndicador( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivoConcepto.seekg(
      ( numeroConcepto - 1 ) * sizeof( ClsConceptos ) );

   // leer el primer registro del archivo
   ClsConceptos conceptos;
   actualizarArchivoConcepto.read( reinterpret_cast< char * >( &conceptos ),
      sizeof( ClsConceptos ) );

   // actualizar el registro
   if ( conceptos.mobtenerCodigo() != 0 ) {
      mostrarLineaConcepto( cout, conceptos );

      // solicitar al usuario que especifique la transacción
      cout << "Escriba el nombre: ";
      char m_sEmpleado [ 20 ];
      cin >> m_sEmpleado;

      cout << "Escriba el Concepto: ";
      char m_sConcepto [ 20 ];
      cin >> m_sConcepto;

      cout << "Escriba el Porcentaje: ";
      float m_sPorcentaje;
      cin >> m_sPorcentaje;

      // actualizar el saldo del registro
      conceptos.mestablecerNombreEmpleado( m_sEmpleado );
      mostrarLineaConcepto( cout, conceptos );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivoConcepto.seekp(
         ( numeroConcepto - 1 ) * sizeof( ClsConceptos ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivoConcepto.write(
         reinterpret_cast< const char * >( &conceptos ),
         sizeof( ClsConceptos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << numeroConcepto
         << " no tiene informacion." << endl;

}

////////////////////////////////////////////IMPRIMIR REGISTRO
void ClsConceptos::imprimirRegistroConcepto( fstream &leerDeArchivoConceptos )
{
   // crear archivo de texto
   ofstream archivoImprimirSalidaConceptos( "ImprimirRegistroConceptos.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalidaConceptos ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if
   else{
    cout<<"Se creo el archivo Departamentos"<<endl;
   }

   archivoImprimirSalidaConceptos << left << setw( 9 ) << "Codigo" << setw( 20 )
       << "Nombre: " << setw( 20 ) << "Concepto:" << setw( 20 ) << "Porcentaje:" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoConceptos.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsConceptos conceptos;
   leerDeArchivoConceptos.read( reinterpret_cast< char * >( &conceptos ),
      sizeof( ClsConceptos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoConceptos.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( conceptos.mobtenerCodigo() != 0 )
         mostrarLineaConcepto( archivoImprimirSalidaConceptos, conceptos );

      // leer siguiente registro del archivo de registros
      leerDeArchivoConceptos.read( reinterpret_cast< char * >( &conceptos ),
         sizeof( ClsConceptos ) );

   } // fin de instrucción while

}

////////////////////////////////////////////BORRAR/ELIMINAR
void ClsConceptos::eliminarRegistroConcepto( fstream &eliminarDeArchivoConcepto )
{
   // obtener número de cuenta a eliminar
   int numeroConcepto= mobtenerIndicador( "Escriba la cuenta a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivoConcepto.seekg(
      ( numeroConcepto - 1 ) * sizeof( ClsConceptos ) );

   // leer el registro del archivo
   ClsConceptos conceptos;
   eliminarDeArchivoConcepto.read( reinterpret_cast< char * >( &conceptos ),
      sizeof( ClsConceptos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( conceptos.mobtenerCodigo() != 0 ) {
      ClsConceptos conceptoEnBlancoDepartamento;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivoConcepto.seekp( ( numeroConcepto - 1 ) *
         sizeof( ClsConceptos ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivoConcepto.write(
         reinterpret_cast< const char * >( &conceptoEnBlancoDepartamento ),
         sizeof( ClsConceptos ) );

      cout << "Empleado clave #" << numeroConcepto << " eliminado correctamente.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
   {
       cerr << "Empleado clave #" << numeroConcepto << " esta vacia.\n";
   }
   getch();

}

////////////////////////////////////////////BUSCAR CONCEPTO
void ClsConceptos::buscarEmpleadoConcepto( fstream &leerDeArchivoConcepto)
{

   // obtener el número de cuenta a buscar
   int numeroConcepto = mobtenerIndicador( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   leerDeArchivoConcepto.seekg(
      ( numeroConcepto - 1 ) * sizeof( ClsConceptos ) );

   // leer el primer registro del archivo
   ClsConceptos conceptos;
   leerDeArchivoConcepto.read( reinterpret_cast< char * >( &conceptos ),
      sizeof( ClsConceptos ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( conceptos.mobtenerCodigo() != 0 ) {
      mostrarLineaConcepto( cout, conceptos );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "La cuenta #" << numeroConcepto
         << " no tiene informacion." << endl;
   }
   getch();

}

////////////////////////////////////////////PARA MENU
ClsConceptos::mcrearConceptos()
{
    ofstream archivoConceptos("RegistrosConceptos.dat", ios::out | ios::binary);
    if(!archivoConceptos)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    ClsConceptos conceptosEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoConceptos.write(reinterpret_cast<const char * > (&conceptosEnBlanco), sizeof(ClsConceptos));
    }
}

ClsConceptos::mmenuConceptos()
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

    int iseleccionMenuConceptos;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoConceptos("RegistrosConceptos.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoConceptos )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearConceptos();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|  SISTEMA GESTION CONCEPTOS  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Concepto"<<endl;
        cout<<"2. Despliegue Conceptos"<<endl;
        cout<<"3. Modifica Concepto"<<endl;
        cout<<"4. Imprimir Regisro de Conceptos"<<endl;
        cout<<"5. Borra Concepto"<<endl;
        cout<<"6. Buscar Concepto"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuConceptos;
        switch(iseleccionMenuConceptos)
        {
        case 1:
            {
                accion = "Ingreso a Agre. Concepto";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                nuevoConcepto(archivoConceptos);
                getch();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Cons. Concepto";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                consultarRegistroConcepto(archivoConceptos);
                getch();
            }
            break;
        case 3:
            {
                accion = "Ingreso a Mod. Concepto";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                actualizarRegistroConcepto(archivoConceptos);
                getch();
            }
            break;
        case 4:
            {
                accion = "Ingreso a Impri. Concepto";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                imprimirRegistroConcepto(archivoConceptos);
                getch();
            }
            break;
        case 5:
            {
                accion = "Ingreso a Elim. Concepto";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                eliminarRegistroConcepto(archivoConceptos);
                getch();
            }
            break;
        case 6:
            {
                accion = "Ingreso a Buscar Concepto";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                buscarEmpleadoConcepto(archivoConceptos);
                getch();
            }
            break;
        case 0:
            {
                accion = "Salio de Gestion Concepto";

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
    }while(iseleccionMenuConceptos!=0);
}

ClsConceptos::~ClsConceptos()
{
    //dtor
}
