#include <iostream>

using namespace std;

class Seg {
	int x, y;

	void setXY(int x, int y){
		this->x = x;
		this->y = y;
	}

public:
	Seg(int x, int y){
        setXY(x, y);
	}

	int getX(){
		return x;
	}

	int getY(){
		return y;
	}

	friend Seg x2me(Seg);
};

class Square {
    int side;

public:
    Square(int v){
        side = v;
    }

    int getSide(){
        return side;
    }

	friend class Circle;
};

class Circle{
    int rad;

public:
    Circle(int v){
        rad = v;
    }

    int getRad(){
        return rad;
    }

    void convert(Square s){
        rad = s.side;
    }
};

Seg x2me(Seg coord){
    coord.setXY(coord.getX()*2, coord.getY()*2);
	return coord;
}

int main(){
	Seg xy(5, 5);
	Seg x2xy = x2me(xy);

	cout << "X, Y: " << xy.getX() << " " << xy.getY() << endl;
	cout << "x2 X, Y: " << x2xy.getX() << " " << x2xy.getY() << endl << endl;

	Square s(10); Circle c(33);
	cout << "Square: " << s.getSide() << endl;
	cout << "Circle: " << c.getRad() << endl;

	c.convert(s);

	cout << "Converted circle: " << c.getRad() << endl;

    return 0;
}
