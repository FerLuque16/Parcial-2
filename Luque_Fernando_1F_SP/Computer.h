#ifndef Persona_H_INCLUDED
#define Persona_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[4096];
    float precio;
    int idTipo;

}eComputer;
#endif

eComputer* computer_new();
eComputer* computer_newParametros(char* idStr,char* descStr,char* precioStr,char* idTipoStr);
void computer_delete(eComputer* this);
int computer_setId(eComputer* this,int id);
int computer_setPrecio(eComputer* this,float precio);
int computer_setDescripcion(eComputer* this,char* desc);
int computer_getDescripcion(eComputer* this,char* desc);
int computer_getPrecio(eComputer* this,float* precio);
int computer_getId(eComputer* this,int* id);
int computer_setTipo(eComputer* this, int tipo);
int computer_getTipo(eComputer* this, int *tipo);
void computer_printComputer(LinkedList* this);
int computer_compareId(void* arg1, void* arg2);
void computer_mapPrecio(void* computer);
int computer_filtrarLaptops(void *pComputer);


int filtrarMotos(void* p);
int filtrarAutos(void* p);


