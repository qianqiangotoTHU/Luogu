#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int r;
	cin >> r;
	int pri[100][100]={0};//改数
	for(int i=1;i<=r;i++){
		for(int j=1;j<=i;j++){
			cin >> pri[i][j];
		}
	}
	int dp[1005]={0};//dp[i]表示遍历到的最后一行第i列的最大路径
	int last[1005]={0};//记录上一行的dp
	dp[1]=pri[1][1];
	last[1]=dp[1];
	for(int i=2;i<=r;i++){
		for(int j=1;j<=i;j++){
			dp[j]=max(last[j-1]+pri[i][j],last[j]+pri[i][j]);
		}
		for(int j=1;j<=i;j++){
			last[j]=dp[j];
		}
	}
	int maxdp = 0;
	for(int i=1;i<=r;i++){
		if(dp[i]>maxdp) maxdp = dp[i];
	}
	cout << maxdp;
	return 0;
}

