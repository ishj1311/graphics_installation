#include<iostream>
#include<string.h>
using namespace std;

class Publication{
	public:
	string title;
	float price = 0;
	
};


class Book:public Publication{
	public:
	int page_count = 0;
	void getdetails(){
		try{
			cout<<"Enter title: ";
			cin.ignore();
			getline(cin, title);
			cout<<"Enter price: ";
			cin>>price;
			cout<<"Enter number of pages in book: ";
			cin>>page_count;
			
			if (price <= 0 || page_count <= 0 || title == ""){
				throw 404;
			}
		}
		catch(...){
			title = "NULL";
			price = 0;
			page_count = 0;
		}
	}
	
	void display(){
		cout<<"The title of book is "<<title<<" ."<<endl;
		cout<<"The price of book is "<<price<<" rupees."<<endl;
		cout<<"The book has "<<page_count<<" pages."<<endl;
	}
};

class Tape:public Publication{
	public:
	int play_time = 0;
	void getdetails(){
		try{
			cout<<"Enter title: ";
			cin.ignore();
			getline(cin, title);
			cout<<"Enter price: ";
			cin>>price;
			cout<<"Enter play time of tape: ";
			cin>>play_time;
			
			if (play_time <= 0 || price <= 0 || title == ""){
				throw 404;
			}
		}
		
		catch(...){
			title = "NULL";
			price = 0;
			play_time = 0;
		}
	}
	
	void display(){
		cout<<"The title of tape is "<<title<<" ."<<endl;
		cout<<"The price of tape is "<<price<<" rupees."<<endl;
		cout<<"The tape plays for "<<play_time<<" minutes."<<endl;
	}
};

int main(){
	Book B1[100];
	Tape T1[100];
	int ch, no_of_books, no_of_tapes, i;
	
	cout<<"How many books do you want to create: ";
	cin>>no_of_books;
	cout<<"How many tapes do you want to create: ";
	cin>>no_of_tapes;
	
	for(i=0; i<no_of_books; i++){
		Book B1[i];	
	}
	
	for(i=0; i<no_of_tapes; i++){
		Tape B1[i];	
	}
	
	while(1){
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"|Press 1 to input Book info.|\n";
		cout<<"|Press 2 to input Tape info.|\n";
		cout<<"|Press 3 to display.        |\n";
		cout<<"|Press 4 to exit!           |\n";
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"\nEnter choice: ";
		cin>>ch;
		
		if(ch == 1){
			for(i=0; i<no_of_books; i++){
				B1[i].getdetails();	
			}
		}
		
		else if(ch == 2){
			for(i=0; i<no_of_tapes; i++){
				T1[i].getdetails();	
			}
		}
		
		else if(ch == 3){
			cout<<"\nBook Information: \n";
			for(i=0; i<no_of_books; i++){
				cout<<"Book "<<i+1<<":\n";
				B1[i].display();	
			}
			cout<<"\nTape Information: \n";
			for(i=0; i<no_of_tapes; i++){
				cout<<"Tape "<<i+1<<":\n";
				T1[i].display();	
			}
		}
		
		else if(ch == 4){
			cout<<"Thankyou!\n";
			break;
		}
		
		else{
			cout<<"Enter a valid choice!!\n";
		}
	}
	
	return 0;
}

/*

OUTPUT:

How many books do you want to create: 1
How many tapes do you want to create: 1

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|Press 1 to input Book info.|
|Press 2 to input Tape info.|
|Press 3 to display.        |
|Press 4 to exit!           |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter choice: 1
Enter title: Harry Potter
Enter price: 200
Enter number of pages in book: 450

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|Press 1 to input Book info.|
|Press 2 to input Tape info.|
|Press 3 to display.        |
|Press 4 to exit!           |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter choice: 2
Enter title: galway Girl 
Enter price: 340
Enter play time of tape: 2 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|Press 1 to input Book info.|
|Press 2 to input Tape info.|
|Press 3 to display.        |
|Press 4 to exit!           |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter choice: 3

Book Information: 
Book 1:
The title of book is Harry Potter .
The price of book is 200 rupees.
The book has 450 pages.

Tape Information: 
Tape 1:
The title of tape is galway Girl .
The price of tape is 340 rupees.
The tape plays for 2 minutes.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|Press 1 to input Book info.|
|Press 2 to input Tape info.|
|Press 3 to display.        |
|Press 4 to exit!           |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter choice: 4
Thankyou!


*/





