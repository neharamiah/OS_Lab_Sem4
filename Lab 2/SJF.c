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
    int completed;
};

int main(){
    int n,i,time=0,completed=0,idx;
    struct process p[20];
    printf("Enter num of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter AT and BT for process %d: ",p[i].pid);
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].completed=0;
    }

    while(completed<n){
        int min_bt=9999;
        idx=-1;
        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].completed==0){
                if(p[i].bt<min_bt){
                    min_bt=p[i].bt;
                    idx=i;
                }
            }
        }
        if(idx!=-1){
            p[idx].st=time;
            p[idx].ct=p[idx].st+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            p[idx].rt=p[idx].st-p[idx].at;

            time=p[idx].ct;
            p[idx].completed=1;
            completed++;
        }
        else{
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }

    return 0;
}

