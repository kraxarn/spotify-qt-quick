import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

Button {
	height: listItemHeight
	width: trackList.width
	flat: true

	property var itemModel

	onClicked: root.playTrack(itemModel.index)
	readonly property var foregroundColor: currentTrackId === itemModel.id
		? Material.accent : undefined

	Label {
		anchors {
			verticalCenter: parent.verticalCenter
			left: parent.left
			leftMargin: 16
		}
		text: itemModel.track
		Material.foreground: foregroundColor
	}
	Label {
		anchors.verticalCenter: parent.verticalCenter
		x: parent.width / 2
		text: itemModel.artist
		Material.foreground: foregroundColor
	}
	ToolButton {
		anchors {
			verticalCenter: parent.verticalCenter
			right: parent.right
			rightMargin: 16
		}
		icon.name: "overflow-menu"
		icon.source: icSrc("overflow-menu")
		flat: true
		onClicked: trackMenu.open()
		TrackMenu {
			id: trackMenu
			trackId: itemModel.id
			artistId: itemModel.artistId
			albumId: itemModel.albumId
		}
	}
}