#include "KQueue.h"
#include "assert.h"

template<typename T>
KQueue<T>::KQueue() : cnt(0) {}

template<typename T>
KQueue<T>::KQueue(T* items, int cnt): cnt(cnt){
    this->items = new T[this->cnt];
    for (int i = 0; i < cnt; i++)
        this->items[i] = items[i];
}

template<typename T>
KQueue<T>::KQueue(const KQueue & init): cnt(init.cnt) {
    items = new T[cnt];
    for (int i = 0; i < cnt; i++)
        items[i] = init.items[i];
}

template<typename T>
KQueue<T>::~KQueue() {
    if(cnt == 1)
        delete items;
    if(cnt > 1)
        delete[] items;
}

template<typename T>
int KQueue<T>::Size() {
    return cnt;
}

template<typename T>
void KQueue<T>::Clear() {
    if(cnt == 1)
        delete items;
    if(cnt > 1)
        delete[] items;
    cnt = 0;
}

template<typename T>
bool KQueue<T>::IsEmpty() {
    return (cnt == 0);
}

template<typename T>
bool KQueue<T>::IsFull() {
    return (cnt > 10000);
}

template<typename T>
T KQueue<T>::Front() {
    if(!IsEmpty())
        return items[0];
    else
        assert(false);
}

template<typename T>
T KQueue<T>::Back() {
    if(!IsEmpty())
        return items[cnt - 1 ];
    else
        assert(false);
}

template<typename T>
void KQueue<T>::Push(T in) {
    if(!IsFull())
    {
        T* temp = new T[cnt + 1];
        for(int i = 0; i < cnt; i++)
            temp[i] = items[i];
        temp[cnt] = in;
        int tempCnt = cnt;
        Clear();
        cnt = tempCnt;
        items = temp;
        cnt++;
    }
    else
        assert(false);
}

template<typename T>
T KQueue<T>::Pop() {
    T first = Front();
    T* temp = new T[cnt - 1];
    for (int i = 0; i < cnt - 1; i++)
        temp[i] = items[i + 1];
    int tempCnt = cnt;
    Clear();
    cnt = tempCnt;
    items = temp;
    cnt--;
    return first;
}

template<typename T>
KQueue<T>& KQueue<T>::operator = (const KQueue& right) {
    if(this == &right)
        return *this;
    Clear();
    cnt = right.cnt;
    items = new T[cnt];
    for (int i = 0; i < cnt; i++)
        items[i] = right.items[i];
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, KQueue<T>& kq)
{
    for (int i = 0; i < kq.cnt; i++)
        out << kq.items[i] << " ";
    return out;
}