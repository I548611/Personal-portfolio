#ifndef GPS_H
#define GPS_H

#include "IGps.h"

#define MINIMUM_HEIGHT 5

class Gps : public IGps
{
public:
    Gps();
    void updatePosition(int diffX, int diffY, int diffHeight) override;
    void landing();
    int getX() const override;
    int getY() const override;
    int getHeight() const override;

private:
    int x;
    int y;
    int height;
};

#endif
