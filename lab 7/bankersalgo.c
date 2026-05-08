#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m];

    /* Input Allocation Matrix */                            
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    /* Input Maximum Matrix */
    printf("\nEnter Maximum Demand Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    /* Input Available Resources */
    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    /* Calculate Need Matrix */
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    /* Step 1: Initialize */
    int work[m], finish[n], safeSequence[n];

    for(i = 0; i < m; i++)
        work[i] = available[i];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    /* Step 2 and Step 3 */
    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                        break;
                }

                /* Process can execute */
                if(j == m)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        /* Step 4 */
        if(found == 0)
        {
            printf("\nSystem is in UNSAFE STATE\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE STATE\n");
    printf("Safe Sequence: ");

    for(i = 0; i < n; i++)
    {
        printf("P%d ", safeSequence[i]);
    }

    return 0;
}
