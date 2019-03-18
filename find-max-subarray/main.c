#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int array[20][100000];

static int
find_max_crossing_subarray(int array[], int start, int mid, int end, int *left_index, int *right_index)
{
    *left_index = -1;
    *right_index = -1;
    int left_max = INT_MIN;
    int right_max = INT_MIN;
    int sum = 0;
    int left_sum = 0;
    int right_sum = 0;
    int i;

    for (i = mid; i >= start; i--)
    {
        sum += array[i];
        if (sum >= left_max)
        {
           *left_index = i;
           left_max = sum;
        }
    }
    left_sum = left_max;

    sum = 0;
    for (i = mid + 1; i <= end; i++)
    {
        sum += array[i];
        if (sum > right_max)
        {
           *right_index = i;
           right_max = sum;
        }
    }
    right_sum = right_max;

    return (left_sum + right_sum); 
}

static int
find_max_subarray(int array[], int start, int end, int *left_index, int *right_index)
{
    if (start == end)
    {
        *left_index = start;
        *right_index = end;
        return (array[start]);
    }
    
    int left_low, left_hight, left_sum;
    int right_low, right_hight, right_sum;
    int crossing_low, crossing_hight, crossing_sum;

    int mid = (end + start) / 2;
    left_sum = find_max_subarray(array, start, mid, &left_low, &left_hight);
    right_sum = find_max_subarray(array, mid + 1, end, &right_low, &right_hight);
    crossing_sum = find_max_crossing_subarray(array, start, mid, end, &crossing_low, &crossing_hight);

    if (left_sum >= crossing_sum && left_sum >= right_sum)
    {
        *left_index = left_low;
        *right_index = left_hight;
        return (left_sum);
    }
    else if (crossing_sum >= left_sum && crossing_sum >= right_sum)
    {
        *left_index = crossing_low;
        *right_index = crossing_hight;
        return (crossing_sum);
    }
    else
    {
        *left_index = right_low;
        *right_index = right_hight;
        return (right_sum);
    }
}

int main(void)
{
    int i = 0;
    int count;
    scanf("%d", &count);
    while (i < count)
    {
        int j = 0;
        scanf("%d", &array[i][j]);
        while ((++j) <= array[i][0])
        {
            scanf("%d", &array[i][j]);
        }

        int left_index;
        int right_index;
        int sum;
        sum = find_max_subarray(array[i], 1, array[i][0], &left_index, &right_index);
        printf("Case %d:\n", i + 1);
        printf("%d %d %d\n\n", sum, left_index, right_index);
        i++;
    }
    return (0);
}
