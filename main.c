#include "biblioteka.h"
void SORTIROVKA(char** tekst,int* mass_size, int pivot)
{
	int size;
	char buffer[256] = { '\0' };
	for(int i = 0; i < pivot; i++)
	{
		if (mass_size[i] > mass_size[i + 1]) 
		{
			size = mass_size[i];
			mass_size[i] = mass_size[i + 1];
			mass_size[i + 1] = size;
			strcpy_s(buffer, mass_size[i+1]+1, tekst[i]);
			strcpy_s(tekst[i], mass_size[i]+1, tekst[i+1]);
			strcpy_s(tekst[i + 1], mass_size[i+1]+1, buffer);

		}
	}
	return tekst;
}
void VIVOD(char** tekst, int kolvo_strok) 
{
	for (int i = 0; i < kolvo_strok; i++) 
	{
		printf("%s\n", tekst[i]);
	}
}
int main(argc, argv)
{
	setlocale(LC_ALL, "Russian");
	FILE* book;
	char** tekst;
	char buffer[256] = {'\0'};
	int size = 0;
	int* mass_size;
	int kolvo_strok = 0;
	fopen_s(&book,"C:\\Users\\mampe\\Desktop\\Программы курс 1\\Лабораторная №2\\book.txt","r+");
	if (book == NULL)
		return(3);
	fseek(book, 0, SEEK_SET);
	while(!feof(book))
	{
	fgets(buffer, 256, book);
	kolvo_strok++;
	}
	fseek(book, 0, SEEK_SET);
	tekst = (char**)malloc(kolvo_strok * sizeof(char*));
	mass_size = (int*)calloc(kolvo_strok, sizeof(int));
	int i = 0;
	while (!feof(book)) 
	{
    fgets(buffer,256,book);
	size = strlen(buffer);
	tekst[i] = (char*)malloc(size * sizeof(char));
	strcpy_s(tekst[i], size + 1, buffer);
	mass_size[i] = size;
	i++;
	}
	i = 0;
	fclose(book);
	SORTIROVKA(tekst,mass_size,kolvo_strok-1);
	//VIVOD(tekst, kolvo_strok);
	for (int i = 0; i < kolvo_strok; i++)
	{
		free(tekst[i]);
	}
	free(mass_size);
	system("pause");
	return(0);
}