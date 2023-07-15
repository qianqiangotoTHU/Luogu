#include<bits/stdc++.h>
using namespace std;

int mountain[105][105];
int r,c;
#define INF 1e9;
int dp[105][105]={0};

int dfs(int rr, int cc)
{
	int ans=1;//长度
	//往上
	if(rr-1>0&&mountain[rr-1][cc]<mountain[rr][cc]){
		if(dp[rr-1][cc]==0) dp[rr-1][cc]=dfs(rr-1,cc);
		ans=max(ans,dp[rr-1][cc]+1);
	}
	//往左
	if(cc-1>0&&mountain[rr][cc-1]<mountain[rr][cc]){
		if(dp[rr][cc-1]==0) dp[rr][cc-1]=dfs(rr,cc-1);
		ans=max(ans,dp[rr][cc-1]+1);
	}
	//往右
	if(cc+1>0&&mountain[rr][cc+1]<mountain[rr][cc]){
		if(dp[rr][cc+1]==0) dp[rr][cc+1]=dfs(rr,cc+1);
		ans=max(ans,dp[rr][cc+1]+1);
	}
	//往下
	if(rr+1>0&&mountain[rr+1][cc]<mountain[rr][cc]){
		if(dp[rr+1][cc]==0) dp[rr+1][cc]=dfs(rr+1,cc);
		ans=max(ans,dp[rr+1][cc]+1);
	}
	return ans;
}

int main()
{
	cin >> r >> c;
	//初始化
	for(int i=0;i<105;i++){
		for(int j=0;j<105;j++){
			mountain[i][j]=INF;
		}
	}
	//输入数据
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin >> mountain[i][j];
		}
	}
	//dfs
	int max=0;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(dp[i][j]==0) dp[i][j]=dfs(i,j);
			if(dp[i][j]>max) max=dp[i][j];
		}
	}
	cout << max;
	return 0;
}
