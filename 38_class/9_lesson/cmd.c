#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("This is My CMD!\n");
    printf("My ENV: %s\n", getenv("MYENV"));
    return 0;
}
