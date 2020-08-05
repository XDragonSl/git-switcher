#include "Store.h"
#include <iostream>

using namespace std;

Store::Store() {
    store.open(STORE_LOCATION + STORE_NAME);
}

Store::~Store() {
    store.close();
}
