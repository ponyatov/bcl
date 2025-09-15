#include "vm.hpp"

#include "os.hpp"

byte M[Msz];
addr Cp = sizeof(bcHeader);
addr Ip = 0xFFFF;  // uninitialized fake value breaks if not configured
addr R[Rsz];
byte Rp = 0;
cell D[Dsz];
byte Dp = 0;

bool trace = true;

void nop() {
    if (trace) fprintf(stderr, "nop\n");
}

void halt() {
    if (trace) fprintf(stderr, "halt\n\n");
    exit(0);
}

void dump() {
    if (trace) fprintf(stderr, "dump");
    fprintf(stderr, "\t[ ");
    for (uint i = 0; i < Dp; i++) fprintf(stderr, "%i ", D[i]);
    fprintf(stderr, " ]\n");
}

void push(cell n) {
    assert(Dp < Dsz);
    D[Dp++] = n;
}

void push(float f) {  //
    push(*(cell*)&f);
}

cell pop() {
    assert(Dp > 0);
    return D[--Dp];
}

cell top() {
    assert(Dp > 0);
    return D[Dp - 1];
}
