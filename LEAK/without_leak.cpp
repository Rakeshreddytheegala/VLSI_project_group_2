#include <stdio.h>
#include "leak.h"
void mu(int a[1000])
{
	// original version
	int i,j;
	int b[1000];
	for(j = 0;j < 1000;j++)
	{
		b[j]=0;
	}
	for (i=0; i<32; i++)
	{
			for(j = 0;j < 1000;j++)
			{
				b[j] <<= 1;
			}
			for( j = 0;j < 1000; j++)
			{
				if(a[j]&1) b[j] |= 1;   // leaking
			}
			for(j=0;j<1000;j++)
			{
				a[j] >>=1;
			}
	}
	for(i=0;i<1000;i++)
	{
		a[i] = b[i];
	}
}


