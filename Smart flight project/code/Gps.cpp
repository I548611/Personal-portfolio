#include "Gps.h"

#include <iostream>

#include <memory>

Gps::Gps()
    : x(0), y(0), height(0)
{
}

void Gps::updatePosition(int diffX, int diffY, int diffHeight)
{
    x += diffX;
    y += diffY;
    height += diffHeight;
    if (height < MINIMUM_HEIGHT)
    {
        height = MINIMUM_HEIGHT;
        std::cout << "Stopped from going lower as you reached the minimum flying height \n";
    }
}

int Gps::getX() const
{
    return x;
}

int Gps::getY() const
{
    return y;
}

int Gps::getHeight() const
{
    return height;
}

void Gps::landing()
{
    height = 0;
}

std::unique_ptr<IGps> createGps()
{
    return std::make_unique<Gps>();
}

