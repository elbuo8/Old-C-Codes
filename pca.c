#include <stdio.h>

#include <culapack.h>

#include <stdlib.h>

#include "cublas.h"

#define imin(X, Y) ((X) < (Y) ? (X) : (Y))

int PCA(int argc, char** argv)

{
    
    culaStatus status;
    
    char jobu = 'A'; // Compute all the columns of matrix U
    
    char jobvt = 'N'; // Not compute the matrix V
    
    int M = 200; // Number of bands
    
    int N = 10000; // Number of pixels
    
    int imgsize = M * N; // total size of matrix A
    
    FILE *fp1,*fp2; // file pointers
    
    float* A = NULL;
    
    float* S = NULL;
    
    float* U = NULL;
    
    float* VT = NULL;
    
    // Setup SVD Parameters
    
    int LDA = M; //The leading dimension of the array A (number of bands)
    
    int LDU = M; //The leading dimension of the array U (number of bands)
    
    int LDVT = N; //The leading dimension of the array VT (number of pixels)
    
    // Allocate matrix A
    
    A = (float*)malloc(imgsize * sizeof(float));
    
    // Open image file
    
    fp1 = fopen("image.dat","rb");
    
    fread(A, sizeof(float), imgsize, fp1);
    
    // Allocate matrices S,U,V
    
    S = (float*)malloc(imin(M,N)*sizeof(float));
    
    U = (float*)malloc(LDU*M*sizeof(float));
    
    VT = (float*)malloc(LDVT*N*sizeof(float));
    
    // Call culaSgesvd function
    
    status = culaInitialize();
    
    printf("Before Kernel\n");
    
    // SVD calculation: X = U*S*VT
    
    status = culaSgesvd(jobu, jobvt, M, N, A, LDA, S, U, LDU, VT, LDVT);
    
    printf("Kernel Exit\n");
    
    // Calculate PCA using cublas
    
    cublasStatus st;
    
    st = cublasInit();
    
    float* d_A; // pointer to matrix A in the device
    
    float* d_U; // pointer to matrix U in the device
    
    float* h_PCA; // pointer to PCA matrix in the host
    
    float* d_PCA; // pointer to PCA matrix in the device
    
    float alpha = 1.0f;
    
    float beta = 0.0f;
    
    // Allocate PCA matrix in the host
    
    h_PCA = (float*)calloc(imgsize, sizeof(float));
    
    // Open image file
    
    rewind(fp1);
    
    fread(A, sizeof(float), imgsize, fp1);
    
    /* Allocate device memory */
    
    st = cublasAlloc(imgsize, sizeof(float), (void**)&d_A);
    
    st = cublasAlloc(LDU*M, sizeof(float), (void**)&d_U);
    
    st = cublasAlloc(imgsize, sizeof(float), (void**)&d_PCA);
    
    /* Copy image to device memory */
    
    st = cublasSetVector(imgsize, sizeof(float), A, 1, d_A, 1);
    
    st = cublasSetVector(LDU*M, sizeof(float), U, 1, d_U, 1);
    
    st = cublasSetVector(imgsize, sizeof(float), h_PCA, 1, d_PCA, 1);
    
    /* Calculate PCA using cublas: PCA = UT * A */
    
    cublasSgemm('t', 'n', M, N, M, alpha, d_U, M, d_A, M, beta, d_PCA, M);
    
    /* Read the result back */
    
    status = cublasGetVector(imgsize, sizeof(float), d_PCA, 1, h_PCA, 1);
    
    fp2 = fopen("pca.dat","wb");
    
    fwrite(h_PCA, sizeof(float), imgsize, fp2);
    
    // Clean up workspace, input, and output memory allocations
    
    free(A);
    
    free(U);
    
    free(S);
    
    free(VT);
    
    free(h_PCA);
    
    st = cublasFree(d_A);
    
    st = cublasFree(d_U);
    
    st = cublasFree(d_PCA);
    
    fclose(fp1);
    
    fclose(fp2);
    
    /* Shutdown */
    
    st = cublasShutdown();
    
    culaShutdown();
    
    printf("\nPress ENTER to exit...\n");
    
    getchar();
    
    return EXIT_SUCCESS;
    
}