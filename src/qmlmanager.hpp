#pragma once

#include "lib/settings.hpp"

#include <QQmlApplicationEngine>

class QmlManager: public QObject
{
Q_OBJECT

public:
	explicit QmlManager(lib::settings &settings);

	void load(const QString &url);

	auto setup() -> bool;
	void main();

private:
	QQmlApplicationEngine appEngine;
	lib::settings &settings;

	static void setStyle();
	void defineTypes();

	static void onObjectCreated(QObject *object, const QUrl &url);
};
