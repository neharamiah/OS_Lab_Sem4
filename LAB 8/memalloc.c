#include<stdio.h>

void firstFit(int b[],int m,int p[],int n){
    int a[n],used[m];

    for(int i=0;i<n;i++)
        a[i]=-1;

    for(int i=0;i<m;i++)
        used[i]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!used[j]&&b[j]>=p[i]){
                a[i]=j;
                used[j]=1;
                break;
            }
        }
    }

    printf("\n--- First Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t",i+1,p[i]);

        if(a[i]!=-1)
            printf("%d\n",a[i]+1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int b[],int m,int p[],int n){
    int a[n],used[m];

    for(int i=0;i<n;i++)
        a[i]=-1;

    for(int i=0;i<m;i++)
        used[i]=0;

    for(int i=0;i<n;i++){
        int best=-1;

        for(int j=0;j<m;j++){
            if(!used[j]&&b[j]>=p[i]){
                if(best==-1||b[j]<b[best])
                    best=j;
            }
        }

        if(best!=-1){
            a[i]=best;
            used[best]=1;
        }
    }

    printf("\n--- Best Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t",i+1,p[i]);

        if(a[i]!=-1)
            printf("%d\n",a[i]+1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int b[],int m,int p[],int n){
    int a[n],used[m];

    for(int i=0;i<n;i++)
        a[i]=-1;

    for(int i=0;i<m;i++)
        used[i]=0;

    for(int i=0;i<n;i++){
        int worst=-1;

        for(int j=0;j<m;j++){
            if(!used[j]&&b[j]>=p[i]){
                if(worst==-1||b[j]>b[worst])
                    worst=j;
            }
        }

        if(worst!=-1){
            a[i]=worst;
            used[worst]=1;
        }
    }

    printf("\n--- Worst Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t",i+1,p[i]);

        if(a[i]!=-1)
            printf("%d\n",a[i]+1);
        else
            printf("Not Allocated\n");
    }
}

int main(){
    int m,n;

    printf("Enter number of memory blocks: ");
    scanf("%d",&m);

    int b[m];

    printf("Enter sizes of %d memory blocks:\n",m);

    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int p[n];

    printf("Enter sizes of %d processes:\n",n);

    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);

    firstFit(b,m,p,n);
    bestFit(b,m,p,n);
    worstFit(b,m,p,n);

    return 0;
}
