#include "gamemap.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>


using namespace std;
gamemap::gamemap()
{
    playerCell = NULL;
    loadMapFromFile();
    isGameOver = false;
}
//Josue Ernesto Rivas De León 9491-21-3133
void gamemap::draw(){
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << cell [i][j].id;
        }
        cout << endl;
    }
}
//Karla Sofia Gomez Tobar 9959-21-1896
bool gamemap::setPlayerCell(int playerX, int playerY)
{
    if (cell[playerX][playerY].isBlockedCell() == false)
    {
        if (cell[playerX][playerY].id == '$')
        {
            drawVictoria();
            isGameOver = true;
            return true;
        } else
        {
            if (cell[playerX][playerY].id == '#')
            {
            drawTrampa();
            isGameOver = true;
            return true;
            }
            if (cell[playerX][playerY].id == '&')
            {
            drawBromita();
            isGameOver = true;
            return true;
            }
            if (playerCell != NULL)
            {
                playerCell->id=0;
            }
            playerCell = &cell[playerX][playerY];
            playerCell->id=223;
        }


        return true;
    }
    else
    {
        return false;
    }

}
//Josue Ernesto Rivas De León 9491-21-3133
void gamemap::loadMapFromFile()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("map.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0')
                {
                    cell[row][p].id = 0;
                } else
                {
                    cell[row][p].id = line[p];
                }
            }
            row++;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: archivo del mapa no pudo ser cargado" << endl;
        cout << "Desea crearlo? " << endl;
        cin >> userInput;
        if (userInput=' ')
        {
            createMapToFile();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }

}
//Josue Ernesto Rivas De León 9491-21-3133
void gamemap::createMapToFile()
{
    ofstream myFile("map.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 || i == 14)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 9)
                    {
                        myFile << "1";
                    } else
                    {
                        myFile << "0";
                    }
                }

            }
            myFile << endl;
        }
        myFile.close();
    } else
    {
        cout << "Error FATAL: archivo no pudo ser creado" << endl;
    }
}

//Marlon Estuardo Hernandez Giron 9491-21-7312
void gamemap::drawPortada()
{
    string line;
    char userInput = ' ';
    ifstream myFile("portada.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
    }
}
//Alyson Vannesa Rodriguez Quezada 9959-21-829
void gamemap::drawVictoria()
{
    string line;
    char userInput = ' ';
    ifstream myFile("premio.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}
//Angel Roberto Agustin de Leon Hernandez 9491-21-7527
void gamemap::drawBromita()
{
    string line;
    char userInput = ' ';
    ifstream myFile("bromita.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de bromita no pudo ser cargado" << endl;
    }
}
//Karla Sofia Gomez Tobar 9959-21-1896
void gamemap::drawTrampa()
{
    string line;
    char userInput = ' ';
    ifstream myFile("trampa.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de trampa no pudo ser cargado" << endl;
    }
}
 //Alyson Vannesa Rodriguez Quezada 9959-21-829
void gamemap::drawCreditos()
{
    string line;
    char userInput = ' ';
    ifstream myFile("creditos.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de creditos no pudo ser cargado" << endl;
    }
}
//Marlon Estuardo Hernandez Giron 9491-21-7312
void gamemap::drawInstrucciones()
{
    string line;
    char userInput = ' ';
    ifstream myFile("instrucciones.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de instrucciones no pudo ser cargado" << endl;
    }
}

gamemap::~gamemap()
{
    //dtor
}
