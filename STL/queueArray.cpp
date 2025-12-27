#include <iostream>
using namespace std;

class Queue
{
private:
    int *queueArray;
    int startIndex;
    int nextIndex;
    int capacity;
    int size;
    void expandArray()
    {
        int *newArray = new int[capacity * 2];
        int index = 0;
        for (int i = startIndex; i < capacity; i++)
        {
            newArray[index] = queueArray[i];
            index++;
        }
        for (int i = 0; i < startIndex; i++)
        {
            newArray[index] = queueArray[i];
            index++;
        }
        nextIndex = capacity;
        startIndex = 0;
        capacity = capacity * 2;
        delete[] queueArray;
        queueArray = newArray;
    }

public:
    Queue()
    {
        capacity = 5;
        queueArray = new int[capacity];
        nextIndex = 0;
        size = 0;
        startIndex = -1;
    }

    void enqueue(int element)
    {
        if (size == capacity)
        {
            expandArray();
        }
        queueArray[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (startIndex == -1)
        {
            startIndex = 0;
        }
        size++;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Empty Queue" << endl;
            return 0;
        }
        return queueArray[startIndex];
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Empty Queue" << endl;
            return 0;
        }
        else
        {
            int ans = queueArray[startIndex];
            startIndex = (startIndex + 1) % capacity;
            size--;
            if (size == 0)
            {
                startIndex = -1;
                nextIndex = 0;
            }
            return ans;
        }
    }
};
