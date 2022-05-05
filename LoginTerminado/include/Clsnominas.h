#ifndef CLSNOMINAS_H
#define CLSNOMINAS_H


class Clsnominas
{
    public:
        Clsnominas( int = 0, string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "" );
        void mstablecerNomina ( int ) ;
        int mobtenerNomina() const;

        void mestablecerNombreEmpleado( string );
        string mobtenerNombreEmpleado() const;

        void mestablecerCargo ( string );
        string mobtenerCargo() const;

        void mestablecerDevengado( string );
        string mobtenerDevengado() const;

        void mestablecerComisiones ( string );
        string mobtenerComisiones() const;

        void mestablecerIGGS( string );
        string mobtenerIGGS() const;

        void mestablecerISR ( string );
        string mobtenerISR() const;

        void mestablecerAnticipos( string );
        string mobtenerAnticipos() const;

        void mestablecerTotalDescuentos ( string );
        string mobtenerTotalDescuentos() const;

        void mestablecerBono( string );
        string mobtenerBono() const;

        void mestablecerTotalLiquido ( string );
        string mobtenerTotalLiquido() const;

        virtual ~Clsnominas();

    protected:

    private:
        int m_inomina;
        char m_cnombreEmpleado[20];
        char m_scargo[20];
        char m_sdevengado[20];
        char m_dcomisiones[20];
        char m_siggs[20];
        char m_sisr[20];
        char m_santicipos[20];
        char m_stotalDescuentos[20];
        char m_sbono[20];
        char m_stotalLiquido[20];
};

#endif // CLSNOMINAS_H
