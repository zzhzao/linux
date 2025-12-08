#pragma once

class Task
{
public:
    Task(int x,int y)
    :_x(x),_y(y)
    {
    }
    void Excute()
    {
        _result = _x + _y;
    }
    
    ~Task(){}

private:
    int _x;
    int _y;
    int _result;
};