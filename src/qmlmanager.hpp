#pragma once

#include "qml/settingsqml.hpp"
#include "qml/spotifyqml.hpp"
#include "utilsqml.hpp"

#include "lib/settings.hpp"
#include "lib/libversion.hpp"
#include "lib/log.hpp"

#include <QObject>
#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QtWebEngine>

class QmlManager: QObject
{
	Q_OBJECT

public:
	explicit QmlManager(lib::settings &settings);

	void load(const QString &url);

	auto setup() -> bool;
	void main();

private:
	QQmlApplicationEngine *appEngine;
	lib::settings &settings;

	void defineTypes();
};
