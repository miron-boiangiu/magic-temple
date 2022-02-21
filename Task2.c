#include "utils.h"
void descifrareCaesar()
{
    int offset = 0;
    scanf("%d ", &offset);
    size_t bufSize = 100;

    char *cod = calloc(bufSize, sizeof(char));
    getline(&cod, &bufSize, stdin);

    for (int i = 0; i < strlen(cod); i++)
    {
        if (cod[i] >= 97 && cod[i] <= 122)
        {
            int offset_temp = offset;
            while (offset_temp > 26)
            {
                offset_temp -= 26;
            }
            int litera;
            litera = cod[i] - 'a';
            if (litera >= offset_temp)
            {
                litera = litera - offset_temp;
            }
            else
            {
                litera = 26 - (offset_temp - litera);
            }
            cod[i] = litera + 'a';
        }
        if (cod[i] >= 65 && cod[i] <= 90)
        {
            int offset_temp = offset;
            while (offset_temp > 26)
            {
                offset_temp -= 26;
            }
            int litera;
            litera = cod[i] - 'A';
            if (litera >= offset_temp)
            {
                litera = litera - offset_temp;
            }
            else
            {
                litera = 26 - (offset_temp - litera);
            }
            cod[i] = litera + 'A';
        }
        if (cod[i] >= 48 && cod[i] <= 57)
        {
            int litera;
            litera = cod[i] - '0';
            int offset_temp = offset;
            while (offset_temp > 10)
            {
                offset_temp -= 10;
            }
            if (litera >= offset_temp)
            {
                litera = litera - offset_temp;
            }
            else
            {
                litera = 10 - (offset_temp - litera);
            }
            cod[i] = litera + '0';
        }
    }

    printf("%s", cod);
    free(cod);
}
void descifrareVig()
{
    size_t bufSize = 100;
    char *key = calloc(bufSize, sizeof(char));
    getline(&key, &bufSize, stdin);
    fflush(stdin);

    char *cod = calloc(bufSize, sizeof(char));
    getline(&cod, &bufSize, stdin);
    int pos = 0;
    for (int i = 0; i < strlen(cod); i++)
    {
        int offset = key[pos] - 'A';
        pos++;
        if (key[pos] == '\n' || key[pos] == '\0')
            pos = 0;
        if (cod[i] >= 97 && cod[i] <= 122)
        {
            int offset_temp = offset;
            while (offset_temp > 26)
            {
                offset_temp -= 26;
            }
            int litera;
            litera = cod[i] - 'a';
            if (litera >= offset_temp)
            {
                litera = litera - offset_temp;
            }
            else
            {
                litera = 26 - (offset_temp - litera);
            }
            cod[i] = litera + 'a';
        }
        if (cod[i] >= 65 && cod[i] <= 90)
        {
            int offset_temp = offset;
            while (offset_temp > 26)
            {
                offset_temp -= 26;
            }
            int litera;
            litera = cod[i] - 'A';
            if (litera >= offset_temp)
            {
                litera = litera - offset_temp;
            }
            else
            {
                litera = 26 - (offset_temp - litera);
            }
            cod[i] = litera + 'A';
        }
        if (cod[i] >= 48 && cod[i] <= 57)
        {
            int litera;
            litera = cod[i] - '0';
            int offset_temp = offset;
            while (offset_temp > 10)
            {
                offset_temp -= 10;
            }
            if (litera >= offset_temp)
            {
                litera = litera - offset_temp;
            }
            else
            {
                litera = 10 - (offset_temp - litera);
            }
            cod[i] = litera + '0';
        }
    }

    printf("%s", cod);
    free(cod);
    free(key);
}
void decodificareNumar(char **cod, int offset)
{
    for (int i = 0; i < strlen(*cod); i++)
    {
        if ((*cod)[i] >= 48 && (*cod)[i] <= 57)
        {
            int litera;
            litera = (*cod)[i] - '0';
            if (litera >= offset)
            {
                litera = litera - offset;
            }
            else
            {
                litera = 10 - (offset - litera);
            }

            (*cod)[i] = litera + '0';
        }
    }
}
void addNumbers(char *n1, char *n2)
{
    char result[1000];
    int cifre1 = strlen(n1);
    int cifre2 = strlen(n2);
    if (cifre1 > cifre2)
    {
        int dif = cifre1 - cifre2;
        for (int i = cifre2; i >= 0; i--)
        {
            n2[i + dif] = n2[i];
        }
        for (int i = 0; i < dif; i++)
        {
            n2[i] = '0';
        }
        cifre2 = cifre1;
    }
    if (cifre2 > cifre1)
    {
        int dif = cifre2 - cifre1;
        for (int i = cifre1; i >= 0; i--)
        {
            n1[i + dif] = n1[i];
        }
        for (int i = 0; i < dif; i++)
        {
            n1[i] = '0';
        }
        cifre1 = cifre2;
    }

    for (int i = 0; i < 1000; i++)
    {
        result[i] = '0';
    }
    result[999] = '\0';
    int c = 0;
    int rest = 0;
    for (int i = cifre1; i >= 0; i--)
    {

        int suma_cifre = 0;
        suma_cifre = n1[i] - '0' + n2[i] - '0' + rest;

        if (suma_cifre > 9)
        {
            rest = 1;
            suma_cifre = suma_cifre % 10;
        }
        else
        {
            rest = 0;
        }
        result[998 - c] = suma_cifre + '0';
        c++;
        if (i == 0)
        {
            result[998 - c] = rest + '0';
        }
    }
    int gasit_cifra_diferita = 0;
    for (int i = 0; i < 998; i++)
    {
        if (result[i] != '0')
        {
            gasit_cifra_diferita = 1;
        }
        if (gasit_cifra_diferita)
        {
            printf("%c", result[i]);
        }
    }
}
void descifrareAdd()
{
    int offset = 0;
    scanf("%d ", &offset);
    size_t bufSize = 1000;
    while (offset > 10)
    {
        offset -= 10;
    }
    char *cod = calloc(bufSize, sizeof(char));
    scanf("%s", cod);
    fflush(stdin);

    char *cod2 = calloc(bufSize, sizeof(char));
    scanf("%s", cod2);

    decodificareNumar(&cod, offset);
    decodificareNumar(&cod2, offset);

    addNumbers(cod, cod2);
}
void SolveTask2()
{
    fflush(stdin);
    while (getchar() != '\n')
        ;
    size_t typeSize = 20;
    char *type = calloc(typeSize, sizeof(char));
    getline(&type, &typeSize, stdin);
    fflush(stdin);

    if (!strcmp(type, "caesar") || !strcmp(type, "caesar\n"))
    {
        descifrareCaesar();
    }
    if (!strcmp(type, "vigenere") || !strcmp(type, "vigenere\n"))
    {
        descifrareVig();
    }
    if (!strcmp(type, "addition") || !strcmp(type, "addition\n"))
    {
        descifrareAdd();
    }
    free(type);
}