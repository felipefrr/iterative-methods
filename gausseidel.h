#ifndef GAUSSEIDEL_H
#define GAUSSEIDEL_H

double infnorm(double *x1, double *x2, int n);
double* initialguess(double *vet, int n);
double residue(double **A, double *b, double *x, int n);
double* gausseidel(double** A, int tam, double* b, double e, int itmax, int escolha, int *num_it);

#endif	// GAUSSEIDEL_H


