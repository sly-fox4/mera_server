#include "header.h"



int main()
{
	Server s1;
	s1.getAirList();
	//s1.showAirlist();
	s1.startListening();
	s1.closeSocket();

	WSACleanup();
	system("PAUSE");
	return 0;
}
