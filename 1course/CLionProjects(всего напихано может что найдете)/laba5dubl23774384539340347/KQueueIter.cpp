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

template<typename T>
KQueueIter2<T>::KQueueIter2(const KQueue<T> &init) : queue(init), index(0) {}

template<typename T>
void KQueueIter2<T>::operator++() {
    index++;
}

template<typename T>
bool KQueueIter2<T>::operator()() {
    return (index != queue.cnt);
}

template<typename T>
T KQueueIter2<T>::operator*() {
    return queue.items[index];
}

template <typename T>
int mismatch(const KQueue<T>& l, const KQueue<T>& r)
{
    KQueueIter2<T> itl(l);
    KQueueIter2<T> itr(r);
    int index = -1;
    int i;
    for (i = 0; itl() && itr(); ++itl, ++itr, ++i)
        if (*itl != *itr)
        {
            index = i;
            break;
        }
    if (itl() || itr())
        index = i;
    if(index == -1)
        std::cout << "the queues are equal: ";
    return index;
}

template <typename T>
bool operator == (const KQueue<T> &l, const KQueue<T> &r)
{
    KQueueIter<T> *itl = l.createIterator();
    KQueueIter<T> *itr = r.createIterator();
    for (itl->first(), itr->first(); !itl->isDone() && !itr->isDone(); itl->next(), itr->next())
        if (itl->currentItem() != itr->currentItem())
            break;
    bool ans = itl->isDone() && itr->isDone();
    delete itl;
    delete itr;
    return ans;
}
