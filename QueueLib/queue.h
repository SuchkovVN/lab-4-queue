#pragma once
#include <string>

template <class TType>
class TQueue
{
private:
    struct Node
    {
        TType data;
        Node* pNext;
        Node(const TType _data = {}, Node* _pNext = nullptr) : data(_data), pNext(_pNext) {}
    };

    Node* pFirst;
    int size;

    TQueue(const TQueue&) = delete; 

    void operator=(const TQueue&) = delete; 

public:
    TQueue() : pFirst(nullptr), size(0) {} 
    ~TQueue() 
    {
        while (size > 0)
            pop_front();
    }

    bool empty() const { return size == 0; } 

    int get_size() const { return size; }

    TType get_front() const
    {
        if (size == 0)
            throw std::string("Queue is empty");
        return pFirst->data;
    }

    TType pop_front()
    {
        if (size == 0)
            throw std::string("Queue is empty");
        Node* tmp = pFirst;
        TType tmpdata = pFirst->data;
        pFirst = pFirst->pNext;
        delete tmp;
        size--;
        return tmpdata;
    }

    void push_back(const TType obj)
    {
        if (size == 0)
        {
            pFirst = new Node(obj, nullptr);
        }
        else
        {
            Node* tmp = pFirst;
            while (tmp->pNext != nullptr)
                tmp = tmp->pNext;
            tmp->pNext = new Node(obj, nullptr);
        }
        size++;
    }
};
