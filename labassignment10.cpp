// Rahul Suthar
// am8633


#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle() {
        radius = 0.0;
    }

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    double getArea() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Circle c1;
    c1.setRadius(5.0);

    cout << "Radius: " << c1.getRadius() << endl;
    cout << "Area: " << c1.getArea() << endl;

    return 0;
}
