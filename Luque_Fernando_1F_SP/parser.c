#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Computer.h"

int parserText(LinkedList* listaComputer,FILE* pFile)
{



    eComputer* computer;

    //FILE* pFile;

    char descripcion[4096];
    char precio[4096];
    char id[4096];
    char idTipo[4096];
    int r;
    int returnAux=0;


    if(pFile!=NULL && listaComputer!=NULL)
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",id,descripcion,precio,idTipo);

        do
        {


            r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);

            if(r==4)
            {


                computer=computer_newParametros(id,descripcion,precio,idTipo);

                if(computer!=NULL)
                {
                    ll_add(listaComputer,computer);
                    returnAux=1;

                }
            }
            else
                break;

        }
        while(!feof(pFile));


    }


    return returnAux;

}

int controller_loadFromText(LinkedList* listaComputers, char* fileName)
{
    int retorno=0;
    FILE* pFile;


    pFile=fopen(fileName,"r");

    if(pFile!=NULL)
    {
        retorno=parserText(listaComputers,pFile);
    }

    fclose(pFile);

    return retorno;

}


int saveAsText(LinkedList* listaComputers)
{
    int returnAux=-1;
    int id;
    char descripcion[256];
    float precio;
    int idtipo;
    int i;

    eComputer* computer=NULL;

    FILE* pFile;

    pFile=fopen("filtrado.csv","w");

    if(pFile!=NULL && listaComputers!=NULL)
    {
        fprintf(pFile,"%s,%s,%s,%s\n\n","id","descripcion","precio","idtipo");

        for(i=0;i<ll_len(listaComputers);i++)
        {
            computer=ll_get(listaComputers,i);

            if(computer!=NULL)
            {
                computer_getId(computer,&id);
                computer_getDescripcion(computer,descripcion);
                computer_getPrecio(computer,&precio);
                computer_getTipo(computer,&idtipo);


                fprintf(pFile,"%d,%s,%.2f,%d\n",id,descripcion,precio,idtipo);
            }
        }
       returnAux=0;
    }

    fclose(pFile);

    return returnAux;




}

