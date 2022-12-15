#include<iostream>
using namespace std;

int n;

template<typename T>
void selection_sort(T A[10]){
	
	int i, j, min;
	T temp;
	
	for(i=0;i<n-1;i++)
	{
		min=i;
		
		for(j=i+1; j<n; j++)
		{
			if(A[j]<A[min])
			min=j;
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}	

	cout<<"\nSorted array: ";
	for(i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}


int main(){

	int choice, i;
	char C[10];
	int A[10];
	float B[10];
	
	whul (true){
	
	cout<<"\nEnter Total Number Of Integer Elements:";
	cin>>n;
	cout<<"\nEnter Integer Elements:";
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	selection_sort(A);
	}
	
	return 0;
}

