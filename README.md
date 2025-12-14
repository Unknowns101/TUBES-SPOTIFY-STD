# TUBES-SPOTIFY-STD

---

Program **Tubes Spotify** adalah aplikasi berbasis **C++** yang mensimulasikan sistem manajemen musik sederhana seperti Spotify.  
Aplikasi ini dibuat untuk memenuhi **Tugas Besar Struktur Data**, dengan penerapan **Multi Linked List**, **Double Linked List**, **Singly Linked List**.


## Deskripsi Umum

Aplikasi ini menyediakan sistem login dengan dua role, yaitu **admin** dan **user**.  
Setiap role memiliki hak akses dan fitur yang berbeda. Data lagu, playlist, user, dan role dikelola menggunakan struktur data linked list dan relasi antar list (Multi Linked List).


## Fitur Program

### Autentikasi
- Register user dengan username, password, dan role (admin/user)
- Login berdasarkan data user yang tersimpan
- Sistem menu berjalan berulang sampai user memilih logout atau exit


## Fitur Admin

1. Tambah Lagu ke Library  
   Admin dapat menambahkan lagu baru ke library dengan data:
   - Judul lagu
   - Penyanyi
   - Genre
   - Durasi (dalam detik)

2. Edit Lagu  
   Admin dapat mengubah detail lagu yang ada di library.

3. Hapus Lagu  
   Lagu akan dihapus dari library dan otomatis dihapus dari seluruh playlist yang menggunakan lagu tersebut.

4. Lihat Library  
   Menampilkan seluruh lagu yang tersedia di library dengan format:
   No. Judul - Penyanyi | Genre | Durasi

## Fitur User

1. Create Playlist  
User dapat membuat playlist baru.

2. Edit Playlist  
User dapat:
- Mengubah nama playlist
- Menambahkan lagu ke playlist
- Menghapus lagu dari playlist
- Mengurutkan lagu berdasarkan durasi
- Membalik urutan lagu dalam playlist

3. Delete Playlist  
Menghapus playlist beserta seluruh relasi lagu di dalamnya.

4. Lihat Playlist  
Menampilkan semua playlist milik user.

5. Lihat Library  
Menampilkan seluruh lagu yang tersedia di library.

6. Play Playlist  
Menampilkan simulasi pemutaran lagu dari playlist, termasuk:
- Lagu yang sedang diputar
- Lagu sebelumnya (Prev)
- Lagu berikutnya (Next)

7. Play Library  
Memutar seluruh lagu di library secara berurutan dengan informasi Prev dan Next.

## Struktur Data yang Digunakan

### Single Linked List
- Role
- User
- Playlist

### Double Linked List
- Song (Library)
- Lagu di dalam playlist

### Multi Linked List
Digunakan untuk relasi:
- Role ke User
- User ke Playlist
- Playlist ke Song

## Konsep Struktur Data

| Konsep | Implementasi |
|------|-------------|
| Multi Linked List | Relasi antar entitas |
| Double Linked List | Library lagu dan playlist |
| CRUD | Create, Read, Update, Delete |
| Traversal | Menampilkan dan memutar lagu |
| Sorting | Pengurutan lagu berdasarkan durasi |
| Reverse | Membalik urutan lagu |


## Alur Program

1. Program dimulai dari Menu Awal
2. User memilih Register, Login, atau Exit
3. Setelah login:
- Admin masuk ke Menu Admin
- User masuk ke Menu User
4. Menu akan terus berulang sampai user memilih Logout
5. Program berhenti jika memilih Exit

---
