#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() 
{
	//declare the screen and color struct found in ml6
	screen s;
	color c;

	//initialize the colors in each struct
	c.red = 0;
	c.green = MAX_COLOR;
	c.blue = MAX_COLOR;

	//clear the screen
	clear_screen(s);
	
	//loop thru, making a gradient under a square root graph
	for(int i = 0, x = 0, y = 0; x <= XRES && y <= YRES; i++, y++, x++)
	{
		c.red = (i * 2) % 150;
		c.green = (i + 10) % 100;
		c.blue = (i * 10) % 500;

		draw_line(x, sqrt(x * XRES), y, (y / 100) % YRES, s, c);
	}

	//display the image and save it as a png
	display(s);
	save_extension(s, "lines.png");
}
