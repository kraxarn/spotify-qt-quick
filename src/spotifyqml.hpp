#pragma once

#include "common.hpp"

class SpotifyQml: public QObject
{
Q_OBJECT
	Q_PROPERTY(QJsonArray playlists READ getPlaylists NOTIFY playlistsChanged)
	Q_PROPERTY(QJsonObject playback READ getPlayback NOTIFY playbackChanged)
	Q_PROPERTY(bool playing READ getPlaying WRITE setPlaying NOTIFY playingChanged)
	QML_ELEMENT

public:
	explicit SpotifyQml(QObject *parent = nullptr);
	~SpotifyQml() override;

	QJsonArray getPlaylists();
	QJsonObject getPlayback();

	bool getPlaying();
	void setPlaying(bool playing);

	// Get tracks
	Q_INVOKABLE QJsonArray getPlaylistTracks(const QString &playlistId);
	Q_INVOKABLE QJsonArray getAlbumTracks(const QString &albumId);

	// Play tracks
	Q_INVOKABLE QString playTracksWithContext(int trackIndex, const QString &context);
	Q_INVOKABLE QString playTrack(const QString &track);

	// Playlists
	Q_INVOKABLE QString addToPlaylist(const QString &playlistId, const QString &trackId);
	Q_INVOKABLE QString removeFromPlaylist(const QString &playlistId, const QString &trackId);

	// Other
	Q_INVOKABLE void requestPlayback();
	Q_INVOKABLE QString systemInfo();
	Q_INVOKABLE QJsonObject search(const QString &query);
	Q_INVOKABLE QJsonObject getArtist(const QString &id);
	Q_INVOKABLE QJsonObject getArtistPages(const QString &id);
	Q_INVOKABLE bool isSavedTrack(const QString &trackId);
	Q_INVOKABLE QString setSavedTrack(const QString &trackId, bool saved);
	Q_INVOKABLE QString addToQueue(const QString &trackId);

signals:
	void playlistsChanged();
	void playbackChanged();
	void playingChanged();

private:
	spt::Spotify *spotify = nullptr;
	Settings settings;
	spt::Playback current;

	int refreshCount = -1;

	void refresh();
	void refreshed(const spt::Playback &playback);
	static QJsonArray tracksToJson(QVector<spt::Track> &tracks);
};


