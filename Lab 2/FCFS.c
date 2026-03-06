#include <stdio.h>
struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int st;
};

int main(){
    int n,i,j;
    struct process p[20],temp;
    printf("Enter num of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter AT and BT for process %d: ",p[i].pid);
        scanf("%d %d",&p[i].at,&p[i].bt);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].at>p[j].at){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    p[0].st=p[0].at;
    p[0].ct=p[0].at+p[0].bt;
    for(i=1;i<n;i++){
        if(p[i].at>p[i-1].ct)
            p[i].st=p[i].at;
        else
            p[i].st=p[i-1].ct;
        p[i].ct=p[i].st+p[i].bt;
    }

    for(i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        p[i].rt=p[i].st-p[i].at;
    }

    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    return 0;
}






