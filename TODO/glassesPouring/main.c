#include <stdio.h>
int gcd(int a, int b)
{
	while(b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		if(a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		if(c > a && c > b)
		{
			printf("%d\n",-1);
			continue;
		}
		if(a == c || b == c)
		{
			printf("%d\n",1);
			continue;
		}
		if(c == 0)
		{
			printf("0\n");
			continue;
		}
		int g = gcd(a,b);
		if(c % g != 0)
		{
			printf("%d\n",-1);
			continue;
		}
		int count = 0, altCount = 0;
		int firstBucket = 0, secondBucket = 0;
		int altFirstBucket = 0, altSecondBucket = 0;
		while(firstBucket != c && secondBucket != c && altFirstBucket != c && altSecondBucket != c)
		{
			if(altFirstBucket == 0)
			{
				altFirstBucket = b;
				altCount++;
			}
			else if(altSecondBucket == a)
			{
				altSecondBucket = 0;
				altCount++;
			}
			else
			{
				int rem = a - altSecondBucket;
				altFirstBucket -= rem;
				altSecondBucket = a;
				if(altFirstBucket < 0)
				{
					altSecondBucket += altFirstBucket;
					altFirstBucket = 0;
				}
				altCount++;
			}
			if(firstBucket == 0)
			{
				firstBucket = a;
				count++;
			}
			else if(secondBucket == b)
			{
				secondBucket = 0;
				count++;
			}
			else
			{
				int rem = b - secondBucket;
				firstBucket -= rem;
				secondBucket = b;
				if(firstBucket < 0)
				{
					secondBucket += firstBucket;
					firstBucket = 0;
				}
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
