#include<stdio.h>
int main(){
	int N,M,sum=0;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++){
		if(i%M==0) sum+=i;
	}
	printf("%d",sum);
	return 0;
}
