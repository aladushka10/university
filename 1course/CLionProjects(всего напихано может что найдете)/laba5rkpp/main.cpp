#include "KQueue.h"
#include "KQueueIter.h"

int main() {
    KQueue<int> k;
    k.Push(10);
    k.Push(19);
    k.Push(15);
    k.Push(17);
    std::cout << k.Size() << '\n';
    std::cout << k.Front() << ' ' << k.Back() << '\n';
    k.Pop();
    k.Pop();
    std::cout << k << '\n';
    KQueue<int> q1;
    for (int i = 1; i < 5; i++)
        q1.Push(i);
    KQueue<int> q2(q1), q3(q1), q4(q1), q5(q1);
    q3.Pop();
    q5.Pop();
    q4.Push(2);
    q5.Push(9);
    std::cout << "1 == 2 is " << (q1 == q2) << '\n';
    std::cout << "1 == 3 is " << (q1 == q3) << '\n';
    std::cout << "1 == 4 is " << (q1 == q4) << '\n';
    std::cout << "1 == 5 is " << (q1 == q5) << '\n';

    return 0;
}
