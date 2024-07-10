/*
Coded by Nick Newman
7/9/24
Summer 24
Comp Sci 1
Dr. Tanvir Ahmed
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size){ 
  
  for(int i = 0; i < size-1; i++)
    printf("%d, ", arr[i]);

  printf("%d\n", arr[size-1]);
  printf("\n");
}

void merge(int a[], int l, int mid, int r){
  
  int i, j, k;

  int n1 = mid-l+1;
  int n2 = r - mid;

  int* L = malloc(n1 * sizeof(int));
  int* R = malloc(n2 * sizeof(int));

  for(i = 0; i<n1; i++){

    L[i] = a[l+i];
        
  }

  for(j = 0; j<n2; j++){

    R[j] = a[mid + 1 + j];
    
  }

  i = 0;
  j = 0;
  k = l;

  while(i<n1 && j<n2){

      if(L[i] < R[j]){
  
        a[k] = L[i];
        i++;
        k++;
        
      }
      else{
  
        a[k] = R[j];
        j++;
        k++;
        
      }
  }

  while(i < n1){

    a[k] = L[i];
    i++;
    k++;
    
  }

  while(j < n2){

    a[k] = R[j];
    j++;
    k++;
  
  }

  free(L);
  free(R);

  
}


void mergeSort(int a[], int l, int r){

  if(r>l)
  {
      
    int mid = (l+r) / 2;
  
    
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, r);
  
    merge(a, l, mid, r);
  
  }
    
}



int main(void) {

  int n = 500;
  int a[n];
  for(int i = 0; i < n; i++){
    a[i] = (rand() % 100) + i;
  }
  
  printArray(a, n);
  mergeSort(a, 0, n-1);
  printArray(a, n);

  
  return 0;
}