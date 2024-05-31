#include<stdio.h>
void Merge(int A[], int mid, int low, int high){
    int B[100];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid &&j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            k++;
            i++;
        }else{
            B[k]=A[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high){
        B[k]=A[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        A[i]=B[i];
    }
}

void MergeSort(int A[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,mid,low,high);

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
    printf("\nEnter the elements :");
    for(a=0;a<n;a++){
        scanf("%d",&A[a]);
    }
    printArray(A,n);
    MergeSort(A,0,n-1);
    printArray(A,n);
    return 0;
}