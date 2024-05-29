#include <stdio.h>
#include <iostream>

using namespace std;

void function (int a, int b, int c){
	int grade[4];
	int classe[4];

	grade[0] = a;
	grade[1] = b;
	grade[2] = c;

	classe[0] = c;
	classe[1] = b;
	classe[2] = a;

	//classe[7] += 10;
}

int main(){
	int x;

	x=0;
	function(1,2,3);

	++x;
	++x;
	cout << "x=" << x << endl;

	return 0;
}
