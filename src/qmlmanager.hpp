#pragma once

#include "lib/settings.hpp"
#include "lib/log.hpp"

#include "common.hpp"
#include "qml/guiapplication.hpp"
#include "qml/settings.hpp"
#include "page/setup.hpp"

#include <QObject>
#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>

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

	void setStyle() const;

	void defineTypes();

	template<typename T>
	void addType(const char *uri, const char *name)
	{
		qmlRegisterType<T>(uri, 1, 0, name);
	}
};
