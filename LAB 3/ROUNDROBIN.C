#include <stdio.h>

struct process{
    int pid;
    int at,bt;
    int ct,tat,wt,rt;
    int remaining_bt;
    int first_exec
};
int main(){
    int n,tq,time=0,completed=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct process p[n];

    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter AT and BT for P%d: ", p[i].pid);
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].remaining_bt=p[i].bt;
        p[i].first_exec=-1;
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    while(completed<n) {
        int executed=0;

        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].remaining_bt>0) {

                if(p[i].first_exec==-1) {
                    p[i].rt=time-p[i].at;
                    p[i].first_exec=1;
                }

                if(p[i].remaining_bt>tq) {
                    time+=tq;
                    p[i].remaining_bt-=tq;
                } else{
                    time+=p[i].remaining_bt;
                    p[i].remaining_bt=0;

                    p[i].ct=time;
                    p[i].tat=p[i].ct-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;

                    completed++;
                }
                executed=1;
            }
        }

        if(!executed) {
            time++;
        }
    }

    float avg_tat=0,avg_wt=0,avg_rt=0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].at, p[i].bt,
            p[i].ct, p[i].tat, p[i].wt, p[i].rt);

        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
        avg_rt += p[i].rt;
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f", avg_wt / n);
    printf("\nAverage RT  = %.2f\n", avg_rt / n);

    return 0;
}
