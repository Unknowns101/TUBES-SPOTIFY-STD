#include <iostream>
#include"TubesSpotify.h"
using namespace std;

int main() {
    Roles R;
    Users U;
    Playlists P;
    Songs S;
    string admin;
    string user;
    addressRole adminRole;
    addressRole userRole;

    createRoles(R);
    createUsers(U);
    createPlaylists(P);
    createSongs(S);

    cout<<"admin";
    cin>>admin;
    cout<<endl;
    cout<<"user";
    cin>>user;
    cout<<endl;
    adminRole = allocateRole(admin);
    userRole  = allocateRole(user);

    insertRole(R, adminRole);
    insertRole(R, userRole);

    menuAwal(R, U, P, S);

    return 0;
}
