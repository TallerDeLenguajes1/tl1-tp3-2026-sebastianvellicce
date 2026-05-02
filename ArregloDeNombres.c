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

int main()
{
    int i;
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
    free(Buff);
    for(i = 0; i < CANTIDAD_NOMBRES; i++)
    {
        free(V[i]);
    }
    return 0;
}
