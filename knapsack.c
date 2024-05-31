#include<stdio.h>
#define max_items 100
#define max_weight 100
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int knapsack(int weights[],int values[],int n,int capacity){
    int i,j;
    int dp[max_items+1][max_weight+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(weights[i-1]<=j){
                dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];

}
int main(){
    int n;
    printf("Enter the number of items:");
    scanf("%d",&n);
    int weights[n];
    printf("\nEnter the weights: ");
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    int values[n];
    printf("\nEnter the values/profits: ");
    for(int i=0;i<n;i++){
        scanf("%d",&values[i]);
    }
    int capacity;
    printf("\nEnter the capacity: ");
    scanf("%d",&capacity);

    int max_value=knapsack(weights,values,n,capacity);
    printf("The maximum value of the Knapsack is: %d",max_value);
    return 0;
}