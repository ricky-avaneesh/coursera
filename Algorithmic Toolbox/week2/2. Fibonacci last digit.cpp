#include <iostream>
using namespace std;
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last_digit_fast(int n)
{
	if(n<=1)
		return n;

	int pre = 0;
	int cur = 1;
	int tmp_pre;
	for(int i=0; i<n-1; ++i)
	{	tmp_pre = pre;
		pre = cur;
		cur = tmp_pre + cur;
		if(tmp_pre>9)
			tmp_pre %= 10;
		if(cur>9)
			cur %= 10;
		if(pre>9)
			pre %= 10;
	}
	return cur;
}
int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';
    }
