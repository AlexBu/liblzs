#include <iostream>
#include <stdio.h>
#include "lzs.h"

using namespace std;

int main(int argc, char** argv)
{
    cout <<"Lzs Algorithm used by FFVIII"<< endl;

    FILE *infile, *outfile;
    unsigned char *in, *out;
    unsigned int lengthin, lengthout;

    if (argc != 4) {
        cout<<"'lzs e/d file1 file2' encodes/decodes file1 into file2."<<endl;
        return 1;
    }

    infile = fopen(argv[2], "rb");
    outfile = fopen(argv[3], "wb");

    fseek(infile, 0, SEEK_END);
    lengthin = ftell(infile);
    fseek(infile, 0, SEEK_SET);
    in = new unsigned char[lengthin];
    out = new unsigned char[lengthin*8];
    fread(in, 1, lengthin, infile);

    if(strpbrk(argv[1], "Ee"))
    {
        lzs_encode(in,out,&lengthin,&lengthout);
    }
    else if(strpbrk(argv[1], "Dd"))
    {
        lzs_decode(in,out,&lengthin,&lengthout);
    }
    else
        cout<<"???"<<argv[1]<<endl;

    fwrite(out, 1, lengthout, outfile);

    fflush(infile);
    fflush(outfile);

    fclose(infile);
    fclose(outfile);

    delete []in;
    delete []out;

    cout << "in = " << lengthin << ", out = " << lengthout << endl;
    return 0;
}