/*
 * Find the sum of the digits of all the numbers from 1 to N
 * (both ends included)
 */

int compute_sum(int n)
{
    int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        int currentNumber = i;

        while(currentNumber >= 1)
        {
            sum += currentNumber % 10;
            currentNumber /= 10;
        }
    }
    return sum;
}


/*
 * take number, figure out how many times its divisible by 10
 * follow below pattern
 *      start at 45
 *      add 10 to this every 10
 *      when 100
 *      start at 55
 *      repeat every 100
 * */
/* * * * * * * * *
 *  0-9  -> 45   *
 * 10-19 -> 55   *
 * 20-29 -> 65
 * 30-39 -> 75
 * 40-49 -> 85
 * 50-59 -> 95
 * 60-69 -> 105
 * 70-79 -> 115
 * 80-89 -> 125
 * 90-99 -> 135     1-99 ----> 900
 * 100-109 -> 55
 * 65
 * 75
 * 85
 * 95
 * 105
 * 115
 * 125
 * 135
 * 145
 * 155 100-199 ----> 1000
 * 65
 * . . .
 * 225
 * 55
 * 
 * */
