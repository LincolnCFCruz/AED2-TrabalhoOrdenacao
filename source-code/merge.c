#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r){
    if (l < r) {

        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    int n;
    int menor = INT_MAX;
    int maior = INT_MIN;
    int *v;
    int i;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
    
    v = (int *)malloc(n * sizeof(int*));
    
    for (i = 0; i < n; ++i) {
      v[i] = rand () % 10;
      if(v[i] < menor) {
        menor = v[i];
      }
      if(v[i] > maior) {
        maior = v[i];
      }
    } 
    
    printArray(v, n);

    mergeSort(v, 0, n - 1);

    printf("\nResolvido \n");
    
    printArray(v, n);

    free(v);
}