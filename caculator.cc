// simple caculator

#include <iostream>

using namespace std;

float get_result(int a, int b, char op)
{
	switch(op)
	{
		case '-':
			return a - b;
		case '+':
			return a + b;
	}
}

int main()
{
	cout << "input a,b and op" << endl;
	int a = 0, b = 0;
	char op;
	float result = 0.0;
	
	cin >> a >> b >> op;

	cout << get_result(a, b, op) << endl;
}
