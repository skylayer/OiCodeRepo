#include <cstdio>
#include <sys/mman.h>
typedef unsigned long long ll;
struct _io {
    char*s;
    _io():s((char*)mmap(0,1<<28,PROT_READ,MAP_PRIVATE,fileno(stdin),0)) {}
    operator ll() {
        ll x=0;

        while(*s<48)s++;

        while(*s>32)x=x*10+*s++-48;

        return x;
    }
} it;
int n=3000000;
ll x;
int main() {
    while(n--)x^=it;

    printf("%llu",x);
    return 0;
}
