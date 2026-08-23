#include "Space.h"
#include <cstring>
using namespace std;

Space::Space(char* name) {
    this->name = name;
}
Space::Space() {
    this->name = "";
}
char *Space::getName() const {
    return name;
}
Space::~Space() {
    
}
