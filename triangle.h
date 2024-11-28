#include <cmath>
#include <iostream>

class Triangle;
class Point;
class GetPosition;
class SetNewPosition;
class IsFigure;
class FigureMove;
class getPerimeter;
class isEqualSquare;

class Point {
private
    :    double x_{ 0.0 };
         double y_{ 0.0 };
public:
    Point() 
        : x_(0.0),
          y_(0.0)
    {}
    Point(double x0, double y0) 
        : x_(x0),
          y_(x0)
    {}
    Point(const Point& object) 
        : x_(object.x_),
          y_(object.y_)
    {}

    bool operator==(const Point& right) const;
    bool operator<(const Point& right) const;
    Point operator+(double k) const;

    friend std::ostream& operator<<(std::ostream& out, const Point& object);
    friend std::istream& operator>>(std::istream& in, Point& object);
    ~Point() {}

};
bool Point::operator==(const Point& right) const
{return ((x_ == right.x_) && (y_ == right.y_));}

bool Point::operator<(const Point& right) const
{return ((x_ * x_ + y_ * y_) < (right.x_ * right.x_ + right.y_ * right.y_));}

Point Point::operator+(double k) const
{return Point(x_ + k, y_ + k);}

std::ostream& operator<<(std::ostream& out, const Point& object)
{return (out << "x= " << object.x_ << "; y= " << object.y_);}

std::istream& operator>>(std::istream& in, Point& object)
{return (in >> object.x_ >> object.y_);}

class Triangle//: private Point,          // basic class to build a triangle
    //  private SetNewPosition, // to set a new position for one point of the triangle
     // private GetPosition,    // to check the positionn of one point of the triangle
      //private IsFigure,       // to check if a figure is a triangle
      //private FigureMove,     // to move the triangle N positions
      //private getPerimeter    // to check the perimeter of the triangle
{ // проблема 1: при можественном наследовании получаю ошибку с отсутствием базового класса
  // проблема 2: override не хочет вариться. Пишет, что ничего не переопределяю, хотя по факту переопределяю
  // проблема 3: проблема с инициализациями и передачей параметров в методы
    friend class Point;
    friend class SetNewPosition;
    friend class GetPosition;
    friend class IsFigure;
    friend class FigureMove;
    friend class getPerimeter;
private
:   double
    a_x{}, a_y{},
    b_x{}, b_y{},
    c_x{}, c_y{};
   
    Point
    a, b, c;
public:

    std::string nameoft;

    Triangle() :
        a{ 0.0, 0.0 },
        b{ 0.0, 1.0 },
        c{ 1.0, 0.0 }
    {}
    Triangle(double a_x, double a_y,
        double b_x, double b_y,
        double c_x, double c_y)
        :
        a{ a_x, a_y },
        b{ b_x, b_y },
        c{ c_x, c_y }
    {}
    Triangle(Point& a_, Point& b_, Point& c_) :
        a{ a_ },
        b{ b_ },
        c{ c_ }
    {}
    Triangle(Point& a_, Point& b_, Point& c_, std::string name)
        :
        a{ a_ },
        b{ b_ },
        c{ c_ },
        nameoft{ name }

    {}
Triangle(const Triangle& triangle):
    a{ triangle.a },
    b{ triangle.b },
    c{ triangle.c }
{}

long double
ABlen = pow(((pow(b_x - a_x, 2)) + (pow(b_y - a_y, 2))), (1 / 2)),
AClen = pow(((pow(c_x - a_x, 2)) + (pow(c_y - a_y, 2))), (1 / 2)),
BClen = pow(((pow(c_x - b_x, 2)) + (pow(c_y - b_y, 2))), (1 / 2)),
perimeter_triangle = ABlen + AClen + BClen,
half_perimeter_triangle = perimeter_triangle / 2.0,
square = pow((half_perimeter_triangle *
    ((half_perimeter_triangle - ABlen) *
        (half_perimeter_triangle - AClen) *
        (half_perimeter_triangle - BClen))), (1 / 2));

long double squareoft = square;
long double perimetert = perimeter_triangle;
Point A = a, B = b, C = c;

void setA(double a_xn, double a_yn) {
    this->a = { a_xn, a_yn };
    std::cout << "new position for point a: " << this->a;
}
void setB(double b_xn, double b_yn) {
    this->b = { b_xn, b_yn };
    std::cout << "new position for point b: " << this->b;
}
void setC(double c_xn, double c_yn) {
    this->c = { c_xn, c_yn };
    std::cout << "new position for point c: " << this->c;
}


void getA() {std::cout << "a point: " << this->a << std::endl; }//move не передает сюда this пачиму?

void getB() {std::cout << "b point: " << this->b << std::endl; }

void getC() {std::cout << "c point: " << this->c << std::endl; }

bool isFigure() {

    try { return ABlen<AClen+BClen && AClen<ABlen+BClen && BClen<ABlen+AClen; }
    catch (std::runtime_error) {
        std::cout << "Triangle is a degenerate";
        return 0;
    }
    return 0;
}

void get_perimeter(Point& a_, Point& b_, Point& c_) {   
    std::cout << "The perimeter of the " << nameoft << " is:" << perimeter_triangle;
}
void get_perimeter(Triangle& some_triangle) {
    std::cout << "The perimeter of the " << some_triangle.nameoft << " is:" << some_triangle.perimeter_triangle;
}
void get_perimeter() {
    std::cout << "The perimeter of the " << nameoft << " is:" << perimeter_triangle;
}
Triangle& move(const double k_x, const double k_y) {
    this->a_x = this->a_x + k_x;
    this->b_x = this->b_x + k_x;
    this->c_x = this->c_x + k_x;
                
    this->a_y = this->a_y + k_y;
    this->c_y = this->c_y + k_y;
    this->b_y = this->b_y + k_y;
    
     return *this;
}
double& move(const double k) {
    std::cout << a_x;
    this->a_x = this->a_x + k;
    std::cout << a_x;
    this->b_x = this->b_x + k;
    this->c_x = this->c_x + k;
                
    this->a_y = this->a_y + k;
    this->b_y = this->b_y + k;
    this->c_y = this->c_y + k;
    return this->a_x;
    //return *this;
}

~Triangle() {}
};

class SetNewPosition
{
protected
    : virtual void setA(double a_x, double a_y) {}
      virtual void setB(double b_x, double b_y) {}
      virtual void setC(double a_x, double c_y) {}
public
    : virtual ~SetNewPosition() {}
};

class GetPosition
{
protected
    : virtual void getA(Point& a) {}
      virtual void getB() {}
      virtual void getC() {}
public
    : virtual ~GetPosition() {}
};

class IsFigure
{
protected
    : virtual bool isFigure() {}
public
    : virtual ~IsFigure() {}
};

class FigureMove
{
protected
    : virtual Triangle& move(const double k_x, const double k_y) {}
      virtual double& move(const double k) {}
public
    : virtual ~FigureMove() {}
};

class getPerimeter
{
protected
    : virtual void get_perimeter(Point& a_, Point& b_, Point& c_) {}
      virtual void get_perimeter(Triangle& some_triangle) {}
      virtual void get_perimeter() {}
public
    : virtual ~getPerimeter() {}
};

class isEqualSquare
{
public:   
    static bool is_equal_square(Triangle& A, Triangle& B) 
    {
        return A.squareoft == B.squareoft;
    }
    ~isEqualSquare() {}
};

class isEqual
{
public:
    static bool is_equal(Triangle& A, Triangle& B)
    {
        return A.A == B.A && A.B == B.B && A.C == B.C;
    }
};
