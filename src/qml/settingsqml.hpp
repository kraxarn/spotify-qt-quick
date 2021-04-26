#pragma once

#include "../src/lib/qtpaths.hpp"
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
	explicit SettingsQml(QObject *parent = nullptr);
	~SettingsQml() override;

	Q_INVOKABLE void logOut(const QString &mode);

	QJsonObject getAccount();

	QJsonObject getGeneral();
	void setGeneral(const QJsonObject &json);

	QJsonObject getSpotify();
	void setSpotify(const QJsonObject &json);

	lib::settings &getSettings();

signals:
	void accountChanged();
	void generalChanged();
	void spotifyChanged();

private:
	lib::settings *settings = nullptr;
	QtPaths *paths = nullptr;

	void update(const QString &section, const QJsonObject &value);
	QJsonDocument toJsonDocument();
	void fromJsonDocument(const QJsonDocument &json);
};