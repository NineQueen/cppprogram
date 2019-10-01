#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int num[100001]={0};
	int v,c;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> v >> c;
		for(int j = 0;j<=n;j++){
			if(j>=v){
				num[j]=max(num[j-v]+c,num[j]);
			}
		}
		}	
	cout << num[n];
	return 0;
}
