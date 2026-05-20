#include <iostream>
using namespace std;

const int MAX = 10;
class Queue
{
    int queue[MAX], head, tail, count;

public:
    Queue()
    {
        head = 0, tail = 0, count = 0;
    }
    void put(int y)
    {
        if (count == MAX)
        {
            cout << "Array is full" << endl;
            return;
        }
        if (tail == MAX)
        {
            tail = 0;
        }
        queue[tail] = y;
        tail++;
        count++;
    }
    int get()
    {
        if (count == 0)
        {
            cout << "Empty Array" << endl;
            return 0;
        }
        if (head == MAX)
        {
            head = 0;
        }
        count--;
        return queue[head++];
    }
};

main()
{
    Queue q1;
    q1.put(10);
    q1.put(20);
    q1.put(30);
    cout << q1.get() << endl;
    cout << q1.get() << endl;
}