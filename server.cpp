
#include "header.h"



int main()
{

	StartWinSock();

	CreateSock();
	Waiting();


	//closesocket(Listen);
	//closesocket(Connect);
	WSACleanup();
	system("PAUSE");
	return 0;
}
