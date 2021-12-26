#include<stdio.h>      //우선순위큐 자료구조를 응용하면 풀리는 문제
#include<queue>
using namespace std;
int main(){
	int n;
	priority_queue<int> q;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x==0){
			if(q.empty()) printf("0\n");
			else{
				printf("%d\n",-q.top());   //꺼낼때도 -를 붙혀서 원상복구를 해준다.
				q.pop();
			}
		}
		else q.push(-x);  //-를 붙혀서 넣어주면 최소힙이 된다.
	}
	return 0;
}
