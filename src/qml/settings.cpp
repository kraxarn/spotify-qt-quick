#include "qml/settings.hpp"

Qml::Settings::Settings(QObject *parent)
	: paths(this),
	settings(paths),
	QObject(parent)
{
}

auto Qml::Settings::get() -> lib::settings &
{
	return settings;
}

auto Qml::Settings::getConst() const -> const lib::settings &
{
	return settings;
}
