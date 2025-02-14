#include "KQueue.h"
#include "KQueueIter.h"
#include "KQueue.cpp"
#include "KQueueIter.cpp"

int main() {
    KQueue<int> k;

    k.Push(10);
    k.Push(19);
    k.Push(15);
    k.Push(17);
    std::cout << "Размер очереди: " << k.Size() << '\n';
    std::cout << "Первый элемент очереди: " << k.Front() << '\n';
    std:: cout<< "Последний элемент очереди: " << k.Back() << '\n';
    k.Pop();
    k.Pop();
    std::cout << "Очередь после удаления первых двух элементов: " << k << std::endl << std::endl;
    KQueue<int> q1;
    for (int i = 1; i < 5; i++)
        q1.Push(i);

    KQueue<int> q2(q1), q3(q1), q4(q1), q5(q1);
    std:: cout<< "Oчередь 1: "  << q1 <<  '\n';
    std:: cout<< "Oчередь 2: "  << q2 <<  '\n';
    std:: cout<< "Oчередь 3: "  << q3 <<  '\n';
    std:: cout<< "Oчередь 4: "  << q4 <<  '\n';
    std:: cout<< "Oчередь 5: "  << q5 << std::endl << std::endl;

    q3.Pop();
    q5.Pop();
    q4.Push(2);
    q5.Push(9);

    std:: cout<< "Oчереди после изменения: " << '\n';
    std:: cout<< "Oчередь 1: "  << q1 <<  '\n';
    std:: cout<< "Oчередь 2: "  << q2 <<  '\n';
    std:: cout<< "Oчередь 3: "  << q3 <<  '\n';
    std:: cout<< "Oчередь 4: "  << q4 <<  '\n';
    std:: cout<< "Oчередь 5: "  << q5 <<  std::endl << std::endl;

    std::cout << "1 == 2 is " << (q1 == q2) << '\n';
    std::cout << "1 == 3 is " << (q1 == q3) << '\n';
    std::cout << "1 == 4 is " << (q1 == q4) << '\n';
    std::cout << "1 == 5 is " << (q1 == q5) << std::endl << std::endl;

    std::cout << "mismatch 1 and 2 on: " << mismatch(q1, q2) << '\n';
    std::cout << "mismatch 1 and 3 on: " << mismatch(q1, q3) << '\n';
    std::cout << "mismatch 1 and 4 on: " << mismatch(q1, q4) << '\n';
    std::cout << "mismatch 1 and 5 on: " << mismatch(q1, q5) << '\n';
    return 0;
}
