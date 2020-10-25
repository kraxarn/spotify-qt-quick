import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

Drawer {
	Material.background: Material.primary
	width: inPortrait ? root.width * 0.8 : 400
	height: root.height - (inPortrait ? 0 : toolBar.height)
	y: inPortrait ? 0 : toolBar.height

	readonly property var drawerTabs: drawerTabs

	modal: inPortrait
	interactive: inPortrait
	position: inPortrait ? 0 : 1
	visible: !inPortrait

	ColumnLayout {
		anchors.fill: parent
		StackLayout {
			currentIndex: drawerTabs.currentIndex
			SearchView {}
			LibraryView {}
			PlaylistsView {}
		}
		TabBar {
			id: drawerTabs
			Layout.fillWidth: true
			Layout.leftMargin: 8
			Layout.rightMargin: 8
			currentIndex: 2
			TabButton {
				icon.name: "search"
				text: "Search"
			}
			TabButton {
				icon.name: "bookmarks-toolbar"
				text: "Library"
			}
			TabButton {
				icon.name: "view-media-playlist"
				text: "Playlists"
			}
		}
		RowLayout {
			Layout.margins: 8
			ToolButton {
				Layout.fillWidth: true
				icon.name: "help-about"
				text: `spotify-qt-quick ${LibVersion}`
				enabled: false
			}
			ToolButton {
				icon.name: "configure"
				onClicked: {
					drawer.close()
					settingsDrawer.open()
				}
			}
			ToolButton {
				icon.name: "im-user-away"
				onClicked: {
					drawer.close()
					dialogLogOut.open()
				}
			}
		}
	}
}