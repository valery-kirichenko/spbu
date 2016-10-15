#include <iostream>

typedef struct {
	int id;
	union {
		struct {
			char firstname[20];
		};
		struct {
			char lessons[20];
		};
		struct {
			int paper[20];
		};
	}_employer;
};

int main() {
	_employer st, lt, ad;
	st.id = 5;
	st.firstname[0] = 'a';
	st.firstname[1] = 0;
	lt.id = 6;
	
	return 0;
}