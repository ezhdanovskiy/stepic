#include "Logger.h"

class StringPointer {
private:
    std::string *s = NULL;
    bool needDelete = false;

public:
    StringPointer(std::string *s) : s(s) {}

    const std::string &operator*() {
        if (!s) {
            s = new std::string("");
            needDelete = true;
        }
        return *s;
    }

    const std::string *operator->() {
        if (!s) {
            s = new std::string("");
            needDelete = true;
        }
        return s;
    }

    operator std::string *() {
        return s;
    }

    virtual ~StringPointer() {
        if (needDelete) {
            delete s;
        }
    }
};

int main(int argv, char **argc) {
    std::string s1 = "Hello, world!";

    StringPointer sp1(&s1);
    StringPointer sp2(NULL);

    std::cout << sp1->length() << std::endl;
    std::cout << *sp1 << std::endl;
    std::cout << sp2->length() << std::endl;
    std::cout << *sp2 << std::endl;

    return 0;
}
