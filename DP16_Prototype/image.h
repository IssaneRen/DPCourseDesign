#ifndef IMAGE
#define IMAGE

#include <iostream>
using namespace std;
#include "imagetype.h"

class Image {
public:
    virtual void draw() = 0;
    static Image* findAndClone(imageType type);
    virtual ~Image() {cout << "Image::删除" << endl; }
protected:
    virtual imageType returnType() = 0;
    virtual Image* clone() = 0;
    static void addPrototype(Image* image) { _prototypes[_nextSlot++] = image; }
private:
    static Image* _prototypes[10];
    static int _nextSlot;
};

//define static members
Image* Image::_prototypes[];
int Image::_nextSlot;

//check if it will be re-compiled
Image* Image::findAndClone(imageType type)
{
    for(int i = 0; i < _nextSlot; i++){
        if(_prototypes[i]->returnType() == type)
            return _prototypes[i]->clone();
    }
}

#endif // IMAGE

