#include<stdio.h>
int BinarySearch(int A[],int low,int high,int key){
    int mid;
    
    
    while(low<=high){
        mid=low +(high-low)/2;
    if(A[mid]==key){
        printf("\nElement found");
        return mid;

    }else if(A[mid]>key){
        high=mid-1;
    }else if(A[mid]<key){
        low=mid+1;
    }else{
        printf("Element not found");
    }
    }
}


void printArray(int A[],int n){
    printf("\nThe array is given by:");
    for(int b=0;b<n;b++){
        printf("%d ",A[b]);
    }
}
int main(){
    int n,a;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    
    int A[n];
    printf("\nEnter the elements in Sorted order :");
    for(a=0;a<n;a++){
        scanf("%d",&A[a]);
    }
    int key;
    printf("Enter the element to be found:");
    scanf("%d",&key);
    printArray(A,n);
    int index=BinarySearch(A,0,n-1,key);
    printf("\nThe element was found at the index %d",index);
    

    return 0;
}