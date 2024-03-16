# URI can't contain dashes
string(REPLACE "-" "_" URI "${PROJECT_NAME}")

qt_add_qml_module(${PROJECT_NAME}
	URI "${URI}"
	VERSION ${PROJECT_VERSION}
	NO_RESOURCE_TARGET_PATH
	QML_FILES
	qml/Home.qml
	qml/Library.qml
	qml/MainFooter.qml
	qml/MainHeader.qml
	qml/MainNavigationBar.qml
	qml/MainPage.qml
	qml/NowPlaying.qml
	qml/Search.qml
	qml/SetupPage.qml
	RESOURCES
	res/ic/album.svg
	res/ic/arrow_back.svg
	res/ic/audiotrack.svg
	res/ic/chevron_right.svg
	res/ic/expand_more.svg
	res/ic/favorite.svg
	res/ic/history.svg
	res/ic/home.svg
	res/ic/library_music.svg
	res/ic/new_releases.svg
	res/ic/pause.svg
	res/ic/people.svg
	res/ic/play_arrow.svg
	res/ic/search.svg
	res/ic/settings.svg
	res/ic/skip_next.svg
	res/ic/timeline.svg
	res/ic/trending_up.svg)