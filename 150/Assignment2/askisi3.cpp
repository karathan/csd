#include "askisi3.h"		

float Perimeter(float length, float width){

	float per;
	per= 2* length + 2* width;
	return per;
}

float Area(float length, float width){

	float area;
	area= length * width;
	return area;
}

int main() {

	float length,width,p,a;
	Rectangle * rect;
	rect = new Rectangle(1,1) ;
	
	cout << "Please give length and width:" <<endl;
	cin >> length >> width;
	*rect = Rectangle(length,width);
	
	p= Perimeter(rect->getL(),rect->getW());
	cout << "The perimeter is: " << p << endl;

	a= Area(rect->getL(),rect->getW());
	cout << "The area is: " << a << endl;
	return 0;
}
