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

	public:
		explicit Setup(QObject *parent);

		Q_INVOKABLE void close();
		Q_INVOKABLE void openDashboard();
		Q_INVOKABLE void authenticate();

		[[nodiscard]] auto getClientId() const -> QString;
		void setClientId(const QString &value);

		[[nodiscard]] auto getClientSecret() const -> QString;
		void setClientSecret(const QString &value);

	signals:
		void clientIdChanged();
		void clientSecretChanged();

	private:
		Qml::Settings settings;
	};
}
