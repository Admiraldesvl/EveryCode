#ifndef GENERATOR_H
#define GENERATOR_H

#include "qrencode.h"
class generator
{
public:
    generator();
    ~generator();
    QRcode *encode_String(const char * text, int version, int er_correction, int case_sensitive);
private:
    QRecLevel ECLEVEL(int lvl);
    
};

#endif // GENERATOR_H
