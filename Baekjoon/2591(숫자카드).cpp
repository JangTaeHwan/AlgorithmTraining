#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

string input;
int N;
int D[105], p[105], q[105];			// p[n] = n��° ���ڷ� 1�ڸ� �� ī�带 ���� �� �ִ���
									// q[n] = n-1��°�� n��° ���ڷ� 2�ڸ� �� ī�带 ���� �� �ִ��� 

int num(int n){
	return input[n] - 48;
}

void set_state(){
	N = input.size();
	D[0] = p[1] = 1;

	for (int i = 1; i < N; i++){
		if (num(i - 1) * 10 + num(i) <= 36 && num(i - 1) != 0) q[i + 1] = 1;
		if (num(i) != 0) p[i + 1] = 1;
		else p[i] = 0;
	}
}

void set_table(){
	for (int i = 1; i <= N; i++){
		D[i] = D[i - 1] * p[i] + D[i - 2] * q[i];
	}
}

int main(){

	cin >> input;

	set_state();
	set_table();
	cout << D[N] << endl;

	return 0;
}