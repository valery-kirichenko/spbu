// 02.09.2016.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	string C[5]={
		"#  #  ####  #     #     ####     #   #   #  ####  ###   #     ###   #",
		"#  #  #     #     #     #  #     #   #   #  #  #  #  #  #     #  #  #",
		"####  ####  #     #     #  #      # # # #   #  #  ###   #     #  #  #",
		"#  #  #     #     #     #  #      # # # #   #  #  #  #  #     #  #   ",
		"#  #  ####  ####  ####  ####       #   #    ####  #  #  ####  ###   #"
	};
	system("color 25");
	for(int i=0;i<5;i++){
		for(int j=0;j<C[i].size();j++)
			putchar(C[i][j]);
		putchar('\n');
	}
	getch();
    return 0;
}
