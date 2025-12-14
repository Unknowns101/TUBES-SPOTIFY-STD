# TUBES-SPOTIFY-STD

# 🎵 Tubes Spotify – Music Library & Playlist Management

Program **Tubes Spotify** adalah aplikasi berbasis **C++** yang mensimulasikan sistem manajemen musik sederhana seperti Spotify.  
Aplikasi ini dibuat untuk memenuhi **Tugas Besar Struktur Data**, dengan penerapan **Multi Linked List** dan **Double Linked List**.

---

## 📌 Fitur Utama

### 🔐 Autentikasi
- **Register** user dengan role (`admin` / `user`)
- **Login** sesuai role
- Sistem menu berjalan terus hingga user memilih **logout** atau **exit**

---

## 👤 Fitur Admin

1. **Tambah Lagu**
   - Menambahkan lagu ke library dengan data:
     - Judul
     - Penyanyi
     - Genre
     - Durasi

2. **Edit Lagu**
   - Mengubah data lagu yang ada di library

3. **Hapus Lagu**
   - Lagu dihapus dari library
   - Lagu otomatis terhapus dari seluruh playlist yang mengandung lagu tersebut

4. **Lihat Library**
   - Menampilkan seluruh lagu dalam library dengan format:
     ```
     No. Judul - Penyanyi | Genre | Durasi
     ```

---

## 👥 Fitur User

1. **Create Playlist**
   - User dapat membuat playlist baru

2. **Edit Playlist**
   - Mengubah nama playlist
   - Menambahkan lagu ke playlist
   - Menghapus lagu dari playlist
   - Mengurutkan lagu berdasarkan durasi
   - Membalik urutan lagu (reverse)

3. **Delete Playlist**
   - Menghapus playlist beserta relasi lagu di dalamnya

4. **Lihat Playlist**
   - Menampilkan seluruh playlist milik user

5. **Lihat Library**
   - Menampilkan seluruh lagu yang tersedia

6. **Play Playlist**
   - Simulasi pemutaran lagu dengan informasi:
     - Lagu saat ini
     - Lagu sebelumnya (Prev)
     - Lagu selanjutnya (Next)

7. **Play Library**
   - Memutar seluruh lagu di library secara berurutan

---

## 🧩 Struktur Data yang Digunakan

### 🔹 Single Linked List
- Role
- User
- Playlist

### 🔹 Double Linked List
- Song (Library)
- Lagu di dalam Playlist

### 🔹 Multi Linked List
Digunakan untuk relasi:
- Role → User
- User → Playlist
- Playlist → Song

---

## 🧠 Konsep Struktur Data

| Konsep | Implementasi |
|------|-------------|
| Multi Linked List | Relasi antar entitas |
| Double Linked List | Library lagu & playlist |
| CRUD | Create, Read, Update, Delete |
| Traversal | Menampilkan & memutar lagu |
| Sorting | Urut lagu berdasarkan durasi |
| Reverse | Membalik urutan playlist |
| Modular Program | Header & CPP terpisah |

---

## 🔁 Alur Program

1. Program dimulai dari **Menu Awal**
2. User memilih:
   - Register
   - Login
   - Exit
3. Setelah login:
   - Admin masuk ke Menu Admin
   - User masuk ke Menu User
4. Menu akan terus berulang hingga memilih **Logout**
5. Program berhenti hanya jika memilih **Exit**

---

## 📁 Struktur File

