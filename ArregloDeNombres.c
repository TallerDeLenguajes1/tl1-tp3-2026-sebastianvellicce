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

void BuscarNombre(char *vectorNombres[], int id)
{
    if (id > CANTIDAD_NOMBRES)
    {
        printf("El ID ingresado no es valido.\n");
    }
    else
    {
        printf("El ID ingresado le corresponde a %s\n",vectorNombres[id]);
    }
}

int main()
{
    int i, id;
    char *Buff;
    char *V[CANTIDAD_NOMBRES];

    Buff = (char*)malloc(sizeof(char)*100);

    for(i = 0; i<CANTIDAD_NOMBRES;i++)
    {
        printf("Ingrese el nombre N%d\n",i+1);
        gets(Buff);
        V[i]=(char*)malloc(sizeof(char)*(strlen(Buff)+1));
        strcpy(V[i],Buff);
    }
    MostrarPersonas(V);
    printf("Ingrese un ID\n");
    scanf("%d",&id);
    BuscarNombre(V,id);

    free(Buff);
    for(i = 0; i < CANTIDAD_NOMBRES; i++)
    {
        free(V[i]);
    }
    return 0;
}
