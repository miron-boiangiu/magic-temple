#include "utils.h"
int directieA(char *comanda)
{
    int max = comanda[1];
    int pos = 1;
    for (int i = 2; i < 5; i++)
    {
        if (comanda[i] > max)
        {
            max = comanda[i];
            pos = i;
        }
    }
    return pos;
}
void printSolutie(int *comenzi, int N, int M, int numar_comenzi)
{
    int **solutie = calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        solutie[i] = calloc(M, sizeof(int));
    }
    int posx = 0;
    int posy = 0;
    solutie[0][0] = 1;
    for (int i = 0; i < numar_comenzi; i++)
    {
        switch (comenzi[i])
        {
        case 1:
            posx++;
            solutie[posy][posx] = i + 2;
            break;
        case 2:
            posy--;
            solutie[posy][posx] = i + 2;
            break;
        case 3:
            posx--;
            solutie[posy][posx] = i + 2;
            break;
        case 4:
            posy++;
            solutie[posy][posx] = i + 2;
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", solutie[i][j]);
        }
        printf("\n");
    }
}
int checkPalindrome(char *comanda)
{
    for (int i = 1; i < strlen(comanda) / 2; i++)
    {
        if (comanda[i] != comanda[strlen(comanda) - i])
        {
            return 0;
        }
    }
    return 1;
}
int checkPrime(char *comanda)
{
    int size = strlen(comanda);
    int c1 = comanda[size - 1] - '0';
    int c2 = comanda[size - 2] - '0';
    int number = c2 * 10 + c1;
    if (number <= 2)
    {
        return 1;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int directieB(char *comanda)
{
    int pali = checkPalindrome(comanda);
    int prime = checkPrime(comanda);
    if (pali && prime)
    {
        return 3;
    }
    if (pali && !prime)
    {
        return 1;
    }
    if (!pali && prime)
    {
        return 2;
    }
    return 4;
}
int directieC(char *comanda)
{
    int S = 0;
    int n = comanda[1] - '0';
    int offset = comanda[2] - '0';
    int current = 0;
    for (int i = 0; i < offset; i++)
    {
        S += comanda[current + 3] - '0';
        current = (current + offset) % n;
    }

    switch (S % 4)
    {
    case 0:
        return 3;
    case 1:
        return 2;
    case 2:
        return 1;
    case 3:
        return 4;
    }
    return 0;
}
void SolveTask1()
{
    int N = 0;
    int M = 0;
    scanf("%d", &N);
    fflush(stdin);
    scanf("%d ", &M);
    fflush(stdin);
    size_t bufSize = 100;
    char *command = calloc(bufSize, sizeof(char));
    getline(&command, &bufSize, stdin);
    char *v = calloc(2, sizeof(char));
    int n = 0;
    for (int i = 0; i <= strlen(command); i++)
    {
        if ((command[i] == ' ') || (command[i] == '\0' || command[i] == '\n'))
        {
            n++;
            continue;
        }
    }
    int *miscari = calloc(n + 1, sizeof(int));
    n = 0;
    for (int i = 0; i <= strlen(command); i++)
    {
        if ((command[i] == ' ') || (command[i] == '\0' || command[i] == '\n'))
        {
            if (v[0] == 'a')
                miscari[n] = directieA(v);
            if (v[0] == 'b')
                miscari[n] = directieB(v);
            if (v[0] == 'c')
                miscari[n] = directieC(v);

            n++;
            strcpy(v, "");
            continue;
        }
        char c[1] = {command[i]};
        strcat(v, c);
    }
    printSolutie(miscari, N, M, n);
}