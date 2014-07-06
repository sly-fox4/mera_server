#include "header.h"

Server::Server()
{
	WORD Version = MAKEWORD(2, 1);
	WSAStartup(Version, &wsa);
    if(WSAStartup(Version, &wsa) != 0)
	{
		cout << "WSA library startup error." << endl;
	}
	else
	{
		cout << "WSA library startup complite." << endl;
	}
	Listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	Connect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(Listen == SOCKET_ERROR || Connect == SOCKET_ERROR)
	{
		cout << "Socket error. Can't create socket." << endl;
	}
	else
	{
		cout << "Socket create complite." << endl;
	}

	Server.sin_family = AF_INET;
	Server.sin_port = htons(1337);
	Server.sin_addr.s_addr = INADDR_ANY;

	if( bind(Listen, (SOCKADDR*)&Server, sizeof(Server)) == SOCKET_ERROR)
	{
		cout << "Can't bind socket." << endl;
	}
	else
	{
		cout << "Socket bind complite." << endl;
	}
	listen(Listen, SOMAXCONN);

	//airList = new Airport();
}

//message mes;

void Server::startListening()
{
	  while(1)
	   {
			if(Connect = accept(Listen, NULL, NULL))
			{
				cout << "Client complite connected." << endl;
				for (int i = 0; i < airNameList.size(); i++)
				{
					send(Connect,(char*) &airNameList[i], sizeof(AirName), 0);
				}
				break;
			}
			Sleep(100);
	   }
}

void Server::closeSocket()
{
	closesocket(Listen);
	closesocket(Connect);
}
