#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;

bool IsB2(int n,int arr[]){
	int npower=n*n;
	int recording[npower];
	for(int i=0;i<npower;i++){
		recording[i]=0;
	}
	int l=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			recording[l]=arr[i]+arr[j];
			l++;
			if(arr[i]>=arr[j]){
				return false;
			}
		}
		
	}
	for(int i=0;i<l;i++){
		for(int j=i+1;j<l;j++){
			if(recording[i]==recording[j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int num=0,l=1;
	while(!EOF){
		cin>>num;
		int arr[num];	
		for(int i=0;i<num;i++){
			cin>>arr[i];
		}
		if(IsB2(num,arr)==true){
			cout<<"Case #"<< l << ": It is a B2-Sequence."<<endl;
		}
		else{
			cout << "Case #" << l << ": It is a B2-Sequence."<<endl;
		}	
		l++;
	}
	return 0;
}
