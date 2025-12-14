#include <iostream>
#include"TubesSpotify.h"
using namespace std;

void createRoles(Roles &R) {
    R.first = nullptr;
}

void createUsers(Users &U) {
    U.first = nullptr;
}

void createPlaylists(Playlists &P) {
    P.first = nullptr;
}

void createSongs(Songs &S) {
    S.first = nullptr;
    S.last = nullptr;
}

addressRole allocateRole(string name) {
    addressRole r = new elmrole;
    r->name = name;
    r->next = nullptr;
    r->firstRelat = nullptr;
    return r;
}

addressUser allocateUser(string username, string password) {
    addressUser u = new elmuser;
    u->username = username;
    u->password = password;
    u->next = nullptr;
    u->firstRelat = nullptr;
    return u;
}

addressPlaylist allocatePlaylist(string name) {
    addressPlaylist p = new elmplaylist;
    p->name = name;
    p->next = nullptr;
    p->firstRelat = nullptr;
    return p;
}

addressSong allocateSong(string title, string singer, string genre, int duration) {
    addressSong s = new elmsong;
    s->title = title;
    s->singer = singer;
    s->genre = genre;
    s->duration = duration;
    s->next = nullptr;
    s->prev = nullptr;
    return s;
}

void insertRole(Roles &R, addressRole r) {
    r->next = R.first;
    R.first = r;
}

void insertUser(Users &U, addressUser u) {
    u->next = U.first;
    U.first = u;
}

void insertPlaylist(Playlists &P, addressPlaylist p) {
    p->next = P.first;
    P.first = p;
}

void insertSong(Songs &S, addressSong s) {
    if (S.first == nullptr) {
        S.first = s;
        S.last  = s;
    } else {
        S.last->next = s;
        s->prev = S.last;
        S.last = s;
    }
}

void connectRoleUser(addressRole r, addressUser u) {
    addressRelRoleUser rel = new elmRelRoleUser;
    rel->user = u;
    rel->next = r->firstRelat;
    r->firstRelat = rel;
}

void connectUserPlaylist(addressUser u, addressPlaylist p) {
    addressRelUserPlaylist rel = new elmRelUserPlaylist;
    rel->playlist = p;
    rel->next = u->firstRelat;
    u->firstRelat = rel;
}

void addSongToPlaylist(addressPlaylist p, addressSong s) {
    addressRelPlaylistSong rel = new elmRelPlaylistSong;
    addressRelPlaylistSong last;
    rel->song = s;
    rel->next = nullptr;
    rel->prev = nullptr;

    if (p->firstRelat == nullptr) {
        p->firstRelat = rel;
    } else {
        last = p->firstRelat;
        while (last->next != nullptr)
            last = last->next;
        last->next = rel;
        rel->prev = last;
    }
}

void DeleteSongDariPlaylist(addressPlaylist p, addressSong s) {
    addressRelPlaylistSong r;

    r = p->firstRelat;

    while (r != nullptr && r->song != s) {
        r = r->next;
    }

    if (r == nullptr) {
        return;
    }

    if (r->prev == nullptr && r->next == nullptr) {
        p->firstRelat = nullptr;
    } else if (r->prev == nullptr) {
        p->firstRelat = r->next;
        p->firstRelat->prev = nullptr;
        r->next = nullptr;
    } else {
        r->prev->next = r->next;
        if (r->next != nullptr) {
            r->next->prev = r->prev;
        }
        r->prev = nullptr;
        r->next = nullptr;
    }
}


void DeleteSongFromLibrary(Songs &S, Playlists P, addressSong s) {
    addressPlaylist p;

    p = P.first;
    while (p != nullptr) {
        DeleteSongDariPlaylist(p, s);
        p = p->next;
    }

    if (S.first == nullptr) {
        s = nullptr;
    } else if (S.first == S.last) {
        s = S.first;
        S.first = nullptr;
        S.last  = nullptr;
    } else if (s == S.first) {
        s = S.first;
        S.first = S.first->next;
        S.first->prev = nullptr;
        s->next = nullptr;
    } else if (s == S.last) {
        s = S.last;
        S.last = S.last->prev;
        S.last->next = nullptr;
        s->prev = nullptr;
    } else {
        s->prev->next = s->next;
        s->next->prev = s->prev;
        s->next = nullptr;
        s->prev = nullptr;
    }
}

void EditSong(addressSong s, string title, string singer, string genre, int duration) {
    s->title = title;
    s->singer = singer;
    s->genre = genre;
    s->duration = duration;
}

void EditPlaylist(addressPlaylist p, string newName) {
    p->name = newName;
}

void HapusPlaylist(addressUser u, addressPlaylist p) {
    addressRelUserPlaylist prevRel;
    addressRelUserPlaylist rel;
    addressRelPlaylistSong r;

    r = p->firstRelat;
    while (r != nullptr) {
        DeleteSongDariPlaylist(p, r->song);
        r = p->firstRelat;
    }

    prevRel = nullptr;
    rel     = u->firstRelat;

    while (rel != nullptr && rel->playlist != p) {
        prevRel = rel;
        rel     = rel->next;
    }

    if (rel == nullptr) {
        p = nullptr;
        return;
    }

    if (prevRel == nullptr) {
        u->firstRelat = rel->next;
    } else {
        prevRel->next = rel->next;
    }
    rel->next = nullptr;
}

void reversePlaylist(addressPlaylist p) {
    addressRelPlaylistSong curr = p->firstRelat;
    addressRelPlaylistSong temp = nullptr;

    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != nullptr) {
         p->firstRelat = temp->prev;
    }
}

void playPlaylist(addressPlaylist p) {
    addressRelPlaylistSong curr = p->firstRelat;

    if (curr == nullptr) {
        cout << "Playlist Kosong" << endl;
        return;
    }

    while (curr != nullptr) {
        cout << "========================" << endl;
        cout << "Now Playing : " << curr->song->title << " - " << curr->song->singer << endl;

        if (curr->prev != nullptr) {
            cout << "Prev        : " << curr->prev->song->title << endl;
        } else {
            cout << "Prev        : -" << endl;
        }
        if (curr->next != nullptr) {
            cout << "Next        : " << curr->next->song->title << endl;
        } else {
            cout << "Next        : -" << endl;
        }
        cout << "========================" << endl;
        curr = curr->next;
    }
}

void showAllSongs(Songs S) {
    addressSong s = S.first;
    int i = 1;

    if (s == nullptr) {
        cout << "Library Kosong" << endl;
        return;
    }

    while (s != nullptr) {
        cout << i << ". " << s->title << " - " << s->singer << " | " << s->genre << " | " << s->duration << " menit" << endl;
        i++;
        s = s->next;
    }
}

void showPlaylistsOfUser(addressUser u) {
    addressRelUserPlaylist r = u->firstRelat;

    if (r == nullptr) {
        cout << "Belum ada playlist" << endl;
        return;
    }

    while (r != nullptr) {
        cout << "- " << r->playlist->name << endl;
        r = r->next;
    }
}

addressSong pilihSong(Songs S) {
    showAllSongs(S);
    int pilih, i;
    addressSong s;
    cout << "Pilih nomor lagu: ";
    cin >> pilih;

    s = S.first;
    i = 1;

    while (s != nullptr && i < pilih) {
        s = s->next;
        i++;
    }

    return s;
}

addressPlaylist pilihPlaylist(addressUser u) {
    addressRelUserPlaylist r = u->firstRelat;
    int i = 1;
    int pilih;
    if (r == nullptr) {
        cout << "Belum ada playlist" << endl;
        return nullptr;
    }

    while (r != nullptr) {
        cout << i << ". " << r->playlist->name << endl;
        r = r->next;
        i++;
    }

    cout << "Pilih playlist: ";
    cin >> pilih;

    r = u->firstRelat;
    i = 1;
    while (r != nullptr && i < pilih) {
        r = r->next;
        i++;
    }

    if (r != nullptr) {
        return r->playlist;
    }
    return nullptr;
}

void sortPlaylistByDuration(addressPlaylist p) {
    bool swapped = true;
    addressRelPlaylistSong a, b;
    addressSong temp;
    if (p->firstRelat == nullptr) {
        return;
    }

    while (swapped) {
        swapped = false;
        a = p->firstRelat;

        while (a->next != nullptr) {
            b = a->next;
            if (a->song->duration > b->song->duration) {
                temp = a->song;
                a->song = b->song;
                b->song = temp;
                swapped = true;
            }
            a = a->next;
        }
    }
}

void playLibrary(Songs S) {
    addressSong s = S.first;

    if (s == nullptr) {
        cout << "Library Kosong" << endl;
        return;
    }

    while (s != nullptr) {
        cout << "========================" << endl;
        cout << "Now Playing : " << s->title << " - " << s->singer << endl;

        if (s->prev != nullptr) {
            cout << "Prev        : " << s->prev->title << endl;
        } else {
            cout << "Prev        : -" << endl;
        }
        if (s->next != nullptr) {
            cout << "Next        : " << s->next->title << endl;
        } else {
            cout << "Next        : -" << endl;
        }
        cout << "========================" << endl;
        s = s->next;
    }
}

void menuAwal(Roles &R, Users &U, Playlists &P, Songs &S) {
    int pilih;
    bool exitProgram = false;
    addressRole role;
    addressUser u;
    while (!exitProgram) {
        cout << endl;
        cout << "=========== WELCOME ===========" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            menuRegister(R, U);
        } else if (pilih == 2) {
            
            u = menuLogin(R, U, role);
            if (u != nullptr) {
                if (role->name == "admin") {
                    menuAdmin(S, P);
                } else {
                    menuUser(u, S, P);
                }
            }
        } else if (pilih == 3) {
            exitProgram = true;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

void menuRegister(Roles &R, Users &U) {
    string username, password, roleName;
    addressUser u;
    addressRole r;

    cout << "=========== REGISTER ===========" << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;
    cout << "Role (admin/user): ";
    cin >> roleName;

    u = allocateUser(username, password);
    insertUser(U, u);

    r = R.first;
    while (r != nullptr && r->name != roleName) {
        r = r->next;
    }
    if (r != nullptr) {
        connectRoleUser(r, u);
    }
    cout << "Register berhasil" << endl;
}

addressUser menuLogin(Roles R, Users U, addressRole &roleOut) {
    string username, password;
    addressUser u;
    addressRole r;
    addressRelRoleUser rel;

    cout << "=========== LOGIN ===========" << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    u = U.first;
    while (u != nullptr) {
        if (u->username == username && u->password == password) {
            r = R.first;
            while (r != nullptr) {
                rel = r->firstRelat;
                while (rel != nullptr) {
                    if (rel->user == u) {
                        roleOut = r;
                        return u;
                    }
                    rel = rel->next;
                }
                r = r->next;
            }
        }
        u = u->next;
    }

    cout << "Login gagal" << endl;
    return nullptr;
}

void menuAdmin(Songs &S, Playlists &P) {
    int pilih;
    bool logout = false;
    
    addressSong s;
    while (!logout) {
        cout << endl;
        cout << "=========== MENU ADMIN ===========" << endl;
        cout << "1. Tambah Lagu" << endl;
        cout << "2. Edit Lagu" << endl;
        cout << "3. Hapus Lagu" << endl;
        cout << "4. Lihat Library" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
        string title, singer, genre;
        int duration;
            cout << "Judul   : "; cin >> title;
            cout << "Singer  : "; cin >> singer;
            cout << "Genre   : "; cin >> genre;
            cout << "Durasi  : "; cin >> duration;

            insertSong(S, allocateSong(title, singer, genre, duration));
            cout << "Lagu berhasil ditambahkan" << endl;
        } else if (pilih == 2) {
            s = pilihSong(S);
            if (s != nullptr) {
                string title, singer, genre;
                int duration;

                cout << "Judul baru  : "; 
                cin >> title;
                cout << "Singer baru : "; 
                cin >> singer;
                cout << "Genre baru  : "; 
                cin >> genre;
                cout << "Durasi baru : "; 
                cin >> duration;

                EditSong(s, title, singer, genre, duration);
                cout << "Lagu berhasil diedit" << endl;
            }
        } else if (pilih == 3) {
            addressSong s = pilihSong(S);
            if (s != nullptr) {
                DeleteSongFromLibrary(S, P, s);
                cout << "Lagu berhasil dihapus" << endl;
            }
        } else if (pilih == 4) {
            showAllSongs(S);
        } else if (pilih == 0) {
            logout = true;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

void menuUser(addressUser u, Songs &S, Playlists &P) {
    int pilih;
    bool logout = false;

    while (!logout) {
        cout << "\n=========== MENU USER ===========" << endl;
        cout << "1. Create Playlist" << endl;
        cout << "2. Edit Playlist" << endl;
        cout << "3. Delete Playlist" << endl;
        cout << "4. Lihat Playlist" << endl;
        cout << "5. Lihat Library" << endl;
        cout << "6. Play Playlist" << endl;
        cout << "7. Play Library" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            menuCreatePlaylist(u, P);
        } else if (pilih == 2) {
             menuEditPlaylist(u, S);
        } else if (pilih == 3) {
            addressPlaylist p = pilihPlaylist(u);
            if (p != nullptr) {
                HapusPlaylist(u, p);
            }
        } else if (pilih == 4) {
            showPlaylistsOfUser(u);
        } else if (pilih == 5) {
            showAllSongs(S);
        } else if (pilih == 6) {
            addressPlaylist p = pilihPlaylist(u);
            if (p != nullptr) {
                playPlaylist(p);
            }
        } else if (pilih == 7) {
            playLibrary(S);
        } else if (pilih == 0) {
            logout = true;
        }
    }
}

void menuCreatePlaylist(addressUser u, Playlists &P) {
    string name;
    addressPlaylist p;

    cout << "Nama Playlist: ";
    cin >> name;

    p = allocatePlaylist(name);
    insertPlaylist(P, p);
    connectUserPlaylist(u, p);
}

void menuEditPlaylist(addressUser u, Songs &S) {
    int pilih;
    addressPlaylist p = pilihPlaylist(u);

    if (p == nullptr) {
        return;
    }

    cout << "1. Edit Nama" << endl;
    cout << "2. Sort Duration" << endl;
    cout << "3. Reverse Lagu" << endl;
    cout << "4. Tambah Lagu" << endl;
    cout << "5. Hapus Lagu" << endl;
    cout << "Pilih: ";
    cin >> pilih;

    if (pilih == 1) {
        string name;
        cout << "Nama baru: ";
        cin >> name;
        EditPlaylist(p, name);
    } else if (pilih == 2) {
        sortPlaylistByDuration(p);
    } else if (pilih == 3) {
        reversePlaylist(p);
    } else if (pilih == 4) {
        menuAddSongToPlaylist(p, S);
    } else if (pilih == 5) {
        addressSong s = pilihSong(S);
        if (s != nullptr) {
            DeleteSongDariPlaylist(p, s);
        }
    }
}

void menuAddSongToPlaylist(addressPlaylist p, Songs S) {
    addressSong s = pilihSong(S);
    if (s != nullptr) {
        addSongToPlaylist(p, s);
    }
}

void menuPlayPlaylist(addressPlaylist p) {
    playPlaylist(p);
}
