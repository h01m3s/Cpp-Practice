#include <iostream>

using namespace std;

#define LOG(x) cout << x << endl;

class Entity {
private:
    int m_X, m_Y;
    // int* m_X, m_Y;           // m_X is a pointer, m_Y is just int
    // int* m_X, *m_Y;          // if want both of them are pointer
    mutable int var;
public:
    int GetX() const {
        // const after method means can't change content of variable
        // m_X = 2;             // This will not work
        // add mutable before declar variable makes it work in this method
        var = 2;
        return m_X;
    }

    int GetX() {
        m_X = 2;
        return m_X;
    }

    void SetX(int x) {
        m_X = x;
    }
};

void PrintEntity(const Entity& e) {
    // Because e is const reference it can't change content of e
    // can only use method that didn't change content of e
    // have to be int GetX() const...
    LOG(e.GetX());
}

int main(int argc, char const *argv[]) {

    Entity e;

    const int MAX_AGE = 90;

    // This makes it read-only
    // Can change where it's pointing to
    // But can't change its content
    const int* a = new int;
    // int const* a = new int;  // This works the same
    // const before asterisk sign
    // *a = 1;                  // This will generate error
    a = (int*)&MAX_AGE;         // This is ok

    // This can change content of pointer
    // But can't change where it's pointing to
    int* const b = new int;
    *b = 2;                     // This is ok
    // b = (int*)&MAX_AGE;      // This will not work

    // Neither content nor where it's pointing to can be changed
    const int* const c = new int;

    LOG(*a);
    LOG(*b);
    LOG(*c);
    return 0;
}
