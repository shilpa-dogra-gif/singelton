#include <string>
#include <iostream>

using namespace std;
/// @brief 
class singeltonExample
{
private:
static singeltonExample * _instance;
string _value; 
static mutex _mutex;


protected:
   singeltonExample(/* args */) {}
   singeltonExample(singeltonExample &) = delete;
   singeltonExample operator = (singeltonExample &) = delete;
   

public:
   static singeltonExample* getinstance()
    {
        lock_guard<mutex> lock(_mutex);
        if(! _instance)
        {
            _instance = new singeltonExample();
        }
        return _instance;
    }

    void setvalue(string t_value)
    {
        if(_instance)
        _instance->_value = t_value;
    }

    string getvalue()
    {
        return _value;
    }
    
    ~singeltonExample() {}
};
singeltonExample* singeltonExample::_instance = nullptr;
mutex singeltonExample::_mutex;