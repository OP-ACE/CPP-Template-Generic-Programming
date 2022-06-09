#include <iostream>
    using namespace std;
 
    class Base
    {
       public:
           virtual void Print() = 0;
           virtual ~Base(){}
    };
 
    class child_1 : public Base
    {
       public:
        void Print()
        {
            cout << "child_1 Print function" << endl;
        }
        ~child_1()
        {
            cout << "child_1 destructor function" << endl;
        }
    };
 
    class child_2: public Base
    {
        public:
            void Print()
            {
                cout << "child_2 Print function" << endl;
            }
            ~child_2()
            {
                cout << "child_2 destructor function" << endl;
            }
    };
 
    int main()
    {
        Base *p = new child_1; //父类指针指向子类对象
        p->Print();
        delete p;  //记住释放,否则内存泄露
        p = new child_2;
        p->Print();
        delete p;
        p = NULL;
        return 0;
    }