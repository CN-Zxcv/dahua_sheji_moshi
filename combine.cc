//桥接：将抽象部分与实现部分分离
//系统可以从多角度分类，将功能与分类分离
#include <iostream>

using namespace std;

class HandsetSoft
{
	public:
		virtual void run() = 0;
};

class HandsetGame: public HandsetSoft
{
	public:
		virtual void run()
		{
			cout << "Game" << endl;
		}
};

class HandsetAddressList: public HandsetSoft
{
	public:
		virtual void run()
		{
			cout << "Address" << endl;
		}
};

class HandsetBrand
{
	public:
		void setHandSoft(HandsetSoft *soft)
		{
			this->soft = soft;
		}
		void run()
		{
			soft->run();
		}
	private:
			HandsetSoft *soft;
};

class HandsetNBrand: public HandsetBrand
{

};

class HandsetMBrand: public HandsetBrand
{

};

int main()
{
	HandsetBrand *ab = 0;
	ab = new HandsetNBrand();
	ab->setHandSoft(new HandsetGame());
	ab->run();

	ab = new HandsetMBrand();
	ab->setHandSoft(new HandsetGame());
	ab->run();

}
