#include<stdio.h>      //벨만포드 알고리즘
#include<vector>
#define MAX 1000000
using namespace std;
struct node{
	int x,y,z;
	node(int a,int b,int c){
		x=a;
		y=b;
		z=c;
	}
};
int main(){
	int a,b,start,end;
	scanf("%d %d",&a,&b);
	vector<node> v;
	vector<int> result(a+1,MAX);
	for(int i=0;i<b;i++){
		int dx,dy,dz;
		scanf("%d %d %d",&dx,&dy,&dz);
		v.push_back(node(dx,dy,dz));
	}
	scanf("%d %d",&start,&end);
	result[start]=0;
	for(int i=0;i<a-1;i++){
		for(int j=0;j<b;j++){
			if(result[v[j].x]!=MAX&&result[v[j].y]>v[j].z+result[v[j].x]){
				result[v[j].y]=result[v[j].x]+v[j].z;
			}
		}
	}
	for(int j=0;j<b;j++){
		if(result[v[j].x]!=MAX&&result[v[j].y]>v[j].z+result[v[j].x]){
			printf("-1");
			return 0;
			}
	}
	printf("%d",result[end]);
	return 0;
}
