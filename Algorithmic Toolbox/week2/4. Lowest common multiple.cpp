#include <iostream>
using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long int lcm_fast(int a, int b)
{
	int gcd;
	long long int lcm;
	int c,d;
	c=a;
	d=b;
	while(1)
	{
		if(a<b)
		{
			a += b;
			b = a-b;
			a -= b;
		}
		a = a-b;
		if(a==b)
		{
			gcd = a;
			break;
		}
	}

	lcm = (c*d)/gcd;
	return lcm;
}

int main() {
  int a, b,gcd;
  unsigned long long int lcm;
  cin >> a >> b;
  //cout << lcm_naive(a, b)<<endl;
  cout<<lcm_fast(a,b)<<endl;
  //gcd = gcd_fast(a,b);
  //cout<<gcd<<endl;
  return 0;
}
