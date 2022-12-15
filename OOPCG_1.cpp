#include<iostream>
using namespace std;

class complex{
	int real, imag;
	public:
		complex(){
			real = 0;
			imag = 0;
		}
		
		complex operator +(complex &obj){
			complex result;
			result.real = real + obj.real;
			result.imag = imag + obj.imag;
			return result;
		}
		
		complex operator *(complex &obj){
			complex result;
			result.real = (real*obj.real) - (imag*obj.imag);
			result.imag = (real*obj.imag) + (imag*obj.real);
			return result;
		}
		
		friend void operator>>(istream&in, complex&c);
		friend void operator<<(ostream&out, complex&c);
};

void operator>>(istream&in, complex &c){
	cout<<"\nEnter real & imaginary parts of number: ";
	cin>>c.real>>c.imag;

}

void operator<<(ostream&out, complex &c){
	cout<<"\nThe complex number is: ";
	cout<<c.real<<"+"<<c.imag<<"i";

}

int main(){
	complex c1, c2, c3, c4;
	int ch;
	
	cin>>c1;
	cout<<c1;
	
	cin>>c2;
	cout<<c2;
	
	while (true){
		
		cout<<"\nEnter choice: ";
		cin>>ch;
		
		if (ch == 1){
			c3 = c1 + c2;
			cout<<"Addition is: ";
			cout<<c3;
		}
		
		else if (ch == 2){
			c4 = c1 * c2;
			cout<<"Multiplication is: ";
			cout<<c4;
		}
		
		else if (ch == 3){
			cout<<"ThankYou"<<endl;
			break;
		}
		
		else{
			cout<<"\nEnter a valid choice!\n";
		}
	}
	return 0;
}
