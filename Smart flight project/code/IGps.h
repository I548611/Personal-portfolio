#ifndef IGPS_H
#define IGPS_H

#include <memory>

class IGps
{
public:
    virtual ~IGps() = default;
    virtual void updatePosition(int diffX, int diffY, int diffHeight) = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getHeight() const = 0;
    virtual void landing() = 0;
};

std::unique_ptr<IGps> createGps();

#endif
