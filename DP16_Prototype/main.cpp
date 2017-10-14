//Just for test
#include <iostream>

using namespace std;
#include "image.h"
#include "imagetype.h"
#include "landsatimage.h"
#include "spotimage.h"
#include "portimage.h"

const int NUM_IMAGES = 12;
imageType input[NUM_IMAGES] = {
    LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT, SPOT, PORT, PORT, LSAT,
};

int main()
{
    Image *images[NUM_IMAGES];

    for(int i = 0; i < NUM_IMAGES; i++)
        images[i] = Image::findAndClone(input[i]);

    for(int i = 0; i < NUM_IMAGES; i++)
        images[i]->draw();

    for(int i = 0; i < NUM_IMAGES; i++)
        delete images[i];

    return 0;
}

