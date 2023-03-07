#include <iostream>
#include <list>

int main(){
    std::list<int> l;

    l.push_back(5);
    l.push_back(10);
    l.push_front(1);

    l.pop_front();

    while(!l.empty()){
        std::cout << l.front() << std::endl;
        l.pop_front();
    }

    return 0;
}