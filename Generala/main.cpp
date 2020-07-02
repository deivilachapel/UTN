#include <iostream>
#include <stdlib.h>
using namespace std;
#include "menu.h"
#include "resolver.h"
#include "rlutil.h"
using namespace rlutil;

int main()
{
setBackgroundColor(RED);
setColor(WHITE);
    bool si_no=false;// si no jugo no pude ver la opcion 3
    int punto=0;//puntos del maximo jugador
    const int t=25;
    char nombre[t];//nombre del maximo jugador
    bool salir=true;
    while (salir==true)
    {
        salir = switch_jugadores(menu_principal(), &si_no, nombre, &punto);//funcion que llama argumentos

        system("cls");
    }
    return 0;
}
