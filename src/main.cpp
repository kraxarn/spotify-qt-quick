#include "qmlmanager.hpp"
#include "lib/qtquickpaths.hpp"

#include <QGuiApplication>
#include <QCoreApplication>
#include <QCommandLineParser>

auto main(int argc, char **argv) -> int
{
	// Set name for settings etc.
	QCoreApplication::setOrganizationName("kraxarn");
	QCoreApplication::setApplicationName("spotify-qt");
	QCoreApplication::setApplicationVersion(APP_VERSION);

	// High-DPI support
	// These flags are deprecated and always enabled in Qt 6 and newer
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

	// Create Qt application
	QGuiApplication app(argc, argv);

	// Settings
	QtQuickPaths paths(nullptr);
	lib::settings settings(paths);

	// Create QML engine
	QmlManager qml(settings);

	// Command line parameters
	QCommandLineParser parser;
	parser.addVersionOption();
	parser.addHelpOption();
	parser.addOptions({
		{"dev", "Enable developer mode for troubleshooting issues."},
		{"reset-credentials", "Allows providing new Spotify credentials."}
	});
	parser.process(app);

	if (parser.isSet("dev"))
	{
		lib::developer_mode::enabled = true;
	}

	// First setup
	if (settings.account.refresh_token.empty()
		|| parser.isSet("reset-credentials"))
	{
		if (qml.setup())
		{
			return 0;
		}
	}

	// Create main view
	qml.main();

	// Run
	return QGuiApplication::exec();
}
