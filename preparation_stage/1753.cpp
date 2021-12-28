#include<stdio.h>     //다익스트라 알고리즘
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 10000000
using namespace std;
struct node{
	int n;
	int d;
	node(int a,int b){
		n=a;
		d=b;
	}
	bool operator<(const node &A)const{
		return d>A.d;
	}
};
int main(){
	int a,b,start;
	priority_queue<node> q;
	vector<pair<int,int>> list[300001];
	scanf("%d %d",&a,&b);
	vector<int> v(a+1,MAX);
	scanf("%d",&start);
	v[start]=0;
	q.push(node(start,0));
	for(int i=0;i<b;i++){
		int dx,dy,dz;
		scanf("%d %d %d",&dx,&dy,&dz);
		list[dx].push_back(make_pair(dy,dz));
	}
	while(!q.empty()){
		//printf("texst");
		int next=q.top().n;
		int value=q.top().d;
		q.pop();
		for(int i=0;i<list[next].size();i++){
			if(v[next]+list[next][i].second<v[list[next][i].first]){
				v[list[next][i].first]=v[next]+list[next][i].second;
				q.push(node(list[next][i].first,v[list[next][i].first]));
			}
		}
	}
	for(int i=1;i<=a;i++){
		if(v[i]==MAX) printf("INF\n");
		else printf("%d\n",v[i]);
	}
	return 0;
}
