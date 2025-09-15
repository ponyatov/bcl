#include "os.hpp"
#include "cli.hpp"
#include "vm.hpp"

__attribute__((weak)) int main(int argc, char* argv[]) {
    arg(0, argv[0]);
    nop();
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
        yyfile = argv[i];
        FILE* yyin;
        assert(yyin = fopen(yyfile, "r"));
        yyparse();
        fclose(yyin);
        yyfile = nullptr;
    }
    halt();
    return 0;
}

void arg(int argc, char* argv) {  //
    fprintf(stderr, "arg[%i] = <%s>\n", argc, argv);
}
