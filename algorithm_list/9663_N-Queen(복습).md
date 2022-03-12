```cpp
//1<=N<=15
#include<stdio.h>
#include<math.h>
using namespace std;
int N,chess[16]={0,},cnt=0;
bool check(int x){
	for(int i=0;i<x;i++){                                      //여기서 만약 x가 아니라 N까지 돌아버리면 level=0 일때 if문에 걸리면서 flase를 반환하게 된다.
		if(chess[i]==chess[x]||abs(chess[i]-chess[x])==abs(i-x)){// 그러면 바로 프로그램이 종료되기 때문에 N이 아닌 현재 level까지만 돌려야 정상적으로 작동된다.
			return false;
		}
	}
	return true;
}
int dfs(int level){
	if(level==N){
		cnt++;
		return 0;
	}
	for(int i=0;i<N;i++){
		chess[level]=i;
		if(check(level)==true){
			dfs(level+1);
		}
	}
	return 0;
}
int main(){
	scanf("%d",&N);
	dfs(0);
	printf("%d",cnt);
	return 0;
}
```

### 풀면서 느낀점 : 
##### 복습하면서 느낀점은 확실히 한번더 풀면 내걸로 되는것 같다. 복습이 중요하다는걸 깨달았다.
