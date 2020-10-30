const load = () => {
	listModel.clear()

	const items = [
		{id: "recently_played", name: "Recently Played", expandable: false},
		{id: "saved_tracks", name: "Liked", expandable: false},
		{id: "top_tracks", name: "Tracks", expandable: false},
		{id: "saved_albums", name: "Albums", expandable: true},
		{id: "top_artists", name: "Artists", expandable: true},
		{id: "followed_artists", name: "Following", expandable: true}
	]

	items.forEach(item => listModel.append({
		id: item.id,
		name: item.name,
		expandable: item.expandable
	}))
}

const itemClicked = item => {
	const expanded = item.itemModel.expandable && item.expandButton.icon.name === "expand"

	if (item.itemModel.expandable) {
		item.expandButton.icon.name = expanded ? "collapse" : "expand"
		item.subList.visible = expanded
	}

	// Items for loading tracks
	let items = []
	switch (item.itemModel.id) {
		case "recently_played":
			items = spotify.recentlyPlayed
			break

		case "saved_tracks":
			items = spotify.savedTracks
			break

		case "top_tracks":
			items = spotify.topTracks
			break

		case "saved_albums":
			items = spotify.savedAlbums
			break

		case "top_artists":
			items = spotify.topArtists
			break

		case "followed_artists":
			items = spotify.followedArtists
			break
	}

	if (items.length > 0) {
		if (item.itemModel.expandable) {
			loadSubListItems(item, items)
		} else {
			root.loadTracks(items, null)
		}
	}
}

const loadSubListItems = (parent, items) => {
	parent.subListModel.clear()
	items.forEach(item => parent.subListModel.append({
		id: item.id,
		text: item.name,
		parentId: parent.itemModel.id
	}))
}

const subListItemClicked = (parentId, id) => {
	if (parentId.includes("album")) {
		root.loadTracks(spotify.getAlbumTracks(id), `spotify:album:${id}`)
	} else if (parentId.includes("artist")) {
		root.loadArtist(id)
	}
}