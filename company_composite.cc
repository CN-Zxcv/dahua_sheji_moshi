//组合模式
#include <iostream>

using namespace std;

class Company
{
	public:
		Company(string name)
		{
			this->name = name;
		}
	
		void add(Company c) = 0;
		void remove(Company c) = 0;
		void display(int depth) = 0;
		void lineOfDuty() = 0;

	private:
		string name;
};
