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

	public:
		Setup();

		Q_INVOKABLE void openDashboard() const;
		Q_INVOKABLE void authenticate();

		[[nodiscard]]
		auto getClientId() const -> QString;
		void setClientId(const QString &value);

		[[nodiscard]]
		auto getClientSecret() const -> QString;
		void setClientSecret(const QString &value);

		auto getAuthButtonEnabled() const -> bool;

	signals:
		void clientIdChanged();
		void clientSecretChanged();
		void authButtonEnabledChanged();

	private:
		Qml::Settings settings;

		bool authButtonEnabled = true;
	};
}
