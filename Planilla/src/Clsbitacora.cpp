#include "Clsbitacora.h"

Clsbitacora::Clsbitacora(int valorCodigo)
{
    mestablecerCodigo(valorCodigo);
}

Clsbitacora::mcrearBitacora()
{
    ofstream archivoBitacora("bitacora.dat", ios::out | ios::binary);
    if(!archivoBitacora)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    Clsbitacora bitacoraEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoBitacora.write(reinterpret_cast<const char * > (&bitacoraEnBlanco), sizeof(Clsbitacora));
    }
}
//Funciones de la clave del empleado
int Clsbitacora::mobtenerCodigo() const
{
    return m_icodigo;
}

void Clsbitacora::mestablecerCodigo (int icodigo)
{
    m_icodigo = icodigo;
}

void Clsbitacora::mnuevaBitacora(fstream &archivoBitacora)
{
   Clsbitacora bitacora;
   int m_iNumeroCuenta = mobtenerIndicadorBancos( "Escriba el numero de cuenta del banco" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoBancos.seekg(
      ( m_iNumeroCuenta - 1 ) * sizeof( ClsBancos ) );

   // leer el registro del archivo
   archivoBancos.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // crear el registro, si éste no existe ya
   if ( banco.mobtenerClaveBancos() == 0 ) {

      char m_sNombreBanco[ 20 ];
      char m_sNombreUsuario[20];
      char m_iSaldoCuenta[20];
      char m_iTipoCuenta[20];

      // el usuario introduce el nombre
      cout << "Escriba el nombre del Banco: " << endl;
      cin >> setw( 20 ) >> m_sNombreBanco;
      cout << "Escriba el nombre del Usuario: " << endl;
      cin >> setw( 20 ) >> m_sNombreUsuario;
      cout << "Escriba el saldo de la Cuenta: " << endl;
      cin >> setw( 20 ) >> m_iSaldoCuenta;
      cout << "Escriba el Tipo de la Cuenta: " << endl;
      cin >> setw( 20 ) >> m_iTipoCuenta;

      // usar valores para llenar los valores de la clave
      banco.mestablecerNombreBancos( m_sNombreBanco );
      banco.mestablecerClaveBancos( m_iNumeroCuenta );
      banco.mestablecerNombreUsuarioBancos( m_sNombreUsuario );
      banco.mestablecerSaldoCuentaBancos( m_iSaldoCuenta );
      banco.mestablecerTipoCuentaBancos( m_iTipoCuenta );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoBancos.seekp( ( m_iNumeroCuenta - 1 ) *
         sizeof( ClsBancos ) );

      // insertar el registro en el archivo
      archivoBancos.write(
         reinterpret_cast< const char * >( &banco ),
         sizeof( ClsBancos ) );

        cout << "Banco agregado con exito.";

   }

   // mostrar error si la cuenta ya existe
   else
   {
       cerr << "La cuenta #" << m_iNumeroCuenta << " ya contiene informacion." << endl;
       getch();
   }
}
