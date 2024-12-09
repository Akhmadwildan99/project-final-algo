#include <iostream>
#include <string>
using namespace std;

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
    cout << "\n Sub Menu Suplier "
         << "\n1. Tambah data"
         << "\n2. Data suplier"
         << "\n3. Cari suplier"
         << "\n4. Update rating suplier"
         << "\n5. Kembali" << endl;

    cout << "Pilih aksi: ";
}

void aksiMenuBahanBaku()
{
    cout << "\n Sub Menu Bahan Baku "
         << "\n1. Tambah data"
         << "\n2. Riwayat stok"
         << "\n3. Riwayat penggunaan"
         << "\n4. Peringatan stok"
         << "\n5. Kembali" << endl;

    cout << "Pilih aksi: ";
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

    int app = 1, role, menu, aksi;

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

                    do
                    {
                        aksiMenuSplier();
                        cin >> aksi;

                        switch (aksi)
                        {
                        case 1:
                            cout << "Aksi tambah suplier" << endl;
                            break;
                        case 2:
                            cout << "Aksi melihat data suplier" << endl;
                            break;
                        case 3:
                            cout << "Aksi mencari suplier" << endl;
                            break;
                        case 4:
                            cout << "Aksi update rating suplier" << endl;
                            break;
                        case 5:
                            cout << "Kembali ke pilih menu admin!" << endl;
                            break;

                        default:
                            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
                        }

                    } while (aksi != 5);

                    break;
                case 2:

                    do
                    {
                        aksiMenuBahanBaku();
                        cin >> aksi;

                        switch (aksi)
                        {
                        case 1:
                            cout << "Aksi tambah suplier" << endl;
                            break;
                        case 2:
                            cout << "Aksi melihat riwayat stok" << endl;
                            break;
                        case 3:
                            cout << "Aksi melihat riwayat penggunaan" << endl;
                            break;
                        case 4:
                            cout << "Aksi peringatan stok" << endl;
                            break;
                        case 5:
                            cout << "Kembali ke pilih menu admin!" << endl;
                            break;

                        default:
                            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
                        }

                    } while (aksi != 5);
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