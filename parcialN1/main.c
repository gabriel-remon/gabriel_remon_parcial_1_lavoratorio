#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicios.h"
#include "trabajo.h"

#define TAM_TIP 5
#define TAM_COL 5
#define TAM_MAS 300
#define TAM_SER 3
#define TAM_TRA 1000

int main()
{
    eTipo tipoAnimal[TAM_TIP]=
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Roedor"},
        {1003, "Gato"},
        {1004, "Pez"},
    };
    eColor color[TAM_COL]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"},
    };
    eServicio servicion[TAM_SER]=
    {
        {20000, "Corte",450},
        {20001, "Desparacitado",800},
        {20002, "Catrado",600},
    };

    eMascota mascotas[TAM_MAS];
    eTrabajo trabajos[TAM_TRA];

    char salir='n';
    int nextId=2000;

    initMascotas(mascotas,TAM_MAS);
    initTrabajo(trabajos,TAM_TRA);
    //hardcodearAnimales(mascotas,TAM_MAS,10); //desabilitar paa probar
    do
    {
        switch(menu())
        {
        case 'A':
            altaMascota(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP);
            break;

        case 'B':
            modificarMascota(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP);
            break;

        case 'C':
            bajaMascota(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP);
            break;

        case 'D':
                utn_clear();
            if(espacioLibreMascota(mascotas,TAM_MAS)>=0)
            {
                ordenarMascotas(mascotas,TAM_MAS);
                mostrarMascotas(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP);
            }
            else
            {

                printf("Primero deve cargar una mascota");
            }
            break;

        case 'E':
            utn_clear();
            mostrarTipo(tipoAnimal,TAM_TIP);
            break;

        case 'F':
            utn_clear();
            mostrarColor(color,TAM_COL);
            break;

        case 'G':
            utn_clear();
            mostrarServicio(servicion,TAM_SER);
            break;
        case 'H':
            altaTrabajo(trabajos,TAM_TRA,servicion,TAM_SER,mascotas,TAM_MAS,&nextId,color,TAM_COL,tipoAnimal,TAM_TIP);
            break;
        case 'I':
                utn_clear();
            if(espacioLibreTrabajo(trabajos,TAM_TRA)>=0)
            {
                mostrarTrabajo(trabajos,TAM_TRA,servicion,TAM_SER,mascotas,TAM_MAS);
            }
            else
            {
                printf("Primero deve cargar un trabajo");
            }
            break;
        case 'j':
            utn_getCharDos(&salir,"desea salir?(y/n) ", "Error ingrese 'n' o 'y'\n",'n','y');
            break;
        default:
            printf("Error, ingrese un caracter valido");

            break;

        }
        utn_stop();
        utn_clear();
    }
    while(salir=='n');

    return 0;
}
