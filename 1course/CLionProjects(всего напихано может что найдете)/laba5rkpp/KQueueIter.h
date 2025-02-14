#ifndef LABA5RKPP_KQUEUEITER_H
#define LABA5RKPP_KQUEUEITER_H
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
int mismatch(const KQueue<T>&, const KQueue<T>&);

template<typename T>
bool operator == (const KQueue<T>&, const KQueue<T>&);

/*#include "KQueue.h"


class KQueueIter{
    const KQueue *queue;
    int index;
public:
    KQueueIter(const KQueue*);
    void first();
    void next();
    bool isDone();
    int currentItem();
};

bool operator == (const KQueue &, const KQueue &);

int mismatch(const KQueue&, const KQueue&);*/
#endif //LABA5RKPP_KQUEUEITER_H
