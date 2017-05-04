#include <iostream>

class SEG {
	int x, y;

	public:
	void set_val(int iX, int iY) {
		x = iX;
		y = iY;
	}
	void print_val() {
		std::cout << x << " " << y << std::endl;
	}
	
	friend SEG dup(SEG);
};

SEG dup(SEG source) {
	SEG seg1;
	seg1.set_val(source.x * 2, source.y * 2);
	return seg1;
}

int main() {
	SEG sg;
	sg.set_val(2, 4);
	sg.print_val();
	dup(sg).print_val();
	return 0;
}
