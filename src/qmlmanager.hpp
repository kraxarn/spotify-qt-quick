#pragma once

#include "lib/settings.hpp"

#include <QObject>

class QmlManager: QObject
{
	Q_OBJECT


public:
	explicit QmlManager(lib::settings &settings);

	void load(const QString &url);

	bool setup();
	void main();

private:
	QObject *appEngine;
	lib::settings &settings;

	void defineTypes();
};


