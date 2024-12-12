#include <iostream>
#include <string>
using namespace std;

int app = 1, role, menu, aksi;
const int size_suplier = 100;
const int size_stoks = 100;
// const int size_stok_historis = 1000;


// data suplier
int current_position_suplier = 0;
string kodes[size_suplier];
string namas[size_suplier];
string bahans[size_suplier];
// data suplier

// data stok
int current_position_stok = 0;
string kode_stoks[size_stoks];
string nama_stoks[size_stoks];
int jumlah_stoks[size_stoks];
// data stok

// // data stok histori
// int current_position_stok_histori = 0;
// string kode_stok_historis[size_stok_historis];
// string nama_stok_historis[size_stok_historis];
// int jumlah_stok_historis[size_stok_historis];

// // data stok histori

void tambahSuplier() {
    string kode,nama, bahan;
   
    cout << "\nMasukan kode: ";
    cin >> kode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan nama suplier: ";
    getline(cin, nama);
    cout << "Masukan jenis bahan: ";
    getline(cin, bahan);
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');


    if(current_position_suplier > size_suplier) {

    } else {
        kodes[current_position_suplier] = kode;
        namas[current_position_suplier] = nama;
        bahans[current_position_suplier] = bahan;
        current_position_suplier++;

        cout << "\nHoreyy suplier " << nama << " berhasil di tambah...." << endl;
    }

    // printSuplier();
}

void printSuplier() {
    cout <<""<<endl;
    cout << "Kode                Suplier             Jenis bahan" << endl;
    cout << "---------------------------------------------------" << endl;


    for (int i = 0; i < current_position_suplier; i++)
    {
        /* code */
        cout << kodes[i];
        for (int j = kodes[i].length(); j < 20; j++)
        {
            /* code */
            cout<<" ";
        }
        
        cout << namas[i];
         for (int j = namas[i].length(); j < 20; j++)
        {
            /* code */
            cout<<" ";
        }
        cout << bahans[i] << endl;

    }
    

}

int indexOfStock(string nama, string kode) {
    for (int i = 0; i <= current_position_stok; i++)
    {
        /* code */

        if(nama_stoks[i] == nama && kode_stoks[i] == kode) {
            return i;
        }

    }

    return -1;
    
}


void printBahanBaku() {
    cout <<""<<endl;
    cout << "Kode                Jenis bahan        Jumlah" << endl;
    cout << "---------------------------------------------" << endl;


    for (int i = 0; i < current_position_stok; i++)
    {
        /* code */
        cout << kode_stoks[i];
        for (int j = kode_stoks[i].length(); j < 20; j++)
        {
            /* code */
            cout<<" ";
        }
        
        cout << nama_stoks[i];
         for (int j = nama_stoks[i].length(); j < 20; j++)
        {
            /* code */
            cout<<" ";
        }
        cout << jumlah_stoks[i] << endl;

    }
    

}

void tambahBahanBaku() {
    string kode,bahan;
    int jumlah;

    cout << "\nMasukan kode: ";
    cin >> kode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan jenis bahan: ";
    getline(cin, bahan);
    cout << "Masukan jumlah: ";
    cin >> jumlah;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int x = indexOfStock(bahan, kode);
    if(x != -1) {
        jumlah_stoks[x]+= jumlah;
        cout << "\nHoreyy stock "<< bahan << " berhasil di perbaharui...." << endl;
    } else if(x == -1 && size_stoks > current_position_stok){
        kode_stoks[current_position_stok] = kode;
        nama_stoks[current_position_stok] = bahan;
        jumlah_stoks[current_position_stok] = jumlah;

        current_position_stok++;

        cout << "\nHoreyy stock "<< bahan << " berhasil di ditambah...." << endl;
    }
}

// tambah stok bisa pilih dari daftar bahan di suplier atau langsung
// sebelum itu ada pilihan terlebih dahulu apakah mau ambil dari daftar
// jika iya akan tampil bahan beserta nomernya
// dan user bisa input nomer dari bahan tsb
// setelah pilih maka tinggal input kode dan jumlah
// jika tidak input manual semuanya
// sterlah input proses validasi jika bahan sudah tersedia di stok 
// maka increase stok
// jika belum ada buat baru



void pilihRole()
{
    cout << "**************************************" << endl;
    cout << "                                      " << endl;
    cout << " Selamat Datang  Silahkan Pilih Role! " << endl;
    cout << "                                      " << endl;
    cout << "======================================" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Staff Produks" << endl;
    cout << "Pilih role: ";
}

void adminMenu()
{

    cout << "\n Menu Admin "
         << "\n1. Suplier"
         << "\n2. Bahan Baku"
         << "\n3. Proyek"
         << "\n4. Keluar" << endl;

    cout << "Pilih menu: ";
}

void staffProduksiMenu()
{
    cout << "\n Menu Staff "
         << "\n1. Manajemen Produksi"
         << "\n2. Pemantauan stok"
         << "\n3. Keluar" << endl;

    cout << "Pilih menu: ";
}

void aksiMenuSplier()
{

    int aksi;
    do
    {
        cout << "\n Manajemen Suplier "
             << "\n1. Tambah data"
             << "\n2. Data suplier"
             << "\n3. Kembali" << endl;

        cout << "Pilih aksi: ";

        cin >> aksi;

        switch (aksi)
        {
        case 1:
            tambahSuplier();
            break;
        case 2:
            printSuplier();
            break;

        case 3:
            cout << "Kembali ke pilih menu admin!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
        }

    } while (aksi != 3);
}

void aksiMenuBahanBaku()
{
    

    int aksi;

    do
    {
        cout << "\n Manajemen Bahan Baku "
         << "\n1. Tambah data"
         << "\n2. Riwayat stok"
         << "\n3. Kembali" << endl;

        cout << "Pilih aksi: ";

        cin >> aksi;

        switch (aksi)
        {
        case 1:
            tambahBahanBaku();
            break;
        case 2:
            printBahanBaku();
            break;
     
        case 3:
            cout << "Kembali ke pilih menu admin!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
        }

    } while (aksi != 3);
}

void aksiMenuProyek()
{
    cout << "\n Sub Menu Proyek "
         << "\n1. Semua proyek"
         << "\n2. Detail penggunaan bahan per proyek"
         << "\n3. Status proyek"
         << "\n4. Estimasi proyek selesai"
         << "\n5. Kembali" << endl;

    cout << "Pilih aksi: ";
}

void aksiMenuManajemenProduksi()
{
    cout << "\n Sub Menu Proyek "
         << "\n1. Pengambilan bahan untuk proyek"
         << "\n2. Progress pengerjaan proyek"
         << "\n3. Kembali" << endl;

    cout << "Pilih aksi: ";
}

void aksiMenuPemantauanStok()
{
    cout << "\n Sub Menu Proyek "
         << "\n1. Pengambilan bahan untuk proyek"
         << "\n2. Progress pengerjaan proyek"
         << "\n3. Kembali" << endl;

    cout << "Pilih aksi: ";
}

int main()
{
    

    do
    {
        pilihRole();
        cin >> role;

        switch (role)
        {
        case 1:

            do
            {
                adminMenu();
                cin >> menu;

                switch (menu)
                {
                case 1:

                    aksiMenuSplier();
                    break;
                case 2:

                    aksiMenuBahanBaku();
                    break;
                case 3:

                    do
                    {
                        aksiMenuProyek();
                        cin >> aksi;

                        switch (aksi)
                        {
                        case 1:
                            cout << "Aksi melihat semua proyek" << endl;
                            break;
                        case 2:
                            cout << "Aksi melihat detail penggunaan bahan per proyek" << endl;
                            break;
                        case 3:
                            cout << "Aksi melihat status proyek" << endl;
                            break;
                        case 4:
                            cout << "Aksi melihat estimasi proyek" << endl;
                            break;
                        case 5:
                            cout << "Kembali ke pilih menu admin!" << endl;
                            break;

                        default:
                            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
                        }

                    } while (aksi != 5);
                    break;
                case 4:
                    cout << "Kembali ke pilih role!" << endl;
                    break;

                default:
                    cout << "Pilihan tidak valid silakan pilih menu kembali!" << endl;
                }

            } while (menu != 4);

            break;
        case 2:
            do
            {
                staffProduksiMenu();
                cin >> menu;

                switch (menu)
                {
                case 1:

                    do
                    {
                        aksiMenuManajemenProduksi();
                        cin >> aksi;

                        switch (aksi)
                        {
                        case 1:
                            cout << "Aksi pengambilan bahan untuk proyek" << endl;
                            break;
                        case 2:
                            cout << "Aksi melihat progress pengerjaan proyek" << endl;
                            break;

                        case 3:
                            cout << "Kembali ke pilih menu staff!" << endl;
                            break;

                        default:
                            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
                        }

                    } while (aksi != 3);
                    break;
                case 2:

                    staffProduksiMenu();
                    cin >> menu;

                    do
                    {
                        aksiMenuPemantauanStok();
                        cin >> aksi;

                        switch (aksi)
                        {
                        case 1:
                            cout << "Aksi melihat ketersediaan bahan baku" << endl;
                            break;
                        case 2:
                            cout << "Aksi melihat kualitas bahan tersedia" << endl;
                            break;

                        case 3:
                            cout << "Aksi peringatan stok menipis" << endl;
                            break;
                        case 4:
                            cout << "Kembali ke pilih menu staff!" << endl;
                            break;

                        default:
                            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
                        }

                    } while (aksi != 4);

                    break;

                case 3:
                    cout << "Kembali ke pilih role!" << endl;
                    break;

                default:
                    cout << "Pilihan tidak valid silakan pilih menu kembali!" << endl;
                }

            } while (menu != 3);
            break;
        default:
            cout << "Pilihan tidak valid silakan pilih role masuk kembali!" << endl;
        }
    } while (app == 1);

    return 0;
}