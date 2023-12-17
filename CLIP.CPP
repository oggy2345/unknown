#include <conio.h>
#include <iostream.h>
#include <graphics.h>
static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xmin, ymin, xmax, ymax;
int getcode(int x, int y)
{
    int code = 0;
    // Perform Bitwise OR to get outcode

    if (y > ymax)
        code |= BOTTOM;
    if (y < ymin)
        code |= TOP;
    if (x < xmin)
        code |= LEFT;
    if (x > xmax)
        code |= RIGHT;
    return code;
}
int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "//TURBOC3//BGI ");
    setcolor(WHITE);
    cout << "Enter Enter windows min and max values: ";
    cin >> xmin >> ymin >> xmax >> ymax;
    rectangle(xmin, ymin, xmax, ymax);
    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;
    line(x1, y1, x2, y2);
    getch();
    int outcode1 = getcode(x1, y1), outcode2 = getcode(x2, y2);
    int accept = 0; // decides if line is to be drawn
    while (1)
    {
        float m = (float)(y2 - y1) / (x2 - x1);
        // Both points inside. Accept line
        if (outcode1 == 0 && outcode2 == 0)
        {
            accept = 1;
            break;
        }
        // AND of both codes != 0.Line is outside. Reject line
        else if ((outcode1 & outcode2) != 0)
        {
            break;
        }
        else
        {
            int x, y;
            int temp;
            // Decide if point1 is inside, if not, calculate intersection
            if (outcode1 == 0)
                temp = outcode2;
            else
                temp = outcode1;
            // Line clips bottom edge
            if (temp & BOTTOM)
            {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }
            else if (temp & TOP)
            { // Line clips top edge
                x = x1 + (ymin - y1) / m;
                y = ymin;
            }
            else if (temp & LEFT)
            { // Line clips left edge
                x = xmin;
                y = y1 + m * (xmin - x1);
            }
            else if (temp & RIGHT)
            { // Line clips right edge
                x = xmax;
                y = y1 + m * (xmax - x1);
            }
            if (temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }
    cout << "After clipping:";
    if (accept)
        cleardevice();
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(RED);
    line(x1, y1, x2, y2);
    getch();
    closegraph();
	return 0;
}