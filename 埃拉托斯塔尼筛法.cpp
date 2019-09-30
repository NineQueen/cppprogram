#include<iostream>
#include<algorithm> 
#include<cmath>
using namespace std;
int num[100001]={0},now[10000]={0};
int n;
int main(){
	cin >> n;
	for(int i=2;i<=n;i++){
		if(num[i]==0){
			for(int j=2;i*j<=n;j++){
				num[j*i] = 1;
			}
		}
		if(n<i*i){
				int m = 0;
				for(int k =2;k<n;k++){
					if(num[k]==0){
						cout << k<<' ';
						m++;
					}
				}
				cout << endl << m;
				break;
			}
	}
	return 0;
} 
