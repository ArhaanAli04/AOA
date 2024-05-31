#include<stdio.h>
void printArray(int A[],int n){
    int b;
    printf("\nThe array is given by: ");
    for(b=0;b<n;b++){
        printf("%d ",A[b]);
    }
}
int partition(int A[],int low, int high){
    int pivot=A[low]; //set pivot element = first element of the array
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            //swap A[i] and A[j]
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    //swap A[low] and A[j]
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}
void QuickSort(int A[],int low,int high){
    int p;
    if(low<high){
        p=partition(A,low,high);
        QuickSort(A,low,p-1);
        QuickSort(A,p+1,high);
    }
}
int main(){
    int n,a;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter the elements:");
    for(a=0;a<n;a++){
        scanf("%d",&A[a]);
    }
    printArray(A,n);
    QuickSort(A,0,n-1);
    printArray(A,n);
    return 0;
}