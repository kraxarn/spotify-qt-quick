import com.kraxarn.spotify 1.0
import com.kraxarn.utils 1.0
import com.kraxarn.settings 1.0

import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

import "/js/main.js" as JS

ApplicationWindow {
	id: root
	title: "spotify-qt-quick"
	visible: true
	width: 540
	height: 960

	Material.theme: Material.Dark
	// Spotify-like colors
	Material.primary: "#282828"
	Material.background: "#121212"
	Material.accent: "#1db954"

	readonly property bool inPortrait: root.width < root.height
	readonly property int listItemHeight: 48
	property string currentContext
	property string currentTrackId

	function loadTracks(tracks, context) {
		drawer.close()
		JS.loadTracks(tracks)
		currentContext = context
	}

	function loadArtist(id) {
		JS.loadArtist(id)
	}

	Utils {
		id: utils
	}

	Spotify {
		id: spotify
		onPlaybackChanged: JS.playbackChanged()
	}

	Settings {
		id: settings
	}

	function icSrc(name) {
		return "qrc:/res/ic/dark/%1.svg".arg(name)
	}

	MainToolbar {
		id: toolBar
	}

	footer: Footer {
		id: footer
	}

	LogOutDialog {
		id: dialogLogOut
	}

	LoggedOutDialog {
		id: dialogLoggedOut
	}

	MainDrawer {
		id: drawer
	}

	SettingsDialog {
		id: settingsDrawer
	}

	ArtistDialog {
		id: artistDrawer
	}

	Component {
		id: listDelegate
		TrackListItem {
			id: listRow
			itemModel: model
		}
	}

	ListView {
		id: trackList
		anchors.fill: parent
		anchors.leftMargin: !inPortrait ? drawer.width : 0
		anchors.topMargin: toolBar.height
		model: ListModel {
			id: trackListModel
		}
		delegate: listDelegate
	}
}
