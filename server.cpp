#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <winsock2.h>

using namespace std;

int main()
{
	cout << "Server: " << endl;

    char message[MAX_PATH];

    WSAData wsa;
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

	system("PAUSE");





	return 0;
}
