#include <iostream>
#include <string>
#include <cmath>

struct BoundingBoxDimensions
{
    double width;
    double height;
};

class Shape
{
    protected:
    double areaFigure = 0;

public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;
};

class Circle : virtual public Shape
{
private:
    double radius = 0;    

public:
    Circle(double inRadius)
    {
        radius = inRadius;
        areaFigure = 3.14 * radius * radius;
    }

    virtual double square()
    {
        return areaFigure;
    }

    virtual BoundingBoxDimensions dimensions()
    {
        BoundingBoxDimensions temp;
        temp.width = 2 * radius;
        temp.height = 2 * radius;
        return temp;
    }

    virtual std::string type()
    {
        return "Circle";
    }
};

class Rectangle : virtual public Shape
{
private:
    double RWidth;
    double RHeight;
public:
    Rectangle(double inWidth, double inHeight)
    {
        RWidth = inWidth;
        RHeight = inHeight;
        areaFigure = RWidth * RHeight;
    }

    virtual double square()
    {
        return areaFigure;
    }

    virtual BoundingBoxDimensions dimensions()
    {
        BoundingBoxDimensions temp;
        temp.height = RHeight;
        temp.width = RWidth;
        return temp;
    }

    virtual std::string type()
    {
        return "Rectangle";
    }
};

class Triangle : virtual public Shape
{
private:
    double a;
    double b;
    double c;

public:
    Triangle(double inA, double inB, double inC)
    {
        a = inA;
        b = inB;
        c = inC;
    }

    virtual double square()
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    virtual BoundingBoxDimensions dimensions()
    {
        double p = (a + b + c) / 2;
        double r = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));

        BoundingBoxDimensions temp;
        temp.width = 2 * r;
        temp.height = 2 * r;
        return temp;
    }

    virtual std::string type()
    {
        return "Triangle";
    }
};

void printParams(Shape* shape)
{
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    std::cout << "Width: " << shape->dimensions().width << std::endl;
    std::cout << "Height: " << shape->dimensions().height << std::endl;    
}

int main() {
    Circle c(3);
    printParams(&c);

    Rectangle r(2, 4);
    printParams(&r);

    Triangle t(3, 4, 5);
    printParams(&t);
}