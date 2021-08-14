#include "page/setup.hpp"

Page::Setup::Setup(QObject *parent)
	: settings(this),
	QObject(parent)
{
}

void Page::Setup::close()
{
	QCoreApplication::quit();
}

void Page::Setup::openDashboard()
{
	Url::open("https://developer.spotify.com/dashboard/applications", parent());
}

void Page::Setup::authenticate()
{
	// TODO: Break out logic from spotify-qt
}

//region clientId

auto Page::Setup::getClientId() const -> QString
{
	return QString::fromStdString(settings.getConst().account.client_id);
}

void Page::Setup::setClientId(const QString &value)
{
	settings.get().account.client_id = value.toStdString();
	settings.get().save();

	emit clientIdChanged();
}

//endregion

//region clientSecret

auto Page::Setup::getClientSecret() const -> QString
{
	return QString::fromStdString(settings.getConst().account.client_secret);
}

void Page::Setup::setClientSecret(const QString &value)
{
	settings.get().account.client_secret = value.toStdString();
	settings.get().save();

	emit clientSecretChanged();
}

//endregion