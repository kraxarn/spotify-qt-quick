#pragma once

#include "qml/settings.hpp"
#include <QtQml/qqmlregistration.h>

namespace Page
{
	class Setup: public QObject
	{
		Q_OBJECT

		QML_ELEMENT
		Q_PROPERTY(QString clientId READ getClientId WRITE setClientId NOTIFY clientIdChanged)
		Q_PROPERTY(QString clientSecret READ getClientSecret WRITE setClientSecret NOTIFY clientSecretChanged)
		Q_PROPERTY(bool authButtonEnabled READ getAuthButtonEnabled NOTIFY authButtonEnabledChanged)
		Q_PROPERTY(QString redirectUriText READ getRedirectUriText NOTIFY redirectUriTextChanged)

	public:
		Setup();

		Q_INVOKABLE void openDashboard() const;
		Q_INVOKABLE void authenticate();
		Q_INVOKABLE void copyRedirectUri();

		[[nodiscard]]
		auto getClientId() const -> QString;
		void setClientId(const QString &value);

		[[nodiscard]]
		auto getClientSecret() const -> QString;
		void setClientSecret(const QString &value);

		auto getAuthButtonEnabled() const -> bool;
		auto getRedirectUriText() const -> const QString &;

	signals:
		void clientIdChanged();
		void clientSecretChanged();
		void authButtonEnabledChanged();
		void redirectUriTextChanged();

	private:
		Qml::Settings settings;

		bool authButtonEnabled = true;
		QString redirectUriText;
	};
}
