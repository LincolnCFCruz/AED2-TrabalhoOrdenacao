#include<stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2) 
{ 
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
  for (int i=0; i < size; i++){
    printf("%d\n", array[i]); 
    } 
} 
 
int main() {
  int i = 0;
  int n = 5;

  int *array = (int*)malloc(sizeof(int)*n);
  
  for(int i = 0; i < 5; i++) {
    scanf("%d", &array[i]);
  }

  bubbleSort(array, n); 
  printArray(array, n); 
  return 0; 
} 