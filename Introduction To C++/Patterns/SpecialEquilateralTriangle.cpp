#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*n-1;j++){
			if(j>=n+1-i && j<=n-1+i && k==1){
				cout<<"*";
				k=0;
			}
			else{
				k=1;
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}