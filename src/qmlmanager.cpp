#include "qmlmanager.hpp"

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
	// spotify-qt-quick
	appEngine->rootContext()->setContextProperty("AppVersion",
		QCoreApplication::applicationVersion());

	// spotify-qt-lib
	appEngine->rootContext()->setContextProperty("LibVersion", LIB_VERSION);

	// qt
	appEngine->rootContext()->setContextProperty("QtVersion", QString("%1.%2")
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
	appEngine->load(QUrl(url));
}

auto QmlManager::setup() -> bool
{
	load("qrc:/qml/setup.qml");
	QCoreApplication::exec();
	settings.load();

	return settings.account.access_token.empty()
		|| settings.account.refresh_token.empty();
}

void QmlManager::main()
{
	auto settingsStyle = QString::fromStdString(settings.general.style);
	QQuickStyle::setStyle(QQuickStyle::availableStyles().contains(settingsStyle)
		? settingsStyle
		: "Material");

	QQmlApplicationEngine::connect(appEngine, &QQmlApplicationEngine::objectCreated,
		this, [](QObject *obj, const QUrl &url)
		{
			if (obj == nullptr)
			{
				lib::log::error("Failed to load: {}",
					url.toString().toStdString());
				QCoreApplication::quit();
			}
		}, Qt::QueuedConnection);

	appEngine->load(QUrl("qrc:/qml/main.qml"));
}
