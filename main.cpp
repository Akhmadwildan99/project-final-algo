#include <iostream>
#include <string>
#include <limits>
using namespace std;

int app = 1, role, menu, aksi;
const int size_suplier = 100;
const int size_stoks = 100;
const int size_proyek = 100;
const int size_stock_out = 100;
const int size_suplier_bahan = 1000;
// const int size_stok_historis = 1000;


// data suplier
int current_position_suplier = 0;
int current_position_suplier_bahan = 0;
string kodes[size_suplier];
string namas[size_suplier];
string bahans[size_suplier_bahan];
string ref_suplier_kode[size_suplier_bahan];
// data suplier

// data stok
int current_position_stok = 0;
string kode_stoks[size_stoks];
string nama_stoks[size_stoks];
int jumlah_stoks[size_stoks];
// data stok

// data proyek
int current_position_proyek= 0;
string kode_proyeks[size_proyek];
string pesanans[size_proyek];
string deskripsi_proyeks[size_proyek];
int start_tanggal_proyeks[size_proyek];
int start_bulan_proyeks[size_proyek];
int start_tahun_proyeks[size_proyek];
int end_tanggal_proyeks[size_proyek];
int end_bulan_proyeks[size_proyek];
int end_tahun_proyeks[size_proyek];
int status_proyeks[size_proyek];
// data proyek

// Data pengeluaran bahan proyek
int current_position_stock_out= 0;
string kode_proyek_stock_out[size_stock_out];
string bahan_stock_out[size_stock_out];
int jumlah_stock_out[size_stock_out];
// Data pengeluaran bahan proyek

// validate kode
bool validateKodeProyek(string kode) {
    for (int i = 0; i < current_position_proyek; i++)
    {
        /* code */
        if(kode_proyeks[i] == kode) {
            cout << "Kode: " << kode << " sudah pernah diinput"<< endl;
            return true;
        }
    }

    return false;
    
}




// input and validate  tanggal
bool validateTanggal(int tanggal, int bulan, int tahun) {
    if(tanggal >= 0 && tanggal <= 31) {

        // bulan tanggal 30
        if(tanggal == 31 && (bulan == 2 || bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11)){
            cout << "\ntanggal dan bulan invalid!!!!" << endl;
            return false;
        }

        

        // bukan kabisat
        int kabisat = false;
        if(tahun % 4 == 0 || tahun % 400 == 0) {
            kabisat = true;
        }

        // bulan 28
        if(tanggal == 29 && bulan == 2 && !kabisat) {
            cout << "\nbukan tahun kabisat!!!!"<< endl;
            return false;
        } 



        return true;
    }

    return false;
}

bool validateBulan(int bulan) {
    if(bulan >= 0 && bulan <= 12) {
        return true;
    }

    cout << "\nbulan invalid!!!!"<< endl;
    return false;
}


string convertIntToStr(int num) {
    if(to_string(num).length() == 1) {
        return "0"+ to_string(num);
    }
    return to_string(num);
}

int indexOfSuplierKode(string kode) {
    for (int i = 0; i < current_position_suplier; i++)
    {
        if(kode == kodes[i]) {
            return i;
        }
    }

    return -1;
    
}

void tambahSuplier() {
   

    if(current_position_suplier > size_suplier || current_position_suplier_bahan > size_suplier_bahan) {
        cout << "\nMaaf penyimpanan suplier sudah penuh "<< endl;
    } else {
            string kode,nama;

        
        int jumlahBahan;
        cout << "\nMasukan kode: ";
        cin >> kode;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukan nama suplier: ";
        getline(cin, nama);

        if(indexOfSuplierKode(kode) != -1) {
            cout << "\nKode " << kode << " Sudah terpakai!"<< endl;
            return;
        }

        kodes[current_position_suplier] = kode;
        namas[current_position_suplier] = nama;

        cout << "Masukan jumlah bahan yang mau diinput: ";
        cin >> jumlahBahan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string bahaninputs[jumlahBahan];

        for (int i = 0; i < jumlahBahan; i++)
        {
            cout << "Masukan bahan ke-" << i+1 << " : ";
            getline(cin, bahaninputs[i]);
            bahans[current_position_suplier_bahan] = bahaninputs[i];
            ref_suplier_kode[current_position_suplier_bahan] = kode;
            current_position_suplier_bahan++;
        }

        current_position_suplier++;

        cout << "\nHoreyy suplier " << nama << " berhasil di tambah...." << endl;
    }

}

string findBahansByKode(string kode) {
    string bahan= "";
    for (int i = 0; i < current_position_suplier_bahan; i++)
    {
        if(ref_suplier_kode[i] == kode) {

            if(ref_suplier_kode[i + 1] == kode) {
                bahan+= bahans[i] + ", ";
            } else {
                 bahan+= bahans[i];
            }
        }

    }

    return bahan;
    
}

void printSuplier() {
    cout <<""<<endl;
    cout << "Kode                Suplier                       Jenis bahan" << endl;
    cout << "-------------------------------------------------------------" << endl;


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
         for (int j = namas[i].length(); j < 30; j++)
        {
            /* code */
            cout<<" ";
        }
        cout << findBahansByKode(kodes[i]) << endl;


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

int indexOfStockBahan(string nama) {
    for (int i = 0; i <= current_position_stok; i++)
    {
        /* code */

        if(nama_stoks[i] == nama ) {
            return i;
        }

    }

    return -1;
    
}

int indexOfStockKode(string kode) {
    for (int i = 0; i <= current_position_stok; i++)
    {
        /* code */

        if(kode_stoks[i] == kode ) {
            return i;
        }

    }

    return -1;
    
}

int indexOfBahanSuplier(string bahan) {
    for (int i = 0; i < current_position_suplier_bahan; i++)
    {
       if( bahan == bahans[i]) {
        return i;
       }
    }
    
    return -1;
}


void printBahanBaku(int status) {
    cout <<""<<endl;
    cout << "Kode                Jenis bahan        Jumlah" << endl;
    cout << "---------------------------------------------" << endl;


    for (int i = 0; i < current_position_stok; i++)
    {
        if(status == 1 && jumlah_stoks[i] <= 0) {
            continue;
        }
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

    if(indexOfBahanSuplier(bahan) == -1) {
        cout << "\nMaaf bahan " << bahan << " tidak tersedia di data suplier"<< endl;
        return;
    }

    int x = indexOfStock(bahan, kode);
    if(x != -1) {
        jumlah_stoks[x]+= jumlah;
        cout << "\nHoreyy stock "<< bahan << " berhasil di perbaharui...." << endl;
    } else if(x == -1 && size_stoks > current_position_stok){
        int y  = indexOfStockBahan(bahan);
        if(y != -1) {
            cout << "\ntidak bisa menambah "<< bahan << " bahan tersebut telah terinput dengan kode " << kode_stoks[y]  << endl;
            return;
        }

        int n = indexOfStockKode(kode);

        if(n != -1) {
            cout << "\ntidak bisa menambah "<< bahan << " dengan kode " << kode << " karena kode tersebut telah terinput dengan bahan yang berbeda " << endl;
            return;
        }


        kode_stoks[current_position_stok] = kode;
        nama_stoks[current_position_stok] = bahan;
        jumlah_stoks[current_position_stok] = jumlah;

        current_position_stok++;

        cout << "\nHoreyy stock "<< bahan << " berhasil di ditambah...." << endl;
    }
}



string converStatus(int num) {
    string status = "";
    switch (num)
    {
    case 0:
        status= "Draft";
        break;
    case 1:
        status= "Mulai";
        break;
    case 2:
        status= "Proses";
        break;
    case 3:
        status= "Selesai";
        break;
    default:
        break;
    }

    return status;

}



void printProyek(int from, int end, int status) {
    cout <<""<<endl;
    cout << "No  Kode                Jenis pesanan       Deskripsi                    Tanggal mulai  Tanggal selesai  Status pesanan" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    int nomor = 1;
    for (int i = from; i < end; i++)
    {
        if(status == 1 && (status_proyeks[i] == 0 || status_proyeks[i] == 3)) {
            continue;
        }
        cout << nomor;
        string number = to_string(nomor);
        for (int j = number.length(); j <  4; j++)
        {
            /* code */
            cout << " ";
        }
        
        /* code */
        cout << kode_proyeks[i];
        for (int j = kode_proyeks[i].length(); j < 20; j++)
        {
            /* code */
            cout<<" ";
        }
        
        cout << pesanans[i];
         for (int j = pesanans[i].length(); j < 20; j++)
        {
            /* code */
            cout<<" ";
        }

        cout << deskripsi_proyeks[i];
         for (int j = deskripsi_proyeks[i].length(); j < 30; j++)
        {
            /* code */
            cout<<" ";
        }

        cout << convertIntToStr(start_tanggal_proyeks[i])  << "/" << convertIntToStr(start_bulan_proyeks[i]) << "/" << convertIntToStr(start_tahun_proyeks[i]);
        cout << "     ";

        cout << convertIntToStr(end_tanggal_proyeks[i])  << "/" << convertIntToStr(end_bulan_proyeks[i]) << "/" << convertIntToStr(end_tahun_proyeks[i]);
        cout << "       ";


        cout << converStatus(status_proyeks[i]);

        
        nomor++;
    }
    

}

void printProyekIdStatus() {
    cout <<""<<endl;
    cout << "Id  Kode                Jenis pesanan       Status pesanan" << endl;
    cout << "----------------------------------------------------------" << endl;

    for (int i = 0; i < current_position_proyek; i++)
    {
        string id = to_string(i+1);
        cout << id;
        for (int j = id.length(); j <  4; j++)
        {
            /* code */
            cout << " ";
        }

        /* code */
        cout << kode_proyeks[i];
        for (int j = kode_proyeks[i].length(); j < 20; j++)
        {
            /* code */
            cout<<" ";
        }
        
        cout << pesanans[i];
         for (int j = pesanans[i].length(); j < 20; j++)
        {
            /* code */
            cout<<" ";
        }

        cout << converStatus(status_proyeks[i]);

    }
}


// fungsi manajemen proyek
void updatedStatusProyek() {
    int id, status;
    char agree;
    printProyekIdStatus();
    // pilih proyek
    cout << "\nMasukan id proyek: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    id = id - 1;
    // tampil status
    cout << "\nPilih status proyek: " 
    << "\n1. Draft" << "\n2. Mulai" << "\n3. Proses" << "\n4. Selesai";
    
    // masukan status
    cout << "\nMasukan status proyek: ";
    cin >> status;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    // apakah yakin akan mengubah status proyek?
    cout << "Apakah Anda setuju? (y/t): ";
    cin >> agree;

    if(agree == 'y') {
        switch (status)
        {
        case 1:
            status_proyeks[id] = 0;
            break;
        case 2:
            status_proyeks[id] = 1;
            break;
        case 3:
            status_proyeks[id] = 2;
            break;
        case 4:
            status_proyeks[id] = 3;
            break;
        
        default:
            cout << "\nGagal update status proyek: " << kode_proyeks[id];
            cout << "\nPilihan status invalid" << endl;
            break;
        } 

        cout << "\nBerhasil update status proyek: " << kode_proyeks[id] << endl;
    } else {
        cout << "\nGagal update status proyek: " << kode_proyeks[id] << endl;
    }

    // pesan berhasil
}

void printProyekAktif() {
    printProyek(0, current_position_proyek, 1);
}
// fungsi manajemen proyek


void tambahDataProyek() {
    string kode, pesanan, deskripsi_proyek;
    int start_tanggal, start_bulan, start_tahun, end_tanggal, end_bulan, end_tahun;
    do
    {
        cout << "Masukan kode: ";
        cin >> kode;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        /* code */
    } while (validateKodeProyek(kode) == true);

    cout << "Masukan pesanan: ";
    getline(cin, pesanan);
    cout << "Masukan deskripsi: ";
    getline(cin, deskripsi_proyek);

    int inputTglStart = 0;
    int inputTglEnd = 0;
    do
    {
        if(inputTglStart > 0) {
            cout << "Masukan tanggal mulai lagi: "   << endl;
            
        } else {
            cout << "Masukan tanggal mulai: "   << endl;
        }
        
        cout << "Masukan tanggal: ";
        cin >> start_tanggal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukan bulan: ";
        cin >> start_bulan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukan tahun: ";
        cin >> start_tahun;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        inputTglStart++;
    } while (!validateBulan(start_bulan) || !validateTanggal(start_tanggal, start_bulan, start_tahun));
    
    do
    {
        if(inputTglEnd > 0) {
            cout << "Masukan tanggal selesai lagi: " << endl;
        } else {
            cout << "Masukan tanggal selesai: " << endl;
        }
    
        cout << "Masukan tanggal: ";
        cin >> end_tanggal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukan bulan: ";
        cin >> end_bulan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukan tahun: ";
        cin >> end_tahun;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!validateBulan(end_bulan) || !validateTanggal(end_tanggal, end_bulan, end_tahun));
   

    // push ke data
    kode_proyeks[current_position_proyek] = kode;
    pesanans[current_position_proyek] = pesanan;
    deskripsi_proyeks[current_position_proyek] = deskripsi_proyek;
    start_tanggal_proyeks[current_position_proyek] = start_tanggal;
    start_bulan_proyeks[current_position_proyek] = start_bulan;
    start_tahun_proyeks[current_position_proyek] = start_tahun;
    end_tanggal_proyeks[current_position_proyek] = end_tanggal;
    end_bulan_proyeks[current_position_proyek] = end_bulan;
    end_tahun_proyeks[current_position_proyek] = end_tahun;
    status_proyeks[current_position_proyek] = 0;
    current_position_proyek++;

    cout << "\nHoreyy proyek dengan kode "<< kode << " berhasil di ditambah...." << endl;

    printProyek(current_position_proyek -1, current_position_proyek, 0);
  
}


// fungsi manajemen bahan baku staff 
bool validateKodeProyekAktif(string kode) {

    for (int i = 0; i < current_position_proyek; i++)
    {
        /* code */
        if(kode_proyeks[i] == kode && (status_proyeks[i] == 1 || status_proyeks[i] == 2)) {
            return true;
        }
    }

    return false;
    
}

int indexOfBahan(string bahan) {
    for (int i = 0; i < current_position_stok; i++)
    {
        /* code */
        if( nama_stoks[i] == bahan) {
            return i;
        }
    }


    return -1;
    
}


bool validateStockExist(int idx, int qtyPermintaan) {
    if(jumlah_stoks[idx] > qtyPermintaan) {
        return true;
    }

    return false;
}


void recordPengeluaranBahan() {
    string bahan, kode;
    int idBahan, jumlah;
    cout << "\nPengeluaran bahan proyek" << endl;
    cout << "Masukan kode proyek: ";
    cin >> kode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan nama bahan: ";
    
    getline(cin, bahan);

    cout << "Masukan jumlah pengambilan: ";
    cin >> jumlah;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    if(!validateKodeProyekAktif(kode)) {
        cout << "\nMaaf kode proyek yang anda pilih tidak tersedia....."<< endl;
        return;
    }

    int idx = indexOfBahan(bahan);

    if(idx == -1) {
        cout << "\nMaaf bahan tidak tersedia di dalam gudang ....."<< endl;
        return;
    }

    

    if(!validateStockExist(idx, jumlah)) {
        cout << "\nMaaf jumlah bahan " <<bahan << " saat ini tidak cukup ....."<< endl;
        return;
    }


    jumlah_stoks[idx] -= jumlah; 


    kode_proyek_stock_out[current_position_stock_out] = kode;
    bahan_stock_out[current_position_stock_out] = bahan;
    jumlah_stock_out[current_position_stock_out] = jumlah;
    current_position_stock_out++;

    cout << "\nHoreeeey kamu berhasil mengambil bahan "  << bahan << " untuk proyek kode: "<< kode << endl;

}






// fungsi manajemen bahan baku staff 
void aksiMenuAdminProyek() {
    int aksi;
    do
    {
        cout << "\n\nProyek "
             << "\n1. Tambah data"
             << "\n2. Lihat data"
             << "\n3. Kembali" << endl;

        cout << "Pilih aksi: ";
        cin >> aksi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (aksi)
        {
        case 1:
            // aksi tambah proyek
            tambahDataProyek();
            break;
        case 2:
            printProyek(0, current_position_proyek, 0);
            break;
        case 3:
            cout << "\nKembali ke menu admin!";
            break;
        default:
            break;
        }
    } while (aksi != 3);
    
}



void pilihRole()
{
    cout << "**************************************" << endl;
    cout << "                                      " << endl;
    cout << " Selamat Datang  Silahkan Pilih Role!" << endl;
    cout << "                                      " << endl;
    cout << "======================================" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Staff Produksi" << endl;
    cout << "3. Matikan aplikasi" << endl;
    cout << "Pilih role: ";
}

void adminMenu()
{

    cout << "\nMenu Admin "
         << "\n1. Suplier"
         << "\n2. Bahan Baku"
         << "\n3. Proyek"
         << "\n4. Keluar" << endl;

    cout << "Pilih menu: ";
}

void staffProduksiMenu()
{
    cout << "\nMenu Staff "
         << "\n1. Manajemen Produksi"
         << "\n2. Status proyek"
         << "\n3. Keluar" << endl;

    cout << "Pilih menu: ";
}

void aksiMenuSplier()
{

    int aksi;
    do
    {
        cout << "\nSuplier "
             << "\n1. Tambah data"
             << "\n2. Data suplier"
             << "\n3. Kembali" << endl;

        cout << "Pilih aksi: ";

        cin >> aksi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        cout << "\nBahan Baku "
         << "\n1. Tambah data"
         << "\n2. Riwayat stok"
         << "\n3. Kembali" << endl;

        cout << "Pilih aksi: ";

        cin >> aksi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (aksi)
        {
        case 1:
            tambahBahanBaku();
            break;
        case 2:
            printBahanBaku(0);
            break;
     
        case 3:
            cout << "Kembali ke pilih menu admin!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
        }

    } while (aksi != 3);
}


void aksiMenuManajemenProduksi()
{
    
    int aksi;
    do
    {
        cout << "\nManajemen produksi "
         << "\n1. Pengambilan bahan untuk proyek"
         << "\n2. Ketersediaan bahan"
         << "\n3. Kembali" << endl;

         cout << "Pilih aksi: ";
        cin >> aksi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (aksi)
        {
        case 1:
            recordPengeluaranBahan();
            break;
        case 2:
             printBahanBaku(1);
            break;

        case 3:
            cout << "Kembali ke pilih menu staff!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
        }

    } while (aksi != 3);
}

void aksiMenuStaffProyek()
{


    int aksi;

    do
    {
        cout << "\n\nStatus proyek "
         << "\n1. Status proyek"
         << "\n2. daftar proyek aktif"
         << "\n3. Kembali" << endl;

        cout << "Pilih aksi: ";

        cin >> aksi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (aksi)
        {
        case 1:
            updatedStatusProyek();
            break;
        case 2:
            printProyekAktif();
            break;
     
        case 3:
            cout << "Kembali ke pilih menu admin!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
        }

    } while (aksi != 3);
}

int main()
{
    

    do
    {
        pilihRole();
        cin >> role;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (role)
        {
        case 1:

            do
            {
                adminMenu();
                cin >> menu;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (menu)
                {
                case 1:

                    aksiMenuSplier();
                    break;
                case 2:

                    aksiMenuBahanBaku();
                    break;
                case 3:
                    aksiMenuAdminProyek();
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (menu)
                {
                case 1:

                    aksiMenuManajemenProduksi();
                    break;
                case 2:
                    aksiMenuStaffProyek();
                    break;

                case 3:
                    cout << "\nKembali ke pilih role!" << endl;
                    break;

                default:
                    cout << "\nPilihan tidak valid silakan pilih menu kembali!" << endl;
                }

            } while (menu != 3);
            break;
        case 3:
            cout << "\nKamu mematikan aplikasi data akan hilang!!!" << endl;
        default:
            cout << "\nPilihan tidak valid silakan pilih role masuk kembali!" << endl;
        }
    } while (role !=3);

    return 0;
}