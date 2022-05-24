#include "mapcell.h"
#include <iostream>

using namespace std;

mapcell::mapcell()
{

    id = 0;

}
//Josue Ernesto Rivas De León 9491-21-3133
bool mapcell::isBlockedCell()
{
    if( id == '1')
    {
        return true;
    } else
    {
        return false;
    }
}
mapcell::~mapcell()
{
    //dtor
}
