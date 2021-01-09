#include "settingsqml.hpp"

SettingsQml::SettingsQml(QObject *parent)
	: QObject(parent)
{
	paths = new QtPaths(this);
	settings = new lib::settings(*paths);
}

SettingsQml::~SettingsQml()
{
	delete settings;
}

QJsonObject SettingsQml::getAccount()
{
	return toJsonDocument()["Account"].toObject();
}

QJsonObject SettingsQml::getGeneral()
{
	return toJsonDocument()["General"].toObject();
}

void SettingsQml::setGeneral(const QJsonObject &json)
{
	update("General", json);
}

QJsonObject SettingsQml::getSpotify()
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
		settings->remove_client();

	if (mode == "clearAll" || mode == "logOut")
		settings->remove_tokens();
}

QJsonDocument SettingsQml::toJsonDocument()
{
	return QJsonDocument::fromJson(QString::fromStdString(settings
		->to_json().dump()).toUtf8());
}

void SettingsQml::fromJsonDocument(const QJsonDocument &json)
{
	settings->from_json(QString::fromUtf8(json.toJson()).toStdString());
}

lib::settings &SettingsQml::getSettings()
{
	return *settings;
}
