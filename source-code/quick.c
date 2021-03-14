#include<stdio.h>
#include<stdlib.h>

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int partition (int arr[], int low, int high) { 
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) { 
        if (arr[j] < pivot) { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
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

  quickSort(vetor, 0, n-1); 
  
  printf("\nResolvido \n");
  printArray(vetor, n); 

  return 0; 
} 