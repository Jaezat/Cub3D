#include "main.h"

int main(int argc, char **argv)
{
    t_parser parser;

    // printf("parsing debugging start\n");
    parsing(argc, argv, &parser);
    // printf("parsing debugging end\n");
    return 0;
}
