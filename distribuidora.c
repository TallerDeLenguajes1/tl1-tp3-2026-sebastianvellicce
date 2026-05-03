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
void MostrarClientes(Cliente *clientes, int cantidadClientes)
{
    int i, j;
    float totalCliente;

    for(i = 0; i < cantidadClientes; i++)
    {
        totalCliente = 0;
        printf("\n--- Cliente %d ---\n", clientes[i].ClienteID + 1);
        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);

        for(j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\n  Producto %d:\n", clientes[i].Productos[j].ProductoID + 1);
            printf("  Tipo: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("  Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("  Precio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("  Costo: %.2f\n", calcularCostoProducto(&clientes[i].Productos[j]));
            totalCliente += calcularCostoProducto(&clientes[i].Productos[j]);
        }
        printf("\nTotal a pagar: %.2f\n", totalCliente);
    }
}



int main()
{
    char *TipoProductos[] = {"Galletas","Snacks", "Cigarrillos", "Caramelos", "Bebidas"};
    char *Buff;
    int cantidadClientes,i,j,tipoRand;
    float costo, costoFinal=0;
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
        clientes[i].NombreCliente= (char*)malloc(sizeof(char) * (strlen(Buff)+1));
        strcpy(clientes[i].NombreCliente,Buff);
        clientes[i].CantidadProductosAPedir = 1 + rand()%4;
        clientes[i].Productos = (Producto*) malloc(sizeof(Producto)* clientes[i].CantidadProductosAPedir);
        
        for(j = 0; j< clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j;
            clientes[i].Productos[j].Cantidad= 1 + rand()%10;
            tipoRand =  rand()%5;
            clientes[i].Productos[j].TipoProducto = TipoProductos[tipoRand];
            clientes[i].Productos[j].PrecioUnitario = 10 + rand()%91;
            costo = calcularCostoProducto(&clientes[i].Productos[j]);
            costoFinal = costoFinal + costo; 
        }
    }
    
    MostrarClientes(clientes, cantidadClientes);




    for(i = 0; i < cantidadClientes; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);
    free(Buff);
    
    return 0;
}