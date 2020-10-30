const load = () => {
	listModel.clear()

	const items = [
		{id: "recently_played", name: "Recently Played", expandable: false},
		{id: "saved_tracks", name: "Liked", expandable: false},
		{id: "top_tracks", name: "Tracks", expandable: false},
		{id: "albums", name: "Albums", expandable: true},
		{id: "artists", name: "Artists", expandable: true},
		{id: "following", name: "Following", expandable: true}
	]

	items.forEach(item => listModel.append({
		id: item.id,
		name: item.name,
		expandable: item.expandable
	}))
}

const itemClicked = item => {
	if (item.itemModel.expandable) {
		item.expandButton.icon.name = item.expandButton.icon.name === "expand"
			? "collapse"
			: "expand"

		item.subList.visible = !item.subList.visible
	}

	switch (item.itemModel.id) {
		case "recently_played":
			root.loadTracks(spotify.recentlyPlayed, null)
			break

		case "saved_tracks":
			root.loadTracks(spotify.savedTracks, null)
			break

		case "top_tracks":
			root.loadTracks(spotify.topTracks, null)
			break
	}
}