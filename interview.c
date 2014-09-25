#include <stdio.h>

int main(void)
{
    const int i = 0;
    int j;
    int *p = (int*)&i;
    *p = 1;
    j = i;  //此时的j为0,也就是说用i时，i表现的是初始化的值(c++和c编译器不同)，但实际i对应的内存中存放的值已经变成了1
    printf("%d %d %d i = %p *p = %p\n", i, j, *p, &i, p);  //结果居然是0 1

    return 0;
}
