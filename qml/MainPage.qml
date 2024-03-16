import Page.Main

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

ApplicationWindow {
	id: root
	title: "spotify-qt-quick"
	visible: true
	width: 540
	height: 960

	Material.theme: Material.Dark
	Material.primary: "#282828"
	Material.background: "#121212"
	Material.accent: "#1db954"

	function icSrc(name) {
		return `qrc:/res/ic/${name}.svg`
	}

	footer: MainFooter {
	}

	StackView {
		id: content
		anchors.fill: parent
		initialItem: homePage
	}

	Component {
		id: homePage
		Home {
		}
	}

	Component {
		id: searchPage
		Search {
		}
	}

	Component {
		id: libraryPage
		Library {
		}
	}
}