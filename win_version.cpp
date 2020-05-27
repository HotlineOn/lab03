#include <string>
#include <sstream>
#include <cstdio>

int
make_info_text() {
    //stringstream buffer;
    const char* name = "Commander Shepard";
    int year = 2154;
    printf("%s was born in %d.\n", name, year);
    //return buffer.str();
    printf("n = %08x\n", 0x1234567);
    return 0;
}
