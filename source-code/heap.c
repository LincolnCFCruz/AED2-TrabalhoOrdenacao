#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void heapify(int arr[], int n, int i) {
  int max = i;
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;
  
  if (leftChild < n && arr[leftChild] > arr[max]) {
    max = leftChild;
  }
  
  if (rightChild < n && arr[rightChild] > arr[max]) {
    max = rightChild;
  }
  
  if (max != i) {
    swap(&arr[i], &arr[max]);
    heapify(arr, n, max);
  }
}
  
void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--){
    heapify(arr, n, i);
  }
  
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
  
    heapify(arr, i, 0);
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
 
  heapSort(vetor, n);
 
  printf("\nResolvido \n");
  printArray(vetor, n); 
  return 0; 
}