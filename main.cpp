
#include "MemManager.h"

#include <boost/cstdint.hpp>
#include <iostream>

int main()
{
    std::cout << "--- Creating MemManager ---" << std::endl;
    MemManager memManager(1024);
    std::cout << "Current index after ctor: " << memManager.getMarker() << std::endl;
    std::cout << "Space left: " << memManager.bytesLeft() << std::endl;

    std::cout << "--- Allocating test variable ---" << std::endl;
    std::cout << "sizeof(test): " << sizeof(boost::uint32_t) << " bytes" << std::endl;
    boost::uint32_t* test = (boost::uint32_t*) memManager.alloc(sizeof(boost::uint32_t));
    std::cout << "Index after test-init: " << memManager.getMarker() << std::endl;
    std::cout << "Space left: " << memManager.bytesLeft() << std::endl;

    *test = 15;
    std::cout << "Value of test: " << *test << std::endl;

    return 0;
}


