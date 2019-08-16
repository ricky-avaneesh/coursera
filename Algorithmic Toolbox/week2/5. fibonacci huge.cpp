#include <iostream>
using namespace std;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }

    return current;
}

long long int pissano_period(int m)
{
	long long int a =0, b=1, c = a+b;
	for(int i=0; i<m*m; i++)
	{
		c = (a+b)%m;
		a = b;
		b = c;
		if(a==0 && b==1)
			return(i+1);
	}
}
int main() {
    long long n, m;
    long long int per;
    int new_fibbonacci;
    cin >> n >> m;
    per = pissano_period(m);
	//cout<<"\nperiod = "<<per<<endl;
    new_fibbonacci = n % per;
    if(new_fibbonacci == 0)
        new_fibbonacci = per;
	//cout<<"new nth fib number = "<<new_fibbonacci<<endl;
    cout << get_fibonacci_huge_naive(new_fibbonacci, m) << '\n';
}
