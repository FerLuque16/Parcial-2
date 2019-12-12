#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utn.h"



/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \param retry Cantidad de reintentos posibles

* \return Si obtuvo el numero [0] si no [-1]
*
*/

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    int auxInt;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit && retry>=0)
        {
            do{

            system("cls");
            printf("%s",message);
            setbuf(stdin,NULL);
            if(scanf("%d",&auxInt)==1)
            {


			if(auxInt >= lowLimit && auxInt <= hiLimit)
                {
                    retorno = 0;
                    *input = auxInt;
                    break;

                }
                else
                {

                    printf("%s\n\n",eMessage);
                    system("pause");
                    retry--;
                }

            }
            else
            {

                    printf("%s\n\n",eMessage);
                    system("pause");
                    retry--;
            }

            }while(retry>=0);
        }

    if(retry==-1)
    {
        retorno=-1;
    }



    return retorno;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \param retry Cantidad de reintentos posibles
* \return Si obtuvo el numero [0] si no [-1]
*
*/

float getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit, int retry)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    float auxFloat;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit)
        {
            do{
            printf("%s",message);
            setbuf(stdin,NULL);
            //scanf("%f",&auxInt);
            if(scanf("%f",&auxFloat)==1)
            {


			if(auxFloat >= lowLimit && auxFloat <= hiLimit)
                {
                    retorno = 0;
                    *input = auxFloat;
                    break;
                }

            }
			else
            {

                printf("%s",eMessage);
                system("pause");
                retry--;
            }


            }while(retry>=0);
        }


    return retorno;
}

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \param retry Cantidad de reintentos posibles
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit, int retry)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    char auxChar;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit)
    {
        do
        {
            printf("%s",message);
            setbuf(stdin,NULL);

            if(scanf("%c",&auxChar)==1)
                {
                    if(auxChar >= lowLimit && auxChar <= hiLimit && (isdigit(auxChar)==0))
                        {
                            retorno = 0;
                            *input=auxChar;
                            break;
                        }

                }
            else
                {
                    printf("%s" ,eMessage);
                    system("pause");
                    retry--;
                }

        }while(retry>=0);


    }

    if(retry==-1)
    {
        retorno=-1;
    }


    return retorno;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \param retry Cantidad de reintentos posibles
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    char auxStr[4096];
    int i;
    int flag=0;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit && retry>=0)
    {
        do{
        system("cls");
        printf("%s" ,message);
        setbuf(stdin,NULL);
        fgets(auxStr,sizeof(auxStr),stdin);
        auxStr[strlen(auxStr)-1] = '\0';

        for(i=0;i<strlen(auxStr);i++)
            {
                if(isdigit(auxStr[i]))
                {
                    flag=1;
                    break;

                }
            }

        if(strlen(auxStr)>=lowLimit && strlen(auxStr)<=hiLimit && flag==0)
            {
                strlwr(auxStr);
                auxStr[0]=toupper(auxStr[0]);
                strcpy(input,auxStr);
                retorno=0;
                break;
            }
            else
            {
                printf("%s" ,eMessage);
                system("pause");
                flag=0;
                retry--;
            }

        }while(retry>=0);
    }
    if(retry==-1)
    {
        retorno=-1;
    }



    return retorno;
}

int getRandomNumber(int desde, int hasta, int inicio)
{
    int randomNumber;
    if (inicio)
    {
        srand (time(NULL));
    }

    randomNumber = desde + (rand() % (hasta + 1 - desde));

return randomNumber;
}

/**
* \brief Solicita un telefono al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima del numero
* \param hiLimit Longitud máxima del numero
* \param retry Cantidad de reintentos posibles
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int getTelefono(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    char auxStr[4096];
    int i;
    int flag=0;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit && retry>=0)
    {
        do{
        printf("%s" ,message);
        setbuf(stdin,NULL);
        fgets(auxStr,sizeof(auxStr),stdin);
        auxStr[strlen(auxStr)-1] = '\0';

        for(i=0;i<strlen(auxStr);i++)
            {
                if(isdigit(auxStr[i]))
                {
                    flag=1;
                    break;

                }
            }

        if(strlen(auxStr)>=lowLimit && strlen(auxStr)<=hiLimit && flag==1)
            {
                strcpy(input,auxStr);
                retorno=0;
                break;
            }
        else
            {
                printf("%s" ,eMessage);
                system("pause");
                flag=0;
                retry--;
            }

        }while(retry>=0);


    }

    if(retry==-1)
    {
        retorno=-1;
    }
     return retorno;
}

/**
* \brief Solicita un domicilio al usuario y lo valida
* \param input Se carga el domicilio ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \param retry Cantidad de reintentos posibles
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int getDomicilio(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    char auxStr[4096];
    int i;
    int flag=0;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit && retry>=0)
    {
        do{
        printf("%s" ,message);
        setbuf(stdin,NULL);
        fgets(auxStr,sizeof(auxStr),stdin);
        auxStr[strlen(auxStr)-1] = '\0';

        for(i=0;i<strlen(auxStr);i++)
            {
                if((auxStr[i]!=' ')&&(auxStr[i] < 'a' || auxStr[i] > 'z') && (auxStr[i] < 'A' || auxStr[i] > 'Z') && (auxStr[i] < '0' || auxStr[i] > '9'))
                {
                    flag=1;
                    break;

                }
            }

        if(strlen(auxStr)>=lowLimit && strlen(auxStr)<=hiLimit && flag==0)
            {
                strcpy(input,auxStr);
                retorno=0;
                break;
            }
        else
            {
                printf("%s" ,eMessage);
                system("pause");
                flag=0;
                retry--;
            }

        }while(retry>=0);

        if(retry==0)
        {
            retorno=-1;
        }


    }

        return retorno;
}

/**
* \brief Solicita un numero en forma de string al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \param retry Cantidad de reintentos posibles
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int getStringNumeros(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry)
{

    char auxStr[256];
    int retorno=-1;


     if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit && retry>=0)
    {
        do
        {
            system("cls");
            printf("%s" ,message);
            setbuf(stdin,NULL);
            scanf("%s" ,auxStr);




        if(strlen(auxStr)>=lowLimit && strlen(auxStr)<=hiLimit)
            {
                strcpy(input,auxStr);
                retorno=0;
                break;
            }
            else
            {
                printf("%s" ,eMessage);
                system("pause");

                retry--;
            }

        }while(retry>=0);
    }
        if(retry==-1)
        {
            retorno=-1;
        }



    return retorno;
}

int getConfirmation(char* input,char message[],char eMessage[],int retry)
{
    int retorno=-1;
    char auxStr[21];

    if(input!=NULL && message!=NULL && eMessage != NULL)
    {
        do
        {
            system("cls");
            printf("%s",message);
            scanf("%s",auxStr);

            strlwr(auxStr);

            if(strcmp(auxStr,"si")==0 || strcmp(auxStr,"no")==0)
            {
                strcpy(input,auxStr);
                retorno=0;
                break;

            }
            else
            {
                printf("%s" ,eMessage);
                system("pause");
                retry--;
            }
        }
        while(retry>=0);
    }

    if(retry==-1)
    {
        retorno=-1;
    }
    return retorno;
}





