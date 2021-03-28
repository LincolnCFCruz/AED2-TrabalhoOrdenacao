#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) {
    int  j, min_idx; 
   
    for (int i = 0; i < n-1; i++) {  
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
 
        swap(&arr[min_idx], &arr[i]); 
    } 
}
  
void heapSort(int arr[], int n) {
  int contagem=0;
  for (int i = n / 2 - 1; i >= 0; i--){
    selectionSort(arr, n);
  }
  
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    selectionSort(arr, i);
  }
}
void printArray(int *array, int size) { 
    int i;
    for (i = i; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
} 

void printArrayInv(int *array, int size) { 
    int i;
    for (i = size-1; i >= 0; i--){
        printf("%d ", array[i]);
    }
    printf("\n");
} 
 
int main() {
  int n;
    
  printf("Entre com o tamanho do vetor: ");
  scanf("%d", &n);

  int *vetor = (int*)malloc(sizeof(int)*n);
  
  for(int i = 0; i < n; i++) {
    vetor[i] = rand () % 10;
  }

  printArray(vetor, n); 
 
  heapSort(vetor, n);
 
  printf("\nResolvido \n");
  printArray(vetor, n); 
  printf("\nResolvido invertido \n");
  printArrayInv(vetor, n); 
  return 0; 
}