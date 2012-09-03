/* Includes, system */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

/* Includes, cuda */

#include "cublas.h"

/* Number of pixels */

#define N (10000)

/* Number of bands */

#define L (200)

/* Main */

int main(void)

{
    
    cublasStatus status;
    
    float* h_image;
    
    float* h_covariance;
    
    float* d_image;
    
    float* d_covariance;
    
    float alpha = 1.0f;
    
    float beta = 0.0f;
    
    int imgsize = N * L;
    
    //int i;
    
    FILE *fp1, *fp2;
    
    /* Initialize CUBLAS */
    
    status = cublasInit();
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! CUBLAS initialization error\n");
        
        return EXIT_FAILURE;
        
    }
    
    /* Allocate host memory for the image */
    
    h_image = (float*)malloc(imgsize * sizeof(float));
    
    if (h_image == 0) {
        
        fprintf (stderr, "!!!! host memory allocation error (image)\n");
        
        return EXIT_FAILURE;
        
    }
    
    h_covariance = (float*)calloc(L * L, sizeof(float));
    
    if (h_covariance == 0) {
        
        fprintf (stderr, "!!!! host memory allocation error (covariance)\n");
        
        return EXIT_FAILURE;
        
    }
    
    /* Fill the image with test data
     
     for (i = 0; i < imgsize; i++) {
     
     h_image[i] = rand() / (float)RAND_MAX;
     
     }*/
    
    fp1 = fopen("image.dat","rb");
    
    fread(h_image, sizeof(float), imgsize, fp1);
    
    printf("Valor de image[0]: %f\n", h_image[8]);
    
    /* Allocate device memory */
    
    status = cublasAlloc(imgsize, sizeof(float), (void**)&d_image);
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! device memory allocation error (image)\n");
        
        return EXIT_FAILURE;
        
    }
    
    status = cublasAlloc(L * L, sizeof(float), (void**)&d_covariance);
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! device memory allocation error (covariance)\n");
        
        return EXIT_FAILURE;
        
    }
    
    /* Copy image to device memory */
    
    status = cublasSetVector(imgsize, sizeof(float), h_image, 1, d_image, 1);
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! device access error (write A)\n");
        
        return EXIT_FAILURE;
        
    }
    
    status = cublasSetVector(L * L, sizeof(float), h_covariance, 1, d_covariance,
                             
                             1);
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! device access error (write covariance)\n");
        
        return EXIT_FAILURE;
        
    }
    
    /* Clear last error */
    
    cublasGetError();
    
    /* Calculate covariance matrix using cublas */
    
    cublasSgemm('n', 't', L, L, N, alpha, d_image, L, d_image, L, beta,
                
                d_covariance, L);
    
    status = cublasGetError();
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! kernel execution error.\n");
        
        return EXIT_FAILURE;
        
    }
    
    /* Read the result back */
    
    status = cublasGetVector(L * L, sizeof(float), d_covariance, 1, h_covariance,
                             
                             1);
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! device access error (read covariance)\n");
        
        return EXIT_FAILURE;
        
    }
    
    fp2 = fopen("covariance.dat","wb");
    
    fwrite(h_covariance, sizeof(float), L*L, fp2);
    
    printf("Valor de covariance[8]: %f\n", h_covariance[8]);
    
    /* Memory clean up */
    
    free(h_image);
    
    free(h_covariance);
    
    status = cublasFree(d_image);
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! memory free error (image)\n");
        
        return EXIT_FAILURE;
        
    }
    
    status = cublasFree(d_covariance);
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! memory free error (covariance)\n");
        
        return EXIT_FAILURE;
        
    }
    
    /* Shutdown */
    
    status = cublasShutdown();
    
    if (status != CUBLAS_STATUS_SUCCESS) {
        
        fprintf (stderr, "!!!! shutdown error (A)\n");
        
        return EXIT_FAILURE;
        
    }
    
    fclose(fp1);
    
    fclose(fp2);
    
    printf("\nPress ENTER to exit...\n");
    
    getchar();
    
    return EXIT_SUCCESS;
    
}