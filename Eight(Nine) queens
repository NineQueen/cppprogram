#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
struct chess{
	int x,y;
};
int ans;
stack<chess> stack_main;
stack<chess> stack_copy; 
stack<chess> stack_copy1;
stack<chess> stack_copy2;
void clear(){
	while(!stack_copy.empty()){
		stack_copy.pop();
	}
}
void print(){
	clear();
	stack_copy2 = stack_main;
	while(!stack_copy2.empty()){
		stack_copy.push(stack_copy2.top());
		stack_copy2.pop();
	}
	while(!stack_copy.empty()){
		chess now = stack_copy.top();
		stack_copy.pop();
		for(int i =1;i<=9;i++){
			if(now.y==i) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
}
bool is_has(chess a){
	stack_copy1 = stack_main;
	while(!stack_copy1.empty()){
		chess check = stack_copy1.top();
		stack_copy1.pop();
		if(check.x==a.x||check.y==a.y||(check.x-a.x)==(check.y-a.y)||(check.x-a.x)==-(check.y-a.y)){
			return false;
		}
	}
	return true;
}
bool checkHas = false;
void find(int deepth){
	if(deepth==10){
		print();
		cout << endl; 
		return;
	}
	chess now;
	now.x = deepth;
	for(int i =1;i<=9;i++){
		now.y = i;
		if(is_has(now)){
			stack_main.push(now);
			find(deepth+1);
			stack_main.pop();
		}
	}
	return;
}
int main(){
	freopen("out.txt","w",stdout);
	find(1);
	return 0;
}
