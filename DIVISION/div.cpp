#include <stdio.h>
#include "ap_cint.h"
#include "division.h"

int val1 = 0x2;
int val2 = 0x20;
int val3 = 0x200;
int val4 = 0x2000;
int val5 = 0x20000;
int val6 = 0x200000;
//int j = 1;
int find_subclass(int l)
{
	int clas = l <= 0x2 ? 1 : l <= 0x20 ? 2 : l <= 0x200 ? 3 : l<= 0x2000 ? 4 : l <= 0x20000 ? 5 : 6;
	return clas;
}
int find_class(int dividend, int divisor)
{
	int clas1 = find_subclass(dividend);
	int clas2 = find_subclass(divisor);
	return max(clas1,clas2);
}
int custom_div(int dividend, int divisor)
{
	int clas = find_class(dividend,divisor);
	if (clas == 1)
	{
		int3 var1 = dividend;
		int3 var2 = divisor;
		return var1/var2;
	}
	else if(clas == 2)
	{
		int7 var1 = dividend;
		int7 var2 = divisor;
		return var1/var2;
	}
	else if(clas == 3)
	{
		int11 var1 = dividend;
		int11 var2 = divisor;
		return var1/var2;
	}
	else if(clas == 4)
	{
		int15 var1 = dividend;
		int15 var2 = divisor;
		return var1/var2;
	}
	else if(clas == 5)
	{
		int20 var1 = dividend;
		int20 var2 = divisor;
		return var1/var2;
	}
	else
	{
		int var1 = dividend;
		int var2 = divisor;
		return var1/var2;
	}
}
int fixed_time(int dividend,int divisor)
{
	return dividend/divisor;
}
int six_div(int dividend,int divisor)
{
	int clas = find_class(dividend,divisor);
	int result1;
	int result2;
	int result3;
	int result4;
	int result5;
	int result6;
	result1 = clas == 1 ? custom_div(dividend,divisor) : custom_div(val1,val1);
	result2 = clas == 2 ? custom_div(dividend,divisor) : custom_div(val2,val2);
	result3 = clas == 3 ? custom_div(dividend,divisor) : custom_div(val3,val3);
	result4 = clas == 4 ? custom_div(dividend,divisor) : custom_div(val4,val4);
	result4 = clas == 5 ? custom_div(dividend,divisor) : custom_div(val5,val5);
	result4 = clas == 6 ? custom_div(dividend,divisor) : custom_div(val6,val6);
	int quo;
	quo = clas == 1 ? result1 : clas == 2 ? result2 : clas == 3 ? result3 : clas == 4 ? result4 : clas == 5 ? 5 : 6;
	return quo;

}
int loop1(int l, int p)
{
	for(int i = 0; i < p ; i++)
	{
		l = l * l;
	}
	return l;
}
int fun1(int dividend,int divisor)
{
	return custom_div(dividend,divisor);
}
int parallel_div(int dividend,int divisor)
{
//	#pragma HLS dataflow
	int quotient = fun1(dividend,divisor);
	int tmp1 = loop1(1,1000);
	quotient = quotient * tmp1;
	return quotient;
}
int mul(int x, int y, int mod)
{
	int p = x * y;
	int l = six_div(p,mod);
	int r = p - mod*l;
	return r;
}

int divide(int a, int b,int * c)
{
    *c = custom_div(a,b);
	return 0;
}
