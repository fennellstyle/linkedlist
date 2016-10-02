#include <iostream>
#include "linkedlist.h"

int main() {
    // int list
    {
        LinkedList<int> ilist {0, 1, 2, 5};
        std::cout << "Size of ilist: " << ilist.size() << std::endl;

        auto head = ilist.head();
        do {
            std::cout << head->get() << std::endl;
            head = head->next();
        } while(head);
    }

    // float list
    {
        LinkedList<float> flist;
        std::cout << "Size of flist: " << flist.size() << std::endl;
        for(int i=15; i<26; ++i)
        {
            auto val = static_cast<float> (i * i + 0.125);
            std::cout << "Adding : " << val << ", new size: " << flist.size() << std::endl;
            flist.add(val);
        }

        for(auto x: flist) std::cout << x << std::endl;
    }
    return 0;
}