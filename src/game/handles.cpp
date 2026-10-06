#include "../pathing/gamedecl.h"

HEntity::HEntity()
	: ID (0)
{
}

HProp::HProp()
	: ID (0)
{
}

bool HEntity::isNull() const
{
	return ID == 0;
}

bool HEntity::isValid() const
{
	return ID;
}

bool HProp::isNull() const
{
	return ID == 0;
}

bool HProp::isValid() const
{
	return ID;
}

bool HItem::isValid() const
{
	return ID;
}

int HEntity::getID() const
{
	return ID;
}

bool HEntity::operator==(HEntity other) const
{
	return ID == other.getID();
}

bool HEntity::operator!=(HEntity other) const
{
	return ID != other.getID();
}
