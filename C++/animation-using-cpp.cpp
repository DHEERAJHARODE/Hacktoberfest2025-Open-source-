#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <iostream.h>

int main()
{
	int gd = DETECT, gm, i, a;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	for (i = 0; i < 600; i++) {
		line(50 + i, 405, 100 + i, 405);
		line(75 + i, 375, 125 + i, 375);
		line(50 + i, 405, 75 + i, 375);
		line(100 + i, 405, 100 + i, 345);
		line(150 + i, 405, 100 + i, 345);
		line(75 + i, 345, 75 + i, 370);
		line(70 + i, 370, 80 + i, 370);
		line(80 + i, 345, 100 + i, 345);

		circle(150 + i, 405, 30);
		circle(50 + i, 405, 30);

		line(0, 436, getmaxx(), 436);

		rectangle(getmaxx() - i, 436,
				650 - i, 431);
		delay(10);
		cleardevice();
	}
	getch();
	closegraph();
}
