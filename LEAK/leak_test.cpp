#include <iostream>
#include "leak.h"
using namespace std;

int main(int argc, char **argv)
{
	int a[1000];
	for(int i = 0; i < 1000;i++)
	{
		a[i] = 0;
	}
   mu(a);
   return 0;
}

