#include "header.h"

//�������� ������ ���� ���������� � ��� ���������� ����� (� ������ ������� ������)
void Server::getAirList()
{
	FILE *f;
	AirName aname;
	f=fopen("airlist.dat", "rb");                   //��������� ���� ��
	while (fread(&aname, sizeof(AirName), 1, f))    //��������� ������ ���� ��� ����
	{
        airNameList.push_back(aname);
		Airport air(aname);                         //������� ������ 1 ���������
		air.getAirport();                           //�������� ��� �����
		airList.push_back(air);                     //���������� ��� � ������
	}
}
//����������� ���������� ����� ���� �� � ���
Airport::Airport(AirName idname)
{
	strcpy(id,idname.id);
	strcpy(name, idname.name);
}


//�������� ���� �� 1 ��������� (� ������ ������� ��������)
void Airport::getAirport()
{
    FILE *f;
	flightData fl;
	f=fopen("file.dat", "rb");                   //��������� ���� ����� ��
	while(fread(&fl, sizeof(flightData), 1, f))  //���� � ��� ���� ������ ������
	{
		if(strcmp(fl.idFrom,id))                 //���� ������ �������
		{                                        //���������� � ���� �������
			flightList.push_back(fl);
		}
	}
	fclose(f);
}




