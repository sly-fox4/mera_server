#include "header.h"



int main()
{
	Server s1;
	s1.getAirList();      //��������� ��������� �� �� �� ������
	s1.sendAirList();     //�������� ������ ��������� ���������� �� ������
    cout<<"Start LISTENING" << endl;
	s1.closeSocket();     //��������� ������
	s1.startListening();


	s1.closeSocket();     //��������� ������
	WSACleanup();
	system("PAUSE");
	return 0;
}
