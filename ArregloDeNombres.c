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

void BuscarNombreID(char *vectorNombres[], int id)
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

char* BuscarNombrePalabra(char *V[],char *palabraBuscada)
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
    int i, id, opcion;
    char *Buff;
    char *palabraBuscada;
    char *resultado;
    char *V[CANTIDAD_NOMBRES];

    palabraBuscada = (char*)malloc(sizeof(char)*100);
    Buff = (char*)malloc(sizeof(char)*100);

    for(i = 0; i<CANTIDAD_NOMBRES;i++)
    {
        printf("Ingrese el nombre N%d\n",i+1);
        getchar();
        gets(Buff);
        V[i]=(char*)malloc(sizeof(char)*(strlen(Buff)+1));
        strcpy(V[i],Buff);
    }
    MostrarPersonas(V);

    printf("\n------------------------MENU------------------------\n");
    printf("1-Buscar por ID\n2-Buscar por palabra\n");
    scanf("%d",&opcion);
    if(opcion == 1)
    {
        printf("Ingrese un ID\n");
        scanf("%d",&id);
        BuscarNombreID(V,id);
    }else if(opcion == 2)
    {
        printf("Ingrese la palabra que quiere buscar\n");
        getchar();
        gets(palabraBuscada);
        resultado = BuscarNombrePalabra(V,palabraBuscada);
        printf("%s\n", resultado);
    }else{
        printf("Opcion invalida\n");
    }



    free(Buff);
    for(i = 0; i < CANTIDAD_NOMBRES; i++)
    {
        free(V[i]);
    }
    return 0;
}
