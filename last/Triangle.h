#include <iostream>
#include <cmath>

class Point;
class Triangle;

class Point {
    protected
:   double x_{ 0.0 };
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

    double getX()
    {return x_;}
    double getY()
    {return y_;}


    bool operator==(const Point& right) const;
    bool operator<(const Point& right) const;
    Point operator+(double k) const;
    Point operator+(Point& obj) const;
    Point operator-(double k) const;
    Point operator-(Point& obj) const;
    Point operator/(double k) const;
    Point operator*(double k) const;

    friend std::ostream& operator<<(std::ostream& out, const Point& object);
    friend std::istream& operator>>(std::istream& in, Point& object);
    ~Point() {}

};
bool Point::operator==(const Point& right) const
{
    return ((x_ == right.x_) && (y_ == right.y_));
}

bool Point::operator<(const Point& right) const
{
    return ((x_ * x_ + y_ * y_) < (right.x_ * right.x_ + right.y_ * right.y_));
}

Point Point::operator+(double k) const
{
    return Point(x_ + k, y_ + k);
}

Point Point::operator+(Point& obj) const
{
    return Point(x_ + obj.x_, y_ + obj.y_);
}

Point Point::operator-(Point& obj) const
{
    return Point(x_ - obj.x_, y_ - obj.y_);
}

Point Point::operator-(double k) const
{
    return Point(x_ - k, y_ - k);
}

Point Point::operator/(double k) const
{
    return Point(x_ / k, y_ / k);
}

Point Point::operator*(double k) const
{
    return Point(x_ * k, y_ * k);
}

std::ostream& operator<<(std::ostream& out, const Point& object)
{
    return (out << "x = " << object.x_ << "; y = " << object.y_);
}

std::istream& operator>>(std::istream& in, Point& object)
{
    return (in >> object.x_ >> object.y_);
}

class Triangle
{
    private:
        Point A_;
        Point B_;
        Point C_;
        double square;
        double perimeter;
        double AB_len;
        double AC_len;
        double BC_len;
        double perimeter_triangle;
        double half_perimeter_triangle;
    public:
        Triangle():
            A_{0.0, 0.0},
            B_{0.0, 1.0},
            C_{1.0, 0.0}
        {}
        Triangle(
            double a_x, double a_y, 
            double b_x, double b_y, 
            double c_x, double c_y):
            A_{a_x, a_y},
            B_{b_x, b_y},
            C_{c_x, c_y}
            {}
        
        Point& setA(double x, double y)
        {
            A_ = {x, y};
        }

        Point& setB(double x, double y)
        {
            B_ = {x, y};
        }

        Point& setC(double x, double y)
        {
            C_ = {x, y};
        }

        Point getA()
        {
            return A_;
        }

        Point getB()
        {
            return B_;
        }

        Point getC()
        {
            return C_;
        }

        bool isFirure()
        {

        }

        double getPerimeter()
        {
            double a_x{A_.getX()}, b_x{B_.getX()}, c_x{C_.getX()},
                   a_y{A_.getY()}, b_y{A_.getY()}, c_y{A_.getY()};

            long double
            ABlen_BC = pow(((pow(b_x - a_x, 2)) + (pow(b_y - a_y, 2))), (1 / 2)),
            AClen_BC = pow(((pow(c_x - a_x, 2)) + (pow(c_y - a_y, 2))), (1 / 2)),
            BClen_BC = pow(((pow(c_x - b_x, 2)) + (pow(c_y - b_y, 2))), (1 / 2)),
            perimeter_triangle_BUFFER_CONTAINER = ABlen_BC + AClen_BC + BClen_BC,
            half_perimeter_triangle_BUFFER_CONTAINER = perimeter_triangle_BUFFER_CONTAINER / 2.0,
            square_BUFFER_CONTAINER = pow((half_perimeter_triangle_BUFFER_CONTAINER *
            ((half_perimeter_triangle_BUFFER_CONTAINER - ABlen_BC) *
            (half_perimeter_triangle_BUFFER_CONTAINER - AClen_BC) *
            (half_perimeter_triangle_BUFFER_CONTAINER - BClen_BC))), (1 / 2));

            AB_len = ABlen_BC;
            AC_len = AClen_BC;
            BC_len = BClen_BC;

            perimeter_triangle = perimeter_triangle_BUFFER_CONTAINER;
            half_perimeter_triangle = half_perimeter_triangle_BUFFER_CONTAINER;

            square = square_BUFFER_CONTAINER;

            return perimeter_triangle;
       }

       


};
