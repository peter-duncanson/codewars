#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>


uint64_t hamber(int n)
{
    const uint64_t max_list = 20000;
    uint64_t nums[max_list];
    uint64_t i = 0, j = 0, k = 0;
    int index = 1;
    nums[0] = 1;

    while (index < n)
    {
        while ((nums[i] * 2) <= nums[index - 1]) i++;
        while ((nums[j] * 3) <= nums[index - 1]) j++;
        while ((nums[k] * 5) <= nums[index - 1]) k++;

        uint64_t temp = nums[i] * 2;
        if ((nums[j] * 3) < temp) temp = (nums[j] * 3);
        if ((nums[k] * 5) < temp) temp = (nums[k] * 5);
        nums[index] = temp;
        
        ++index;
    }

    return nums[n - 1];
}

int main(void)
{
    uint64_t ans = hamber(10);
    printf("%ld\n", ans);

    
    return 0;
}
