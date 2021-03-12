#include<stdio.h>
#include<stdlib.h>

void swap(int *n1, int *n2) { 
    int temp = *n1; 
    *n1 = *n2; 
    *n2 = temp; 
} 
  
void bubbleSort(int *array, int n) { 
  for (int i = 0; i < n-1; i++){         
    for (int j = 0; j < n-i-1; j++)  {
      if (array[j] > array[j+1]) {
        swap(&array[j], &array[j+1]); 
      }
    }
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

  bubbleSort(vetor, n); 
  
  printf("\nResolvido \n");
  printArray(vetor, n); 
  return 0; 
} 
