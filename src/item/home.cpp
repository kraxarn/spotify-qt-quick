#include "item/home.hpp"

Item::Home::Home(const QString &text, const QString &icon,
	Item::Home::IconType iconType, bool title)
	: text(text),
	icon(icon),
	iconType(iconType),
	title(title)
{
}
