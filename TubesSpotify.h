#ifndef TUBESPOTIFY_H
#define TUBESPOTIFY_H

#include <iostream>
#include <string>
using namespace std;

typedef struct elmsong *addressSong;
typedef struct elmplaylistnode *addressPlaylistNode;
typedef struct elmplaylist *addressPlaylist;
typedef struct elmuser *addressUser;
typedef struct elmrole *addressRole;

struct elmrole {
    string name;
    addressRole next;
};
typedef struct Roles{
    addressRole first;
};

struct elmsong {
    string id;
    string title;
    string singer;
    int duration;
    addressSong next;
    addressSong prev;
};
typedef struct Songs{
    addressSong head;
    addressSong tail;
};

struct elmplaylistnode {
    addressPlaylist parent;
    addressSong child;
    addressPlaylistNode next;
    addressPlaylistNode prev;
};

struct elmplaylist {
    string name;
    addressPlaylist next;
    addressPlaylistNode firstRel;
};
typedef struct Playlists{
    addressPlaylist first;
};

struct elmuser {
    string username;
    string password;
    addressRole role;
    addressPlaylist firstPlaylist;
    addressUser next;
};
typedef struct Users{
    addressUser first;
};

void initRoleList(Roles &R);
addressRole createRole(Roles &R, string name);
void insertRole(Roles &R, addressRole newRole);
addressRole findRole(Roles R, string name);

addressUser createUser(Roles R);
void insertUserLast(Users &U, addressUser newUser);
addressUser loginUser(Users U);

void initSongList(Songs &L);
addressSong createSong(string id, string title, string singer, int duration);
void insertSongLast(Songs &L, addressSong newSong);
addressSong findSongByID(Songs L, string id);
void deleteSongByID(Songs &L, string id);
void showAllSongs(Songs L);

addressPlaylist createPlaylist(string name);
void insertPlaylistLast(Playlists &P, addressPlaylist newPlaylist);
addressPlaylist findPlaylist(Playlists P, string name);
void showPlaylists(Playlists P);

void addSongToPlaylist(addressPlaylist P, addressSong S);
void showPlaylistSongs(addressPlaylist P);
void removeSongFromPlaylist(addressPlaylist P, string songID);

void userCreatePlaylist(addressUser U);
void userAddSongToPlaylist(addressUser U, Songs L);
void userRemoveSongFromPlaylist(addressUser U);
void userShowAllPlaylists(addressUser U);
void userDeletePlaylist(addressUser U);

#endif
