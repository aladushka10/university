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

/*#include "KQueue.h"
#include "assert.h"

KQueue::KQueue() {
  cnt = 0;
}

KQueue::KQueue(int* items, int cnt): cnt(cnt){
    this->items = new int[this->cnt];
    for (int i = 0; i < cnt; i++)
        this->items[i] = items[i];
}

KQueue::KQueue(const KQueue & init): cnt(init.cnt) {
    items = new int[cnt];
    for (int i = 0; i < cnt; i++)
        items[i] = init.items[i];
}

KQueue::~KQueue() {
    if(cnt == 1)
        delete items;
    if(cnt > 1)
        delete[] items;
}

int KQueue::Size() {
    return cnt;
}

void KQueue::Clear() {
    if(cnt == 1)
        delete items;
    if(cnt > 1)
        delete[] items;
    cnt = 0;
}

bool KQueue::IsEmpty() {
    return (cnt == 0);
}

bool KQueue::IsFull() {
    return (cnt > 10000);
}

int KQueue::Front() {
    if(!IsEmpty())
        return items[0];
    else
        assert(false);
}

int KQueue::Back() {
    if(!IsEmpty())
        return items[cnt - 1 ];
    else
        assert(false);
}

void KQueue::Push(int in) {
    if(!IsFull())
    {
        int* temp = new int[cnt + 1];
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

int KQueue::Pop() {
    int first = Front();
    int* temp = new int[cnt - 1];
    for (int i = 0; i < cnt - 1; i++)
        temp[i] = items[i + 1];
    int tempCnt = cnt;
    Clear();
    cnt = tempCnt;
    items = temp;
    cnt--;
    return first;
}

KQueue  &KQueue ::operator = (const KQueue& right) {
    if(this == &right)
        return *this;
    Clear();
    cnt = right.cnt;
    items = new int[cnt];
    for (int i = 0; i < cnt; i++)
        items[i] = right.items[i];
    return *this;
}

std::ostream &operator <<(std::ostream & out, const KQueue & kq) {
    for(int i = 0; i < kq.cnt; i++)
        out << kq.items[i] << " ";
    return out;
}


*/
