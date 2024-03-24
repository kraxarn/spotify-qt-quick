#include "page/setup.hpp"
#include "util/url.hpp"

#include <QClipboard>
#include <QCoreApplication>
#include <QGuiApplication>

Page::Setup::Setup()
	: settings(this),
	redirectUriText(QStringLiteral("Copy redirect uri"))
{
}

void Page::Setup::openDashboard() const
{
	Url::open("https://developer.spotify.com/dashboard/applications", parent());
}

void Page::Setup::authenticate()
{
	// TODO: Break out logic from spotify-qt

	authButtonEnabled = false;
	emit authButtonEnabledChanged();
}

void Page::Setup::copyRedirectUri()
{
	auto *clipboard = QGuiApplication::clipboard();
	clipboard->setText(QStringLiteral("sptqt://auth"), QClipboard::Clipboard);

	redirectUriText = QStringLiteral("Copied redirect uri!");
	emit redirectUriTextChanged();
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

auto Page::Setup::getAuthButtonEnabled() const -> bool
{
	return authButtonEnabled;
}

auto Page::Setup::getRedirectUriText() const -> const QString &
{
	return redirectUriText;
}
