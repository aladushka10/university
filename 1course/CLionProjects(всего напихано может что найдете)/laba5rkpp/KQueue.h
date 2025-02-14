#ifndef LABA5RKPP_KQUEUE_H
#define LABA5RKPP_KQUEUE_H

#include <iostream>

template <typename T>
class KQueueIter;

template <typename T>
class KQueue{
private:
    T* items;
    int cnt;
public:
    friend class KQueueIter<T>;
    KQueue();
    KQueue(T*, int);
    KQueue(const KQueue&);

    ~KQueue();
    int Size();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    T Front();
    T Back();
    void Push(T);
    T Pop();
    KQueue& operator = (const KQueue&);

    friend std::ostream& operator << (std::ostream& out, KQueue<T>& kq)
    {
        for (int i = 0; i < kq.cnt; i++)
            out << kq.items[i] << " ";
        return out;
    }

    KQueueIter<T>* createIterator() const;
};
#endif //LABA5RKPP_KQUEUE_H
/*
#include <iostream>

class KQueueIter;


class KQueue{
private:
    int* items;
    int cnt;
public:
    friend class KQueueIter;
    KQueue();
    KQueue(int*, int);
    KQueue(const KQueue&);

    ~KQueue();
    int Size();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    int Front();
    int Back();
    void Push(int);
    int Pop();
    KQueue& operator = (const KQueue&);
    friend std::ostream & operator << (std::ostream &, const KQueue&);

    KQueueIter* createIterator() const;
};*/
