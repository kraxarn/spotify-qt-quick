#include "qmlmanager.hpp"
#include "lib/qtquickpaths.hpp"

#include <QCommandLineParser>
#include <QGuiApplication>

auto main(int argc, char **argv) -> int
{
	// Set name for settings etc.
	QCoreApplication::setOrganizationName(ORG_NAME);
	QCoreApplication::setApplicationName(APP_NAME);
	QCoreApplication::setApplicationVersion(APP_VERSION);

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
