#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "gausseidel.h"

int main(){
    
    double **A, *b, *x, TOL, res;
    int size, i, itmax, choice, k;
    
    printf("Enter the dimension of A (>=3):");
    scanf("%d",&size);
    A = buid_pentadiagonal_matrix(size);
    
    printf("Please, choose a type for b:\n (0) sum of the lines of A.\n (1)Vector of 2 divide each entry by their index.\n ");
    scanf("%d",&choice);
    if(!choice){
        b = allocatevector(size);
        for(i = 0; i < size; i++)
            b[i] = sumline(A, size, i);
    }else
        b = divide_by_i(size);
    
    printf("Enter the tolerance value\nI.e.: 1*10^-3 = 0.001\n ");
    scanf("%le",&TOL);
    
    printf("Type the maximum number of iterations: ");
    scanf("%d",&itmax);
    x = gausseidel(A, size, b, TOL, itmax, choice, &k);
    if(x != NULL){
        printf("\nSolution:");
        printvector(x,size);
    }else
        printf("Ops, something went wrong!\n");
    
    //printmatrix(A,size);
    
    res = residue(A,b,x,size);
    printf("\nResidue: %lf",res);
    printf("\nNumber of iterations used: %d",k);
    deallocatematrix(&A,size);
    deallocatevector(b);
    deallocatevector(x); 
    return 0;
}
