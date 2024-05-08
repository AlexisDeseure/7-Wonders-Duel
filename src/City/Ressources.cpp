#include"../../includes/City/Ressource.h"


std::ostream& operator<<(std::ostream& os, const Ressource& ressource) {
    os << "Amount: " << ressource.getAmount() << ", Price: " << ressource.getPrice();
    return os;
}


