#include <math.h>
#include <stdlib.h>
#include "matrix.h"

/* Uniform Norm */
double infnorm(double *x1, double *x2, int size){
    double dif, max;
    int i;
    dif = 0;
    max = 0;

    for(i = 0; i < size; i++){
        dif = fabs(x2[i] - x1[i]);
        if(dif > max)
            max = dif;
    }
    return max;
}

double* initialguess(double *vet, int size){
    int i;
    for(i = 0; i<size; i++)
        vet[i] = rand()%100+(i/100);
    return vet;
}

double residue(double **A, double *b, double *x, int size){
    int i;
    double *aux, *r, res;
    aux = prod_matrix_vector(A,x,size);
    r = allocatevector(size);
    for(i=0; i< size; i++)
        r[i] = b[i] - aux[i];
    res = infnorm(b,aux,size);
    deallocatevector(aux);
    deallocatevector(r);
    return res;
}

double* gausseidel(double** A, int size, double* b, double e, int itmax, int choice, int *num_it){
    int i, j, k=0;
    double *xk, *xk_prox, som;
    xk = allocatevector(size);
    xk_prox = allocatevector(size);
    for(i=0;i<size;i++){
        xk_prox[i] = 0;
        xk[i] = 0;
    }
    
    if(choice)
        xk = initialguess(xk, size);
    
    while(k<itmax){
        copyvector(xk,xk_prox, size);
        for(i = 0; i < size; i++){
            som = 0;
            for(j=0; j< size; j++)
                if(i!=j)
                    som += A[i][j] * xk_prox[j];

            xk_prox[i] = (b[i]-som)/A[i][i];
        }
        if(infnorm(xk,xk_prox,size)<e){
            deallocatevector(xk);
            *num_it = k;
            return xk_prox;
        }
        k++;
    }
    *num_it = k;
    return xk_prox;
}
