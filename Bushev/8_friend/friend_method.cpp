#include <iostream>

using namespace std;

class Coord2 {
	int x, y;

	void setXY(int x, int y){
		this->x = x;
		this->y = y;
	}

public:
	Coord2(int x, int y){
        setXY(x, y);
	}

	int getX(){
		return x;
	}

	int getY(){
		return y;
	}

	friend Coord2 x2me(Coord2);
};

Coord2 x2me(Coord2 coord){
    coord.setXY(coord.getX()*2, coord.getY()*2);
	return coord;
}

int main(){
	Coord2 xy(5, 5);
	Coord2 x2xy = x2me(xy);

	cout << "X, Y: " << xy.getX() << " " << xy.getY() << endl;
	cout << "x2 X, Y: " << x2xy.getX() << " " << x2xy.getY() << endl;

    return 0;
}
