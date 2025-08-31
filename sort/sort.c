#include <stdio.h>

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }   
        }
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIdx = i;

        for(int j=i+1;j<n;j++){
            if( arr[minIdx] > arr[j]){
                minIdx = j;
            }
        }

        if ( minIdx != i){
            int t=arr[i];
            arr[i]=arr[minIdx];
            arr[minIdx]=t;
        }
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key =arr[i];
        int j=i-1;

        if ( arr[j] > key && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        }
}

void main(){
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0; i<n; i++){ 
        scanf("%d", &arr[i]);
    }

    printf("Enter 1 for bubble sort, 2 for selection sort, 3 for insertion sort: ");
    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1: bubbleSort(arr, n);
                break;
        case 2: selectionSort(arr, n);
                break;     
        case 3: insertionSort(arr, n);
                break;
        default: printf("Invalid choice");
                 return;
    }

    printf("Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

}