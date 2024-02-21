#include "Singeltonfile.h"
#include <chrono>
#include <thread>

void Thread1()
{
    this_thread::sleep_for(std::chrono::milliseconds(2000));
    singeltonExample* singleton1 = singeltonExample::getinstance();
    singleton1->setvalue(" Boo ");
    cout << singleton1->getvalue() << std::endl;
}

void Thread2()
{
    this_thread::sleep_for(std::chrono::milliseconds(2000));
    singeltonExample* singleton2 = singeltonExample::getinstance();
    singleton2->setvalue(" Hoo ");
    cout << singleton2->getvalue() << std::endl;
}

int main()
{
    std::cout<< "Thread ";
   std::thread t1 (Thread1);
   std::thread t2 (Thread2);
    t1.join();
    t2.join();

    return 0;
}