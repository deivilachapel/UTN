#include<iostream>
#include<cstdlib>
#include <string.h>
using namespace std;
#include "menu.h"
#include "resolver.h"

void jugar1(char *nombre,int *punto)
{
    const int t1=5, t2=10, t3=25;
    int dados[t1];
    bool jugadas[t2];//las 10 jugadas posibles
    enVerdadero(jugadas, t2);//jugadas en true
    char nombre1 [t3];
    int puntos=0;
    int turnos=0;
    cout<< "Indicar  su Nombre \t";
    cin>> nombre1;
    cout<<endl<<"Cantidad de turnos que desea jugar \t";
    cin>>turnos;
    system("cls");
    int x;
    for(x=0; x<turnos; x++)
    {
        cout<<endl<<"\t jugador "<<nombre1<<endl;
        cout<<"\t Ronda "<<x+1<<" "<<endl;
        tirarDados(dados, t1);
        mostrarDados(dados, t1);
        cambiarDados(dados, t1);
        puntos+=sumarPuntos(dados, t1, jugadas, t2);
        cout<<endl<<"\t Sus puntos son "<<puntos<<endl<<endl;
        if (x==0 && puntos==50)
        {
            x=turnos;//generala ronda 1, gano
        }
        system("pause");
        system("cls");
    }
    cout<<endl<<"\t Fin del juego "<<endl;
    cout<<endl<<"\t Sus puntos son de "<<puntos<<endl<<endl;

    system("pause");
    system("cls");
//maxima puntuacion
    if(puntos>*punto)
    {
        strncpy(nombre, nombre1, 25);
        *punto=puntos;
    }
}

void jugar2(char nombre [],int *punto)
{
    const int t1=5, t2=10, t3=25;
    int dados[t1];
    bool jugador1 [t2], jugador2 [t2];//las 10 jugadas posibles del jugador 1 y 2
    enVerdadero(jugador1, t2);
    enVerdadero(jugador2, t2);
    char nombre1 [t3], nombre2 [t3];
    int puntos1=0, puntos2=0;
    cout<< "Indique Nombre del jugador 1 \t";
    cin>> nombre1;
    cout<<endl<< "Indique Nombre del jugador 2 \t";
    cin>> nombre2;
    system("cls");
    int x;
    for(x=0; x<10; x++)
    {
        cout<<endl<<"\t jugador "<<nombre1<<endl;
        cout<<"\t ronda "<<x+1<<" "<<endl;
        tirarDados(dados, t1);
        mostrarDados(dados, t1);
        cambiarDados(dados, t1);
        puntos1+=sumarPuntos(dados, t1, jugador1, t2);
        cout<<endl<<"\t sus puntos son "<<puntos1<<endl<<endl;
        if (x==0 && puntos1==50)
        {
            x=10;//generala ronda 1, gano jugador 1
        }
        system("pause");
        system("cls");
        cout<<endl<<"\t jugador "<<nombre2<<endl;
        cout<<"\t Ronda "<<x+1<<" "<<endl;
        tirarDados(dados, t1);
        mostrarDados(dados, t1);
        cambiarDados(dados, t1);
        puntos2+=sumarPuntos(dados, t1, jugador2, t2);
        cout<<endl<<"\t Sus puntos son "<<puntos2<<endl<<endl;
        if (x==0 && puntos2==50)
        {
            x=10;//generala ronda 1, gano jugador 2
        }
        system("pause");
        system("cls");
    }
    *punto=ganar(nombre1,nombre2, puntos1, puntos2, punto, nombre);//jugador con maxima puntucion y ganador
    system("pause");
    system("cls");
}

int menu_principal()
{
     system("cls");
    cout<<endl<<endl;
    cout <<"\t\t==============================================================================="<< endl;
    cout <<"\t\t=                                Bienvenidos                                  ="<< endl;
    cout <<"\t\t=                           Juego de Dados Generala                           ="<< endl;
    cout <<"\t\t==============================================================================="<< endl<<endl<<endl;
    cout<<"\t Seleccione  la opcion correcta: \t"<<endl;
    int opcion1;
    cout<<endl<< "\t 1- jugar";
    cout<<endl<< "\t 2- Reglas";
    cout<<endl<< "\t 3- Maxima Puntuacion";
    cout<<endl<< "\t 4- Salir"<<endl<<"\t\t\t"<<endl;

    cout<<"\t Opcion: ";
    cin>>opcion1;

    return opcion1;
}

void reglas()
{
    system("cls");
    cout <<"\t\t Reglas"<<endl<<endl;
    cout <<"Cada jugador cuenta con 5 dados"<<endl;
    cout<<"usted tendra 2 oportunidades de cambiar cualquiera de los 5 dados"<<endl;
    cout<<"tiene que formar las siguientes jugadas con sus respectivos puntajes:"<<endl<<endl;
    cout<<"juego de 1"<<endl;
    cout<<"1 x numero de dados iguales a 1"<<endl<<endl;
    cout<<"juego de 2"<<endl;
    cout<<"2 x numero de dados iguales a 2"<<endl<<endl;
    cout<<"juego de 3"<<endl;
    cout<<"3 x numero de dados iguales a 3"<<endl<<endl;
    cout<<"juego de 4"<<endl;
    cout<<"4 x numero de dados iguales a 4"<<endl<<endl;
    cout<<"juego de 5"<<endl;
    cout<<"5 x numero de dados iguales a 5"<<endl<<endl;
    cout<<"juego de 6"<<endl;
    cout<<"6 x numero de dados iguales a 6"<<endl<<endl;
    cout<<"escalera"<<endl;
    cout<<"son 5 dados uno menor que el otro o uno mayor que el otro= 25 puntos"<<endl<<endl;
    cout<<"full"<<endl;
    cout<<"un valor se repeti 2 veces y otro valor se repite 3 veces= 30 puntos"<<endl<<endl;
    cout<<"poker"<<endl;
    cout<<"un valor se repeti 4 veces= 40 puntos"<<endl<<endl;
    cout<<"generala"<<endl;
    cout<<"un valor se repeti 5 veces= 50 puntos"<<endl<<endl;
    cout<<"para 2 jugadores son 10 rondas y gana el de mayor puntaje"<<endl;
    cout<<"en el formato de 1 jugador, no tiene rondas, ni ganador"<<endl;
    cout<<"si el jugador consigue generala en la primera jugada automaticamente se transforma en ganador"<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}
