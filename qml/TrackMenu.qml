import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "/js/TrackMenu.js" as JS

Menu {
	property string trackId
	property string artistId
	property string albumId
	property string playlistId

	enabled: !!trackId

	onOpened: {
		JS.getIsLiked()
	}

	function addToPlaylist(playlistId) {
		JS.addToPlaylist(playlistId)
	}

	MenuItem {
		id: like
		text: "Like"
		icon.name: "starred-symbolic"
		enabled: false
		onClicked: JS.setIsLiked()
	}
	MenuItem {
		text: "Add to queue"
		icon.name: "media-playlist-append"
		onClicked: JS.addToQueue()
	}

	MenuSeparator { }
	MenuItem {
		text: "Add to playlist"
		icon.name: "list-add"
		onClicked: JS.getPlaylists()
		Menu {
			id: playlistMenu
		}
	}
	MenuItem {
		text: "Remove from playlist"
		icon.name: "list-remove"
		enabled: !!playlistId
		onClicked: JS.removeFromPlaylist()
	}

	MenuSeparator { }
	MenuItem {
		text: "View artist"
		icon.name: "view-media-artist"
		enabled: !!artistId
		onClicked: JS.viewArtist()
	}
	MenuItem {
		text: "Open album"
		icon.name: "view-media-album-cover"
		enabled: albumId.length > 1
		onClicked: JS.openAlbum()
	}
}