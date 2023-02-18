import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

ToolBar {
	RowLayout {
		anchors.fill: parent

		ToolButton {
			id: backButton
			visible: false
			icon.source: icSrc("arrow_back")
		}

		Label {
			text: "Home"
			font.pointSize: 18
			font.weight: Font.DemiBold
			Layout.fillWidth: true
			Layout.leftMargin: 14
		}

		ToolButton {
			id: searchButton
			icon.source: icSrc("search")
		}

		ToolButton {
			id: settingsButton
			icon.source: icSrc("settings")
		}
	}
}