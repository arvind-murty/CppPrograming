

#include "gwindow.h"
#include "gobjects.h"


void DrawArc(GWindow & gw, const char *color, double y_of_center);


int main()
{
    GWindow gw;
    gw.setColor("CYAN");
    gw.fillRect(0, 0, gw.getWidth(), gw.getHeight());
    DrawArc(gw, "RED",   00);
    DrawArc(gw, "ORANGE",  20);
    DrawArc(gw, "YELLOW", 40);
    DrawArc(gw, "GREEN", 60);
    DrawArc(gw, "BLUE", 80);
    DrawArc(gw, "MAGENTA", 100);
    DrawArc(gw, "CYAN",    120);
    return 0;
}


void DrawArc(GWindow & gw, const char *color, double delta_y)
{
    double cx = gw.getWidth() / 2;
    double cy = gw.getHeight() / 2;

    double rx = gw.getWidth() * 1.2 /2;
    double ry = gw.getWidth() / 2;

    GArc *arc = new GArc(cx - rx, gw.getHeight()/2 + delta_y - 80, 2 * rx, 2 * ry, 0, 360);
    arc->setFillColor(color);
    arc->setFilled(true);
    gw.add(arc);
}
