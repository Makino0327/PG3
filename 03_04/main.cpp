#include "Circle.h"
#include "Rectangle.h"

int main() {

    IShape* shapes[2];

    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 3.0);

    for (int i = 0; i < 2; i++) {
        shapes[i]->Size();
        shapes[i]->Draw();
    }

    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}
