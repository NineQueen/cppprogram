#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;
string pos;
char let;
bool fm=false,lm=false; 
//pos ʽ�� letδ֪�� fm��һ����ĸ lm�ڶ�����ĸ falseΪ�� 
int fn,ln;
void find_number(){ //��ȡ��ĸ 
	bool fflag=false;
	let = pos[0];
	if(pos[3]=='+') fm = true;
	for(int i = 4;i<pos.length();i++){
		if(fflag==false&&pos[i]>='0'&&pos[i]<='9'){
			fn = fn*10+(pos[i]-'0');
			continue;
		}else if(fflag==false){
			if(pos[i+1]=='+') lm = true;
			fflag = true;
			continue;
		}
		if(fflag==true&&pos[i]>='0'&&pos[i]<='9'){
			ln = ln*10+(pos[i]-'0');
		}
	}
}
bool flag;
void out(){
	for(int i =1;i<ceil(sqrt(ln));i++){
		if(ln%i!=0) continue;
		if(lm){
			if(i+ln/i==fn){
				if(fm==false)
					cout << '('<<let<<'-'<<i<<')'<<'('<<let<<'-'<<ln/i<<')';
				else
					cout << '('<<let<<'+'<<i<<')'<<'('<<let<<'+'<<ln/i<<')';
				break;
			}
		}else{
			//x^2-5x-6
			if(abs(i-ln/i)==fn){
				if(fm==false)
					cout << '('<<let<<'+'<<i<<')'<<'('<<let<<'-'<<ln/i<<')';
				else
					cout << '('<<let<<'-'<<i<<')'<<'('<<let<<'+'<<ln/i<<')';
				break;
			}
		}
	}
}
int main(){
	cout << "�������ʽ��x^2+5x+6��ʽ��"<<endl;
	cin >> pos;
	find_number(); 
	out();
	return 0;
}
