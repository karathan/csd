#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Shape {
  public:
    virtual float GetArea(void) = 0;
};

class TwoDimensionalShapes: public Shape {
  public:
    virtual float GetArea(void) = 0;
};

class Square: public TwoDimensionalShapes {
  protected:
    float x, y;
  public:
    Square(float _x,float _y) : x(_x), y(_y) {}
    float GetArea() { return x*y; }
};

class Circle: public TwoDimensionalShapes {
  protected:
    float r;
  public:
    Circle(int _r) : r(_r) {}
    float GetArea() { return 3.14*pow(r,2); }
};

int main () {
  vector<Shape *> shapes;
  shapes.push_back(new Square(10,10));
  shapes.push_back(new Circle(10));

  for (int i=0; i<shapes.size();i++){
    if (Square *k = dynamic_cast<Square *>(shapes[i]))
      cout << "We have a square with area of " << shapes[i]->GetArea() << endl;
    else if (Circle *k = dynamic_cast<Circle *>(shapes[i]))
      cout << "We have a circle with area of " << shapes[i]->GetArea() << endl;
  }

  return 0;
}
