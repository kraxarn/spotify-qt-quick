import QtQuick.Controls

Label {
	wrapMode: Label.WordWrap
	text: "Before using the app, you need to setup your Spotify Web API keys.\n" +
		"You can do this by opening the Spotify Dashboard, create a new app and " +
		"set the redirect uri (not website) to sptqt://auth.\n" +
		"Then, enter your Client ID and secret below from the same application page:"
}