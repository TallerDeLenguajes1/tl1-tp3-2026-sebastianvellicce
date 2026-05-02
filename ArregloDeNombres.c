#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD_NOMBRES 5

void MostrarPersonas(char *V[])
{
    int i;
    printf("----------LOS NOMBRES SON------\n");
    for(i = 0; i < CANTIDAD_NOMBRES; i++)
    {
        printf("%s\n", V[i]);
    }
}

char* BuscarNombre(char *V[],char *palabraBuscada)
{
    char *resultado;
    int i;
    for(i = 0;i<CANTIDAD_NOMBRES;i++)
    {
        resultado = strstr(V[i],palabraBuscada);
        if(resultado)
        {
            return V[i];
        }
    }
    return "-1";
}

int main()
{
    int i;
    char *Buff;
    char *palabraBuscada;
    char *resultado;
    char *V[CANTIDAD_NOMBRES];

    palabraBuscada = (char*)malloc(sizeof(char)*100);
    Buff = (char*)malloc(sizeof(char)*100);

    for(i = 0; i<CANTIDAD_NOMBRES;i++)
    {
        printf("Ingrese el nombre N%d\n",i+1);
        gets(Buff);
        V[i]=(char*)malloc(sizeof(char)*(strlen(Buff)+1));
        strcpy(V[i],Buff);
    }
    MostrarPersonas(V);
    printf("Ingrese la palabra que quiere buscar\n");
    gets(palabraBuscada);


    resultado = BuscarNombre(V,palabraBuscada);
    printf("%s\n", resultado);
    free(Buff);
    for(i = 0; i < CANTIDAD_NOMBRES; i++)
    {
        free(V[i]);
    }
    return 0;
}
