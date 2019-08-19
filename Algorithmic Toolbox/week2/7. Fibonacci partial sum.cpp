#include <iostream>
#include <vector>
using namespace  std;
int fibonassi_period()
{
	int current=0, next=1;
	int c  = (current + next);
	for(int i=0; i<100; ++i)
	{
		c = (current + next)%10;
		current = next;
		next = c;
		if(current==0 && next==1)
			return(i+1);
	}
}
int get_fibonacci_partial_sum_naive(long long from, long long to) {
    int sum = 0;

    long long current = 0;
    long long next  = 1;
    long long new_current;
    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += (current % 10);
            sum %= 10;
        }

        new_current = next%10;
        next = (next + current) % 10;
        current = new_current % 10;
    }

    return sum;
}

int main() {
    long long from, to;

    int per = fibonassi_period();
    //cout<<"Value of variable per : "<<per<<endl;
    long long n = to - from;
    int rem = n % per;
    to = from + rem;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
