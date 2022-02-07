#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    T setx(T x)
    {
        this->x = x;
    }
    T getx()
    {
        return x;
    }
    V sety(V y)
    {
        this->y = y;
    }
    V gety()
    {
        return y;
    }
};

int main()
{

    Pair<Pair<int, int>, int> p1;

    Pair<int, int> p2;

    p2.setx(0);
    p2.sety(1);

    p1.setx(p2);
    p1.sety(2);

    cout << p1.getx().getx() << " " << p1.getx().gety() << " " << p1.gety();
}