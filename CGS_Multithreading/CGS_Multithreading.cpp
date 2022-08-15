#include <iostream>
#include <thread>

using namespace std;

bool DidQuit = false;
int ThreadVar = 0;
int ThreadVar2 = 0;

void HelloWorldThread()
{
	while (!DidQuit) {

		ThreadVar++;
		if (ThreadVar > 1000)
		{
			ThreadVar = 0;
		}
	}
}

void HelloWorldThread2()
{
	while (!DidQuit) {

		ThreadVar2++;
		if (ThreadVar2 > 1000)
		{
			ThreadVar2 = 0;
		}
	}
}

int main()
{
	cout << "Hello World" << endl;

	thread HWThread(HelloWorldThread);
	thread HWThread2(HelloWorldThread2);

	char UserInput;

	while (!DidQuit)
	{
		cout << "Enter any key to display counter: " << endl;
		cout << "Enter q to quit" << endl;
		cin >> UserInput;
		DidQuit = (UserInput == 'q');

		cout << "Thread Var: " << ThreadVar << endl;
		cout << "Thread Var 2: " << ThreadVar2 << endl;
	}

	HWThread.join();
	HWThread2.join();

	return 0;
}