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

for (i=0;i<n;i++){
        int sum=0;
            for (j=0;j<n;j++){
                    sum+=arr[i][j];}
            printf("Sum of row %d is %d\n", i+1,sum);

}

for (j=0;j<n;j++){
        int sum=0;
            for (i=0;i<n;i++){
                    sum+=arr[i][j];}
            printf("Sum of column %d is %d\n", j+1,sum);

}
}
