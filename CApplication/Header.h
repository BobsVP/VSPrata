#pragma once
#ifndef Header_h
#define Header_h


#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<typename Type>
class QueueTP
{
private:
    struct Node { Type item; struct Node* next; };
    enum { Q_SIZE = 10 };
    Node* front;       
    Node* rear;        
    int items;          
    const int qsize;    
    QueueTP(const Type& q) : qsize(0) { }
    QueueTP& operator=(const QueueTP& q) { return *this; }
public:
    QueueTP(int qs = Q_SIZE); 
    ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int QueueTPcount() const;
    bool enQueueTP(const Type& item); 
    bool deQueueTP(Type& item);       
    //Node* GetRear() { return rear; }
    //Node* GetFront() { return front; }
    Type& GetItem(int n);
};
 
template<typename Type>
QueueTP<Type>::QueueTP(int qs) : qsize(qs)
{
    front = rear = NULL;    
    items = 0;
}
template<typename Type>
QueueTP<Type>::~QueueTP()
{
    Node* temp;
    while (front != NULL)   
    {
        temp = front;       
        front = front->next;
        delete temp;        
    }
}
template<typename Type>
bool QueueTP<Type>::isempty() const
{
    return items == 0;
}
template<typename Type>
bool QueueTP<Type>::isfull() const
{
    return items == qsize;
}
template<typename Type>
int QueueTP<Type>::QueueTPcount() const
{
    return items;
}

template<typename Type>
bool QueueTP<Type>::enQueueTP(const Type& item)
{
    if (isfull())
        return false;
    Node* add = new Node;  
    add->item = item;       
    add->next = NULL;       
    items++;
    if (front == NULL)      
        front = add;        
    else
        rear->next = add;   
    rear = add;             
    return true;
}

template<typename Type>
bool QueueTP<Type>::deQueueTP(Type& item)
{
    if (front == NULL)
        return false;
    item = front->item;     
    items--;
    Node* temp = front;    
    front = front->next;    
    delete temp;            
    if (items == 0)
        rear = NULL;
    return true;
}
template<typename Type>
Type& QueueTP<Type>::GetItem(int n)
{
    Node* temp = front;
    for (int i = 0; i < n; ++i)
    {
        temp = temp->next;
    }
    return temp->item;
}


class Worker   
{
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string& s, long n)
        : fullname(s), id(n) {}
    virtual ~Worker() = 0; 
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string& s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waiter(const Worker& wk, int p = 0)
        : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker
{
protected:
    enum {
        other, alto, contralto, soprano,
        bass, baritone, tenor
    };
    enum { Vtypes = 7 };
    void Data() const;
    void Get();
private:
    static const char* pv[Vtypes];    // string equivs of voice types
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string& s, long n, int v = other)
        : Worker(s, n), voice(v) {}
    Singer(const Worker& wk, int v = other)
        : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

// multiple inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const std::string& s, long n, int p = 0,
        int v = other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker& wk, int p = 0, int v = other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter& wt, int v = other)
        : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer& wt, int p = 0)
        : Worker(wt), Waiter(wt, p), Singer(wt) {}
    void Set();
    void Show() const;
};

#endif