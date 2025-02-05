#include <stdio.h>
#include <stdlib.h>

typedef struct parameters
{
    int a;
    int b;
    float alpha;
    float beta;
} Parameters;

Parameters readInput(int, char **);
double **allocMatrix(int, int);

int main(int argc, char *argv[])
{

    printf("=================POINT A=================\n");
    Parameters p = readInput(argc, argv);
    printf("=================POINT B=================\n");
    double **matrix = allocMatrix(p.a, p.b);
    printf("=================POINT C=================\n");
    printf("=================POINT D=================\n");
    printf("=================POINT E=================\n");
}

void error(char *error)
{
    fprintf(stderr, "[ERROR]: %s\n", error);
    exit(1);
}

Parameters readInput(int argc, char *argv[])
{
    if (argc != 5)
        error("Wrong number of parameters");

    int a = atoi(argv[1]);
    if (a < 5 || a > 20)
        error("Worng parameters a");

    int b = atoi(argv[2]);
    if (b < 5 || b > 20)
        error("Worng parameters b");

    float alpha = atof(argv[3]);
    if (alpha < 10 || alpha > 20)
        error("Worng parameters alpha");

    float beta = atof(argv[4]);
    if (beta < 1 || beta > 5)
        error("Worng parameters beta");

    Parameters p = {a, b, alpha, beta};

    return p;
}

double **allocMatrix(int a, int b)
{
    // Alloco la memoria alla matrice di dimensioni A x B
    double **M = (double **)malloc(sizeof(double *) * a);
    if (M == NULL)
        error("Allocation for **M not correctly done");

    for (int i = 0; i < a; i++)
    {
        M[i] = (double *)malloc(sizeof(double) * b);
        //Se l'allocazione non avviene correttamente
        if (M[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(M[j]);
            }
            free(M);
            error("Memory allocation during M[i] not correctly done");
        }
    }

    return  M;
}