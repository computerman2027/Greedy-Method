#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct object
{
    int weight;
    int profit;
    float profitPerWeight;
    int index;
    float contribution;
} Obj;

void sort(Obj *arr, int n)
{
    int i, j;
    Obj temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].profitPerWeight < arr[j + 1].profitPerWeight)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int knapsack(Obj *arr, int n, float maxw)
{
    sort(arr, n);
    int i;
    for (i = 0; i < n; i++)
    {
        if (maxw / arr[i].weight >= 1)
        {
            arr[i].contribution = 1;
            maxw -= arr[i].weight;
        }
        else
        {
            arr[i].contribution = maxw / arr[i].weight;
            maxw = 0;
        }
        if (maxw == 0)
            return 0;
    }
    return -1;
}

int main()
{
    int n, i;
    float maxweight;
    printf("Enter total number of object : ");
    scanf("%d", &n);

    Obj *objs = (Obj *)malloc(n * sizeof(Obj));

    printf("Enter data for each objects : ");

    for (i = 0; i < n; i++)
    {
        printf("Enter weight : ");
        scanf("%d", &objs[i].weight);
        printf("Enter profit : ");
        scanf("%d", &objs[i].profit);
        objs[i].index = i;
        // objs[i].profitPerWeight=((double)objs[i].profit)/((double)objs[i].weight);
    }

    printf("enter max weight of knapsack : ");
    scanf("%f", &maxweight);

    int result = knapsack(objs, n, maxweight);

    if (result == -1)
    {
        printf("Not possible\n");
    }
    else
    {
        float *ans = (float *)calloc(n, sizeof(float));
        for (i = 0; i < n; i++)
        {
            ans[objs[i].index] = objs[i].contribution;
        }
        printf("Ans vector : ");
        for (i = 0; i < n; i++)
        {
            printf("%f ", ans[i]);
        }
    }
    return 0;
}