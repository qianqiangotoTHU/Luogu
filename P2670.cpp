#include<bits/stdc++.h>
using namespace std;
int boom[200][200]={0};

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			if(c=='*') boom[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(boom[i][j]==1) cout<<"*";
			else
			{
				cout<<boom[i-1][j]+boom[i][j-1]+boom[i+1][j]+boom[i][j+1]+boom[i-1][j-1]+boom[i+1][j+1]+boom[i-1][j+1]+boom[i+1][j-1];
			}
		}
		cout<<endl;
	}
	return 0;
}

