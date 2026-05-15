#include "main.h"

int main(int argc, char **argv)
{
    t_parser parser;

    printf("hello world\n");
    parsing(argc, argv, &parser);
    printf("bye world\n");
    return 0;
}
