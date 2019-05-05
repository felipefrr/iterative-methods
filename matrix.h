#ifndef MATRIZ_H
#define MATRIZ_H
double **allocatematrix(int n);
void deallocatematrix(double ***M, int n);
double sumline(double **M, int n, int i);
void printmatrix(double **M, int n);
double** buid_pentadiagonal_matrix(double n);
double* allocatevector(int n);
void copyvector(double *c, double *v, int tam);
double* prod_matrix_vector(double **M, double *v, int n);
double* divide_by_i(int n);
void printvector(double *v, int n);
void deallocatevector(double *v);

#endif	// MATRIZ_H


