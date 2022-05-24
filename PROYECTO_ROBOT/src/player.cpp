#include "player.h"
#include <iostream>
#include <fstream>

using namespace std;

//Angel Roberto Agustin de Leon Hernandez 9491-21-7527
player::player()
{
    //ctor
    x = 1;
    y = 1;
    lastX = 1;
    lastY = 1;
}

//Angel Roberto Agustin de Leon Hernandez 9491-21-7527
player::~player()
{
    //dtor
    //
}
int player::getValueX(){
    return x;
}
int player::getValueY(){
    return y;
}
void player::setValueX(int valueX){
    x = valueX;
}
void player::setValueY(int valueY){
    y = valueY;
}

//Karla Sofia Gomez Tobar 9959-21-1896
void player::callInput()
{
    char userInput = ' ';
    cin >> userInput;
    switch(userInput)
    {
    case 'a':
        lastY = y;
        y = y - 1;
        break;
    case 'd':
        lastY = y;
        y = y + 1;
        break;
    case 's':
        lastX = x;
        x = x + 1;
        break;
    case 'w':
        lastX = x;
        x = x - 1;
        break;
    case 'x':
        cout << " -- Juego Terminado -- :(" << endl << endl;
        drawCreditos();
        cout << endl;
        exit(0);
    }
}
void player::resetToSafePosition()
{
    x = lastX;
    y = lastY;
}

//Marlon Estuardo Hernandez Giron 9491-21-7312
void player::drawCreditos()
{
    string line;
    char userInput = ' ';
    ifstream myFile("creditos.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
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

