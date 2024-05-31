#include<stdio.h>
void printArray(int A[],int n){
    int b;
    printf("\nThe array is given by:");
    for(b=0;b<n;b++){
        printf("%d ",A[b]);

    }
}

void Selectionsort(int A[],int n){
    int i,j,indexofmin,temp;
    for(i=0;i<n;i++){
        indexofmin=i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[indexofmin]){
                indexofmin=j;
            }
            
        }
        temp=A[i];
        A[i]=A[indexofmin];
        A[indexofmin]=temp;
    }
}
int main(){
    int a,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter the elements :");
    for(a=0;a<n;a++){
        scanf("%d",&A[a]);

    }
    printArray(A,n);
    Selectionsort(A,n);
    printArray(A,n);
    return 0;
}