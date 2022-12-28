#pragma once
#include "Queue.cpp"
#include "Queue.h"
template <typename T>
class algorithm		//����� ����������
{
public:

	//void sortAscendingOrder(queue<T>::template Iterator itBeg, queue<T>::template Iterator itEnd) {		//���������� �� �����������
	//	T objMin, objJ;			//������ min � j �����������
	//	//objMin = objJ = (*itBeg).ChooseParams();		//����� ���������
	//	queue<T>::template Iterator min;			//�������� �� ����������� �������
	//	queue<T>::template Iterator j;				//�������� �� itBeg �� �����
	//	do
	//	{
	//		min = itBeg;
	//		j = itBeg;
	//		do
	//		{
	//			objMin.replace(*min);
	//			objJ.replace(*j);			//�������� �� ����� ���������
	//			if (objJ > objMin)		//����������
	//				min = j;
	//			j++;
	//		} while (j != itEnd);		//���� �� �����
	//		if (min != itBeg)
	//		{
	//			T tmp = *min;
	//			*min = *itBeg;
	//			*itBeg = tmp;			//������ �������
	//		}
	//		itBeg++;
	//	} while (itBeg != itEnd);		//���� �� �����
	//};

	//void sortDescendingOrder(queue<T>::template Iterator itBeg, queue<T>::template Iterator itEnd) {		//���������� ��	��������
	//	T objMin, objJ;			//������ min � j �����������
	//	objMin = objJ = (*itBeg).ChooseParams();		//����� ���������
	//	queue<T>::template Iterator min;			//�������� �� ����������� �������
	//	queue<T>::template Iterator j;				//�������� �� itBeg �� �����
	//	do
	//	{
	//		min = itBeg;
	//		j = itBeg;
	//		do
	//		{
	//			objMin.replace(*min);
	//			objJ.replace(*j);			//�������� �� ����� ���������
	//			if (objMin > objJ)		//����������
	//				min = j;
	//			j++;
	//		} while (j != itEnd);		//���� �� �����
	//		if (min != itBeg)
	//		{
	//			T tmp = *min;
	//			*min = *itBeg;
	//			*itBeg = tmp;			//������ �������
	//		}
	//		itBeg++;
	//	} while (itBeg != itEnd);		//���� �� �����
	//};


	template <typename T>
	queue<T>::template Iterator searchObj(queue<T>::template Iterator itBeg, queue<T>::template Iterator itEnd, T obj) {					//����� ��������
		for (; itBeg != itEnd; itBeg++) {		//���� �� �����
			if (*itBeg == obj)		//����� ������
				return itBeg;
		}
		return itBeg;
	}

	template <typename T>
	queue<T> searchQueue(queue<T>::template Iterator itBeg, queue<T>::template Iterator itEnd, T obj) {		//����� �������
		queue<T> find;
		do {
			itBeg = searchObj(itBeg, itEnd, obj);		//����� ��������
			if (itBeg != itEnd) {
				find.put(*itBeg);		//��������� � �������
				itBeg++;
			}
		} while (itBeg != itEnd);
		return find;
	}
};

