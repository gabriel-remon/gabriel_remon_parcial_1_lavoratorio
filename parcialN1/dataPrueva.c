#include <string.h>
#include "dataPrueva.h"
#include "mascota.h"
#include "tipo.h"
#include "color.h"

int hardcodearAnimales(eMascota mas[],int tamMas,int cant)
{
    char nombres[20][20] =
    {
        "Juan",
        "Pedro",
        "Sofia",
        "Miguel",
        "Valentina",
        "Camila",
        "Andrea",
        "Luis",
        "Diego",
        "Analia",
    };

    int idTipo[12]= {1000,1000,1001,1003,1004,1002,1004,1001,1001,1000,1002,1000,};
    int idColor[12]= {5000,5000,5001,5003,5004,5002,5004,5001,5001,5000,5002,5000,};
    char vacunas[12]= {'S','N','S','S','N','S','S','N','S','S','N','S',};


    int edades[10] = {23,21,28,34,35,34,23,28,30,31};


    int contador = -1;
    if (mas != NULL && tamMas > 0 && cant>0 && cant<=10 )
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            mas[i].isEmpty=0;
            mas[i].id=contador;
            mas[i].idColor=idColor[i];
            mas[i].idTipo=idTipo[i];
            mas[i].edad=edades[i];
            mas[i].vacunas=vacunas[i];
            strcpy(mas[i].nombreMascota,nombres[i]);
            contador++;
        }
    }
    return contador;
}



