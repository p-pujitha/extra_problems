/*5.Given three numbers n1,n2,and r. Merge the table of n1 and n2 and find the r th number. In merging it should eliminate duplicate values (tables consists the multiples of those numbers ,ie 3 contains 3,6,9,12..)
Ex , n1=3 ,n2=5 and r=5, The merged table is 3,5,9,10,12,15(One more 15 is removed as its duplicate ) 18,20,21,24,25........so on .
The rth num ie 5th number is 12 ,so OP is 12*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int lcm(int , int );
int gcd(int, int );
int find_kthvalue(int , int , int );
int merge(int , int , int );
void dotest();

struct testcases
{
	int n1;
	int n2;
	int K;
	int output;
}testcases[5] = {
	{3 , 5, 7, 18},
	{0, 1, 8, 9}, 
	{0, 0, 45, 0}, 
	{25, 5, 14, 75},
	{1, 2, -5, 0}
};


int find_kthvalue(int a, int b, int k)
{
	int i, j, ncp, cp, LCM, index_of_cp, after_cp, temp, sum = 0;
	int add;

	if (k < 0)
		return 0;

	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	if (a == 0 && b != 0)
		a = b;
	else if (a != 0 && b == 0)
		b = a;
	else if (a == 0 && b == 0)
		return 0;

	LCM = lcm(a, b);

	cp = (LCM / a) + (LCM / b) - 1;

	ncp = k / cp;
	after_cp = (k + 1) % cp;
	index_of_cp = ncp*cp - 1;
	add = merge(a, b, after_cp);

	if (after_cp == 0)
		sum = (ncp + 1)*LCM;
	else
		sum = ncp*LCM + add;
	return sum;
	

}

int lcm(int x, int y)
{
	int i, GCD, temp, ans = 1;

	GCD = gcd(x, y);
	if (GCD == 1)
		return ans*x*y;
	else if (GCD == 0)
		return 0;
	else
	{
		x = x / GCD;
		y = y / GCD;
		ans = GCD*lcm(x, y);
	}


	return ans;
}


int gcd(int x, int y)
{
	int temp, flag = 1, div, diff;

	while (flag)
	{
		if (x == 0)
		{
			return 0;
			break;
		}
		div = y / x;
		diff = y - (x*div);
		if (diff == 0)
		{
			flag = 0;
			return x;
		}
		y = x;
		x = diff;
	}

}

void main()
{
	dotest();
	_getch();
}

int merge(int x, int y, int k)
{
	int count = 0, temp, i, mul_x = x, mul_y = y, mul = x;

	for (i = 0; i < k; i++)
	{
		if (mul_x < mul_y)
		{
			mul = mul_x;
			mul_x = mul_x + x;
		}
		else if (mul_x > mul_y)
		{
			mul = mul_y;
			mul_y = mul_y + y;
		}
		else
		{
			mul = mul_x;
			mul_x = mul_x + x;
			mul_y = mul_y + y;
		}

	}
	return mul;
}


void dotest()
{
	
	for (int i = 0; i < 5; i++)
	{
		if (find_kthvalue(testcases[i].n1, testcases[i].n2, testcases[i].K) == testcases[i].output)
			printf("TESTCASE %d ->valid\n", i + 1);
		else
			printf("TESTCASE %d ->Invalid\n", i + 1);
	}
}





