#include "qmlmanager.hpp"

QmlManager::QmlManager(lib::settings &settings)
	: appEngine(new QQmlApplicationEngine(this)),
	settings(settings)
{
	defineTypes();
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
		.arg(QT_VERSION_MAJOR, QT_VERSION_MINOR));

	// Custom types
	addType<Qml::GuiApplication>("Qml.GuiApplication", "GuiApplication");
	addType<Qml::Settings>("Qml.Settings", "Settings");

	// Pages
	addType<Page::Setup>("Page.Setup", "Setup");
}

void QmlManager::load(const QString &url)
{
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

	appEngine->load(QUrl(url));
}

void QmlManager::setStyle() const
{
	/*
	 * TODO
	 * Dark theme in spotify-qt uses Fusion, while dark theme in
	 * spotify-qt-quick uses Material. These should probably not
	 * depend on each other, so force Material on dark theme
	 * for now
	 */

	const auto settingsStyle = settings.get_dark_theme()
		? "Material"
		: QString::fromStdString(settings.general.style);

	QQuickStyle::setFallbackStyle("Material");
	QQuickStyle::setStyle(settingsStyle);
}

auto QmlManager::setup() -> bool
{
	setStyle();
	load("qrc:/qml/setup.qml");
	QCoreApplication::exec();

	return settings.account.access_token.empty()
		|| settings.account.refresh_token.empty();
}

void QmlManager::main()
{
	setStyle();
	load("qrc:/qml/main.qml");
}
