#include<iostream>
#include<cstring>
using namespace std;
int num[10];
int n[10][10];
int now = 1;
int point[10];
bool is_end = false;
int main(){
	for(int i=0;i<10;i++){
		cin >> num[i];
	}
	while(!is_end){
		memset(n,-1,sizeof(int)*100);
		memset(point,0,10);
		is_end = true;
		for(int i=0;i<10;i++){
			n[(num[i]/now)%10][point[(num[i]/now)%10]] = num[i];
			point[(num[i]/now)%10]++;
			if(now*10<=num[i]){
				is_end = false;
			}
		}
		int p = 0;
		now = now*10;
		for(int i=0;i<10;i++){
			for(int j =0;j<10;j++){
				if(n[i][j]!=-1){
					num[p] = n[i][j];
					p++;
				}
			}
		}
	}
	for(int i = 0;i<10;i++){
		cout << num[i]<<' ';
	}
	return 0;
}
