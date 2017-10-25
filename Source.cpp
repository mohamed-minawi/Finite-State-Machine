#include <iostream>
#include "FSM.h"
using namespace std;


int main(int argc, char *argv[])
{
	string x;

	if (argc > 1)
		x = argv[1];
	else cin >> x;

	try {

		FSM one;
		one.loadFSM(x);
		one.runFSM();
	}
	catch (const string & e)
	{
		cout << endl << "Exception: " << e << endl;
	}
	catch (invalid_argument & e)
	{
		cout << endl << "Exception: " << e.what() << endl;

	}
	system("pause");
    return 0;
}