#include "qmlmanager.hpp"

#include "page/setup.hpp"
#include "page/main.hpp"

#include <QQmlContext>
#include <QCoreApplication>
#include <QQuickStyle>

QmlManager::QmlManager(lib::settings &settings)
	: settings(settings)
{
	defineTypes();

	QQmlApplicationEngine::connect(&appEngine, &QQmlApplicationEngine::objectCreated,
		this, &QmlManager::onObjectCreated, Qt::QueuedConnection);
}

void QmlManager::defineTypes()
{
	// spotify-qt-quick
	appEngine.rootContext()->setContextProperty(QStringLiteral("AppVersion"),
		QCoreApplication::applicationVersion());

	// spotify-qt-lib
	appEngine.rootContext()->setContextProperty(QStringLiteral("LibVersion"),
		QStringLiteral(LIB_VERSION));

	// qt
	appEngine.rootContext()->setContextProperty(QStringLiteral("QtVersion"),
		QString("%1.%2").arg(QT_VERSION_MAJOR, QT_VERSION_MINOR));

	// Custom types
	//addType<Qml::GuiApplication>("Qml.GuiApplication", "GuiApplication");
	//addType<Qml::Settings>("Qml.Settings", "Settings");

	// Pages
	qmlRegisterType<Page::Setup>("Page.Setup", 1, 0, "Setup");
	qmlRegisterType<Page::Main>("Page.Main", 1, 0, "Main");
}

void QmlManager::load(const QString &url)
{
	appEngine.load(QUrl(url));
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
	load(QStringLiteral("qrc:/qml/SetupPage.qml"));
	QCoreApplication::exec();

	return settings.account.access_token.empty()
		|| settings.account.refresh_token.empty();
}

void QmlManager::main()
{
	setStyle();
	load(QStringLiteral("qrc:/qml/MainPage.qml"));
}

void QmlManager::onObjectCreated(QObject *object, const QUrl &url)
{
	if (object != nullptr)
	{
		return;
	}

	lib::log::error("Failed to load: {}", url.toString().toStdString());
	QCoreApplication::quit();
}
