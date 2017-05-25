#include <iostream>

int main() {
	int a1, a2;
	char op;
	std::cout << "Write down your expression (example: 5+8):" << std::endl;
	std::cin >> a1;
	std::cin >> op;
	std::cin >> a2;
	if (op == '+')
		std::cout << a1 << op << a2 << '=' << a1 + a2;
	if (op == '-')
		std::cout << a1 << op << a2 << '=' << a1 - a2;
	if (op == '*')
		std::cout << a1 << op << a2 << '=' << a1*a2;
	if (op == '/')
		std::cout << a1 << op << a2 << '=' << a1 / a2;
	if (op == '%')
		std::cout << a1 << op << a2 << '=' << a1%a2;
	system("pause");
}