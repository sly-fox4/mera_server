#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <System.hpp>
#include <vector>

#define numOfAir 10

using namespace std;

void StartWinSock();
void CreateSock();
void Waiting();

struct flight
{
	char idFrom[3];
	char nameFrom[20];
	char idTo[3];
	char nameTo[20];
	bool typeOfFlight;
	TDateTime date;
	flight* next;
};

class Airport
{
	private:
		char id[3];
		char name[20];
		flight firstFlight;
	public:
		Airport();
		void getAirport();
};

class Server
{
	private:
		WSAData wsa;
		SOCKET Listen;
		SOCKET Connect;
		SOCKADDR_IN Server;
	public:
		Server();
		void startListening();
		void sendAirList();
		void sendFlightList();
		void getFlightList();
		vector<Airport> airList;
};


struct message
{
	int ID;
	string time;
};
