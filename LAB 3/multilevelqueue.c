#include <stdio.h>
#include <string.h>

struct process{
    int pid;
    int at, bt;
    int ct, tat, wt, rt;
    int remaining_bt;
    int first_exec;
    int pri;
    char type[10];
};

int main(){
    int n,time=0,completed=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct process p[n];


    for(int i=0;i<n;i++){
        p[i].pid = i+1;
        printf("Enter AT, BT and PRI(1=system,2=user) for P%d: ", p[i].pid);
        scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pri);

        p[i].remaining_bt=p[i].bt;
        p[i].first_exec = -1;
if (p[i].pri == 1)
    strcpy(p[i].type, "system");
else
    strcpy(p[i].type, "user");
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].at > p[j].at){
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }


    while(completed < n){
        int idx = -1;

        for(int i=0;i<n;i++){
            if(p[i].at <= time && p[i].remaining_bt > 0 && p[i].pri == 1){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            for(int i=0;i<n;i++){
                if(p[i].at <= time && p[i].remaining_bt > 0 && p[i].pri == 2){
                    idx = i;
                    break;
                }
            }
        }

        if(idx == -1){
            time++;
            continue;
        }


        if(p[idx].first_exec == -1){
            p[idx].rt = time - p[idx].at;
            p[idx].first_exec = 1;
        }


        p[idx].remaining_bt--;
        time++;

        if(p[idx].remaining_bt == 0){
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }
    }

    float avg_tat=0,avg_wt=0,avg_rt=0;

    printf("\nPID\tTYPE\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%s\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,p[i].type,p[i].at, p[i].bt,
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
