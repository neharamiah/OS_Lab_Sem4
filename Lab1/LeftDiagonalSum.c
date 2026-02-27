#include <stdio.h>

int main(){

    int n, i,j;
    int arr[100][100];
    printf("Enter dim of matrix: ");
    scanf("%d", &n);
    printf ("Enter ur elements: ");
    for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                    scanf("%d",&arr[i][j]);
            }
    }
int sum=0;
for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                    if (i==j)
                    sum+=arr[i][i];
}}
    printf("The sum of left diagonal is %d",sum);
    return 0;
}
