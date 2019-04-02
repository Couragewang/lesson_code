#include <stdio.h>

int mysum(int top_)
{
    int sum = 0;
    int i = 1;
    for(; i <= top_; i++){
        sum += i;
        printf("current sum is : %d\n", sum);
    }
    return sum;
}

int main()
{
    printf("gdb begin!\n");
    int top = 100;
    int res = mysum(top);
    printf("result: %d\n", res);
    return 0;
}
