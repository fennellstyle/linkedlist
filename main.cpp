#include <iostream>
#include "linkedlist.h"
#include <typeinfo>

int main() {
    // int list
    {
        LinkedList<int> ilist {0, 1, 2, 5};
        std::cout << "Size of ilist: " << ilist.size() << std::endl;

        for(auto x: ilist) {
            std::cout << x << std::endl;
        }

        // edit
        for(auto& x: ilist) {
            x++;
        }

        // new
        for(auto x: ilist) {
            std::cout << "new int: " << x << std::endl;
            x++;
        }

        // should be same as above
        for(auto x: ilist) {
            std::cout << "same int?: " << x << std::endl;
        }
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

    // invalid
    LinkedList<double> dlist;

    try {
        std::cout << dlist.head() << std::endl;
    } catch (std::out_of_range) {
        std::cout << "\nCaught out of range error on dlist." << std::endl;
    }
    return 0;
}