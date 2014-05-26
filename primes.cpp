#include <iostream>
#include <sys/times.h>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 100000000

bool prime[MAX];
int allCount = 0;
int cnt = 0;
int primeUse[MAX];

int PrimeOld()
{
	int i;

	cnt = 0;
	memset(prime, true, sizeof(prime));
	for (i = 2; i < MAX; i++)
	{
		if (prime[i])	
		{
			primeUse[cnt++] = i;
			for (int j = i + i; j < MAX; j += i)	
			{
				prime[j] = false;
				allCount++;
			}
		}
	}
}
int PrimeNew()
{
	int i;

	memset(prime, true, sizeof(prime));
	allCount = 0;
	cnt = 0;
	for (i = 2; i < MAX; i++)
	{
		if (prime[i])	
			primeUse[cnt++] = i;
		for (int j = 0; j < cnt && i * primeUse[j] < MAX; j++)
		{
			prime[i * primeUse[j]] = false;
			allCount++;
			if (i % primeUse[j] == 0)
				break;
		}
	}
}
int main()
{
	clock_t start, end;	
	cout << "Old Prime : " << endl;
	start = times(NULL);
	PrimeOld();
	end = times(NULL);
	cout << "times : " << (int)((end - start) / (double)sysconf(_SC_CLK_TCK) * 1000) << "ms" << endl;
	cout << "AllCount : " << allCount << endl;
	cout << "New Prime : " << endl;
	start = times(NULL);
	PrimeNew();
	end = times(NULL);
	cout << "times : " << (int)((end - start) / (double)sysconf(_SC_CLK_TCK) * 1000) << "ms" << endl;
	cout << "AllCount : " << allCount << endl;

}
