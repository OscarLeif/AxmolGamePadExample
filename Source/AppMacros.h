//
// Created by oscar on 3/21/2024.
//

#ifndef AXMOLGAMEPAD_APPMACROS_H
#define AXMOLGAMEPAD_APPMACROS_H

#include "axmol.h"

typedef struct tagResource
{
    axmol::Size size;
    char directory[100];
}Resource;

static axmol::Size designResolutionSize = axmol::Size(1920, 1080);

static Resource mediumResource =  { axmol::Size(960, 540),  "ipad"   };
static Resource largeResource  =  { axmol::Size(1920, 1080), "ipadhd" };

#endif //AXMOLGAMEPAD_APPMACROS_H
