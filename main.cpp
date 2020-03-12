#include<iostream>
using namespace std;



bool isPrime(int n);
void Eratosthenes(int a, int  b);
int highest_common_factor(int m, int n);




int main()
{

	int  a[10] = { 166,984,1124,1281,1338,2020,202003,20200310,1301,1601};
	int  b[10] = { 332,1038,1213,2019,2018,313,1601,1231,1373,1681};
	
	
	for (int i = 0; i <= 9; i++)
	cout<<'('<<a[i]<<','<<b[i]<<')'<<"的最大公因数为"<< highest_common_factor(a[i], b[i])<<'\n';

	return 0;
}



bool isPrime(int n)
{
	if (n <= 1)
		return false;
	else if (n == 2)
		return false;
	else if (n % 2==0)
		return false;
	else
		for (int i = 3; i * i <= n; i+=2)
			if (n % i==0)
				return false;
	return true;
}



void Eratosthenes(int a, int b)
{
	int number = b - a + 1;
	int *result = new int[number];
	for (int i = a; i <= b; i++)
		result[i - a] = i;
	for (int i = 2;  i * i <= b; i++)
		if(isPrime(i))
		for (int p = a; p <= b ; p++)
			if(result[p - a] % i == 0)
				result[p - a] = 0;
	for (int i = a; i <= b; i++)
		if (result[i - a] != 0)
			cout << result[i- a]<<'\t';



}

int  highest_common_factor(int m, int n)
{
	if (m < 0)
		m = -m;
	if (n < 0)
		n = -n;
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	int max = m > n ? m : n;
	int min = m < n ? m : n;
	int p = 0, r = 0;
	while (max % min != 0)
	{
		p = max / min;
		r = max - p * min;
		max = min;
		min = r;
	}
	return min;
}



