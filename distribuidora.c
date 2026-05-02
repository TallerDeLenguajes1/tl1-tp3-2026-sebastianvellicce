#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
}typedef Producto;

struct {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}typedef Cliente;

float calcularCostoProducto(Producto *producto)
{
    return(producto->PrecioUnitario*producto->Cantidad);    
}



int main()
{
    char *TipoProductos[] = {"Galletas","Snacks", "Cigarrillos", "Caramelos", "Bebidas"};
    char *Buff;
    int cantidadClientes,i,j,tipoRand;
    Cliente *clientes;
    srand(time(NULL));
    
    printf("Ingrese la cantidad de clientes.\n");
    scanf("%d",&cantidadClientes);
    clientes = (Cliente*)malloc(sizeof(Cliente)*cantidadClientes);
    Buff= (char*)malloc(sizeof(char)*100);

    for(i = 0; i<cantidadClientes; i++)
    {
        printf("Ingrese el cliente N%d\n",i+1);
        clientes[i].ClienteID = i;
        printf("Ingrese el nombre de su cliente\n");
        getchar();
        gets(Buff);
        clientes[i].NombreCliente= (char*)malloc(sizeof(char)*(Buff+1));
        strcpy(clientes[i].NombreCliente,Buff);
        clientes[i].CantidadProductosAPedir = 1 + rand()%4;
        clientes[i].Productos = (Producto*) malloc(sizeof(Producto)* clientes[i].CantidadProductosAPedir);
        
        for(j = 0; j< clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j;
            clientes[i].Productos[j].Cantidad= 1 + rand()%10;
            tipoRand = 1 + rand()%5;
            clientes[i].Productos[j].TipoProducto = TipoProductos[tipoRand];
            clientes[i].Productos[j].PrecioUnitario = 10 + rand()%91;
            calcularCostoProducto(&clientes[i].Productos[j]); 
        }
    }
    





    for(i = 0; i < cantidadClientes; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);
    free(Buff);
    
    return 0;
}