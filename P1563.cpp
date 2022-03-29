#include<bits/stdc++.h>
using namespace std;

struct toll
{
	char turn;
	string name;
};

int main()
{
	int n,m;
	cin>>n>>m;
	struct toll man[100000];
	for(int i=0;i<n;i++)
	{
		cin>>man[i].turn;
		cin>>man[i].name;
	}
	int s=0;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		if((man[s].turn=='0'&&a==1)||man[s].turn=='1'&&a==0)
		{
			s+=b;
			s%=n;
		}
		else
		{
			s-=b;
			s=(s+n)%n;
		}
	}
	cout<<man[s].name;
	return 0;
}

