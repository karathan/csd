#include "std_lib_facilities.h"
using namespace std;


int power(int base, int exponent) {
	int temp;

	if (i==1){
		temp = base;
		i++;
	}
	if (exponent==1){
		
		return temp;

	}else{
		
		temp=temp*base;
		exponent--;
		power(base,exponent); 
	} 

	
}
int main(){

	int base, exponent,p;


	cout << "Please enter a base and an exponent: ";
	cin >> base >> exponent ;
	cout << "power(" << base << "," << exponent << ") = " ;
	p=power(base,exponent);
	cout << p;


}