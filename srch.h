#pragma once
template <typename defl>
int linesrch(defl *mass, defl val, int size)
{
	if (size == 0) {
		return -1;

	}
	for (int i = 0; i < size; i++)
		if (val == mass[i])
			return i;
	return -1;
}


template <typename defb>
int binarsrch(defb *mass, defb val, int size)
{
	int num = 0, inf = 0, sup = size - 1;
	if (sup == -1) {
		return sup;

	}
	while (inf < sup) {
		num = inf + (sup - inf) / 2;
		if (val <= mass[num])
			sup = num;
		else
			inf = num + 1;
	}
	if (mass[sup] == val)
		return sup;
	else
		return -1;
}