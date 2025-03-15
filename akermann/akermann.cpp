#include<iostream>

using namespace std;

int total = 0;

int ack(int m,int n)
{
	total++;
    if(m == 0)
        return n+1;
    else if(n == 0)
        return ack(m-1,1);
    else
        return ack(m-1,ack(m,n-1));
}

int main() {
	int num = ack(3,3);	
	cout <<num<<endl;
	cout<<total<<endl;
	return 0;
}
