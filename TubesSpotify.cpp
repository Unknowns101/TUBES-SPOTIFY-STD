#include "TubesSpotify.h"
//apayak
void initRoleList(Roles &R) {
    R.first = nullptr;
}

void insertRole(Roles &R, addressRole newRole) {
    addressRole p;

    if (R.first == nullptr) {
        R.first = newRole;
    } else {
        p = R.first;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newRole;
    }
}

addressRole createRole(Roles &R, string name) {
    addressRole newRole;

    newRole = new elmrole;
    newRole->name = name;
    newRole->next = nullptr;

    insertRole(R, newRole);
    return newRole;
}

addressRole findRole(Roles R, string name) {
    addressRole p;

    p = R.first;
    while (p != nullptr) {
        if (p->name == name) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

addressUser createUser(Roles R) {
    addressUser U;
    string r;

    U = new elmuser;

    cout << "Masukkan username: ";
    cin >> U->username;

    cout << "Masukkan password: ";
    cin >> U->password;

    cout << "Pilih role (admin/user): ";
    cin >> r;

    U->role = findRole(R, r);
    U->firstPlaylist = nullptr;
    U->next = nullptr;

    return U;
}

void insertUserLast(Users &U, addressUser newUser) {
    addressUser p;

    if (U.first == nullptr) {
        U.first = newUser;
    } else {
        p = U.first;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newUser;
    }
}

addressUser loginUser(Users U) {
    string uname;
    string pass;
    addressUser p;

    cout << "Username: ";
    cin >> uname;

    cout << "Password: ";
    cin >> pass;

    p = U.first;
    while (p != nullptr) {
        if (p->username == uname && p->password == pass) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void initSongList(Songs &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

addressSong createSong(string id, string title, string singer, int duration) {
    addressSong S;

    S = new elmsong;
    S->id = id;
    S->title = title;
    S->singer = singer;
    S->duration = duration;
    S->next = nullptr;
    S->prev = nullptr;

    return S;
}

void insertSongLast(Songs &L, addressSong newSong) {
    if (L.head == nullptr) {
        L.head = newSong;
        L.tail = newSong;
    } else {
        L.tail->next = newSong;
        newSong->prev = L.tail;
        L.tail = newSong;
    }
}

addressSong findSongByID(Songs L, string id) {
    addressSong p;

    p = L.head;
    while (p != nullptr) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteSongByID(Songs &L, string id) {
    addressSong p;

    p = findSongByID(L, id);
    if (p == nullptr) {
        return;
    }

    if (p == L.head) {
        L.head = p->next;
        if (L.head != nullptr) {
            L.head->prev = nullptr;
        }
    } else {
        p->prev->next = p->next;
    }

    if (p == L.tail) {
        L.tail = p->prev;
    } else if (p->next != nullptr) {
        p->next->prev = p->prev;
    }

    delete p;
}

void showAllSongs(Songs L) {
    addressSong p;

    cout << endl << "--- Daftar Lagu di Library ---" << endl;

    p = L.head;
    while (p != nullptr) {
        cout << p->id << " | "
             << p->title << " | "
             << p->singer << " | "
             << p->duration << " detik"
             << endl;
        p = p->next;
    }
}
