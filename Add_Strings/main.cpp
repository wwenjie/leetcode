#include<iostream>
#include<string>

using namespace std;


string addStrings(string num1, string num2); 

int main() {
	string num1("0");
	string num2("11123");

	string res = addStrings(num1, num2);
	cout<<res<<endl;
	
	return 0;
}

// 也可以优化成先在短的string的前面补0，等长再while遍历
string addStrings(string num1, string num2) {
    int size1 = num1.size();
    int size2 = num2.size();

    int carry = 0;
	string res = "";

    while(size1>=1 || size2>=1 || carry){
		int n1 = 0;
		if (size1 >= 1)
			n1 = num1[size1-1] - '0';
			size1--;
		int n2 = 0;
		if (size2 >= 1)
			n2 = num2[size2-1] - '0';
			size2--;
		int sum = n1 + n2 + carry;
		carry = sum / 10;
		sum %= 10;
		string str_sum = "0";
		str_sum[0] += sum; 
		res = str_sum + res;
    }
	return res;
}
