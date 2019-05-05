#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funcao que aloca a matriz na memoria */
double **allocatematrix(int n){
    double **M;
    int i;
    M = (double **)malloc(n*sizeof(double*));
    if(M == NULL){
        printf("\nAllocation error!\n");
        return(NULL);
    }
    for(i=0; i< n; i++){
        M[i] = (double *)calloc(n,sizeof(double));
        if(M[i]==NULL){
            printf("\nAllocation error!\n");
            return(NULL);
        }
    }
    return(M);
}

/* Funcao que desaloca a matriz da memoria */
void deallocatematrix(double ***M, int n){
    int i;
    for(i = 0; i < n; i++){
        free((*M)[i]);
        (*M)[i] = NULL;
    }
    free(*M);
    *M = NULL;
    return;
}

double sumline(double **M, int n, int i){
    int j;
    double sum=0;
    for(j = 0; j < n; j++)
            sum += M[i][j];
    return sum;
}

/* Funcao que imprime a matriz */
void printmatrix(double **M, int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf(" %.2lf ",M[i][j]);
        printf("\n");
    }
    return;
}

/* Criar a Matriz */
/* Criaremos uma matriz pentadiagonal de dimensao n  onde:*/
/* A diagonal principal eh 3 */
/* As diagonais entre a diagonal principal (chamerei de secundarias) eh -0.75 */
/* As diagonais entre a diagonais secundarias eh 0 */
/* O restante tambem eh 0 */

double **buid_pentadiagonal_matrix(double n){
    double **M;
    int i, j;
    M = allocatematrix(n);
    if(M==NULL)
        return(NULL);
      
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            M[i][j] = 0;
    
    for(i = 0; i < n; i++)
        M[i][i] =  3;
    
    for(i = 0; i < n-1; i++){
        M[i][i+1] = -0.75;
        M[i+1][i] = -0.75;
    }
    
   for(i = 0; i < n-3; i++){
        M[i][i+3] = -0.75;
        M[i+3][i] = -0.75;
    }
    
    return M;
}

double* allocatevector(int n){    
  double *v;
  v = (double *)calloc(n,sizeof(double));
  if (v == NULL) {
    printf("\nErro de Alocacao\n");
    return(NULL);
  }
  return v;
}

void copyvector(double *c, double *v, int tam){
    memcpy(c, v, tam * sizeof *c);
    return;
}

double* prod_matrix_vector(double **M, double *v, int n){
    int i, j;
    double *vet;
    vet = allocatevector(n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            vet[i] += M[i][j]*v[j];
    
    return vet;
}

double* divide_by_i(int n){
    double *b;
    b = allocatevector(n);
    int i;
    for(i = 1; i <= n; i++)
        b[i] = 2/i;
    return b;
}

void printvector(double *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("x[%d] =  %.8lf",i,v[i]);
        printf("\n");
    }
    return;
}

void deallocatevector(double *v){
    free(v);
    v = NULL;
    return;
}
