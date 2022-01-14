#include<stdio.h>
int a,b,A[20]={0,},res[20]={0,},check[20]={0,};// dfs인자는 레벨 즉 깊이, 깊이를 사용해 dfs를 멈추고 원하는 순열의 길이만 출력한다
int dfs(int level){                            // 순열 등등 경우의 수를 구할때는 dfs에 반복문을 결합한 상태를 떠올리면 될것같다.
	if(level==b){
		for(int i=0;i<b;i++){
			printf("%d ",res[i]);
		}
		printf("\n");
		return 0;
	}
	else{
		for(int i=0;i<a;i++){
			if(check[i]==0){
				check[i]=1;
				res[level]=A[i];
				dfs(level+1);
				check[i]=0;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d %d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",&A[i]);
	}
	dfs(0);
	return 0;
}
