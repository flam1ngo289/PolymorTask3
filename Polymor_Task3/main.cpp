#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;
    int numSides;
public:
    Figure(const std::string& figure_name, int sides) {
        name = figure_name;
        numSides = sides;
    }
    
   virtual void print_info() {
        std::cout << name << std::endl;
       std::cout << "Количество сторон: " <<  numSides << std::endl;
    }
    
    virtual bool check() {
        return numSides > 0;
    }
};

class Triangle : public Figure{
protected:
    int a, b, c;
    int A, B, C;
    
public:
    Triangle(int side1, int side2, int side3, int angle1, int angle2, int angle3) : Figure("Треугольник", 3), a(side1), b(side2), c(side3), A(angle1), B(angle2), C(angle3){}
    
    void print_info() override {
        std::cout << name << ":" << std::endl;
        std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
        std::cout << std::endl;
    }
    
    bool check() override {
        bool sidesCheck = a > 0 && b > 0 && c >0;
        bool angleCheck = A + B + C == 180;
        return sidesCheck && angleCheck && Figure::check();
    }
};

class RightTriangle : public Triangle{
public:
    RightTriangle(int side1, int side2, int side3, int angle1, int angle2) : Triangle(side1, side2, side3, angle1, angle2, 90) {
        name = "Прямоугольный треугольник";
    }
    
    bool check() override {
        return C == 90 && Triangle::check();
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side1, int side2, int angle1, int angle2) : Triangle(side1, side2, side1, angle1, angle2, angle1){
        name = "Равнобедренный треугольник";
    }
    
    bool check() override {
        return a == c && A && C && Triangle::check();
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side1) : Triangle(side1, side1, side1, 60, 60, 60){
        name = "Равносторонний треугольник";
    }
    bool check() override {
        return a == b == c && A == C && Triangle::check();
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quadrangle(int side1, int side2, int side3, int side4, int angle1, int angle2, int angle3, int angle4) : Figure("Четырехугольник", 4), a(side1), b(side2), c(side3), d(side4), A(angle1), B(angle2), C(angle3), D(angle4){}
    
    void print_info() override {
        std::cout << name << ":" << std::endl;
        std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d="<< d << std::endl;
        std::cout  << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D="<< D;
        std::cout << std::endl;
    }
    
    bool check() override {
        bool sidesCheck = a > 0 && b > 0 && c > 0 && d > 0;
        bool angleCheck = A + B + C + D == 360;
        return sidesCheck && angleCheck && Figure::check();
    }
};
class Parallelogram : public Quadrangle{
public:
    Parallelogram(int side1, int side2, int angle1, int angle2) : Quadrangle(side1, side2, side1, side2, angle1, angle2, angle1, angle2){
        name = "Параллелограмм";
    }
    
    bool check() override {
        return a==c && b == d && A == C && B == D && Quadrangle::check();
    }
};

class Rectangle : public Parallelogram{
public:
    Rectangle(int side1, int side2) : Parallelogram(side1, side2, 90, 90){
        name = "Прямоугольник";
    }
    bool check() override {
        return a==c && b == d && A == 90 && B == 90 && C == 90 && D == 90 && Quadrangle::check();
    }
};

class Square : public Rectangle{
public:
    Square(int side1) : Rectangle(side1, 90){
        name = "Квадрат";
    }
    
    bool check() override {
        return a==c==b==d && A == 90 && B == 90 && C == 90 && D == 90 && Quadrangle::check();
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int side1, int angle1, int angle2) : Parallelogram(side1, side1, angle1, angle2){
        name = "Ромб";
    }
    
    bool check() override {
        return a==c==b==d && A == C && B == D && Quadrangle::check();
    }
};

void print_info(Figure* figure){
    figure->print_info();
    if (figure->check()) {
        std::cout << "Правильная\n\n";
    } else {
        std::cout << "Неправильная\n\n";
    }

}

int main(int argc, const char * argv[]) {
    
    Figure figure("Фигура", 0);
    print_info(&figure);

    Triangle triangle(10, 20, 30, 50, 60 ,70);
    print_info(&triangle);
    
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    print_info(&rightTriangle);
    
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    print_info(&isoscelesTriangle);
    
    EquilateralTriangle equilateralTriangle(30);
    print_info(&equilateralTriangle);
    
    Quadrangle quadrangle(10,20,30,40,50,60,70,80);
    print_info(&quadrangle);
    
    Rectangle rectangle(10, 20);
    print_info(&rectangle);
    
    Parallelogram parallelogram(20,30, 30, 40);
    print_info(&parallelogram);
    
    Rhombus rhombus(30, 30, 40);
    print_info(&rhombus);

        return 0;
}
