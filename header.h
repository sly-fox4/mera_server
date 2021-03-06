#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <System.hpp>
#include <vector>



using namespace std;

void StartWinSock();
void CreateSock();
void Waiting();

struct flightData          //��������� ��� 1 ������
{
	char idFrom[4];
	char nameFrom[30];
	char idTo[4];
	char nameTo[30];
	int timeFrom;
	int timeTo;
	bool typeOfFlight;
	int date;
};

struct AirName         //��������� ��� ������ �� ������� ����������
{
	char id[4];
	char name[30];
};

class Airport
{
	private:
		char name[30];

		//vector<flightData> flightList;
	public:
		vector<flightData> flightList;
		char id[4];
		Airport(AirName);
		void getAirport();
		void sendFlightList();
};

class Server
{
	private:
		WSAData wsa;
		SOCKET Listen;
		SOCKET Connect;
		SOCKADDR_IN Server;
	public:
		vector<AirName> airNameList;
		vector<Airport> airList;
		Server();

		void startListening();

		void getAirList();
		void sendAirList();

		void findAirport(AirName );
		void closeSocket();
};


