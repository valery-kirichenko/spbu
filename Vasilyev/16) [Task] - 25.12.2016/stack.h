#pragma once
#ifndef STACK_H
#define STACK_H

template <typename ST>
class stackV {
private:
	unsigned int size;
	struct list {
		ST value;
		list *ptr;
	};
	list *first, *last;

public:
	//Конструктор стека
	stackV()
	{
		size = 0;
		list *lst;
		lst = new list;
		lst->ptr = nullptr;
		first = lst;
		last = lst;
	}

	//Деструктор стека.
	~stackV()
	{
		if (size > 0) {
			list *temp;
			while (first->ptr != nullptr) {
				temp = first;
				first = first->ptr;
				delete temp;
			}
			delete first;
		}
		else
			delete first;
		size = 0;
	}

	//Добавление элемента в стек.
	void push(ST value)
	{
		if (size == 0) {
			if (first != nullptr) {
				first->value = value;
				last = first;
			}
			else {
				list *temp;
				temp = new list;
				temp->value = value;
				temp->ptr = nullptr;
				first = temp;
				last = temp;
			}
		}
		else {
			list *temp;
			temp = new list;
			temp->value = value;
			temp->ptr = first;
			first = temp;
		}
		size++;
	}

	//Извлечение элемента из стека
	ST pop()
	{
		ST result;
		if (size > 0) {
			list *temp;
			temp = first->ptr;
			result = first->value;
			delete first;
			first = temp;
			size--;
		}
		else
			throw "stackV<>:: empty stack!";
		return result;
	}

	//Вывод стека.
	void print() {
		list *temp;
		temp = first;
		for (unsigned int i = 0; i < size; i++) {
			std::cout << temp->value << " ";
			temp = temp->ptr;
		}
		std::cout << "\n";
	}

	//Получение размера стека.
	unsigned int getSize()
	{
		return size;
	}

	//Проверка пустоты стека.
	bool empty()
	{
		return (size == 0);
	}

	//Очистка стека.
	void clear()
	{
		if (size > 0) {
			list *temp;
			while (first->ptr != nullptr) {
				temp = first;
				first = first->ptr;
				delete temp;
			}
			delete first;
		}
		else
			delete first;
		size = 0;
		first = new list;
		first->ptr = nullptr;
		last = first;
	}
};

#endif /* STACK_H */