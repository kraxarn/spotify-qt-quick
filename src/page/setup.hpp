#pragma once

#include "common.hpp"
#include "qml/settings.hpp"
#include "util/url.hpp"

namespace Page
{
	class Setup: public QObject
	{
	Q_OBJECT

		QML_ELEMENT
		Q_PROPERTY(QString clientId READ getClientId WRITE setClientId NOTIFY clientIdChanged)
		Q_PROPERTY(QString clientSecret READ getClientSecret WRITE setClientSecret NOTIFY clientSecretChanged)

	public:
		explicit Setup(QObject *parent = nullptr);

		Q_INVOKABLE void close();
		Q_INVOKABLE void openDashboard();
		Q_INVOKABLE void authenticate();

		auto getClientId() const -> QString;
		void setClientId(const QString &value);

		auto getClientSecret() const -> QString;
		void setClientSecret(const QString &value);

	signals:
		void clientIdChanged();
		void clientSecretChanged();

	private:
		Qml::Settings settings;
	};
}
