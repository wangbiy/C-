#include <stdio.h>
#include <Windows.h>
#include <math.h>
#if 0
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 100; i <= 200; ++i)
	{
		for (j = 2; j < i; ++j)
		{
			if (i%j == 0)
				break;
		}
		if (j == i)
		{
			printf("%d是素数\n", i);
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 101; i <= 200; i += 2)
	{
		for (j = 2; j < i; ++j)
		{
			if (i%j == 0)
				break;
		}
		if (j == i)
		{
			printf("%d是素数\n", i);
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 101; i <= 200; i+=2)
	{
		for (j = 2; j < i / 2; j++)
		{
			if (i%j == 0)
				break;
		}
		if (j == i / 2)
		{
			printf("%d是素数\n", i);
			count++;
		}
		
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; ++i)
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)
				break;
		}
		if (j>sqrt(i))
		{
			printf("%d是素数\n", i);
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 101; i < 200; i += 2)
	{
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)
				break;
		}
		if (j>sqrt(i))
		{
			printf("%d是素数\n", i);
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif
int main()
{
	int i = 9;
	int j = 0;
	int arr[100];
	int count = 0;
	for (i = 0; i < 100; ++i)
	{
		arr[i] = i + 1;
	}
	for (i = 0; i < 100; ++i)
	{
		j = i - 1;//空过0、1、2
		while (j>1)
		{
			if (arr[i] % j == 0)
				arr[i] = 0;
			j = j - 1;
		}
	}
	for (j = 1; j < 100; ++j)
	{
		if (arr[j] != 0)
		{
			printf("%d是素数\n", arr[j]);
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}