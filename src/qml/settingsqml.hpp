#pragma once

#include "lib/qtquickpaths.hpp"
#include "lib/settings.hpp"

#include <QObject>
#include <QtQml>

class SettingsQml: public QObject
{
Q_OBJECT
	Q_PROPERTY(QJsonObject account READ getAccount NOTIFY accountChanged)
	Q_PROPERTY(QJsonObject general READ getGeneral WRITE setGeneral NOTIFY generalChanged)
	Q_PROPERTY(QJsonObject spotify READ getSpotify WRITE setSpotify NOTIFY spotifyChanged)
	QML_ELEMENT

public:
	explicit SettingsQml(lib::settings &settings, QObject *parent);

	Q_INVOKABLE void logOut(const QString &mode);

	auto getAccount() -> QJsonObject;

	auto getGeneral() -> QJsonObject;
	void setGeneral(const QJsonObject &json);

	auto getSpotify() -> QJsonObject;
	void setSpotify(const QJsonObject &json);

	auto getSettings() -> lib::settings &;

signals:
	void accountChanged();
	void generalChanged();
	void spotifyChanged();

private:
	lib::settings &settings;

	void update(const QString &section, const QJsonObject &value);
	auto toJsonDocument() -> QJsonDocument;
	void fromJsonDocument(const QJsonDocument &json);
};
