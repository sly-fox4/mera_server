#include "header.h"

//Получает вектор всех аэропортов с уже записанной инфой (в рамках обьекта Сервер)
void Server::getAirList()
{
	FILE *f;
	AirName aname;
	f=fopen("airlist.dat", "rb");                   //Загружаем файл БД
	while (fread(&aname, sizeof(AirName), 1, f))    //Считываем записи пока они есть
	{
		//cout<< aname.name<<endl;
		airNameList.push_back(aname);
		Airport air(aname);                         //Создаем обьект 1 Аэропорта
		air.getAirport();                           //Получаем его рейсы
		airList.push_back(air);                     //записываем его в список
		//cout<<air.flightList[0].idFrom<<endl;
	}
}
//Конструктур записываем часть инфы ИД и ИМЯ
Airport::Airport(AirName idname)
{
	strcpy(id,idname.id);
	strcpy(name, idname.name);
}


//Получаем инфу об 1 аэропорте (в рамках обьекта Аэропорт)
void Airport::getAirport()
{
    FILE *f;
	flightData fl;
	f=fopen("file.dat", "rb");                   //Загружаем файл нашей БД
	while(fread(&fl, sizeof(flightData), 1, f))  //Пока в нем есть записи читаем
	{
		//cout<<fl.idTo;
		if(strcmp(fl.idFrom,id)==0)                 //Если строки совпали
		{                                        //записываем в лист полетов
			flightList.push_back(fl);

		}
	}
	fclose(f);
}




