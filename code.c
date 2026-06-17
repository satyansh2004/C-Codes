#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{

    int sum = 0;
    int *ptr = (int *)malloc(200);
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            sum = nums[i] + nums[j];
            if (sum == target)
            {
                *returnSize = 2;
                ptr[0] = i;
                ptr[1] = j;
                goto end;
            }
        }
        sum = 0;
    }
end:

    return ptr;
}
int main(void)
{
    int nums[] = {2, 3, 4};
    int numsSize = 4;
    int target = 18;
    int returnSize;

    for (int i = 0; i < 2; i++)
    {
        printf("\n%d is", twoSum(nums, numsSize, target, &returnSize)[i]);
    }
}