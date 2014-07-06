#include "header.h"



int main()
{
	Server s1;
	s1.getAirList();      //Скачиваем Аэропорты из БД на сервер
	s1.sendAirList();     //Отсылаем список доступных Аэропортов на Клиент
    cout<<"Start LISTENING" << endl;
	s1.closeSocket();     //Закрываем сокеты
	s1.startListening();


	s1.closeSocket();     //Закрываем сокеты
	WSACleanup();
	system("PAUSE");
	return 0;
}
