#include <stdio.h>

int main(){
    int n,i,j,count=0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    int status[n];

    printf("Enter %d elements: ", n);
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
        status[i]=0;
    }

    for (i=0;i<n;i++){
        if (status[i]==1) {
            continue;
        }
        for (j=i+1;j<n;j++) {
            if (arr[i]==arr[j]) {
                count++;
                status[j]=1;
            }
        }
    }

    printf("Total number of duplicate elements: %d\n", count);

    return 0;
}
