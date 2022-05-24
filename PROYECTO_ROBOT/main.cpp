#include <iostream>
#include <windows.h>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"

using namespace std;

int main()
{
    //Marlon Estuardo Hernández Girón 9491-21-7312
    //char cancion[]="C:\music.wav";
    //cout<<PlaySound((LCPCSTR)cancion, NULL , SND_FILENAME);
    //-static-libgcc -lwimm
    int op;
    gamemap map;
    player hero;
    map.drawPortada();
    //map.draw();
    //Marlon Estuardo Hernández Girón 9491-21-7312
    cout<<"-------------------------------"<<endl;
    cout<<"|             MENU            |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"1.INICIAR JUEGO"<<endl;
    cout<<"2.INSTRUCCIONES"<<endl;
    cout<<"3.CREDITOS"<<endl;
    cout<<"4.SALIR"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"OPCION A ESCOGER:[1/2/3]"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"INGRESA TU OPCION:"<<endl;
    cin>>op;
    switch(op){
        case 1:
            {
        while(map.isGameOver==false)
    {
    cout<<"-------------------------------"<<endl; //Marlon Estuardo Hernández Girón 9491-21-7312
    cout<<"|           CONTROLES         |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"w=ARRIBA, s=ABAJO, a=IZQUIERDA, d=DERECHA"<<endl;
    cout<<"PRESIONE CUALQUIER TECLA PARA COMENZAR"<<endl;
      hero.callInput();
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
        map.draw();
      } else
      {
        hero.resetToSafePosition();
        map.draw();
      }
    }
        }
        break;

        case 2:
            {
                system("cls");
               map.drawInstrucciones();//Marlon Estuardo Hernández Girón 9491-21-7312
            }
            break;
            case 3:
            {
                  system("cls");//Josue Ernesto Rivas De León 9491-21-3133
               map.drawCreditos();
               break;
            }
             case 4:
                 {
                 }
                 break;
    }
    return 0;
}
