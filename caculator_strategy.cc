
// 策略模式加上简单工厂 
// 工厂封装对象的生成，客户需要同时知道工厂和父类的细节，强调类的统一管理
// 策略类封装使用对象的行为，为用户提供统一的使用接口，强调统一用户接口
// 策略类和工厂混用隐藏了父类的细节，用户只需要知道策略对象即可

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
        virtual float get_result()
        {
        }
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

class OperationContext
{
    public:
        /*
        OperationContext(Operation &op)
        {
            //pure strategy
        }
        */
        OperationContext(char op)
        {
            switch(op)
            {
                case '+':
                    operate = new Add();
                case '-':
                    operate = new Sub();
            }
        }
        ~OperationContext()
        {
            delete operate;
        }

        float get_result()
        {
            return operate->get_result();
        }

        void set_a(int val)
        {
            return operate->set_a(val);
        }
        void set_b(int val)
        {
            return operate->set_b(val);
        }
    private:
        Operation *operate;
};

int main()
{
	cout << "input a,b and op" << endl;
	int a = 0, b = 0;
	char op;
	float result = 0.0;
	
	cin >> a >> b >> op;

    OperationContext cal = OperationContext(op);
    cal.set_a(a);
    cal.set_b(b);
	cout << cal.get_result() << endl; 
}


