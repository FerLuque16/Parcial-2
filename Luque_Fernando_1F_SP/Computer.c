#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Computer.h"

eComputer* computer_new()
    {
        eComputer *this;

        this=malloc(sizeof (eComputer));

		return this;
    }

eComputer* computer_newParametros(char* idStr,char* descStr,char* precioStr,char* idTipoStr)

    {
        eComputer *computer=NULL;
		int id;
		float precio;
		int idTipo;

		id=atoi(idStr);
		precio=atof(precioStr);
		idTipo=atoi(idTipoStr);


		computer=computer_new();

		computer_setId(computer,id);
		computer_setDescripcion(computer,descStr);
		computer_setPrecio(computer,precio);
		computer_setTipo(computer,idTipo);



		return computer;
    }

void computer_delete(eComputer* this)
{
        if(this!=NULL)
        {
            free(this);
        }



}


int computer_setId(eComputer* this,int id)
    {
        int retorno=-1;
        if(this!=NULL && id>0)
            {
                this->id=id;
                retorno=0;

            }

        return retorno;
    }

int computer_getId(eComputer* this,int* id)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                *id=this->id;
                retorno=0;
            }

        return retorno;
    }

int computer_setDescripcion(eComputer* this,char* desc)
    {
        int retorno=-1;

        if(this!=NULL )
            {
                strcpy(this->descripcion,desc);
                retorno=0;

            }
        return retorno;
    }

int computer_getDescripcion(eComputer* this,char* desc)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                strcpy(desc,this->descripcion);
                retorno=0;
            }

        return retorno;
    }


int computer_setPrecio(eComputer* this,float precio)
    {
        int retorno=-1;
        if(this!=NULL && precio>0)
            {
                this->precio=precio;
                retorno=0;

            }

        return retorno;
    }

int computer_getPrecio(eComputer* this,float* precio)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                *precio=this->precio;
                retorno=0;
            }

        return retorno;
    }

 int computer_setTipo(eComputer* this, int tipo)
     {
         int retorno=-1;

         if(this!=NULL && tipo>0)
         {
             this->idTipo=tipo;
             retorno=0;
         }

        return retorno;
     }

int computer_getTipo(eComputer* this, int *tipo)
     {
         int retorno=-1;

         if(this!=NULL)
         {
             *tipo=this->idTipo;
             retorno=0;
         }

        return retorno;
     }




int computer_compareId(void* arg1, void* arg2)
{
    int retorno=-1;
    eComputer* comp1;
    eComputer* comp2;

    comp1=(eComputer*) arg1;
    comp2=(eComputer*) arg2;

    if(comp1->id>comp2->id)
    {
        retorno=1;
    }
    else if(comp1->id==comp2->id)
    {
        retorno=0;
    }

    return retorno;

}



void computer_printComputer(LinkedList* this)
{
    eComputer* computer;
    int id;
    char descripcion[256];
    float precio;
    int idTipo;
    int i;

    system("cls");
    printf("%.5s %15s %10s %10s\n" ,"ID","DESCRIPCION","PRECIO","TIPO");

    for(i=0;i<ll_len(this);i++)
    {
        computer=ll_get(this,i);

        computer_getId(computer,&id);
        computer_getDescripcion(computer,descripcion);
        computer_getPrecio(computer,&precio);
        computer_getTipo(computer,&idTipo);

        if(idTipo==1)
        {
             printf("\n%d %.15s %.2f %.10s\n" ,id,descripcion,precio,"DESKTOP");
        }
        else
        {
             printf("\n%d %.15s %.2f %.10s\n" ,id,descripcion,precio,"LAPTOP");
        }
    }


}

void computer_mapPrecio(void* computer)
{
    float auxPrecio;
    int auxIdtipo;
    float nuevoPrecio;

    if(computer!=NULL)
    {
        computer_getTipo(computer,&auxIdtipo);
        computer_getPrecio(computer,&auxPrecio);

        if(auxIdtipo==1)
        {
            nuevoPrecio=auxPrecio*1.10;
            computer_setPrecio(computer,nuevoPrecio);
        }
        if(auxIdtipo==2)
        {
            nuevoPrecio=auxPrecio*1.20;
            computer_setPrecio(computer,nuevoPrecio);
        }


    }




}

int computer_filtrarLaptops(void *pComputer)
{
    int retorno=0;
    eComputer* computer;

    if(pComputer!=NULL)
    {
        computer=(eComputer*)pComputer;

        if(computer->idTipo==2)
        {
            retorno=1;
        }
    }

    return retorno;
}
/*int filtrarAutos(void* p)
{

    int ok = 0;
    Persona* ePersona;

    if(p != NULL){

        ePersona = (Persona*) p;

        if(ePersona->tipo == 'A')
		{
            ok = 1;
        }
    }

    return ok;

}

int filtrarMotos(void* p)
{

    int ok = 0;
    Persona* ePersona;

    if(p != NULL){

        ePersona = (Persona*) p;

        if(ePersona->tipo == 'M')
		{
            ok = 1;
        }
    }

    return ok;

}*/
