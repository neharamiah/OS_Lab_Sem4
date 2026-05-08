#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m], request[n][m];
    int available[m];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    int work[m], finish[n];

    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    for(i = 0; i < n; i++)
    {
        int flag = 0;

        for(j = 0; j < m; j++)
        {
            if(allocation[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
            finish[i] = 0;
        else
            finish[i] = 1;
    }

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            for(j = 0; j < m; j++)
            {
                if(request[i][j] > work[j])
                    break;
            }

            if(j == m)
            {
                for(k = 0; k < m; k++)
                {
                    work[k] += allocation[i][k];
                }

                finish[i] = 1;

                i = -1;
            }
        }
    }

    int deadlock = 0;

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            printf("Process P%d is deadlocked\n", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
    {
        printf("\nNo Deadlock Detected\n");
    }

    return 0;
}                                                                  
