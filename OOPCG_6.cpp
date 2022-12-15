#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ITEM{
	public:
		int cost, code, quantity;
		char name[100];
		
		bool operator<(const Item& i1){ 
	 		if(code<i1.code)
				return 1;
	 		return 0;
		}
};

vector<ITEM> object;
void insert(){
	ITEM item;
	cout<<"Enter name of Item: ";
	cin>>item.name;
	cout<<"Enter cost: ";
	cin>>item.cost;
	cout<<"Enter quantity: ";
	cin>>item.quantity;
	cout<<"Enter code: ";
	cin>>item.code;
	object.push_back(item);
}

void print(ITEM &item){
	cout<<endl;
	cout<<"Name: "<<item.name<<endl;
	cout<<"Cost: "<<item.cost<<endl;
	cout<<"Quantity: "<<item.quantity<<endl;
	cout<<"Code: "<<item.code<<endl;
}

void display(){
	for_each(object.begin(),object.end(),print);
}

void sort(const ITEM &item1, const ITEM &item2){
	return item1.cost < item2.cost;
}

int main(){
	
	int ch;
	
	cout<<"To Enter data press 1\n";
	cout<<"To Display data press 2\n";
	cout<<"To Sort data press 3\n;"
	cout<<"To Exit press 4\n";
	while (true){
		cout<<"\nEnter choice: ";
		cin>>ch;
		if (ch == 1)
			insert();	
		else if (ch == 2)
			display();
		else if (ch == 3)
			compare()
		else if (ch == 4)
			break;
		else
			cout<<"Enter valid choice.";
	}

	return 0;
}





