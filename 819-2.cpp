#include<iostream>
#include <stdlib.h>
#include<cstring>
#include<vector>
using namespace std;
class C819{
	public:
		C819(){
			input_sign = 1;
			ans_sign = 1;
		}
		~C819(){
			input.clear();
			ans.clear();
		}
		void input_clear(){
			input.clear();
			input_sign = 1;
		}
		void ans_clear(){
			ans.clear();
			ans_sign = 1;
		}
		void input_neg(){
			input_sign = -1;
		}
		void exchange(){
			vector<char> tmp;
			tmp.resize(input.size());
			for(int i = 0; i < input.size(); i++){
				tmp[i] = input[i];
			}
			input.resize(ans.size());
			
			
			//cout << "DDDDDDD\n";
			//cout << ans.size();
			for(int i = 0; i < ans.size(); i++){
				//cout << ans[ans.size() - 1 - i];
				input[i] = ans[ans.size() - 1 - i];
			}
			
			
			//cout << "II\n";
			//print_input();
			//cout << "II\n";
			
			ans.resize(tmp.size());
			for(int i = 0; i < tmp.size(); i++){
				ans[i] = tmp[tmp.size() - 1 - i];
			}
			//cout << "AA\n";
			//print_ans();
			//cout << "AA\n";
			
			int a = input_sign;
		}
		void print_ans(){
			//cout << "*************************\n";
			//cout << "size: " << ans.size() << endl;
			//cout << "ans: ";
			if(ans_sign == -1){
				cout << "-";
			}
			int zero = 0;
			for(int i = ans.size() - 1; i >= 0; i--){
				if(!zero){
					if(ans[i] != '0'){
						zero = 1;
						ans.resize(i + 1);
						cout << ans[i];
					}
				}
				else
					cout << ans[i];
			}
			if(!zero){
				cout << "0";
				ans.resize(1);
			}
			cout << endl;
			//cout << "size: " << ans.size() << endl;
			//cout << "*************************\n";
		}
		void check(){
			int zero = 0;
			for(int i = ans.size() - 1; i >= 0; i--){
				if(!zero){
					if(ans[i] != '0'){
						zero = 1;
						ans.resize(i + 1);
						break;
					}
				}
			}
			if(!zero){
				ans.resize(1);
			}
		}
		void print_input(){
			//cout << "/////////////////////////\n";
			//cout << "input: ";
			for(int i = 0; i < input.size(); i++){
				cout << input[i];
			}
			cout << endl;
			//cout << "/////////////////////////\n";
		}
	/* ========================================================== */
		void op(){
			if(input_sign * ans_sign > 0){
				add();
			}
			else{
				minus();
			}
		}
		void add(){
			int carry = 0;
			if(ans.size() < input.size()){
				ans.resize(input.size() + 1, '0');
			}
			for(int i = 0; i < input.size(); i++){
				//cout << ans[i] - '0' << "," << input[input.size() - 1 - i] - '0' << endl;
				int sum = (ans[i] - '0') + carry;
				carry = 0;
				if(sum > 9){
					carry = 1;
					sum -= 10;
				}
				ans[i] = '0' + sum;
				
				sum = (ans[i] - '0') + (input[input.size() - 1 - i] - '0');
				if(sum > 9){
					carry = 1;
					sum -= 10;
				}
				ans[i] = '0' + sum;
						
				//cout << "ans[i]=" << ans[i] << endl;
				
			}
						
			if(carry){
				for(int i = input.size(); carry && i < ans.size(); i++){
					int sum = (ans[i] - '0') + carry;
					carry = 0;
					if(sum > 9){
						carry = 1;
						sum -= 10;
					}
					ans[i] = '0' + sum;
				}
				if(carry)
					ans.push_back('1');
			}
			//cout << "after add:\n";
			//print_ans();
		}
		int cmp(){
			//cout << "===========================\n";
			//cout << "cmp:\n";
			//print_input();
			//print_ans();
			//cout << "===========================\n";
			if(input.size() > ans.size())
				return -1;
			else if(input.size() < ans.size())
				return 1;
			else{
				for(int i = 0; i < input.size(); i++){
					if(input[i] > ans[ans.size() - 1 - i])
						return -1;
					else if(input[i] < ans[ans.size() - 1 - i])
						return 1;
				}
				return 0;
			}
		}
		void minus(){
			switch(cmp()){
				case 1:{
					//cout << "case1, ";
					int carry = 0;
					for(int i = 0; i < input.size(); i++){
						//cout << ans[i] - '0' << "," << input[input.size() - 1 - i] - '0' << endl;
						int dif = (ans[i] - '0') - carry;
						carry = 0;
						if(dif < 0){
							carry = 1;
							dif += 10;
						}
						ans[i] = '0' + dif;
						
						dif = (ans[i] - '0') - (input[input.size() - 1 - i] - '0');
						if(dif < 0){
							carry = 1;
							dif += 10;
						}
						ans[i] = '0' + dif;
								
						//cout << "ans[i]=" << ans[i] << endl;
						
					}
								
					if(carry){
						for(int i = input.size(); carry && i < ans.size(); i++){
							int dif = (ans[i] - '0') - carry;
							carry = 0;
							if(dif < 0){
								carry = 1;
								dif += 10;
							}
							ans[i] = '0' + dif;
						}
					}
					break;
				}
				case -1:{
					//cout << "case-1, ";
					exchange();
					//print_ans();
					//print_input();
					int carry = 0;
					for(int i = 0; i < input.size(); i++){
						//cout << ans[i] - '0' << "," << input[input.size() - 1 - i] - '0' << endl;
						int dif = (ans[i] - '0') - carry;
						carry = 0;
						if(dif < 0){
							carry = 1;
							dif += 10;
						}
						ans[i] = '0' + dif;
						
						dif = (ans[i] - '0') - (input[input.size() - 1 - i] - '0');
						if(dif < 0){
							carry = 1;
							dif += 10;
						}
						ans[i] = '0' + dif;
								
						//cout << "ans[i]=" << ans[i] << endl;
						
					}
								
					if(carry){
						for(int i = input.size(); carry && i < ans.size(); i++){
							int dif = (ans[i] - '0') - carry;
							carry = 0;
							if(dif < 0){
								carry = 1;
								dif += 10;
							}
							ans[i] = '0' + dif;
						}
					}
					
					ans_sign *= -1;
					break;
				}
				case 0:{
					//cout << "QQ\n";
					ans.clear();
					ans.push_back('0');
					ans_sign = true;
					break;
				}
			}
			//cout << "after minus:\n";
			//print_ans();
		}
		void save(char buf){
			input.push_back(buf);
		}
	private:
		vector<char> input;
		vector<char> ans;
		int input_sign, ans_sign;
};

int main(){
	vector<char> s;
	cout << s.max_size();
	
    char buf;
    C819 A;
	while(~scanf("%c", &buf)){
		if(buf == '-'){
			A.input_neg();
		}
		else if(buf == ' '){
			A.op();
			A.check();
			A.input_clear();
		}
		else if(buf == '\n'){
			A.op();
			A.print_ans();
			A.input_clear();
			A.ans_clear();
		}
		else{
			A.save(buf);
		}
	}
	return 0;
} 
