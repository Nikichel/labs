#pragma once
template <typename T>
struct nodeQ {
	T inform;		//����������
	nodeQ* nx;		//��������� �� ���������
	nodeQ* pr;		//��������� �� ���������� �������

	nodeQ() {
		nx = pr = nullptr;
	}
	
	nodeQ(const nodeQ& other) {
		this = &other;
	}

	nodeQ* operator=(const nodeQ& other) {
		this = &other;
		return this;
	}

	~nodeQ() {};
};