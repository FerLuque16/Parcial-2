int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry);
float getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit, int retry);
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit, int retry);
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry);
int getTelefono(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry);
int getDomicilio(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry);

int getStringNumeros(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int retry);

int getConfirmation(char* input,char message[],char eMessage[],int retry);

int getRandomNumber(int desde, int hasta, int inicio);
