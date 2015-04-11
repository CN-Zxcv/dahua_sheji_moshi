
// simple caculator

#include <iostream>

using namespace std;

class Operation
{
	public:
        virtual ~Operation()
        {
            cout << "base destory" << endl;
        }
		virtual float get_result()
		{
            cout << "base function" << endl;
		}
        
        void set_a(int val)
        {
            a = val;
        }
        void set_b(int val)
        {
            b = val;
        }
    protected:
        int a,b;
};

class Add: public Operation
{
    public:
        Add()
        {
            cout << "Add init" << endl;
        }
        ~Add()
        {
            cout << "Add destory" << endl;
        }
        virtual float get_result()
        {
            return a + b;
        }
};

class Sub: public Operation
{
    public:
        Sub()
        {
            cout << "Sub init" << endl;
        }
        ~Sub()
        {
            cout << "Sub destory" << endl;
        }
        virtual float get_result()
        {
            return a - b;
        }
};

class OperationFactory
{
    public:
        static Operation * createOperation(char op)
        {
            switch(op)
            {
                case '+':
                    return new Add();
                case '-':
                    return new Sub();
            }
        }
};

int main()
{
	cout << "input a,b and op" << endl;
	int a = 0, b = 0;
	char op;
	float result = 0.0;
	
	cin >> a >> b >> op;

    Operation *cal;
    cout << "start" << endl;
    cal = OperationFactory::createOperation(op);
    cal->set_a(a);
    cal->set_b(b);

	cout << cal->get_result() << endl; 
    cout << "end" << endl;
    delete cal;
}

