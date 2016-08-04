#include <iostream>
#include "forge/logging.hpp"
#include "forge/structures/list/DLList.hpp"
#include "forge/structures/list/DLIterator.hpp"

using namespace forge;
using namespace forge::structures;
using namespace forge::structures::list;
using namespace forge::structures::array;
using namespace forge::structures::string;


void printList(DLList<unsigned int> list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        logging::out() << it.node()->data() << '\n';
    }
}


int main() {
    logging::init(std::cout, std::cerr);

    DLList<unsigned int> list;
    new(list.push_back()) unsigned int (25);
    new(list.push_back()) unsigned int(300);

    while (!list.empty()) {
        printList(list);
        auto beg = list.begin();
        list.erase(beg);
    }

    logging::deInit();
}
