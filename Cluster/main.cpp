#include <iostream>
#include <string>
#include "cluster.h"

using namespace std;

void cleaner()
{
	while (getchar() != '\n');
	cin.clear();
}

int main()
{
	int exit = 1;
	while (exit != 2)
	{
		int _k; 
		int _tacts; 
		int _queueSize; 
		double _frequency; 
		cout << "Enter the values:\n\tNumber of processors (from 1 to 64): ";
		cin >> _k;
		cout << "\tNumber of cluster clock cycles (from 1 to 1000): ";
		cin >> _tacts;
		cout << "\tMax queue size in cluster (from 5 to 50): ";
		cin >> _queueSize;
		cout << "\tFrequency of appearance of tasks\n\t(from 0(exclusive) to 1 (inclusive)): ";
		cin >> _frequency;
		try
		{
			Cluster cl(_k, _tacts, _queueSize, _frequency);
			cout << '\n' << cl.simulation() << '\n';
		}
		catch (string exc)
		{
			cout << exc;
		}
		cout << "\nContinue using the program?\n\t1 - Yes\n\t2 - No\n\t";
		cin >> exit;
		cleaner();
		cout << '\n';
	}
	system("pause");
	return 0;
}
