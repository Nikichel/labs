#pragma once
template <typename T>
struct node {
	T inform;		//����������
	node* nx;		//��������� �� ���������
	node* pr;		//��������� �� ���������� �������

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