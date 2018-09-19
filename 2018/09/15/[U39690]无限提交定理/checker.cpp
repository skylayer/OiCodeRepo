#include "testlib.h"
int main(int argc,char* argv[]) {

    registerTestlibCmd(argc, argv);
    int get=ouf.readInt();
    int jans=ans.readInt();

    if(get==jans) {
        quitf(_ok,"Well done!You`ve got cqxxx`s attention.");
    } else {
        quitf(0.2,"Oooops!Try again.");
    }

    return 0;
}
