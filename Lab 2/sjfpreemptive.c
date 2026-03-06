#include <stdio.h>

struct process{
    int pid;
    int at;
    int bt;
    int rt_bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int st;
    int completed;
};

int main(){
    int n,i,time=0,completed=0,idx;
    float avg_tat=0,avg_wt=0,avg_rt=0;
    struct process p[20];

    printf("Enter num of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter AT and BT for process %d: ",p[i].pid);
        scanf("%d %d",&p[i].at,&p[i].bt);

        p[i].rt_bt=p[i].bt; 
        p[i].completed=0;
        p[i].st=-1; 
    }

    while(completed<n){
        int min_bt=9999;
        idx=-1;

        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].completed==0){
                if(p[i].rt_bt < min_bt && p[i].rt_bt>0){
                    min_bt=p[i].rt_bt;
                    idx=i;
                }
            }
        }

        if(idx!=-1){

            if(p[idx].st==-1){
                p[idx].st=time;
                p[idx].rt=p[idx].st-p[idx].at;
            }

            p[idx].rt_bt--;

            time++;

            if(p[idx].rt_bt==0){
                p[idx].ct=time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;

                avg_tat+=p[idx].tat;
                avg_wt+=p[idx].wt;
                avg_rt+=p[idx].rt;

                p[idx].completed=1;
                completed++;
            }
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

    avg_tat/=n;
    avg_wt/=n;
    avg_rt/=n;

    printf("\nAverage TAT = %.2f",avg_tat);
    printf("\nAverage WT = %.2f",avg_wt);
    printf("\nAverage RT = %.2f\n",avg_rt);

    return 0;
}
