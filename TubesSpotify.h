#ifndef TUBESPOTIFY_H
#define TUBESPOTIFY_H

#include <iostream>
#include <string>
using namespace std;

typedef struct elmrole* addressRole;
typedef struct elmuser* addressUser;
typedef struct elmplaylist* addressPlaylist;
typedef struct elmsong* addressSong;

typedef struct elmRelRoleUser* addressRelRoleUser;
typedef struct elmRelUserPlaylist* addressRelUserPlaylist;
typedef struct elmRelPlaylistSong* addressRelPlaylistSong;

struct elmrole {
    string name;
    addressRole next;
    addressRelRoleUser firstRelat;
};

struct Roles {
    addressRole first;
};

struct elmuser {
    string username;
    string password;
    addressUser next;
    addressRelUserPlaylist firstRelat;
};

struct Users {
    addressUser first;
};

struct elmplaylist {
    string name;
    addressPlaylist next;
    addressRelPlaylistSong firstRelat;
};

struct Playlists {
    addressPlaylist first;
};

struct elmsong {
    string title;
    string singer;
    string genre;
    int duration;
    addressSong next;
    addressSong prev;
};

struct Songs {
    addressSong first;
    addressSong last;
};

struct elmRelRoleUser {
    addressUser user;
    addressRelRoleUser next;
};

struct elmRelUserPlaylist {
    addressPlaylist playlist;
    addressRelUserPlaylist next;
};

struct elmRelPlaylistSong {
    addressSong song;
    addressRelPlaylistSong next;
    addressRelPlaylistSong prev;
};

void createRoles(Roles &R);
void createUsers(Users &U);
void createPlaylists(Playlists &P);
void createSongs(Songs &S);

addressRole allocateRole(string name);
addressUser allocateUser(string username, string password);
addressPlaylist allocatePlaylist(string name);
addressSong allocateSong(string title, string singer, string genre, int duration);

void insertRole(Roles &R, addressRole r);
void insertUser(Users &U, addressUser u);
void insertPlaylist(Playlists &P, addressPlaylist p);
void insertSong(Songs &S, addressSong s);

void connectRoleUser(addressRole r, addressUser u);
void connectUserPlaylist(addressUser u, addressPlaylist p);
void addSongToPlaylist(addressPlaylist p, addressSong s);

void EditSong(addressSong s, string title, string singer, string genre, int duration);
void DeleteSongFromPlaylist(addressPlaylist p, addressSong s);
void DeleteSongFromLibrary(Songs &S, Playlists P, addressSong s);

void DeletePlaylist(addressUser u, addressPlaylist p);
void EditPlaylist(addressPlaylist p, string newName);

void sortPlaylistByDuration(addressPlaylist p);
void reversePlaylist(addressPlaylist p);

void showAllSongs(Songs S);  
void showPlaylistsOfUser(addressUser u);  
void showSongsInPlaylist(addressPlaylist p);

void playPlaylist(addressPlaylist p);
void playLibrary(Songs S);

void menuAwal(Roles &R, Users &U, Playlists &P, Songs &S);

void menuRegister(Roles &R, Users &U);
addressUser menuLogin(Roles R, Users U, addressRole &roleOut);

void menuAdmin(Songs &S, Playlists &P);
void menuUser(addressUser u, Songs &S, Playlists &P);

void menuCreatePlaylist(addressUser u, Playlists &P);
void menuEditPlaylist(addressUser u, Songs &S);
void menuAddSongToPlaylist(addressPlaylist p, Songs S);
void menuPlayPlaylist(addressPlaylist p);

void tampilkanLibrarySingkat(Songs S);
addressPlaylist pilihPlaylist(addressUser u);
addressSong pilihSong(Songs S);

#endif
