#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a,b,longer,shorter;
	int sum[1000]={0};
	cin>>a>>b;
	int as=a.length();
	int bs=b.length();
	int max,min;
	if(as>=bs)
	{
		longer=a;
		shorter=b;
		max=as;
		min=bs;
	}
	else
	{
		longer=b;
		shorter=a;
		max=bs;
		min=as;
	}
	int s=0;
	int more=max-min;
	for(int i=0;i<min;i++)
	{
		int temp=sum[s]+longer[max-i-1]+shorter[min-i-1]-2*'0';
		sum[s]=temp%10;
		sum[++s]=temp/10;
	}
	for(int i=min;i<max;i++)
	{
		int temp=sum[s]+longer[max-i-1]-'0';
		sum[s]=temp%10;
		sum[++s]=temp/10;
	}
	if(sum[s]!=0) cout<<sum[s];
	for(int i=s-1;i>=0;i--)
	{
		cout<<sum[i];
	}
	return 0;
}

