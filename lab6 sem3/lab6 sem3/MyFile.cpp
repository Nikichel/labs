#include "MyFile.h"

//template <typename T>
//void MyFile<T>::fileClose() {				//закрыть
//	try {
//		if (_outFile.is_open())
//			_outFile.close();
//		if (_inFile.is_open())
//			_inFile.close();				//закрыть открытый файл
//		if (_outFile.is_open() || _inFile.is_open()) {			//если не закрылся
//			throw MyExceptionFILE(101, "Ошибка закрытия файла", "Файл поврежден");
//		}
//	}
//	catch (MyExceptionFILE ErrFile) {
//		ErrFile.what();			//вывод ошибки
//	}
//};
//
//template <typename T>
//void MyFile<T>::fileWrite(T& inform) {		//записать
//	try {
//		if (!_outFile.is_open() && _inFile.is_open())		//если режмм чтения
//			throw MyExceptionFILE(-100, "Неверный режим", "Вы пытаете записать в файл в режиме чтения");
//		if (!isOpen())
//			throw MyExceptionFILE(-101, "Файл закрыт", "Откройте файл в режиме записи");
//		_outFile << endl;
//		_outFile << inform;			//запись
//	}
//	catch (MyExceptionFILE ErrFile) {
//		ErrFile.what();			//вывод ошибки
//	}
//};
//
//template <typename T>
//void MyFile<T>::fileRead(T& inform) {		//прочитать
//	try {
//		if (!_outFile.is_open() && _inFile.is_open())				//если не тот режим
//			throw MyExceptionFILE(-100, "Неверный режим", "Вы пытаете прочить из файла в режиме записи");
//		if (!isOpen())
//			throw MyExceptionFILE(-101, "Файл закрыт", "Откройте файл в режиме чтения");
//		_outFile >> inform;			//чтение
//	}
//	catch (MyExceptionFILE ErrFile) {
//		ErrFile.what();				//вывод ошибки
//	}
//};
//
//template <typename T>
//void MyFile<T>::remote() {					//в начало файла
//	if (_outFile.is_open())
//		_outFile.seekp(0, ios::beg);		//перемещение указатель в начале
//};
//
//template <typename T>
//bool MyFile<T>::isEnd() {					//конец?
//	if (_inFile.eof() && _inFile.is_open() || _outFile.eof() && _outFile.is_open())
//		return true;			//да конец
//	else
//		return false;		//нет 
//};
//
//template <typename T>
//bool MyFile<T>::isOpen() {
//	if (_inFile.is_open() || _outFile.is_open())
//		return true;
//	return false;
//}