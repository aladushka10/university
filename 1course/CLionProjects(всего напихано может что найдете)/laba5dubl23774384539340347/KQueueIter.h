#ifndef KQUEUEITER_H
#define KQUEUEITER_H
#include "KQueue.h"

template<typename T>
class KQueueIter{
    const KQueue<T> *queue;
    int index;
public:
    KQueueIter(const KQueue<T>*);
    void first();
    void next();
    bool isDone();
    T currentItem();
};

template<typename T>
class KQueueIter2
{
    const KQueue<T>& queue;
    int index;
public:
    KQueueIter2(const KQueue<T>&);

    void operator++();
    bool operator() ();
    T operator *();
};

template<typename T>
int mismatch(const KQueue<T>&, const KQueue<T>&);

template<typename T>
bool operator == (const KQueue<T>&, const KQueue<T>&);

#endif //LABA5RKPP_KQUEUEITER_H
