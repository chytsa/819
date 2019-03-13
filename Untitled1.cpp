#include<iostream>
#include<fstream>
#define inbuf_dig 1000000
using namespace std;
int main(){
	fstream fp;
	fp.open("1.txt", ios::out);
	fp << 1;
	for(int i = 1; i < inbuf_dig; i++){
		fp << 0;
	}
	
	fp.close();
	return 0;
} 
