/*

Program to converts digits into words (International System).
(Supports upto 18 digits)

Program by Paras Sharmaa

*/

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int d_count(long long);
string d_words(long long);

int main() {
	long long d;
	cout<<"Enter number:";
	cin>>d;
	cout<<"Number of digits: "<<d_count(d)<<endl;
	cout<<"In words: "<<d_words(d)<<endl;
}

int d_count(long long n) {
	int c(0);
	while(n) {
		n/=10;
		c++;
	}
	return c;
}
string d_words(long long n) {
	string r;
	int s(0);
	int p(0);
	stack <string> r_stack;
	string key_a[15] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string key_b[15]  = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	string key_c[15]  = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string key_d[15]  = {"hundred", "thousand", "million", "billion", "trillion", "quadrillion"};
  
	while(n) {
		if(p>0) {
			r_stack.push(key_d[p]);
		}
		s = 0;
		if(n%100<20 && n%100>9) {
			r_stack.push(key_b[(n%100)-10]);
			n/=100;
			s+=2;
		}
		else {
			r_stack.push(key_a[n%10-1]);
			n/=10;
			s++;
		}
		if(s==1 && n%10>1) {
			r_stack.push(key_c[n%10-2]);
			n/=10;
			s++;
		}
		else {
			n/=10;
			s++;
		}
		if(s==2 && n%10>0) {
			if(!p) {
				r_stack.push(key_a[n%10-1]+" "+key_d[0]+" and");
				n/=10;
			}
			else {
				r_stack.push(key_a[n%10-1]+" "+key_d[0]);
				n/=10;
			}
		}
		else {
			if(!p) {
				r_stack.push("and");
			}
			n/=10;
		}
		p++;
	}

	while(!r_stack.empty()) {
		r+=r_stack.top();
		r.append(" ");
		r_stack.pop();
	}
	return r;
}

//program by Paras Sharmaa

// 999,999,999,999,999,999

//nine hundred nine quadrillion 
//nine hundred ninety nine trillion 
//nine hundred ninety nine billion 
//nine hundred ninety nine million 
//nine hundred ninety nine thousand 
//nine hundred and ninety nine

/*
Sample Output:
Enter number:1126
Number of digits: 4
In words: one thousand one hundred and twenty six
*/
