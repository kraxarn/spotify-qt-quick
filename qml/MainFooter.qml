import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ToolBar {
	RowLayout {
		id: nowPlayingLayout
		spacing: 8

		anchors {
			fill: parent
			leftMargin: 12
			rightMargin: 12
		}

		Image {
			id: album
			Layout.leftMargin: 12
			Layout.rightMargin: Layout.leftMargin
			height: 72
			source: icSrc("album")
		}

		ColumnLayout {
			Label {
				id: trackName
				text: "No music playing"
				font.pixelSize: artistName.font.pixelSize * 1.2
			}

			Label {
				id: artistName
				visible: false
				text: "Artist"
			}
		}

		Item {
			Layout.fillWidth: true
		}

		ToolButton {
			id: playPause
			icon.height: parent.height * 0.4
			icon.width: parent.height * 0.4
			icon.source: icSrc("play_arrow")
		}

		ToolButton {
			id: nextTrack
			icon.height: playPause.icon.height
			icon.width: playPause.icon.width
			icon.source: icSrc("skip_next")
		}
	}
}