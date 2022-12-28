#pragma once
template <typename T>
struct node {
	T inform;		//информация
	node* nx;		//указатель на следующий
	node* pr;		//указатель на предыдущий элемент

	node() {
		nx = pr = nullptr;
	}
	
	node(const node& other) {
		this = &other;
	}

	node* operator=(const node& other) {
		this = &other;
		return this;
	}

	~node() {};
};