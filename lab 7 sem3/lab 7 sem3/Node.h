#pragma once
template <typename T>
struct nodeQ {
	T inform;		//информация
	nodeQ* nx;		//указатель на следующий
	nodeQ* pr;		//указатель на предыдущий элемент

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