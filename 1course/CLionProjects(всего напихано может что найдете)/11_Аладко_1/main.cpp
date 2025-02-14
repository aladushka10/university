#include <iostream>
#include "Music.h"
#include "MusicalComposition.h"
#include "Performer.h"

int main() {
    setlocale(LC_ALL, "Russian");
    MusicComposition* m1 = new MusicComposition("Надежда", song, 1971);
    m1->set_title("Believe");
    MusicComposition* m2 = new MusicComposition("I've Got You Under My Skin",  jazz, 1985);
    MusicComposition* m3 = new MusicComposition("Симфония №5", simphony , 1956);

    cout << m1->get_genre()<< endl << endl;
    cout << *m1 << '\n';
    cout << *m2 << '\n';
    cout << *m3 << '\n';
    Performer* p = new Performer("I've Got You Under My Skin",  jazz, 1985, 5, new int[5]{3, 6, 12, 9, 17});
    return 0;
}
