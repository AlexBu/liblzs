#if !defined(LZS_H)
#define LZS_H

void lzs_decode(unsigned char *in, unsigned char *out, unsigned int *lengthin, unsigned int *lengthout);
void lzs_encode(unsigned char *in, unsigned char *out, unsigned int *lengthin, unsigned int *lengthout);

#endif // !defined(LZS_H)
