#include "macros.h"
class Shape{};
class TwoD:public Shape{};
class ThreeD:public Shape{};
class Triangle: public TwoD{};
class Circle : public TwoD{};
class Square: public TwoD{};
class Sphere:public ThreeD{};
class Cube: public ThreeD{};
class Thetrahadon: public ThreeD{};
int main() {

}
