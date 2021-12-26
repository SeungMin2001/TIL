#include<stdio.h>
#include<algorithm>
using namespace std;
int A[1000001]={0,};
int Find(int x){
	if(A[x]==x) return x;
	else{
		return A[x]=Find(A[x]);
	}
}
int Union(int a,int b){
	a=Find(a);
	b=Find(b);
	A[a]=b;
	return 0;
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	for(int i=0;i<=a;i++){
		A[i]=i;
	}
	for(int i=0;i<b;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(x==0){
			Union(y,z);
		}
		else{
			if(Find(y)==Find(z)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
