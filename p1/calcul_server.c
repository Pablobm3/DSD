#include "calcul.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_VECTOR_SIZE 100 // Define el tamaño máximo de los vectores según tus necesidades

float *
sum_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float  result;

    result = argp ->a + argp->b;

    printf("Recibida la solicitud de suma de %.2f y %.2f\n", argp ->a, argp->b);
    printf("Resultado enviado: %.2f\n", result);

    return &result;
}

float *
res_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float  result;

    result = argp ->a - argp->b;

    printf("Recibida la solicitud de resta de %.2f y %.2f\n", argp ->a, argp->b);
    printf("Resultado enviado: %.2f\n", result);

    return &result;
}

float *
mult_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float  result;

    result = argp ->a * argp->b;

    printf("Recibida la solicitud de multiplicacion de %.2f y %.2f\n", argp ->a, argp->b);
    printf("Resultado enviado: %.2f\n", result);

    return &result;
}

float *
div_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float  result;

    if (argp->b == 0) {
        printf("Error: División por cero.\n");
        exit(1);
    }

    result = argp ->a / argp->b;

    printf("Recibida la solicitud de division de %.2f y %.2f\n", argp ->a, argp->b);
    printf("Resultado enviado: %.2f\n", result);

    return &result;
}

float *
pot_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float  result;

    double potencia = pow(argp ->a, argp->b);
    result = (float)potencia;

    printf("Recibida la solicitud de potencia de %.2f y %.2f\n", argp ->a, argp->b);
    printf("Resultado enviado: %.2f\n", result);

    return &result;
}

float *
vector_sum_1_svc(vectores *argp, struct svc_req *rqstp)
{
    static float result[MAX_VECTOR_SIZE]; // Define el tamaño máximo de los vectores según tus necesidades
    int vector_size1 = argp->float_array1.float_array1_len;
    int vector_size2 = argp->float_array2.float_array2_len;

    if (vector_size1 != vector_size2) {
        printf("Error: Los vectores tienen diferentes tamaños.\n");
        exit(1);
    }

    for (int i = 0; i < vector_size1; i++) {
        result[i] = argp->float_array1.float_array1_val[i] + argp->float_array2.float_array2_val[i];
    }

    printf("Recibida la solicitud de suma de vectores.\n");
    // Imprimir los vectores recibidos y el resultado de la suma
    printf("Vector 1: ");
    for (int i = 0; i < vector_size1; i++) {
        printf("%.2f ", argp->float_array1.float_array1_val[i]);
    }
    printf("\nVector 2: ");
    for (int i = 0; i < vector_size2; i++) {
        printf("%.2f ", argp->float_array2.float_array2_val[i]);
    }
    printf("\nResultado de la suma de vectores: ");
     printf("[ ");
    for (int i = 0; i < vector_size1; i++) {
        printf("%.2f ", result[i]);
    }
   printf("]\n");

    return result;
}

float *
vector_res_1_svc(vectores *argp, struct svc_req *rqstp)
{
    static float result[MAX_VECTOR_SIZE]; // Define el tamaño máximo de los vectores según tus necesidades
    int vector_size1 = argp->float_array1.float_array1_len;
    int vector_size2 = argp->float_array2.float_array2_len;

    if (vector_size1 != vector_size2) {
        printf("Error: Los vectores tienen diferentes tamaños.\n");
        exit(1);
    }

    for (int i = 0; i < vector_size1; i++) {
        result[i] = argp->float_array1.float_array1_val[i] - argp->float_array2.float_array2_val[i];
    }

    printf("Recibida la solicitud de resta de vectores.\n");
    // Imprimir los vectores recibidos y el resultado de la resta
    printf("Vector 1: ");
    for (int i = 0; i < vector_size1; i++) {
        printf("%.2f ", argp->float_array1.float_array1_val[i]);
    }
    printf("\nVector 2: ");
    for (int i = 0; i < vector_size2; i++) {
        printf("%.2f ", argp->float_array2.float_array2_val[i]);
    }
    printf("\nResultado de la resta de vectores: ");
    printf("[ ");
    for (int i = 0; i < vector_size1; i++) {
        printf("%.2f ", result[i]);
    }
    printf("]\n");

    return result;
}

float *
vector_mult_1_svc(vectores *argp, struct svc_req *rqstp)
{
    static float result[MAX_VECTOR_SIZE]; // Define el tamaño máximo de los vectores según tus necesidades
    int vector_size1 = argp->float_array1.float_array1_len;
    int vector_size2 = argp->float_array2.float_array2_len;

    if (vector_size1 != vector_size2) {
        printf("Error: Los vectores tienen diferentes tamaños.\n");
        exit(1);
    }

    for (int i = 0; i < vector_size1; i++) {
        result[i] = argp->float_array1.float_array1_val[i] * argp->float_array2.float_array2_val[i];
    }

    printf("Recibida la solicitud de multiplicación de vectores.\n");
    // Imprimir los vectores recibidos y el resultado de la multiplicación
    printf("Vector 1: ");
    for (int i = 0; i < vector_size1; i++) {
        printf("%.2f ", argp->float_array1.float_array1_val[i]);
    }
    printf("\nVector 2: ");
    for (int i = 0; i < vector_size2; i++) {
        printf("%.2f ", argp->float_array2.float_array2_val[i]);
    }
    printf("\nResultado de la multiplicación de vectores: ");
     printf("[ ");
    for (int i = 0; i < vector_size1; i++) {
        printf("%.2f ", result[i]);
    }
    printf("]\n");

    return result;
}