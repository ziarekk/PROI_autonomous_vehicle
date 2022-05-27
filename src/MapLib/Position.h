#pragma once

class Position
{
public:
    int x;
    int y;
    Position() : x(0), y(0) {};
    Position(int x, int y) noexcept {
        this->x = x;
        this->y = y;
    }
    bool operator==(Position const& pos) const noexcept {
        if (this->x == pos.x && this->y == pos.y) {
            return true;
        }
        return false;
    }

};
