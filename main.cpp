#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <iomanip> 
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
bool status_bahans[size_suplier_bahan];
bool status_suplier[size_suplier];
// data suplier

// data stok
int current_position_stok = 0;
string kode_stoks[size_stoks];
string nama_stoks[size_stoks];
int jumlah_stoks[size_stoks];
bool status_bahan_stoks[size_stoks];
// data stok

// data proyek
int current_position_proyek = 0;
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
int current_position_stock_out = 0;
string kode_proyek_stock_out[size_stock_out];
string bahan_stock_out[size_stock_out];
int jumlah_stock_out[size_stock_out];
// Data pengeluaran bahan proyek



// validate kode
bool validateKodeProyek(string kode)
{
    for (int i = 0; i < current_position_proyek; i++)
    {
        /* code */
        if (kode_proyeks[i] == kode)
        {
            cout << "Kode: " << kode << " sudah pernah diinput" << endl;
            return true;
        }
    }

    return false;
}

int indexOfBahanSuplier(string bahan)
{
    for (int i = 0; i < current_position_suplier_bahan; i++)
    {
        if (bahan == bahans[i] && status_bahans[i])
        {
            return i;
        }
    }

    return -1;
}

int indexOfBahan(string bahan)
{
    for (int i = 0; i < current_position_stok; i++)
    {
        /* code */
        if (nama_stoks[i] == bahan)
        {
            return i;
        }
    }

    return -1;
}

// input and validate  tanggal

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (year < 1900 || year > 2100) {
        return false; // Batasi tahun antara 1900 dan 2100
    }

    if (month < 1 || month > 12) {
        return false; // Bulan harus antara 1 dan 12
    }

    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            daysInMonth = isLeapYear(year) ? 29 : 28;
            break;
        default:
            return false; // Tidak seharusnya sampai sini
    }

    return (day >= 1 && day <= daysInMonth);
}

bool isStartDateBeforeEndDate(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {
    tm startDate = {};
    startDate.tm_mday = startDay;       
    startDate.tm_mon = startMonth - 1;   
    startDate.tm_year = startYear - 1900;

    tm endDate = {};
    endDate.tm_mday = endDay;       
    endDate.tm_mon = endMonth - 1;   
    endDate.tm_year = endYear - 1900;


    time_t startTime = std::mktime(const_cast<std::tm*>(&startDate));
    time_t endTime = std::mktime(const_cast<std::tm*>(&endDate));

    return startTime < endTime;
}


int indexOfSuplierKode(string kode)
{
    for (int i = 0; i < current_position_suplier; i++)
    {
        if (kode == kodes[i])
        {
            return i;
        }
    }

    return -1;
}



string formatDate(int day, int month, int year) {
    tm date = {};
    date.tm_mday = day;       
    date.tm_mon = month - 1;   
    date.tm_year = year - 1900;

    // Memformat tanggal ke dalam string
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%d %B %Y", &date); // Format dd-mmmm-yyyy

    return std::string(buffer);
}


bool validateSizeSuplierBahan()
{
    if (current_position_suplier >= size_suplier || current_position_suplier_bahan >= size_suplier_bahan)
    {
        cout << "\nMaaf penyimpanan suplier sudah penuh " << endl;
        return true;
    }
    return false;
}

bool validateInputJumlahBahan(int n) {
    if(n > size_suplier_bahan) {
        cout << "\nInput jumlah bahan invalid!" << endl;
        return true;
    }

    return false;
}



void tambahSuplier()
{

    if(validateSizeSuplierBahan()) {
        return;
    }
    string kode, nama;

    int jumlahBahan;
    cout << "\nMasukan kode: ";
    cin >> kode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan nama suplier: ";
    getline(cin, nama);

    if (indexOfSuplierKode(kode) != -1)
    {
        cout << "\nKode " << kode << " Sudah terpakai!" << endl;
        return;
    }

    

    cout << "Masukan jumlah bahan yang mau diinput: ";
    cin >> jumlahBahan;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string bahaninputs[jumlahBahan];

    int n = jumlahBahan + current_position_suplier_bahan;
    if(validateInputJumlahBahan(n)){
        return;
    }

    kodes[current_position_suplier] = kode;
    namas[current_position_suplier] = nama;

    for (int i = 0; i < jumlahBahan; i++)
    {
        cout << "Masukan bahan ke-" << i + 1 << " : ";
        getline(cin, bahaninputs[i]);
        bahans[current_position_suplier_bahan] = bahaninputs[i];
        ref_suplier_kode[current_position_suplier_bahan] = kode;
        status_bahans[current_position_suplier_bahan]= true;

        int idxBahan= indexOfBahan(bahaninputs[i]);

        if(idxBahan != -1 && !status_bahan_stoks[idxBahan]) {
            status_bahan_stoks[idxBahan]= true;
        }

        current_position_suplier_bahan++;
    }

    status_suplier[current_position_suplier]= true;
    current_position_suplier++;

    cout << "\nHoreyy suplier " << nama << " berhasil di tambah...." << endl;
}




int jumlahBahanSuplier(string bahan) {
    int count=0;
     for (int i = 0; i < current_position_suplier_bahan; i++)
    {
       if(bahans[i] == bahan) {
        count++;
       }
    }
    return count;

}

// non aktif bahan di stok
void nonAktifBahanStok(string bahan) {

    if(jumlahBahanSuplier(bahan) > 1) {
        return;
    }

    for (int i = 0; i < current_position_stok; i++)
    {
        if(nama_stoks[i] == bahan) {
            status_bahan_stoks[i] = false;
        }
    }
    
}

// non aktif suplier

void nonAktifBahanSuplier(string kode) {

    // non aktif bahan di suplier
    for (int i = 0; i < current_position_suplier_bahan; i++)
    {
        if(ref_suplier_kode[i] == kode) {
            nonAktifBahanStok(bahans[i]);
            status_bahans[i] = false;
        }
    }

}



void nonAktifSuplier() {
    string kode;
    char agree;

    cout << "\nMasukan kode: ";
    cin >> kode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int idSuplier= indexOfSuplierKode(kode);
    if (idSuplier == -1)
    {
        cout << "\nKode " << kode << " tidak ada di daftar!" << endl;
        return;
    }



    // apakah yakin akan mengubah status proyek?
    cout << "Apakah Anda setuju? (y/t): ";
    cin >> agree;

    if(agree == 'y') {
        nonAktifBahanSuplier(kode);
        status_suplier[idSuplier]= false;

        cout << "\n Berhasil menonaktifkan suplier dengan kode " << kode << endl;
    }
        
    


}


string findBahansByKode(string kode)
{
    string bahan = "";
    for (int i = 0; i < current_position_suplier_bahan; i++)
    {
        if (ref_suplier_kode[i] == kode)
        {

            if (ref_suplier_kode[i + 1] == kode)
            {
                bahan += bahans[i] + ", ";
            }
            else
            {
                bahan += bahans[i];
            }
        }
    }

    return bahan;
}

void printSuplier()
{
    cout << "" << endl;
    cout << "Kode                Suplier                       Jenis bahan" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i < current_position_suplier; i++)
    {
        if(!status_suplier[i]) {
            continue;
        }
        /* code */
        cout << kodes[i];
        for (int j = kodes[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }

        cout << namas[i];
        for (int j = namas[i].length(); j < 30; j++)
        {
            /* code */
            cout << " ";
        }
        cout << findBahansByKode(kodes[i]) << endl;
    }
}

int indexOfStock(string nama, string kode)
{
    for (int i = 0; i <= current_position_stok; i++)
    {
        /* code */

        if (nama_stoks[i] == nama && kode_stoks[i] == kode)
        {
            return i;
        }
    }

    return -1;
}

int indexOfStockBahan(string nama)
{
    for (int i = 0; i <= current_position_stok; i++)
    {
        /* code */

        if (nama_stoks[i] == nama)
        {
            return i;
        }
    }

    return -1;
}

int indexOfStockKode(string kode)
{
    for (int i = 0; i <= current_position_stok; i++)
    {
        /* code */

        if (kode_stoks[i] == kode)
        {
            return i;
        }
    }

    return -1;
}



void printBahanBaku(int status)
{
    cout << "" << endl;
    cout << "Kode                Jenis bahan        Jumlah" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < current_position_stok; i++)
    {
        if ((status == 1 && jumlah_stoks[i] <= 0) || (jumlah_stoks[i] <= 0 && !status_bahan_stoks[i]))
        {
            continue;
        }
        /* code */
        cout << kode_stoks[i];
        for (int j = kode_stoks[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }

        cout << nama_stoks[i];
        for (int j = nama_stoks[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }
        cout << jumlah_stoks[i] << endl;
    }
}

void tambahBahanBaku()
{
    string kode, bahan;
    int jumlah;

    cout << "\nMasukan kode: ";
    cin >> kode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan jenis bahan: ";
    getline(cin, bahan);
    cout << "Masukan jumlah: ";
    cin >> jumlah;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (indexOfBahanSuplier(bahan) == -1)
    {
        cout << "\nMaaf bahan " << bahan << " tidak tersedia di data suplier" << endl;
        return;
    }

    int x = indexOfStock(bahan, kode);
    if (x != -1)
    {
        jumlah_stoks[x] += jumlah;
        cout << "\nHoreyy stock " << bahan << " berhasil di perbaharui...." << endl;
    }
    else if (x == -1 && size_stoks > current_position_stok)
    {
        int y = indexOfStockBahan(bahan);
        if (y != -1)
        {
            cout << "\ntidak bisa menambah " << bahan << " bahan tersebut telah terinput dengan kode " << kode_stoks[y] << endl;
            return;
        }

        int n = indexOfStockKode(kode);

        if (n != -1)
        {
            cout << "\ntidak bisa menambah " << bahan << " dengan kode " << kode << " karena kode tersebut telah terinput dengan bahan yang berbeda " << endl;
            return;
        }

        kode_stoks[current_position_stok] = kode;
        nama_stoks[current_position_stok] = bahan;
        jumlah_stoks[current_position_stok] = jumlah;
        status_bahan_stoks[current_position_stok] = true;

        current_position_stok++;

        cout << "\nHoreyy stock " << bahan << " berhasil di ditambah...." << endl;
    }
}

string converStatus(int num)
{
    string status = "";
    switch (num)
    {
    case 0:
        status = "Draft";
        break;
    case 1:
        status = "Mulai";
        break;
    case 2:
        status = "Proses";
        break;
    case 3:
        status = "Selesai";
        break;
    default:
        break;
    }

    return status;
}

void printProyek(int from, int end, int status)
{
    cout << "" << endl;
    cout << "No  Kode                Jenis pesanan       Deskripsi                     Tanggal mulai            Tanggal selesai         Status pesanan" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;

    int nomor = 1;
    for (int i = from; i < end; i++)
    {
        if (status == 1 && (status_proyeks[i] == 0 || status_proyeks[i] == 3))
        {
            continue;
        }
        cout << nomor;
        string number = to_string(nomor);
        for (int j = number.length(); j < 4; j++)
        {
            /* code */
            cout << " ";
        }

        /* code */
        cout << kode_proyeks[i];
        for (int j = kode_proyeks[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }

        cout << pesanans[i];
        for (int j = pesanans[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }

        cout << deskripsi_proyeks[i];
        for (int j = deskripsi_proyeks[i].length(); j < 30; j++)
        {
            /* code */
            cout << " ";
        }

        string startDate = formatDate(start_tanggal_proyeks[i], start_bulan_proyeks[i], start_tahun_proyeks[i]);
        cout << startDate;
         for (int j = startDate.length(); j < 25; j++)
        {
            /* code */
            cout << " ";
        }

        string endDate = formatDate(end_tanggal_proyeks[i], end_bulan_proyeks[i], end_tahun_proyeks[i]);

        cout << endDate;
        for (int j = endDate.length(); j < 25; j++)
        {
            /* code */
            cout << " ";
        }

        cout << converStatus(status_proyeks[i]);

        nomor++;
    }
}

void printProyekIdStatus()
{
    cout << "" << endl;
    cout << "Id  Kode                Jenis pesanan       Status pesanan" << endl;
    cout << "----------------------------------------------------------" << endl;

    for (int i = 0; i < current_position_proyek; i++)
    {
        string id = to_string(i + 1);
        cout << id;
        for (int j = id.length(); j < 4; j++)
        {
            /* code */
            cout << " ";
        }

        /* code */
        cout << kode_proyeks[i];
        for (int j = kode_proyeks[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }

        cout << pesanans[i];
        for (int j = pesanans[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }

        cout << converStatus(status_proyeks[i]);
    }
}


// print durasi proyeks
int calculateDurationInDays(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {
    tm startDate = {};
    startDate.tm_mday = startDay;       
    startDate.tm_mon = startMonth - 1;   
    startDate.tm_year = startYear - 1900;

    tm endDate = {};
    endDate.tm_mday = endDay;       
    endDate.tm_mon = endMonth - 1;   
    endDate.tm_year = endYear - 1900;


    time_t startTime = std::mktime(const_cast<std::tm*>(&startDate));
    time_t endTime = std::mktime(const_cast<std::tm*>(&endDate));

    return static_cast<int>(difftime(endTime, startTime) / (60 * 60 * 24));
}


bool isProjectDelayed(int endDay, int endMonth, int endYear) {
    tm endDate = {};
    endDate.tm_mday = endDay;       
    endDate.tm_mon = endMonth - 1;   
    endDate.tm_year = endYear - 1900;

    std::time_t endTime = std::mktime(const_cast<std::tm*>(&endDate));
    std::time_t currentTime = std::time(nullptr); // Waktu saat ini
    return currentTime > endTime; // true jika proyek terlambat
}

string convertStatusKeterlambatan(int endDay, int endMonth, int endYear) {
    if(isProjectDelayed(endDay, endMonth, endYear)) {
        return "Terlambat";
    } 

    return "Tepat Waktu";
}


void printDurasiProyek() {
     cout << "" << endl;
    cout << "Id  Kode                Jenis pesanan       Durasi       Status keterlambatan" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < current_position_proyek; i++)
    {
        string id = to_string(i + 1);
        cout << id;
        for (int j = id.length(); j < 4; j++)
        {
            /* code */
            cout << " ";
        }

        /* code */
        cout << kode_proyeks[i];
        for (int j = kode_proyeks[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }

        cout << pesanans[i];
        for (int j = pesanans[i].length(); j < 20; j++)
        {
            /* code */
            cout << " ";
        }

        cout << calculateDurationInDays(start_tanggal_proyeks[i], start_bulan_proyeks[i], start_tahun_proyeks[i], end_tanggal_proyeks[i], end_bulan_proyeks[i], end_tahun_proyeks[i] ) << " Hari";
        cout << "       ";
        cout << convertStatusKeterlambatan(end_tanggal_proyeks[i], end_bulan_proyeks[i], end_tahun_proyeks[i]);
    }
}

// fungsi manajemen proyek
void updatedStatusProyek()
{
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

    if (agree == 'y')
    {
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
    }
    else
    {
        cout << "\nGagal update status proyek: " << kode_proyeks[id] << endl;
    }

    // pesan berhasil
}

void printProyekAktif()
{
    printProyek(0, current_position_proyek, 1);
}
// fungsi manajemen proyek

void tambahDataProyek()
{
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
        if (inputTglStart > 0)
        {
            cout << "Masukan tanggal mulai lagi: " << endl;
        }
        else
        {
            cout << "Masukan tanggal mulai: " << endl;
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
    } while (!isValidDate(start_tanggal, start_bulan, start_tahun));

    do
    {
        if (inputTglEnd > 0)
        {
            cout << "Masukan tanggal selesai lagi: " << endl;
        }
        else
        {
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
    } while (!isValidDate(end_tanggal, end_bulan, end_tahun));


    if(!isStartDateBeforeEndDate(start_tanggal, start_bulan, start_tahun, end_tanggal, end_bulan, end_tahun)) {
        cout << "\nTanggal selesai tidak boleh lebih awal dari tanggal mulai!" << endl;
        return;
    }


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

    cout << "\nHoreyy proyek dengan kode " << kode << " berhasil di ditambah...." << endl;

    printProyek(current_position_proyek - 1, current_position_proyek, 0);
}

// fungsi manajemen bahan baku staff
bool validateKodeProyekAktif(string kode)
{

    for (int i = 0; i < current_position_proyek; i++)
    {
        /* code */
        if (kode_proyeks[i] == kode && (status_proyeks[i] == 1 || status_proyeks[i] == 2))
        {
            return true;
        }
    }

    return false;
}



bool validateStockExist(int idx, int qtyPermintaan)
{
    if (jumlah_stoks[idx] >= qtyPermintaan)
    {
        return true;
    }

    return false;
}

void recordPengeluaranBahan()
{
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

    if (!validateKodeProyekAktif(kode))
    {
        cout << "\nMaaf kode proyek yang anda pilih tidak tersedia....." << endl;
        return;
    }

    int idx = indexOfBahan(bahan);

    if (idx == -1)
    {
        cout << "\nMaaf bahan tidak tersedia di dalam gudang ....." << endl;
        return;
    }

    if (!validateStockExist(idx, jumlah))
    {
        cout << "\nMaaf jumlah bahan " << bahan << " saat ini tidak cukup ....." << endl;
        return;
    }

    jumlah_stoks[idx] -= jumlah;

    kode_proyek_stock_out[current_position_stock_out] = kode;
    bahan_stock_out[current_position_stock_out] = bahan;
    jumlah_stock_out[current_position_stock_out] = jumlah;
    current_position_stock_out++;

    cout << "\nHoreeeey kamu berhasil mengambil bahan " << bahan << " untuk proyek kode: " << kode << endl;
}

// fungsi manajemen bahan baku staff
void aksiMenuAdminProyek()
{
    int aksi;
    do
    {
        cout << "\n\nProyek "
             << "\n1. Tambah data"
             << "\n2. Lihat data"
             << "\n3. Durasi proyek"
             << "\n4. Kembali" << endl;

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
            printDurasiProyek();
            break;
        case 4:
            cout << "\nKembali ke menu admin!";
            break;
        default:
            break;
        }
    } while (aksi != 4);
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
             << "\n3. Non aktif suplier"
             << "\n4. Kembali" << endl;

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
            nonAktifSuplier();
            break;
        case 4:
            cout << "Kembali ke pilih menu admin!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid silakan pilih aksi kembali!" << endl;
        }

    } while (aksi != 4);
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
    } while (role != 3);

    return 0;
}