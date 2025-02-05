#include <stdio.h>
#include <stdlib.h>

typedef struct parameters {
    int a;
    int b;
    float alpha;
    float beta;
} Parameters;

Parameters readInput(int, char **);
 
int main(int argc, char *argv[])
{

    printf("=================POINT A=================\n");
    Parameters p  = readInput(argc, argv);
    printf("=================POINT B=================\n");
    printf("=================POINT C=================\n");
    printf("=================POINT D=================\n");
    printf("=================POINT E=================\n");

}

void error(char *error)
{
    fprintf(stderr, "[ERROR]: %s\n", error);
    exit(1);
}

Parameters readInput(int argc,char *argv[])
{
    if (argc != 5)
        error("Wrong number of parameters");

    int a = atoi(argv[1]);
    if (a < 5 || a > 20)
        error("Worng parameters a");

    int b = atoi(argv[2]);
    if (b < 5 || b > 20)
        error("Worng parameters b");

    float alpha  = atof(argv[3]);
    if (alpha < 10 || alpha > 20)
        error("Worng parameters alpha");

    float beta = atof(argv[4]);
    if (beta < 1 || beta > 5)
        error("Worng parameters beta");
    
    Parameters p = {a, b, alpha, beta};

    return p;
}