#include <stdio.h>

int main()
{
    int a, b;
    double ans;
    scanf("%d%d", &a, &b);

    ans = (double)a/b;
    printf("%.2lf", ans);
    return 0;
}