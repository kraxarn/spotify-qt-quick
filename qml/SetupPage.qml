import Page.Setup

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
	Material.theme: Material.System

	Setup {
		id: setup
	}

	// OpenLinkDialog {
	// 	id: openLinkDialog
	// 	width: root.width * 0.9
	// }

	Dialog {
		id: authErrorDialog
		title: "Error"
		standardButtons: Dialog.Ok
		modal: true
		anchors.centerIn: parent
		Label {
			id: authErrorMsg
		}
	}

	ColumnLayout {
		anchors {
			left: parent.left
			right: parent.right
			top: parent.top
			leftMargin: 32
			rightMargin: 32
			topMargin: 96
		}

		Label {
			text: "Welcome to spotify-qt-quick!"
			font.pointSize: 24
			font.weight: 700
		}

		WelcomeLabel {
			Layout.fillWidth: true
			Layout.topMargin: 32
			Layout.bottomMargin: 32
		}

		Label {
			text: "Client ID"
			Layout.leftMargin: 4
		}

		TextField {
			id: clientId
			Layout.fillWidth: true
			text: setup.clientId
		}

		Label {
			text: "Client Secret"
			Layout.topMargin: 16
			Layout.leftMargin: 4
		}

		TextField {
			id: clientSecret
			Layout.fillWidth: true
			text: setup.clientSecret
		}

		Button {
			text: setup.redirectUriText
			Layout.fillWidth: true
			Layout.topMargin: 32
			onClicked: setup.copyRedirectUri()
		}

		Button {
			text: "Authenticate"
			enabled: setup.authButtonEnabled
			Layout.fillWidth: true
			onClicked: setup.authenticate()
		}

		Button {
			text: "Spotify Dashboard"
			flat: true
			Layout.fillWidth: true
			onClicked: setup.openDashboard()
		}
	}
}