const load = () => {
	listModel.clear()

	const items = [
		{id: "recently_played", name: "Recently Played", expandable: false},
		{id: "liked", name: "Liked", expandable: false},
		{id: "tracks", name: "Tracks", expandable: false},
		{id: "new_releases", name: "New Releases", expandable: false},
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

	console.log("clicked:", item)
}