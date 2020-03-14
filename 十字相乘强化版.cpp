#include<iostream>
#include<cmath>
using namespace std;
int a,b,c;
struct nums{
	int first,last;
};
int main(){
	while(cin >> a >> b >> c){
		bool is_has = false; 
		bool fm = true;
		bool lm = true;
		nums n[101];
		int tot = 0;
		if(a<0){
			cout << '-';
			a = -a;
			b = -b;
			c = -c;
		}
		if(c<0){
			c = -c;
			lm = false;
		}
		if(b<0){
			b = -b;
			fm = false;
		}
		for(int i =1;i<=a;i++){
			if(a%i==0){
				n[tot].first = i;
				n[tot++].last = a/i;
			}
		}
		for(int i=1;i<=c;i++){
			if(c%i==0){
				if(lm){
					for(int j =0;j<tot;j++){
						if(i*n[j].first+(c/i)*n[j].last==b){
							is_has = true;
							if(fm==false)
								cout << "("<<n[j].last<<"x-"<<i<<")("<<n[j].first<<"x-"<<c/i<<')'<<endl;
							else
								cout << "("<<n[j].last<<"x+"<<i<<")("<<n[j].first<<"x+"<<c/i<<')'<<endl;
							break;
						}
					}
				}else{
					for(int j =0;j<tot;j++){
						if(-(i*n[j].first-(c/i)*n[j].last)==b){
							is_has = true;
							if(fm==false)
								cout << "("<<n[j].last<<"x+"<<i<<")("<<n[j].first<<"x-"<<c/i<<')'<<endl;
							else
								cout << "("<<n[j].last<<"x-"<<i<<")("<<n[j].first<<"x+"<<c/i<<')'<<endl;
							break;
						}
					}
				}
			}
			if(is_has) break;
		}	
		system("PAUSE");
	}
	return 0;
}
