#include "header.h"



int main()
{
	Server s1;
	s1.getAirList();      //Скачиваем Аэропорты из БД на сервер
	s1.sendAirList();     //Отсылаем список доступных Аэропортов на Клиент

	s1.startListening();


	s1.closeSocket();     //Закрываем сокеты
	WSACleanup();
	system("PAUSE");
	return 0;
}
