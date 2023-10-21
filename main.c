#include <stdio.h>

#include "engine.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("expected to have 1 argument, but got %d\n", argc - 1);
        return 1;
    }
    Engine* engine = create_engine(argv[1], 100000);
    eval(engine);
    return 0;
}
