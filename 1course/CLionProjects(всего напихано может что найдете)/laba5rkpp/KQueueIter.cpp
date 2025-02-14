#include "KQueueIter.h"

template <typename T>
KQueueIter<T>::KQueueIter(const KQueue<T>* q) {
    queue = q;
}

template <typename T>
void KQueueIter<T>::first() {
    index = 0;
}

template <typename T>
void KQueueIter<T>::next() {
    index++;
}

template <typename T>
bool KQueueIter<T>::isDone() {
    return (index == queue->cnt) ;
}

template <typename T>
T KQueueIter<T>::currentItem() {
    return queue->items[index];
}

template <typename T>
KQueueIter<T>* KQueue<T>::createIterator() const {
    return new KQueueIter<T>(this);
}

template <typename T>
int mismatch(const KQueue<T>& l, const KQueue<T>& r)
{
    KQueueIter<T>* itl = l.createIterator();
    KQueueIter<T>* itr = r.createIterator();
    int index = -1;
    int i;
    for (i = 0, itl->first(), itr->first();
         !itl->isDone() && !itr->isDone(); itl->next(), itr->next(), ++i)
        if (itl->currentItem() != itr->currentItem())
        {
            index = i;
            break;
        }
    if (!(itl->isDone() && itr->isDone()))
        index = i;
    return index;
}

template <typename T>
bool operator == (const KQueue<T> &l, const KQueue<T> &r)
{
    KQueueIter<T> *itl = l.createIterator();
    KQueueIter<T> *itr = r.createIterator();
    for (itl->first(), itr->first();
         !itl->isDone() && !itr->isDone(); itl->next(), itr->next())
        if (itl->currentItem() != itr->currentItem()) break;
    bool ans = itl->isDone() && itr->isDone();
    delete itl;
    delete itr;
    return ans;
}

/*#include "KQueueIter.h"

KQueueIter::KQueueIter(const KQueue *q) {
    queue = q;
}

void KQueueIter::first() {
    index = 0;
}

void KQueueIter::next() {
    index++;
}

bool KQueueIter::isDone() {
    return (index == queue->cnt) ;
}

int KQueueIter::currentItem() {
    return queue->items[index];
}

KQueueIter *KQueue::createIterator() const {
    return new KQueueIter(this);
}

bool operator == (const KQueue &l, const KQueue &r)
{
    KQueueIter *itl = l.createIterator();
    KQueueIter *itr = r.createIterator();
    for (itl->first(), itr->first();
         !itl->isDone() && !itr->isDone(); itl->next(), itr->next())
        if (itl->currentItem() != itr->currentItem()) break;
    bool ans = itl->isDone() && itr->isDone();
    delete itl;
    delete itr;
    return ans;
}

int mismatch(const KQueue& l, const KQueue& r){
    KQueueIter *itl = l.createIterator();
    KQueueIter *itr = r.createIterator();
    int index = -1;
    int i = 0;
    for(i = 0, itl->first(), itr->first(); !itl->isDone()&& !itr->isDone(); itl->next(), itr->next(),i++)
        if()
}
*/