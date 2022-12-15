#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	string data;
	
	ofstream file1;
	file1.open("sample.txt");
	cout<<"Enter the data you want to write in the file: ";
	getline(cin, data);
	file1<<data;
	file1.close();
	
	ifstream file2;
	file2.open("sample.txt");
	if (file2.is_open()){
		std::cout<<file2.rdbuf()<<endl;
	}
	file2.close();
	
	return 0;
}


