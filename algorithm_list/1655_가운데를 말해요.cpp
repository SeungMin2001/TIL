#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>> up;//mid보다 큰 수들의 최소힙
priority_queue<int,vector<int>,less<int>> down;//mid보다 작은 수들의 최대힙
vector<int> v;
int t,cnt,x,mid;

int algo(int data){
	if(cnt==1){//처음 들어온 애는 무조건 중앙값이므로 바로 mid에 넣기
		mid=data;
		return mid;
	}
	else{
		if(mid<=data) up.push(data);//mid와 비교해 우선순위큐에 넣어준다.
		else down.push(data);
		if(cnt%2==0){//지금까지 들어온 data의 개수가 짝수일때(중앙 두개의 값중 작은값 리턴))
			if(up.size()>down.size()) return mid;
			else return down.top();
		}
		else{//홀수일때(중앙값 리턴)
			if(up.size()==down.size()){//up,down의 균형이 맞을때는 무조건 mid가 중앙값
				return mid;
			}
			else{
				if(up.size()>down.size()){
					down.push(mid);
					mid=up.top();
					up.pop();	
				}
				else{
					up.push(mid);
					mid=down.top();
					down.pop();
				}
				return mid;
			}
		}
	}
}

int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int data;
		scanf("%d",&data);
		cnt++;//지금까지 들어온 data의 개수(t에 수렴한다)
		v.push_back(algo(data));
	}
	for(int i=0;i<v.size();i++) printf("%d ",v[i]);
	return 0;
}
