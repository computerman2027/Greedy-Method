#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int **arr, int n)
{
    int i, j;
    int *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if ((arr[j][2] > arr[j + 1][2]) || (arr[j][2] == arr[j + 1][2] && arr[j][1] > arr[j + 1][1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void activitySelector(int **arr, int n)
{
    sort(arr, n);
    int i = 0, m, k = 1;
    arr[i][3] = k;
    k++;
    for (m = 1; m < n; m++)
    {
        if (arr[m][1] >= arr[i][2])
        {
            i = m;
            arr[i][3] = k;
            k++;
        }
    }
}

int main()
{
    int n;
    printf("Enter number of activity : ");
    scanf("%d", &n);

    int **activities;
    activities = (int **)malloc(n * sizeof(int *));

    int i, j;
    for (i = 0; i < n; i++)
    {
        activities[i] = (int *)malloc(4 * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        activities[i][0] = i;
        activities[i][3] = 0;
        printf("Enter Start Time : ");
        scanf("%d", &activities[i][1]);
        printf("Enter End Time : ");
        scanf("%d", &activities[i][2]);
    }

    activitySelector(activities, n);

    int *ans = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        ans[activities[i][0]] = activities[i][3];
    }

    printf("Ans Vector : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}