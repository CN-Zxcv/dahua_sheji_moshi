//抽象工厂，合并同系列的类的生成
//不足在于添加功能会涉及工厂的修改
//TODO:可以使用反射的方式解决
#include <iostream>

using namespace std;

class User
{
	public:
		string name;
	private:
		int id;
};

class UserAPI
{
	public:
		virtual ~UserAPI(){}
		virtual void insert(User user) = 0;
		virtual User getUser(int id) = 0;
};
class SqlServerUserAPI: public UserAPI
{
	public:
		void insert(User user)
		{
			cout << "sql user insert" << endl;
		}
		User getUser(int id)
		{
			cout << "sql user select" << endl;
		}
};
class AccessServerUserAPI: public UserAPI
{
	public:
		void insert(User user)
		{
			cout << "access user insert" << endl;
		}
		User getUser(int id)
		{
			cout << "access user select" << endl;
		}
};

class Department
{
	
};

class DepartmentAPI
{
	public:
		virtual ~DepartmentAPI(){}
		virtual void insert(Department department) = 0;
		virtual Department getDepartment(int id) = 0;
};
class SqlServerDepartmentAPI: public DepartmentAPI
{
	public:
		void insert(Department department)
		{
			cout << "sql department insert" << endl;
		}
		Department getDepartment(int id)
		{
			cout << "sql department select" << endl;
		}
};
class AccessServerDepartmentAPI: public DepartmentAPI
{
	public:
		void insert(Department department)
		{
			cout << "access department insert" << endl;
		}
		Department getDepartment(int id)
		{
			cout << "access department select" << endl;
		}
};

class APIFactory
{
	public:
		virtual ~APIFactory(){}
		virtual UserAPI * createUserAPI() = 0;
		virtual DepartmentAPI * createDepartmentAPI() = 0;
};
class SqlServerFactory: public APIFactory
{
	public:
		UserAPI * createUserAPI()
		{
			return new SqlServerUserAPI();
		}
		DepartmentAPI * createDepartmentAPI()
		{
			return new SqlServerDepartmentAPI();
		}
};
class AccessServerFactory: public APIFactory
{
	public:
		UserAPI * createUserAPI()
		{
			return new AccessServerUserAPI();
		}
		DepartmentAPI * createDepartmentAPI()
		{
			return new AccessServerDepartmentAPI();
		}
};

int main()
{
	User user;
	Department department;
	//APIFactory * factory = new SqlServerFactory();
	APIFactory * factory = new AccessServerFactory();
	UserAPI * su = factory->createUserAPI();
	DepartmentAPI *sd = factory->createDepartmentAPI();
	delete factory;
	
	su->insert(user);
	su->getUser(1);

	delete su;

	sd->insert(department);
	sd->getDepartment(1);

	delete sd;
}
