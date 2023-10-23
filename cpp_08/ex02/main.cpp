#include "MutantStack.hpp"
#include <list>
#include <vector>
int main()
{
    std::cout << "=== Test MutantStack ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "========================" << std::endl << std::endl;

    std::cout << "====== Test List =======" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);
    std::list<int>::iterator it2 = list.begin();
    std::list<int>::iterator ite2 = list.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::list<int> s2(list);
    std::cout << "========================" << std::endl << std::endl;



    std::cout << "===== Test Vector ======" << std::endl;
    std::vector<int> vector;
    vector.push_back(5);
    vector.push_back(17);
    std::cout << vector.back() << std::endl;
    vector.pop_back();
    std::cout << vector.size() << std::endl;
    vector.push_back(3);
    vector.push_back(5);
    vector.push_back(737);
    //[...]
    vector.push_back(0);
    std::vector<int>::iterator it3 = vector.begin();
    std::vector<int>::iterator ite3 = vector.end();
    ++it3;
    --it3;
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    std::vector<int> s3(vector);
    std::cout << "========================" << std::endl << std::endl;
    return 0;
}