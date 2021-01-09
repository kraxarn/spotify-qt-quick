#include "qmlmanager.hpp"

#include "settingsqml.hpp"
#include "spotifyqml.hpp"
#include "utilsqml.hpp"

#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QtWebEngine>

#define GET_ENGINE() (dynamic_cast<QQmlApplicationEngine *>(appEngine))

QmlManager::QmlManager(lib::settings &settings)
	: appEngine(new QQmlApplicationEngine(this)),
	settings(settings)
{
	defineTypes();

	// TODO: Qt on mobile doesn't support WebEngine, do something else
	//QtWebEngine::initialize();
}

void QmlManager::defineTypes()
{
	auto engine = GET_ENGINE();

	// spotify-qt
	engine->rootContext()->setContextProperty("AppVersion", QCoreApplication::applicationVersion());
	// spotify-qt-quick
	engine->rootContext()->setContextProperty("LibVersion", LIB_VERSION);
	// qt
	engine->rootContext()->setContextProperty("QtVersion", QString("%1.%2")
		.arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));

	qmlRegisterType<SpotifyQml>("com.kraxarn.spotify",
		1, 0,
		"Spotify");

	qmlRegisterType<UtilsQml>("com.kraxarn.utils",
		1, 0,
		"Utils");

	qmlRegisterType<SettingsQml>("com.kraxarn.settings",
		1, 0,
		"Settings");
}

void QmlManager::load(const QString &url)
{
	GET_ENGINE()->load(QUrl(url));
}

bool QmlManager::setup()
{
	load("qrc:/qml/setup.qml");
	QCoreApplication::exec();
	settings.load();

	return settings.account.accessToken.isEmpty() || settings.account.refreshToken.isEmpty();
}

void QmlManager::main()
{
	auto engine = GET_ENGINE();

	auto settingsStyle = QString::fromStdString(settings.general.style);
	QQuickStyle::setStyle(QQuickStyle::availableStyles()
		.contains(settingsStyle)
		? settingsStyle
		: "Material");

	QQmlApplicationEngine::connect(engine, &QQmlApplicationEngine::objectCreated, this,
		[](QObject *obj, const QUrl &url)
		{
			if (obj == nullptr)
				QCoreApplication::quit();
		}, Qt::QueuedConnection);

	engine->load(QUrl("qrc:/qml/main.qml"));
}