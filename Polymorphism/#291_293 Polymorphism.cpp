// vector<different shapes>
#include<iostream>
#include<vector>
#define el "\n"
using namespace std;
class Shape{
public:
    virtual void PrintArea(){cout<<"Shape";}
};
class Circle: public Shape{
private:
   double radius;
public:
    Circle(double a):radius(a){}
    void PrintArea(){
        cout<<"Circle Area: "<<(double)radius*radius*(double(22/7))<<el;
    }
};
class Rectangle:public Shape{
    int w, h;
public:
    Rectangle(int a, int b):w(a),h(b){}
    void PrintArea(){
        cout<<"Rectangle Area: "<<w*h<<el;
    }
};
int main(){
        //[circle, rectangle, rectangle, circle]
        vector<Shape *> v(4);
        v[0]= new Circle(7.0);
        v[1]= new Rectangle(2, 4);
        v[2]= new Rectangle(4, 8);
        v[3]= new Circle(14);
        for(auto i:v)
            i->PrintArea();

}