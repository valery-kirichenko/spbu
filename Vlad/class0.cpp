class action {
public:
	int newx, newy;
	action(int newx, int newy) {
		this->newx = newx*2;
		this->newy = newy*2;
	}
	~action(){std::cout << std::endl << "It works!";};
};

int main() {
	int x, y;
	std::cout << "Imput 2 numbers: ";
	std::cin >> x >> y;
	std::cout << "Your numbers: " << x << ' ' << y << std::endl;
	action body(x, y);
	std::cout << "New numbers: " << body.newx << ' ' << body.newy;
}
