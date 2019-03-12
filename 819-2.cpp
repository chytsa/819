#include<stdio.h>
#include <stdlib.h>
#include<cstring>
#include<vector>
#define inbuf_dig 1000000
//#define inbuf_dig 5
//#define ans_dig 33554432
#define ans_dig 30000000
char ans[ans_dig];
int main(){
    char buf;
    char tmp[inbuf_dig];
    
    int digit = 0;
    
    
    for(int i = 0; i < inbuf_dig; i++){
    	tmp[i] = 0;
	}
    
	while(~scanf("%c", &buf)){
		if(buf == ' '){
			for(int i = 0; i < inbuf_dig; i++){
				if(tmp[i] == 0)
					break;
		    	tmp[i] = 0;
			}
		}
		else if(buf == '\n'){
			for(int i = 0; i < inbuf_dig; i++){
				if(tmp[i] == 0)
					break;
		    	tmp[i] = 0;
			}
		}
		else{
			strncat(tmp, &buf, 1);
			digit++;
		}
		printf("%s\n", tmp);
	}
    
	
	
	return 0;
} 
