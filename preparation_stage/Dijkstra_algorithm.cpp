#include<stdio.h>
#include<queue>
#include<vector>
#define MAX 1000000000
using namespace std;
struct node{
	int n,v;
	node(int a,int b){
		n=a;
		v=b;
	}
	bool operator<(const node &A)const{
		return v>A.v;
	}
};
int main(){
	int a,b;
	double test1,test2;
	test1=time(NULL);
	vector<pair<int,int>> v[21];
	priority_queue<node> q;
	scanf("%d %d",&a,&b);
	vector<int> result(a+1,MAX);
	for(int i=0;i<b;i++){
		int dx,dy,dz;
		scanf("%d %d %d",&dx,&dy,&dz);
		v[dx].push_back(make_pair(dy,dz));
	}
	result[1]=0;
	q.push(node(1,0));
	while(!q.empty()){
		int next=q.top().n;
		int val=q.top().v;
		q.pop();
		if(val>result[next]) continue;
		for(int i=0;i<v[next].size();i++){
			int next_node=v[next][i].first;
			int next_value=v[next][i].second+val;
			if(result[next_node]>next_value){
				result[next_node]=next_value;
				q.push(node(next_node,next_value));
			}
		}
	}
	for(int i=2;i<=a;i++){
		if(result[i]==MAX) printf("impossble");
		else printf("%d ",result[i]);
	}
	return 0;
}
