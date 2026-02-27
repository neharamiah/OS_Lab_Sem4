#include <stdio.h>

int main(){

    int n, i;
    int arr[100];
    printf("Enter no of elemnets: ");
    scanf("%d", &n);
    printf ("Enter ur elements: ");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
int max=arr[0];
int smax=arr[0];
for (i=0;i<n;i++){
        if (arr[i]>max){
        smax=max;
        max=arr[i];}
        else if (arr[i] > smax && arr[i] < max) {
            smax = arr[i];
        }

}
    printf("The second greatest element is %d",smax);
    return 0;
}
