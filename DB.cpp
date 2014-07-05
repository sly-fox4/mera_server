#include "header.h"

//Получает вектор всех аэропортов с уже записанной инфой (в рамках обьекта Сервер)
void Server::getAirList()
{
	FILE *f;
	AirName aname;
	f=fopen("airlist.dat", "rb");
	while (fread(&aname, sizeof(AirName), 1, f))
	{
		Airport air(aname);
		air.getAirport();
		airList.push_back(air);
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
	f=fopen("file.dat", "rb");
	while(fread(&fl, sizeof(flightData), 1, f))
	{
		if (fl.idFrom==id)
		{
			flightList.push_back(fl);
		}
	}
	fclose(f);
}




