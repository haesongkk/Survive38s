#include "Header.h"
#include "Util.h"

COORD to_coord(Vector2 v)
{
	COORD c = { v.x,v.y };
	return c;
}