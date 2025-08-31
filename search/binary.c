#include <stdio.h>

int binarySearch(int arr[], int n, int key, int low, int high){
    while(low<high){
      int mid = low + (high - low)/2;
      if(arr[mid]==key)
        return mid;
      else if (arr[mid]>key)
        high = mid-1;
      else 
        low = mid+1;
       }
         return -1;
    }

void main(){
    printf("Enter number of elements in array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0; i<n; i++)  
        scanf("%d", &arr[i]);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Enter element to be searched: ");
    int key;
    scanf("%d", &key);

    int result = (int)binarySearch(arr, n, key, 0, n-1);
    if(result == -1)
        printf("Element %d not found in the array\n", key);
    else
        printf("Element %d found at position %d\n", key, result+1);
}
