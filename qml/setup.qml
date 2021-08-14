import Page.Setup 1.0

import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

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

	OpenLinkDialog {
		id: openLinkDialog
		width: root.width * 0.9
	}

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
			margins: 16
		}
		Label {
			text: "Welcome to spotify-qt-quick!"
			font.pointSize: 16
		}
		WelcomeLabel {
			Layout.topMargin: 16
		}
		Label {
			text: "Client ID"
			Layout.topMargin: 16
		}
		TextField {
			id: clientId
			Layout.fillWidth: true
			text: setup.clientId
		}
		Label {
			text: "Client Secret"
			Layout.topMargin: 16
		}
		TextField {
			id: clientSecret
			Layout.fillWidth: true
			text: setup.clientSecret
		}
	}

	ColumnLayout {
		anchors {
			left: parent.left
			right: parent.right
			bottom: parent.bottom
			leftMargin: 24
			rightMargin: 24
			bottomMargin: 24
		}
		Button {
			text: "Cancel"
			Layout.fillWidth: true
			onClicked: setup.close()
		}
		Button {
			text: "Spotify Dashboard"
			Layout.fillWidth: true
			onClicked: setup.openDashboard()
		}
		Button {
			text: "Authenticate"
			Layout.fillWidth: true
			onClicked: setup.authenticate()
		}
	}
}