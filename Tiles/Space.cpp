#include "Space.h"
#include <cstring>
using namespace std;

Space::Space(const char* name) {
    this->name = name;
}
Space::Space() {
    this->name = "";
}
const char *Space::getName() const {
    return name;
}
Space::~Space() {
    
}
