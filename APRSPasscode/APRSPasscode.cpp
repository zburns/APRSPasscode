// APRSPasscode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "************************************" << endl;
	cout << "* APRS CallSign PassCode Generator *" << endl;
	cout << "*            de N8ZAK              *" << endl;
	cout << "************************************" << endl;

	while (true)
	{
		char rootCall[10];

		cout << "Enter in CallSign:";
		cin >> rootCall;

		char *p1 = rootCall;
		short hash;
		short i;
		short len;
		char *ptr = rootCall;

		hash = 0x73e2;
		i=0;
		len = (short)strlen(rootCall);
		while (i<len)
		{
			hash ^= (unsigned char)(*ptr++)<<8;
			hash ^= (*ptr++);
			i+=2;
		}
		cout << "PassCode is: " << (short)(hash & 0x7fff) << endl;
	}
	return 0;
}

