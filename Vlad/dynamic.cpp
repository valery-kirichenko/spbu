int main() {
	int i;
	cin >> i;
	int *b = new int [i];
	for (int a = 0; a < i; a++) {
		cin >> b[a];
	}
	delete  []b;
	//b = &a;
	//c = *b; //c = 5
	//*b = 6;
	//std::cout << a;
	
}