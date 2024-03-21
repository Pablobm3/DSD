#include "calcul.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_VECTOR_SIZE 100 // Define el tamaño máximo de los vectores según tus necesidades

void free_memory(float *result, char opr) {
    if (opr == 'V') {
        free(result); // Liberar memoria si el resultado es un array de floats
    }
}

void print_vector(float *result, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", result[i]);
    }
    printf("]\n");
}

float *calculate_prog1_1(char *host, float n1, float n2, char opr, float *vector1, float *vector2, int vector_size, CLIENT *clnt) {
    float *result;

    float *vr[vector_size];

    if (opr == 'S' || opr == 'R' || opr == 'M') { // Operación con vectores
        

        // Crear la estructura vectores y asignar los valores
        vectores v;
        v.float_array1.float_array1_len = vector_size;
        v.float_array1.float_array1_val = vector1;
        v.float_array2.float_array2_len = vector_size;
        v.float_array2.float_array2_val = vector2;

        switch (opr) {
            case 'S': // Suma de vectores
                // Lógica para llamar a la función remota de suma de vectores
                result = vector_sum_1(&v, clnt);
                printf("El resultado de la suma de vectores es: ");
                print_vector(result, vector_size);
                
                
                //printf("El resultado de la suma de vectores es: ");
                //print_vector(vr, vector_size);
                
                break;
            case 'R': // Resta de vectores
                // Lógica para llamar a la función remota de resta de vectores
                result = vector_res_1(&v, clnt);
                printf("El resultado de la resta de vectores es: ");
                print_vector(result, vector_size);
                break;
            case 'M': // Multiplicación de vectores
                // Lógica para llamar a la función remota de multiplicación de vectores
                result = vector_mult_1(&v, clnt);
                printf("El resultado de la multiplicación de vectores es: ");
                print_vector(result, vector_size);
                break;
            default:
                printf("Operador de vector no válido.\n");
                
                exit(1);
        }
    } else { // Operación simple
        // Lógica para llamar a la función remota de operación simple
        inputs arg;
        arg.a = n1;
        arg.b = n2;
        arg.c = opr;

        result = (float *)malloc(sizeof(float));
        if (result == NULL) {
            printf("Error de asignación de memoria.\n");
            exit(1);
        }

        switch (opr) {
            case '+':
                *result = *sum_1(&arg, clnt);
                break;
            case '-':
                *result = *res_1(&arg, clnt);
                break;
            case '*':
                *result = *mult_1(&arg, clnt);
                break;
            case '/':
                *result = *div_1(&arg, clnt);
                break;
            case '^':
                *result = *pot_1(&arg, clnt);
                break;
            default:
                printf("Operador no válido.\n");
                free_memory(result, opr);
                exit(1);
        }

        printf("El resultado de la operación %c es: %.2f\n", opr, *result);
    }

    return result;
}

int main(int argc, char *argv[]) {
    char *host;
    float a, b;
    CLIENT *clnt;
    char op;
    int vector_size = 0;

    if (argc < 2) {
        printf("usage: %s server_host\n", argv[0]);
        exit(1);
    }

    host = argv[1];

    #ifndef	DEBUG
    clnt = clnt_create(host, CALCULATE_PROG1, CALCULATE_VER1, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }
    #endif	/* DEBUG */

    printf("Bienvenido a la calculadora de Pablo\n");

    
        printf("Inserte operador :\n");
    printf("+ para Suma\n - para Resta\n * para Multiplicación\n / para División\n ^ para Potencia\n S para Suma de vectores\n R para Resta de vectores\n M para Multiplicación de vectores\n");
    scanf(" %c", &op);

    if (op == 'S' || op == 'R' || op == 'M') {
        printf("Inserte el tamaño de los vectores: ");
        scanf("%d", &vector_size);

        float *vector1 = (float *)malloc(vector_size * sizeof(float));
        float *vector2 = (float *)malloc(vector_size * sizeof(float));
        if (vector1 == NULL || vector2 == NULL) {
            printf("Error de asignación de memoria.\n");
            exit(1);
        }

        printf("Inserte los valores del primer vector:\n");
        for (int i = 0; i < vector_size; i++) {
            printf("Valor %d: ", i + 1);
            scanf("%f", &vector1[i]);
        }

        printf("Inserte los valores del segundo vector:\n");
        for (int i = 0; i < vector_size; i++) {
            printf("Valor %d: ", i + 1);
            scanf("%f", &vector2[i]);
        }

        

        

        float *result = calculate_prog1_1(host, a, b, op, vector1, vector2, vector_size, clnt);
        
     
        
        /*free(vector1);
        free(vector2);
        free(result); // Liberar memoria del resultado*/
    } else {

        printf("Inserte el primer número :\n");
        scanf("%f", &a);

        printf("Inserte el segundo número :\n");
        scanf("%f", &b);


        float *result = calculate_prog1_1(host, a, b, op, NULL, NULL, 0, clnt);
        //free(result); // Liberar memoria del resultado
    }

    #ifndef	DEBUG
    clnt_destroy (clnt);
    #endif	 /* DEBUG */
    exit(0);
}

