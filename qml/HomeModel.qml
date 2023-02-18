import QtQuick

ListModel {
	ListElement {
		text: "Library"
		title: true
		expand: true
	}

	ListElement {
		text: "History"
		icon: "history"
	}

	ListElement {
		text: "Liked tracks"
		icon: "audiotrack"
	}

	ListElement {
		text: "Top tracks"
		icon: "trending_up"
	}

	ListElement {
		text: "New releases"
		icon: "new_releases"
	}

	ListElement {
		text: "Liked albums"
		icon: "album"
		navigate: true
	}

	ListElement {
		text: "Top artists"
		icon: "timeline"
		navigate: true
	}

	ListElement {
		text: "Followed artists"
		icon: "people"
		navigate: true
	}

	ListElement {
		text: "Playlists"
		title: true
		expand: true
	}
}