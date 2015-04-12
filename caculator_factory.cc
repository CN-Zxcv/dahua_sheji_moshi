
//工厂模式是为了满足开放封闭原则
//在增加功能时不去修改已经写好的类
//但是会将判断交给用户去做，这是一个很大的缺点

#include <iostream>

using namespace std;

class Operation
{
	public:
        
        void set_a(int val)
        {
            a = val;
        }
        void set_b(int val)
        {
            b = val;
        }
        virtual float get_result(){}
    protected:
        int a,b;
};

class Add: public Operation
{
    public:
        virtual float get_result()
        {
            return a + b;
        }
};

class Sub: public Operation
{
    public:
        virtual float get_result()
        {
            return a - b;
        }
};

class OperationFactory
{
    public:
        virtual Operation * createOperation(){}
};

class AddFactory: public OperationFactory
{
    public:
        virtual Operation * createOperation()
        {
            return new Add();
        }
};

class SubFactory: public OperationFactory
{
    public:
        virtual Operation * createOperation()
        {
            return new Sub();
        }
};

int main()
{
	cout << "input a,b and op" << endl;
	int a = 0, b = 0;
	char op;
	float result = 0.0;
	
	cin >> a >> b >> op;

    OperationFactory *factory = NULL;
    switch(op)
    {
        case '+':
            factory = new AddFactory();
            break;
        case '-':
            factory = new SubFactory();
            break;
    }

    Operation *cal = factory->createOperation();
    delete factory;

    cal->set_a(a);
    cal->set_b(b);

	cout << cal->get_result() << endl; 
    delete cal;
}

