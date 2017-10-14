#ifndef LANDSATIMAGE
#define LANDSATIMAGE

#include <iostream>
using namespace std;
#include "imagetype.h"
#include "image.h"

class LandSatImage: public Image
{
public:
    imageType returnType() {return LSAT;}
    void draw() {cout << "LandSatImage::绘制 " << _id << endl;}

    Image* clone() { return new LandSatImage(1);}
    ~LandSatImage() {cout << "LandSatImage::删除 ";}
protected:
    LandSatImage(int dummy) {_id = _count++; }
private:
    static LandSatImage _landSatImage;
    LandSatImage() { addPrototype(this);}
    int _id;
    static int _count;
};

LandSatImage LandSatImage::_landSatImage;
int LandSatImage::_count = 1;

#endif // LANDSATIMAGE

