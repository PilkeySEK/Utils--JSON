#include <iostream>
#include "JSON.cpp"

int main() {
    JSONObject o;
    int val1 = 123;
    o.addKeyValuePair(new JSONKeyValuePair("abc", &val1));
    std::cout << o.keyExists("asdf") << std::endl << o.keyExists("abc") << std::endl;
    std::cout << *((int *) o.getKeyValuePair("abc")->value());
    return 0;
}

/*
OUTPUT:

0
1
123

*/