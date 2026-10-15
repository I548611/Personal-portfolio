#ifndef MGPS_H
#define MGPS_H

#include "IGps.h"

#include <gmock/gmock.h>

class MGps : public IGps 
{
public:
    MOCK_METHOD3(updatePosition, void(int diffX, int diffY, int diffHeight));
    MOCK_CONST_METHOD0(getX, int());
    MOCK_CONST_METHOD0(getY, int());
    MOCK_CONST_METHOD0(getHeight, int());
    MOCK_METHOD0(landing, void());
};

#endif
