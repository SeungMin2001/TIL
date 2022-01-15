#include<stdio.h>
int A[3][16]={0,},N,Max=-1,sum=0;   
int dfs(int x,int sum){
	if(x==N+1){                       //N인지 N+1인지 한참동안 고민한 문제
		if(Max<sum) Max=sum;            // 왜 N인지 : ex): 7일까지인데 5일에 3일을 가야한다 치자
		return 0;                       // 그러면 5,6,7 이렇게 3일을 해서 조건만족인데
	}                                 // 더하면 8일이 되버린다. 따라서 N+1을 해줘야 논리적으로 맞는 코드가 된다.
	else{
		if(x+A[0][x]<=N+1){
			dfs(x+1,sum);
			dfs(x+A[0][x],sum+A[1][x]);
		}
	}
	if(Max<sum) Max=sum;
	return 0;
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d %d",&A[0][i],&A[1][i]);
	}
	dfs(1,0);
	printf("%d",Max);
	return 0;
}
