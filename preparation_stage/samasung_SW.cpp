#include<stdio.h>
int n,a,b,c,d,A[11]={0,},Max=-1,Min=101;
int dfs(int level,int sum){                //처음에는 이문제를 기호들의 순열을 다 구해서 각각의 순열들마다의 최댓값,최솟값을 구하려 했으나
	if(level==n){                           // 그것보단 기호들의 개수를 문제에서 알려주기 때문에 
		if(Max<sum) Max=sum;                  // dfs를 바로 돌리면서 개수를 차감,증가를 조율해서 경우의수를 다 구하는게
		if(Min>sum) Min=sum;                  //더 빠르다고 판단하여 코드를 짬
		return 0;                             //따라서 이 코드는 +,-,*,/ 4가지를 dfs로 돌려서 다 구해냄
	}
	else{
		if(a!=0){
			a--;
			dfs(level+1,sum+A[level]);
			a++;
		}
		if(b!=0){
			b--;
			dfs(level+1,sum-A[level]);
			b++;
		}
		if(c!=0){
			c--;
			dfs(level+1,sum*A[level]);
			c++;
		}
		if(d!=0){
			d--;
			dfs(level+1,sum/A[level]);
			d++;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d %d %d %d",&a,&b,&c,&d);
	dfs(1,A[0]);
	printf("%d %d",Max,Min);
	return 0;
}
