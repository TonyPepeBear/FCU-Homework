#include <cstdlib>
#include <ctime>

int ran1to13() {
    srandom(time(NULL));
    return (int) random() % 13 + 1;
}
