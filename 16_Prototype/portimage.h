#ifndef PORTIMAGE
#define PORTIMAGE

#include <iostream>
using namespace std;
#include <image.h>
#include <imagetype.h>

class PortImage : public Image{
public:
    imageType returnType() { return PORT; }
    void draw() { cout << "PortImage::绘制" << _id << endl; }
    Image* clone() { return new PortImage(1); }
    ~PortImage() { cout << "PortImage::删除 "; }
protected:
    PortImage(int dummy) { _id = _count++;}
private:
    PortImage() { addPrototype(this);}
    static PortImage _portImage;
    int _id;
    static int _count;
};

PortImage PortImage::_portImage;
int PortImage::_count = 1;

#endif // PORTIMAGE

