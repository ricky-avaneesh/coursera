//*****************************************************************//
//                       Created by Avaneesh                       //
//*****************************************************************//
//           Programme to find the maximum pairwise product        //
//*****************************************************************//
#include <iostream>
#include <vector>
using namespace std;
unsigned long long int product_v1(vector<long long int>& num)
{
	long long int l;
	long long int sl;
	long long int s;
	unsigned long long int product;
	int n = num.size();

	l = num[0];
	for(int i=0; i<n; ++i)
		if(num[i]>l)
			l = num[i];
		else
			s = num[i];
	sl = s;

	for(int j=0; j<n;j++)
		if(num[j]>sl && num[j]<l)
			sl = num[j];
	product = l*sl;
	return product;
}
unsigned long long int product_v2(vector<long long int>& num)
{
	int n = num.size();
	unsigned long long int product;
	long long int tmp;
	for(int i=0; i<2; ++i)
		for(int j = 0; j<n-i-1; ++j)
		{
			if(num[j]>num[j+1])
			{
				num[j] += num[j+1];
				num[j+1]=num[j] - num[j+1];
				num[j] -= num[j+1];
			}
		}

	product = num[n-1]*num[n-2];
	return product;
}
void stress_test(vector<long long int>& num, vector<long long int>& r_num)
{
	unsigned long long int res1, res2;
	res1 = product_v2(num);
	res2 = product_v2(r_num);
	if(res1 == res2)
		cout<<"OK\n";
	else
		cout<<"Wrong\nResul1="<<res1<<"\tResult2="<<res2<<endl;

}
int main() {
	int n;
	cin >> n;
	vector<long long int> numbers(n);
	vector<long long int> rev_num(n);
 	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
		//remove the below comment for stress testing
		//rev_num[n-i-1] = numbers[i];
	}
	//below function performs the stress test... while submitting add comment
	//stress_test(numbers, rev_num);
	cout<<product_v2(numbers)<<"\n";
return 0;
}
