#include<stdio.h>    //꼭 복습하자
#include<queue>
using namespace std;
int main(){
	int t,result=0,sum;
	priority_queue<int> q;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int data;
		scanf("%d",&data);
		q.push(-data);
	}
	if(t==1) printf("0");
	else{
		while(!q.empty()){
			sum=0;
			sum=sum+(-q.top());
			q.pop();
			sum=sum+(-q.top());
			q.pop();
			result+=sum;
			if(q.size()==0) break;
			q.push(-sum);
		}
		printf("%d",result);
	}
	return 0;
}
