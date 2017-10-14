#ifndef SPOTIMAGE
#define SPOTIMAGE

#include <iostream>
using namespace std;
#include "imagetype.h"
#include "image.h"

class SpotImage : public Image{
public:
    imageType returnType() {return SPOT; }
    void draw() {cout << "SpotImage::绘制" << _id << endl; }
    Image* clone() {return new SpotImage(1); }
    ~SpotImage() {cout << "SpotImage::删除 "; }
protected:
    SpotImage(int dummy) {_id = _count++; }
private:
    SpotImage() { addPrototype(this); }
    static SpotImage _spotImage;
    int _id;
    static int _count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

#endif // SPOTIMAGE

