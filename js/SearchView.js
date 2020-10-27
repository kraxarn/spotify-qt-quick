let results

const search = query => {
	rowSearch.enabled = false
	results = spotify.search(query)
	updateItems()
	rowSearch.enabled = true
}

const getSelectedType = () => {
	let name = menuSearchSelectedType.icon.name
	return name === "view-media-track"
		? "tracks" : name === "view-media-artist"
			? "artists" : name === "view-media-album-cover"
				? "albums" : "playlists"
}

const updateItems = () => {
	let items = results[getSelectedType()]

	searchListModel.clear()
	items.forEach(item => {
		searchListModel.append({
			"id": item.id,
			"title": item.name,
			"subtitle": item.artist
		})
	})
}

const clickedItem = id => {
	switch (getSelectedType()) {
		case "tracks":
			spotify.playTrack(`spotify:track:${id}`)
			break

		case "albums":
			root.loadTracks(spotify.getAlbumTracks(id), `spotify:album:${id}`)
			break

		case "playlists":
			root.loadTracks(spotify.getPlaylistTracks(id), `spotify:playlist:${id}`)
			break

		case "artists":
			root.loadArtist(id)
			break
	}
}