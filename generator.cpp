#include "generator.h"

generator::generator()
{

}
generator::~generator()
{
}
// Read 'qrencode.h' to learn more about QRecLevel & QRcode_encodeString(...).
QRecLevel generator::ECLEVEL(int lvl)
{
    switch (lvl) {
    case 0:
        return QR_ECLEVEL_L; 
        break;
    case 1:
        return QR_ECLEVEL_M;
        break; 
    case 2:
        return QR_ECLEVEL_Q;
        break;
    default:
        return QR_ECLEVEL_H;
        break;
    }
}
QRcode *generator::encode_String(const char *text, int version, int er_correction, int case_sensitive)
{
    if(text==0){
        return nullptr;
    }
    QRecLevel lvl = generator::ECLEVEL(er_correction);
    return QRcode_encodeString(text,version,lvl,QR_MODE_8,case_sensitive);
}
