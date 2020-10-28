import QtQuick 2.12
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12

import "/js/Footer.js" as JS

Pane {
	readonly property var progress: progress
	readonly property var position: position
	readonly property var duration: duration

	readonly property var playPause: playPause
	readonly property var shuffle: shuffle
	readonly property var repeat: repeat

	Material.background: Material.primary
	Material.elevation: 12
	anchors {
		left: parent.left
		right: parent.right
	}

	ColumnLayout {
		anchors {
			fill: parent
			leftMargin: !inPortrait ? drawer.width : 12
			rightMargin: !inPortrait ? 0 : 12
		}

		RowLayout {
			Label {
				id: position
				text: "0:00"
			}
			Slider {
				id: progress
				Layout.fillWidth: true
				from: 0
				value: 0
			}
			Label {
				id: duration
				text: "0:00"
			}
		}
		RowLayout {
			Item {
				Layout.fillWidth: true
			}
			ToolButton {
				id: shuffle
				icon.name: "media-playlist-shuffle"
				icon.source: icSrc("media-playlist-shuffle")
				checkable: true
				onClicked: JS.toggleShuffle()
			}
			ToolSeparator {
			}
			ToolButton {
				icon.name: "media-skip-backward"
				icon.source: icSrc("media-skip-backward")
			}
			ToolButton {
				id: playPause
				icon.name: "media-playback-start"
				icon.source: icSrc("media-playback-start")
				onClicked: JS.togglePlayPause()
			}
			ToolButton {
				icon.name: "media-skip-forward"
				icon.source: icSrc("media-skip-forward")
			}
			ToolSeparator {
			}
			ToolButton {
				id: repeat
				icon.name: "media-playlist-repeat"
				icon.source: icSrc("media-playlist-repeat")
				checkable: true
				onClicked: JS.toggleRepeat()
			}
			Item {
				Layout.fillWidth: true
			}
		}
	}
}