#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void printArray(int *array, int size) { 
    int i;
    for (i = 0; i < size; i++){
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

  insertionSort(vetor, n); 
  
  printf("\nResolvido \n");
  printArray(vetor, n); 
  return 0; 
} 