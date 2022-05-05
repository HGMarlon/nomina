#include "Clsnominas.h"

Clsnominas::Clsnominas( int ivalorNomina, string svalorNombreEmpleado, string svalorEncargo, string svalorDevengado, string svalorComisiones,
string svalorIGGS, string svalorISR, string svalorAnticipos, string svalorDescuentos,string svalorBono, string svalorTotalLiquido )
{
    //ctor
    mstablecerNomina ( ivalorNomina ) ;
    mestablecerNombreEmpleado( svalorNombreEmpleado );
    mestablecerCargo ( svalorEncargo );
    mestablecerDevengado( svalorDevengado );
    mestablecerComisiones ( svalorComisiones );
    mestablecerIGGS( svalorIGGS );
    mestablecerISR ( svalorISR );
    mestablecerAnticipos( svalorAnticipos );
    mestablecerTotalDescuentos ( svalorDescuentos );
    mestablecerBono( svalorBono );
    mestablecerTotalLiquido ( svalorTotalLiquido );
}

int Clsnominas::mobtenerNomina() const
{
    return m_inomina;
}

void Clsnominas::mestablecerNumero (int ivalorNomina)
{
    m_inomina = ivalorNomina;
}
//1
string ClsPuestos::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerNombreEmpleado( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//2
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerCargo( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//3
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerDevengado( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//4
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerComisiones( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//5
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerIGGS( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//6
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerISR( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//7
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}

void Clsnominas::mestablecerAnticipos( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//8
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerTotalDescuentos( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//9
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerNombreP( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}
//10
string Clsnominas::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void Clsnominas::mestablecerNombreP( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}

Clsnominas::~Clsnominas()
{
    //dtor
}
