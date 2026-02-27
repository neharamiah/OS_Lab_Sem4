#include <stdio.h>
#include <limits.h>

int main(){

    int n, i,pos;
    int arr[100];
    printf("Enter no of elemnets: ");
    scanf("%d", &n);
    printf ("Enter ur elements: ");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
printf("Enter pos of element to delete: ");
scanf("%d", &pos);
for (i=pos-1;i<n;i++){
        arr[i]=arr[i+1];
        }


    printf("The updated array is: ");
    for (i=0;i<n-1;i++){
        printf("%d ,",arr[i]);
    }
    return 0;
}
