#ifndef KQUEUE_H
#define KQUEUE_H

#include <iostream>

template <typename T>
class KQueueIter;

template <typename T>
class KQueueIter2;

template <typename T>
class KQueue{
private:
    T* items;
    int cnt;
public:
    friend class KQueueIter<T>;
    friend class KQueueIter2<T>;
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
    
    template <typename K>
    friend std::ostream& operator << (std::ostream& out, KQueue<K>& kq);

    KQueueIter<T>* createIterator() const;
};
#endif //LABA5RKPP_KQUEUE_H
