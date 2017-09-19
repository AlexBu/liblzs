#include <iostream>
#include <stdio.h>
#include "lzs.h"

using namespace std;

int main(int argc, char** argv)
{
    cout <<"Lzs Algorithm used by FFVIII"<< endl;

    if (argc != 4) {
        cout<<"'lzs e/d file1 file2' encodes/decodes file1 into file2."<<endl;
        return 1;
    }

    if(strpbrk(argv[1], "Ee"))
    {
        lzs_encode_file(argv[2], argv[3]);
    }
    else if(strpbrk(argv[1], "Dd"))
    {
        lzs_decode_file(argv[2], argv[3]);
    }
    else
        cout<<"???"<<argv[1]<<endl;

    return 0;
}