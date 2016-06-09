

#include "gwindow.h"


void draw_square(GWindow & gw, const char *color, int x, int y);
void draw_circle(GWindow & gw, const char *color, int x, int y);
void draw_row(GWindow & gw, bool borl, int y);
void draw_circles(GWindow & gw, bool borl, int y);
void draw_board(GWindow & gw);


int main()
{
    GWindow gw(400, 400);
    draw_board(gw);
    return 0;
}


void draw_square(GWindow & gw, const char *color, int x, int y)
{
    gw.setColor(color);
    gw.fillRect(x, y, 50, 50);
}


void draw_circle(GWindow & gw, const char *color, int x, int y)
{
    gw.setColor(color);
    gw.fillOval(x, y, 40, 40);
}


void draw_row(GWindow & gw, bool borl, int y)
{
    int i = 0;

    if (borl)
    {
        while (i < 4)
        {
            draw_square(gw, "WHITE", 100 * i, y);
            draw_square(gw, "GRAY", 100 * i + 50, y);
            ++i;
        }
    }
    else
    {
        while (i < 4)
        {
            draw_square(gw, "GRAY", 100 * i, y);
            draw_square(gw, "WHITE", 100 * i + 50, y);
            ++i;
        }
    }
}


void draw_circles(GWindow & gw, bool borl, int y)
{
    int i = 0;

    if (y <= 100)
    {
        if (borl)
        {
            while (i < 4)
            {
                draw_circle(gw, "RED", 100 * i + 55, y + 5);
                ++i;
            }
        }
        else
        {
            while (i < 4)
            {
                draw_circle(gw, "RED", 100 * i + 5, y + 5);
                ++i;
            }
        }
    }
    else if (y >= 250)
    {
        if (borl)
        {
            while (i < 4)
            {
                draw_circle(gw, "BLACK", 100 * i + 55, y + 5);
                ++i;
            }
        }
        else
        {
            while (i < 4)
            {
                draw_circle(gw, "BLACK", 100 * i + 5, y + 5);
                ++i;
            }
        }
    }
}


void draw_board(GWindow & gw)
{
    int i = 0;

    while (i < 4)
    {
        draw_row(gw, true, 100 * i);
        draw_row(gw, false, 100 * i + 50);
        ++i;
    }

    i = 0;

    while (i < 4)
    {
        draw_circles(gw, true, 100 * i);
        draw_circles(gw, false, 100 * i + 50);
        ++i;
    }
}
