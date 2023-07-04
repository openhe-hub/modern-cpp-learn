#include <functional>
#include <iostream>

int foo(int a, int b, int c){
    return  a+b+c;
}

int main(int argc, char** argv)
{
    auto bind_foo = std::bind(foo, std::placeholders::_1, 1, 2);
    std::cout<<bind_foo(1)<<std::endl;
    return 0;
}