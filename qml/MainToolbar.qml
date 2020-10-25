import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ToolBar {
	z: inPortrait ? 0 : 1
	parent: root.overlay
	width: root.width

	readonly property var currentArtist: currentArtist
	readonly property var currentTrack: currentTrack
	readonly property var currentAlbum: currentAlbum

	RowLayout {
		anchors.fill: parent
		ToolButton {
			icon.name: "application-menu"
			icon.source: icSrc("application-menu")
			visible: inPortrait
			onClicked: function () {
				drawer.visible = !drawer.visible
			}
		}
		Image {
			id: currentAlbum
			Layout.leftMargin: inPortrait ? 0 : 12
			Layout.maximumHeight: currentPlaying.height - 6
			fillMode: Image.PreserveAspectFit
			source: icSrc("media-optical-audio")
		}
		Column {
			id: currentPlaying
			Layout.fillWidth: true
			spacing: -4
			Label {
				id: currentArtist
				text: ""
				font.pixelSize: 14
			}
			Label {
				id: currentTrack
				text: "No media playing"
				font.pixelSize: 20
			}
		}
	}
}