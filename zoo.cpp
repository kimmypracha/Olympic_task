#include <bits/stdc++.h> 
 using namespace std;
  const int limc = 5e4 + 10;
  const int limn = 1e4 + 10;
  int dp[1<<5][1<<5][limn];
  int arr[limn];
  vector<int> lst[limc];
  vector<int> fst[limc];
  vector<int> cst[limn];
  int cal(int st , int nst , int now ){
	int ans = 0;
	for(int i =0 ; i < cst[now].size(); i++){
		bool happy = false;
		int chi = cst[now][i];
		for(int j=0 ; j < fst[chi].size() and not happy ; ++j){
			int k = fst[chi][j];
			if((nst&(1<<k)) == 0) happy = true;
		}
		for(int j = 0 ; j < lst[chi].size()and not happy ; ++j){
			int k = lst[chi][j];
			if((nst&(1<<k))) happy = true;
		}
		if(happy) ans++;
	}
	return ans;	
  }
  int main(){
	int n , c;
	scanf("%d%d",&n,&c);
	for(int i =0 ; i < (1<<5) ; ++i){
		for(int j = 0 ; j < (1<<5) ; ++j){
			for(int k= 0 ; k <= n+4 ; ++k){
				dp[i][j][k] = -1;
			}
		}
	}
	for(int i = 1 ; i <= n + 4;++i){
		arr[i] = i;
		if(arr[i]>n) arr[i] -= n;
	}
	for(int i=0 ; i < c;++i){
		int E , F , L;
		scanf("%d%d%d",&E,&F,&L);
		cst[E+4].push_back(i);
		for(int j=  0 ; j < F ; ++j){
			int A;
			scanf("%d",&A);
			if(n  < A and E+4 > n) A += n; 
				fst[j].push_back(E+4 - A);
		}
		for(int j = 0 ; j < L ; ++j){
			int A;
			scanf("%d",&A);
			if(n  < A and E+4 > n) A += n; 
				lst[j].push_back(E+4- A);
		}
	}
	for(int i =0 ; i < (1<<5) ; ++i){
		for(int j = 5; j <= n+4 ; ++j){
			if(j == 5){
				dp[i][i][j] = cal(i , i , j);
				continue;
			}
			if(j > n){
				int ad = (i >> (5-j-n-1));
				for(int k= 0 ; k < (1<<5)  ;++k){
					if(dp[i][k][j-1] != -1) 
					dp[i][((k<<1) +ad)%32][j] = dp[i][k][j-1] + cal( i ,((k<<1)+ad)%32 , j) ;
				}
				continue;
			}
			for(int k = 0 ; k < (1<<5); ++k){
				if(dp[i][k][j-1]!= -1){
					dp[i][(k<<1|1)%32][j] = max(dp[i][k][j-1] + cal(i , k<<1|1 ,j), dp[i][(k<<1|1)%32][j]);
					dp[i][(k<<1)%32][j] = max(dp[i][k][j-1] + cal(i , k<<1 ,j), dp[i][(k<<1)%32][j]);
				}
			}
			
		}
	}
	int ans = 0;
	for(int i =0 ; i < (1<<5) ; ++i){
		for(int j= 0; j < (1<<5) ; ++j){
			ans = max(ans , dp[i][j][n+4]);
		}
	}
	printf("%d",ans);
  }
