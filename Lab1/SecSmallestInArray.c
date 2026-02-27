#include <stdio.h>
#include <limits.h>

int main(){

    int n, i;
    int arr[100];
    printf("Enter no of elemnets: ");
    scanf("%d", &n);
    printf ("Enter ur elements: ");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
int min=INT_MAX;
int smin=INT_MAX;
for (i=0;i<n;i++){
        if (arr[i]<min){
        smin=min;
        min=arr[i];}
        else if (arr[i]<smin && arr[i] >min) {
            smin= arr[i];
        }

}
    printf("The second smallest element is %d",smin);
    return 0;
}
