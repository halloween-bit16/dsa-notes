#include <stdio.h>

void main(){
        printf("Enter number of elements in array: ");
        int n;
        scanf("%d", &n);
        int arr[n];
        printf("Enter array elements: ");
        for(int i=0; i<n; i++)  
            scanf("%d", &arr[i]);
        printf("Enter element to be searched: ");
        int key;
        scanf("%d", &key);

        for(int i=0; i<n; i++){
            if(arr[i] == key){
                printf("Element %d found at position %d\n", key, i+1);
                return;
            }
        } printf("Element %d not found in the array\n", key);
}
