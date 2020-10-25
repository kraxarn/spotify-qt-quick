import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Menu {
	property var trackId
	property var artistId
	property var albumId

	enabled: !!trackId

	MenuItem {
		text: "Like"
		icon.name: "starred-symbolic"
	}
	MenuItem {
		text: "Add to queue"
		icon.name: "media-playlist-append"
	}

	MenuSeparator { }
	MenuItem {
		text: "Add to playlist"
		icon.name: "list-add"
	}
	MenuItem {
		text: "Remove from playlist"
		icon.name: "list-remove"
	}

	MenuSeparator { }
	MenuItem {
		text: "View artist"
		icon.name: "view-media-artist"
		enabled: !!artistId
	}
	MenuItem {
		text: "Open album"
		icon.name: "view-media-album-cover"
		enabled: !!albumId
	}
}