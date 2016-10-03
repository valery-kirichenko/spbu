int main() {
	int i;
	cin >> i;
	int *b = new int [i];
	for (int a = 0; a < i; a++) {
		cin >> b[a];
	}
	delete  []b;
}
