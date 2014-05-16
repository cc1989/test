#include <stdio.h>
#include <string.h>


main()
{
	char s[] = "1234567890";
	char *p1 = s;
	char *p2 = s + 2;
	//memcpy(p2, p1, 10);  //出现问题
	memmove(p2, p1, 10);  //没问题
	printf("%s\n", p2);
}
