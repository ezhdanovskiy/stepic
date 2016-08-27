Тут задача очень простая. Вам нужно **создать умный указатель** на объект класса std::string. 
Он должен иметь защиту от разыменования NULL - при попытке это сделать он должен конструировать внутри себя пустую строку.

Следующий код должен работать.

```C++
std::string s1 = "Hello, world!";

StringPointer sp1(&s1);
StringPointer sp2(NULL);

std::cout << sp1->length() << std::endl;
std::cout << *sp1 << std::endl;
std::cout << sp2->length() << std::endl;
std::cout << *sp2 << std::endl;
```

**N.B.** Так как ваш указатель при определенных случаях может конструировать внутри себя пустую строку, 
не забудьте позаботиться об освобождении памяти в деструкторе. 
Система не проверяет корректность работы в памятью, так что это остается на вашу совесть :)

```C++
class StringPointer {
public:
    std::string *operator->() {}
    operator std::string*() {}
    StringPointer(std::string *Pointer) {}
    ~StringPointer() {}
};
```