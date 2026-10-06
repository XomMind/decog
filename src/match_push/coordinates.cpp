// NOTE: placeholder names; recovered two-coordinate and four-field layouts.
struct PushCoord
{
	int x;
	int y;
	PushCoord(int x_, int y_);
	PushCoord subtract(const PushCoord &p);
	PushCoord add(const PushCoord &p);
};
PushCoord PushCoord::subtract(const PushCoord &p)
{
	return PushCoord(x - p.x,y - p.y);
}
PushCoord PushCoord::add(const PushCoord &p)
{
	return PushCoord(x + p.x,y + p.y);
}
struct PushBounds
{
	int x;
	int y;
	int width;
	int height;
	int right();
	int bottom();
	PushCoord topLeft();
	PushCoord topRight();
	PushCoord bottomLeft();
	PushCoord bottomRight();
	PushCoord center();
	void grow(int amount);
};
int PushBounds::right()
{
	return x + width - 1;
}
int PushBounds::bottom()
{
	return y + height - 1;
}
PushCoord PushBounds::topLeft()
{
	return PushCoord(x,y);
}
PushCoord PushBounds::topRight()
{
	return PushCoord(x + width - 1,y);
}
PushCoord PushBounds::bottomLeft()
{
	return PushCoord(x,y + height - 1);
}
PushCoord PushBounds::bottomRight()
{
	return PushCoord(x + width - 1,y + height - 1);
}
PushCoord PushBounds::center()
{
	return PushCoord(width / 2 + x,height / 2 + y);
}
void PushBounds::grow(int amount)
{
	x = x - amount;
	y = y - amount;
	width = width + amount * 2;
	height = height + amount * 2;
}
