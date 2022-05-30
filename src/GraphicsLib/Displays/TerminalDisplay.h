#include "displays.h"
#include <stdio.h>

class TerminalDisplay: public Display{
public:
    TerminalDisplay() = default;
    void setPosition(Position coords);
    void drawPoint(Position coords, char character) override;
};
