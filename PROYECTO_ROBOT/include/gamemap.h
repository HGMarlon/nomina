#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "mapcell.h"

class gamemap
{
    public:
        gamemap();
        mapcell* playerCell;//Josue Ernesto Rivas De León 9491-21-3133
        mapcell cell [15][10];//Josue Ernesto Rivas De León 9491-21-3133
        void draw();
        bool setPlayerCell(int playerX, int playerY);
        void drawPortada(); //Marlon Estuardo Hernandez Giron 9491-21-7312
        void drawVictoria(); //Alyson Vannesa Rodriguez Quezada 9959-21-829
        void drawTrampa(); // Karla Sofia Gomez Tobar 9959-21-1896
        void drawBromita(); //Angel Roberto Agustin de Leon Hernandez 9491-21-7527
        void drawInstrucciones();//Marlon Estuardo Hernandez Giron 9491-21-7312
        void drawCreditos(); //Josue Ernesto Rivas De León 9491-21-3133
        virtual ~gamemap();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile();
        void createMapToFile();
};

#endif // GAMEMAP_H
