#include <iostream>
using namespace std;
int fibonassi_period()
{
	long long n=10;
	int a=0,b=1,c=a+b;
	for(int i=0; i<n*n; i++)
	{
		c=(a+b)%n;
		a=b;
		b=c;
		if(a==0 && b==1)
			return (i+1);
	}
}

int sum_no(int n)
{
	if (n<=1)
		return n;

	int c,a=0,b=1;
	long long int sum = 1;
	for(int i=0;i<n-1;++i)
	{
		c = (a+b)%10;
		a=b;
		b=c;
		sum += c;
		//cout<<"sum1 = "<<sum<<endl;
		if(sum>=10)
			sum%=10;
		//cout<<"sum2 = "<<sum<<endl;
	}
	return (sum%10);
}
int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    int per = fibonassi_period();
    int rem = n%per;

    if(rem ==0)
        rem = per;
    int rem_sum = sum_no(rem);

    /*for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum += current;
	if(sum>10)
	{
		sum%=10;
	}
    }*/

    return rem_sum;
}

int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_fast(n)<<endl;
}
