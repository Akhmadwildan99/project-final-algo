# Software Requirement

## Deskripsi Proyek
Proyek ini adalah aplikasi manajemen proyek dan inventaris yang dirancang untuk membantu admin dan staff produksi dalam mengelola supplier, bahan, dan status proyek. Aplikasi ini memungkinkan pengguna untuk melakukan input data, memantau stok, dan memperbarui status proyek dengan mudah.

## Fitur

### Sebagai Admin
#### Manajemen Supplier
- **Data Supplier:**
  - Input data supplier (kode, nama, jenis bahan) untuk mencatat mitra.
  - Melihat daftar supplier untuk memonitor mitra.

#### Manajemen Bahan
- **Kontrol Stok:**
  - Input bahan masuk (kode, nama, jumlah) untuk memperbarui stok.
  - Melihat stok tersedia untuk mengontrol persediaan.

### Sebagai Staff Produksi
#### Manajemen Produksi
- **Penggunaan Bahan:**
  - Mencatat pengambilan bahan (kode proyek, bahan, jumlah) untuk memperbarui stok.
  - Melihat ketersediaan bahan untuk memeriksa stok.

#### Status Proyek
- **Progress Update:**
  - Memperbarui status proyek (mulai/proses/selesai) untuk memonitor kemajuan.
  - Melihat daftar proyek aktif untuk memantau pengerjaan.

## Menjalankan aplikasi
```
    g++ main.cpp -o main && ./main
```


# Navigasi Aplikasi

<img width="702" alt="image" src="https://github.com/user-attachments/assets/0440bbbb-9fbc-464a-827c-5ace4c2f98bb" />



# Notes
1. Navigasi dan pemilihan status di aplikasi ini menggunkan input nomor.
2. Di menu suplier terdapat aksi menambah data. User akan diminta memasukkan kode, nama suplier dan jumlah bahan baku yang mau diinput, Setelah itu user akan diminta memasukan bahan baku sesuai jumlah jenis bahan baku yang diinput.
3. Pada menu bahan baku di role admin. User akan diminta memasukan kode bahan baku, nama bahan baku dan jumlah. Dengan catatan bahan harus sesuai yang sudah diinput di menu suplier. Dan jika bahan A sudah terinput dengan kode AB maka untuk menambah stok bahan A harus menginput dengan kode dan nama bahan yang sama.
4. Di menu proyek admin  akan diminta memasukan kode proyek, pesanan, keterangan, tanggal mulai dan selesai. Selesai menginput maka status proyek sementara draft.
5. Staff produksi dapat mengubah status proyek pada menu Status proyek dan aksi Status proyek. User akan diminta memsukan id proyek dan memilih status dengan input berupa angka.
6. Di role Staff produksi juga terdapat menu pengambilan bahan untuk proyek. User akan diminta memasukan kode proyek, nama bahan yang mau diambil dan jumlah yamg mau diambil. Jika berhasil stok bahan akan otomatis berkurang.



