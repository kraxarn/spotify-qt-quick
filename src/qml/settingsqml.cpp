#include "settingsqml.hpp"

SettingsQml::SettingsQml(lib::settings &settings, QObject *parent)
	: settings(settings),
	QObject(parent)
{
}

auto SettingsQml::getAccount() -> QJsonObject
{
	return toJsonDocument()["Account"].toObject();
}

auto SettingsQml::getGeneral() -> QJsonObject
{
	return toJsonDocument()["General"].toObject();
}

void SettingsQml::setGeneral(const QJsonObject &json)
{
	update("General", json);
}

auto SettingsQml::getSpotify() -> QJsonObject
{
	return toJsonDocument()["Spotify"].toObject();
}

void SettingsQml::setSpotify(const QJsonObject &json)
{
	update("Spotify", json);
}

void SettingsQml::update(const QString &section, const QJsonObject &value)
{
	auto json = toJsonDocument().object();
	json[section] = value;
	fromJsonDocument(QJsonDocument(json));
	settings->save();
}

void SettingsQml::logOut(const QString &mode)
{
	if (mode == "clearAll")
	{
		settings.remove_client();
	}

	if (mode == "clearAll" || mode == "logOut")
	{
		settings.remove_tokens();
	}
}

auto SettingsQml::toJsonDocument() -> QJsonDocument
{
	return QJsonDocument::fromJson(QString::fromStdString(settings
		.to_json().dump()).toUtf8());
}

void SettingsQml::fromJsonDocument(const QJsonDocument &json)
{
	settings.from_json(QString::fromUtf8(json.toJson()).toStdString());
}

auto SettingsQml::getSettings() -> lib::settings &
{
	return settings;
}
