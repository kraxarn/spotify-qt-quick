#include "util/url.hpp"

void Url::open(const QString &url, QObject *parent)
{
	if (QDesktopServices::openUrl(QUrl(url)))
	{
		return;
	}

	auto *dialog = parent->findChild<QObject *>("openLinkDialog");
	if (dialog == nullptr)
	{
		return;
	}

	dialog->setProperty("linkText", url);
	dialog->setProperty("visible", true);
}
