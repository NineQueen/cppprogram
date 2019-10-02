#include<iostream>
using namespace std;
int n;
int a[1001];
int visit[1001];
void dfs(int p){
	if(p==n+1){
		for(int i=1;i<=n;i++){
			cout << a[i]<<' ';
		}
		cout << endl;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(visit[i]==0){
			a[p] = i;
			visit[i] = 1;
			dfs(p+1);
			visit[i] = 0;
		}
	}
}
int main(){
	cin >> n;
	dfs(1);
	return 0;
}
