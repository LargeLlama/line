#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) 
{

	//if the first point is "ahead" of the second
	if (x1 < x0)
	{
		//just swap the coordinates so we don't have to draw backwards
		draw_line(x1, y1, x0, y0, s, c);
	}
	else 
	{
		//set the x and y cordinates to the one given
		int x = x0;
		int y = y0;

		//set A and B according to the line algorithm
		int A = y1 - y0;
		int B = -(x1 - x0);

		//octant I
		//defined by the fact that the line's slope is between 0 and 1
		if (A <= -B && A >= 0)
		{
		  int d = 2*A + B;

		  while (x <= x1)
		  {
			plot(s, c, x, y);
			x++;
			d += 2 * A;

			if(d >= 0)
			{
			   y++;
			   d += 2*B;
			}
		  }
		}
		//octant II
		//slope is between 1 and undefined
		else if(A >= 0 && A >= -B)
		{
		  int d = A + (2 * B);

		  while (y <= y1)
		  {
			plot(s, c, x, y);
			y++;
			d += 2*B;

			if(d <= 0)
			{
			   x++;
			   d += 2*A;
			}
		  }
		}
		//octant VII
		//slope is between undefined and -1
		else if (A <= 0 && A <= B)
		{
		  int d = A - (2 * B);

		  while (y >= y1)
		  {
			plot(s, c, x, y);
			y--;
			d-= 2*B;

			if (d >= 0)
			{
			   x++;
			   d += 2 * A;
			}
		  }
		}
		//octant IIX
		//slope is between -1 and 0
		else if (A <= 0 && A >= B)
		{
		  int d = (2 * A) - B;

		  while (x <= x1)
		  {
			plot(s, c, x, y);
			x++;
			d += 2 * A;

			if (d <= 0)
			{
			   y--;
			   d -= 2*B;
			}
		  }
		}
	}
}
