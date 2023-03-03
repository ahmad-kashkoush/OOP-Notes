// vector<different shapes>
#include<iostream>
#include<vector>
#define el "\n"
using namespace std;
class Shape{
public:
    virtual void PrintArea(){cout<<"Shape";}
    virtual Shape* Clone(){return nullptr;}
};
class Circle: public Shape{
private:
   double radius;
public:
    Circle(double a):radius(a){}
    virtual void PrintArea()override{
        cout<<"Circle Area: "<<(double)radius*radius*(double(22/7))<<el;
    }
    Circle()=default;
    virtual Shape *Clone()override{return new Circle(*this);}
};
class Rectangle:public Shape{
private:
    int w, h;
public:
    Rectangle()=default;
    Rectangle(int a, int b):w(a),h(b){}
    virtual void PrintArea()override{
        cout<<"Rectangle Area: "<<w*h<<el;
    }
    virtual Shape *Clone()override{
        return new Rectangle(*this);
    }
};
class Editor{
private:
    vector<Shape*> Shapes;
public:
    Editor(){Shapes.clear();}
    void AddShape(Shape *sh){
        Shapes.emplace_back(sh->Clone());
    }
    void Print(){
        for(auto i:Shapes)
            i->PrintArea();
    }
    ~Editor(){
        for(auto ShapePtr:Shapes)
            delete ShapePtr;
    }
};
int main(){
    Editor editor;
    editor.AddShape(new Circle(7));
    editor.AddShape(new Rectangle(2, 4));
    editor.AddShape(new Circle(14));
    editor.Print();
}