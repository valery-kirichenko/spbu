#pragma once

template <typename defbb>
void bsort(defbb  *mass, int size, int mode)
{
	defbb *buff = new defbb;
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			if (((mass[i] > mass[j]) && (mode == 1)) || ((mass[i] < mass[j]) && (mode == -1))) {
				*buff = mass[i];
				mass[i] = mass[j];
				mass[j] = *buff;
			}
	delete buff;
}

template<typename defs>
void selsort(defs *mass, int size, int mode)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
			if (((mass[j] > mass[min]) && (mode == -1)) || ((mass[j] < mass[min]) && (mode == 1)))
				min = j;

		if (min != i)
		{
			defs *buff = new defs;
			*buff = mass[i];
			mass[i] = mass[min];
			mass[min] = *buff;
			delete buff;
		}
	}
}


template <typename defis>
void inssort(defis *mass, int size, int mode)
{
		defis *buff = new defis;
		int post;
		for (int c = 1; c < size; c++) {
			*buff = mass[c];
			post = c - 1;
			while (((post >= 0) && (mass[post] > *buff) && (mode == 1)) || ((post >= 0) && (mass[post] < *buff) && (mode == -1))) {
				mass[post + 1] = mass[post];
				mass[post] = *buff;
				post--;	
			}
			
		}
		delete buff;
}

template <typename defqs>
void qcksort(defqs *a, long size, int mode) {


	long i = 0, j = size - 1;
	defqs buff, p;

	p = a[size / 2];
	if (mode == 1) {
		do {
			while (a[i] < p) i++;
			while (a[j] > p) j--;

			if (i <= j) {
				buff = a[i]; a[i] = a[j]; a[j] = buff;
				i++; j--;
			}
		} while (i <= j);

		if (j > 0) qcksort(a, j, mode);
		if (size > i) qcksort(a + i, size - i, mode);
	}
	if (mode == -1) {
		do {
			while (a[i] > p) i++;
			while (a[j] < p) j--;

			if (i <= j) {
				buff = a[i]; a[i] = a[j]; a[j] = buff;
				i++; j--;
			}
		} while (i <= j);

		if (j > 0) qcksort(a, j, mode);
		if (size > i) qcksort(a + i, size - i, mode);
	}
}

