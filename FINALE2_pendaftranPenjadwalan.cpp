#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

void title(){
	system("color 0b");
	cout << "___________________________________________________________________________________" << endl;
	cout << endl;
	cout << "       [][][][  ][][][][ []   []  [][[]    []  []  []   []  []   []  [][[]         " << endl;
	cout << "     [][           []    []   []  []   []  []  []  []   []  []   []  []   []       " << endl;
	cout << "       [][][]      []    []   []  []   []  []  []  []===[]  []   []  [][[][        " << endl;
	cout << "            ][]    []    []   []  []   []    []    []   []  []   []  []   []       " << endl;
	cout << "      ][][][]      []     [[|]]   [][[]      []    []   []   [[|]]   [][[]         " << endl;
	cout << "___________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                          LEARNING COURSES AND MENTORING                           " << endl;
	cout << "___________________________________________________________________________________" << endl;	
}

void titleStu(){
	cout << "______________________________________________________________________________" << endl;
	cout << endl; 
	cout << "         [][][][  ][][][][ []   []  [][[]    [][][]  [][]  []  ][][][][       " << endl;
	cout << "       [][           []    []   []  []   []  []      [] [] []     []          " << endl;
	cout << "         [][][]      []    []   []  []   []  [][][]  []  [][]     []          " << endl;
	cout << "              ][]    []    []   []  []   []  []      []   []]     []          " << endl;
	cout << "        ][][][]      []     [[|]]   [][[]    [][][]  []    []     []          " << endl;
	cout << "______________________________________________________________________________" << endl;
	cout << "==============================================================================" << endl;
}

void titleAdm(){
	cout << "_____________________________________________________________________________" << endl;
	cout << endl; 
	cout << "                 [][]      [][[]    [][    ][]  [][][]  [][]  []             " << endl;
	cout << "                []  []     []   []  [] [][] []    []    [] [] []             " << endl;
	cout << "               [][][][]    []   []  []  []  []    []    []  [][]             " << endl;
	cout << "              []      []   []   []  []      []    []    []   []]             " << endl;
	cout << "             []        []  [][[]    []      []  [][][]  []    []             " << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "=============================================================================" << endl;
}

//struct for login interface
struct accRec{
	string fname;
	string lname;
	string pass;
	string cfrm_pass;
	string username;
};

//struct for interfaceMurid()
typedef struct{
	string drafted_user;
	string drafted_grade;
	string drafted_class;
	string drafted_schedule;
	char pilihan;
	char kelas;
	char jadwal;
	char jurusan;
}menu;


//membuat data struktur vektor dari file ke program (untuk akun-akun di file "user.txt")
vector <accRec> accountFromFile() {
	vector<accRec> accounts;
 	ifstream login("users.txt");
 	accRec record;
	// Read the integer score from the file
 	while(login >> record.username >> record.pass){
 		accounts.push_back(record);
	}
 	login.close();
	return accounts; // Return struct name
}

//membuat data struktur vektor dari file ke program (untuk searching username di file "pendaftaran.txt")
vector <menu> accountFromPendaftaran() {
	vector<menu> draftedAcc;
 	ifstream fileDA("pendaftaran.txt");
 	//untuk linking struct 
 	menu draft;
	// Read the integer score from the file
 	while(fileDA >> draft.drafted_user){
 		draftedAcc.push_back(draft);
	}
 	fileDA.close();
	return draftedAcc; // Return struct name
}

//mengecek row buat user, grade, kelas, jadwal dari file
vector <menu> jadwalFromPendaftaran() {
	vector<menu> jadwal;
 	ifstream fileSch("pendaftaran.txt");
    
	string line;
    // Read each line from the file
    while (getline(fileSch, line)) {
        menu draftedSch;
        stringstream ss(line);
        ss >> draftedSch.drafted_user >> draftedSch.drafted_grade >> draftedSch.drafted_class >> draftedSch.drafted_schedule;
        jadwal.push_back(draftedSch);
    }
    fileSch.close();
    return jadwal;
}


//searching and scanning file buat cari username & password yang sama
bool checkLogin(const string& loginuser, const string& loginpass) { 
	vector<accRec> accounts = accountFromFile();
 	// Check if the username and password match the stored data
	for (int i = 0; i < accounts.size(); i++) {
		if (loginuser == accounts[i].username && loginpass == accounts[i].pass) {
		return true;
  		}
	}
	return false;
}

//return username & password ekslusif untuk admin
bool checkLoginAdmin(const string& loginuser, const string& loginpass) {
	// Check if the username and password match the assigned admin data
 	if (loginuser == "CentralAdmin01" && loginpass == "fivalavide") {
  		return true;
 	}
	return false;
}

//searching and scanning file buat cari username yang sama (kalau sama bakal return true, artinya sudah ada akun)
bool checkAccAvailability(const string& loginuser) { 
	vector<accRec> accounts = accountFromFile();
 	// Check if the username match the stored data
	for (int i = 0; i < accounts.size(); i++) {
		if (loginuser == accounts[i].username) {
		return false;
  		}
	}
	return true;
}

bool checkDraftedAcc(const string& loginuser) { 
	vector<menu> draftedAcc = accountFromPendaftaran();
 	// Check if the username match the stored data
	for (int i = 0; i < draftedAcc.size(); i++) {
		if (loginuser == draftedAcc[i].drafted_user) {
		return false;
  		}
	}
	return true;
}

void checkDraftedSchedule(const string& loginuser) { 
	vector<menu> jadwal = jadwalFromPendaftaran();
	for(int i=0; i < jadwal.size(); i++){
		if(jadwal[i].drafted_user == loginuser){
			cout << "USERNAME : " << jadwal[i].drafted_user << endl;
			cout << "Kelas : " << jadwal[i].drafted_class << " " << jadwal[i].drafted_grade << endl;
			cout << endl;
			cout << "Jadwal Anda:\n";
			if(jadwal[i].drafted_schedule == "jadSD1"){
				cout << "   [HARI]    [PELAJARAN SD]        [WAKTU]     " << endl;
				cout << "===============================================" << endl;
                cout << "1. Senin    Bahasa Indonesia   13.00 - 14.00   " << endl;
                cout << endl;
                cout << "   Selasa   Bahasa Inggris     13.00 - 14.00   " << endl;
                cout << endl;
                cout << "   Kamis    Matematika         13.00 - 14.00   " << endl;
                cout << "===============================================" << endl;
			}
			else if(jadwal[i].drafted_schedule == "jadSD2"){
				cout << "   [HARI]    [PELAJARAN SD]        [WAKTU]     " << endl;
				cout << "===============================================" << endl;
                cout << "2. Selasa   Bahasa Indonesia   13.00 - 14.00   " << endl;
                cout << endl;
                cout << "   Kamis    Bahasa Inggris     13.00 - 14.00   " << endl;
                cout << endl;
                cout << "   Jumat    Matematika         13.00 - 14.00   " << endl;
				cout << "===============================================" << endl;
			}
			else if(jadwal[i].drafted_schedule == "jadSD3"){
				cout << "   [HARI]    [PELAJARAN SD]        [WAKTU]     " << endl;
				cout << "===============================================" << endl;
                cout << "3. Senin    Bahasa Inggris     13.00 - 14.00   " << endl;
                cout << endl;
                cout << "   Rabu     Matematika         13.00 - 14.00   " << endl;
                cout << endl;
                cout << "   Jumat    Bahasa Indonesia   13.00 - 14.00   " << endl;
                cout << "===============================================" << endl;
			}
			else if(jadwal[i].drafted_schedule == "jadSMP1"){
				cout << "   [HARI]     [PELAJARAN SMP]       [WAKTU]      " << endl;
				cout << "=================================================" << endl;
				cout << "1. Senin      Bahasa Inggris     15.00 - 16.20   " << endl;
				cout << "              IPS                16.40 - 18.00   " << endl;
				cout << endl;
				cout << "   Selasa     Matematika         15.00 - 16.20   " << endl;
				cout << endl;
				cout << "   Kamis      IPA                15.00 - 16.20   " << endl;
				cout << "              Bahasa Indonesia   16.40 - 18.00   " << endl;
				cout << "=================================================" << endl;		
			}
			else if(jadwal[i].drafted_schedule == "jadSMP2"){
				cout << "   [HARI]     [PELAJARAN SMP]       [WAKTU]      " << endl;
				cout << "=================================================" << endl;
				cout << "2. Selasa     Bahasa Inggris     15.00 - 16.20   " << endl;
				cout << "              IPS                16.40 - 18.00   " << endl;
				cout << endl;
				cout << "   Kamis      Matematika         15.00 - 16.20   " << endl;
				cout << endl;
				cout << "   Jumat      IPA                15.00 - 16.20   " << endl;
				cout << "              Bahasa Indonesia   16.40 - 18.00   " << endl;
				cout << "=================================================" << endl;			
			}
			else if(jadwal[i].drafted_schedule == "jadSMP3"){
				cout << "   [HARI]     [PELAJARAN SMP]       [WAKTU]      " << endl;
				cout << "=================================================" << endl;
				cout << "3. Senin      IPS                15.00 - 16.20   " << endl;
				cout << "              Bahasa Inggris     16.40 - 18.00   " << endl;
				cout << endl;
				cout << "   Rabu       IPA                15.00 - 16.20   " << endl;
				cout << "              Bahasa Indonesia   16.40 - 18.00   " << endl;
				cout << endl;
				cout << "   Kamis      Matematika         15.00 - 16.20   " << endl;
				cout << "=================================================" << endl;			
			}
			else if(jadwal[i].drafted_schedule == "jadSMA_IPA1"){
				cout << "   [HARI]     [PELAJARAN SMA-IPA]     [WAKTU]     " << endl;
				cout << "==================================================" << endl;
				cout << "1. Senin        Bahasa Inggris     16.00 - 17.30  " << endl;
				cout << "                Kimia              18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Selasa       Matematika         16.00 - 17.30  " << endl;
				cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Kamis        Fisika             16.00 - 17.30  " << endl;
				cout << "                Biologi            18.15 - 19.45  " << endl;
				cout << "==================================================" << endl;		
			}
			else if(jadwal[i].drafted_schedule == "jadSMA_IPA2"){
				cout << "   [HARI]     [PELAJARAN SMA-IPA]     [WAKTU]     " << endl;
				cout << "==================================================" << endl;
				cout << "2. Selasa       Bahasa Inggris     16.00 - 17.30  " << endl;
				cout << "                Kimia              18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Kamis        Matematika         16.00 - 17.30  " << endl;
				cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Jumat        Fisika             16.00 - 17.30  " << endl;
				cout << "                Biologi            18.15 - 19.45  " << endl;
				cout << "==================================================" << endl;			
			}
			else if(jadwal[i].drafted_schedule == "jadSMA_IPA3"){
				cout << "   [HARI]     [PELAJARAN SMA-IPA]     [WAKTU]     " << endl;
				cout << "==================================================" << endl;
				cout << "3. Senin        Matematika         16.00 - 17.30  " << endl;
				cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Rabu         Bahasa Inggris     16.00 - 17.30  " << endl;
				cout << "                Kimia              18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Kamis        Biologi            16.00 - 17.30  " << endl;
				cout << "                Fisika             18.15 - 19.45  " << endl;
               	cout << "==================================================" << endl;				
			}
			else if(jadwal[i].drafted_schedule == "jadSMA_IPS1"){
				cout << "   [HARI]     [PELAJARAN SMA-IPS]     [WAKTU]     " << endl;
				cout << "==================================================" << endl;
				cout << "1. Senin        Bahasa Inggris     16.00 - 17.30  " << endl;
				cout << "                Sejarah            18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Selasa       Matematika         16.00 - 17.30  " << endl;
				cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Kamis        Ekonomi            16.00 - 17.30  " << endl;
				cout << "                Sosiologi          18.15 - 19.45  " << endl;
				cout << "==================================================" << endl;	
			}
			else if(jadwal[i].drafted_schedule == "jadSMA_IPS2"){
				cout << "   [HARI]     [PELAJARAN SMA-IPS]     [WAKTU]     " << endl;
				cout << "==================================================" << endl;
				cout << "2. Selasa       Bahasa Inggris     16.00 - 17.30  " << endl;
				cout << "                Sejarah            18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Kamis        Matematika         16.00 - 17.30  " << endl;
				cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Jumat        Ekonomi            16.00 - 17.30  " << endl;
				cout << "                Sosiologi          18.15 - 19.45  " << endl;
				cout << "==================================================" << endl;				
			}
			else if(jadwal[i].drafted_schedule == "jadSMA_IPS3"){
				cout << "   [HARI]     [PELAJARAN SMA-IPS]     [WAKTU]     " << endl;
				cout << "==================================================" << endl;
				cout << "3. Senin        Matematika         16.00 - 17.30  " << endl;
				cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Rabu         Bahasa Inggris     16.00 - 17.30  " << endl;
				cout << "                Sejarah            18.15 - 19.45  " << endl;
				cout << endl;
				cout << "   Kamis        Sosiologi          16.00 - 17.30  " << endl;
				cout << "                Ekonomi            18.15 - 19.45  " << endl;
	        	cout << "==================================================" << endl;				
			}										
		}
	}
}


int pendaftaranMurid(string loginuser){
	//declare variable awal
	menu data;
    char pilihan, kelas, jadwal, jurusan;
    
	while (true) {
    	// Menu utama 
    	cout << "Pilihan Pendidikan Bimbel:";
    	cout << "\n1. SD";
		cout << "\n2. SMP";
    	cout << "\n3. SMA";
    	cout << "\n4. Kembali";
    	cout << "\nMasukkan Pilihan Anda: "; cin >> data.pilihan;
    	system("cls");
		
		//------------------------------------------PILIHAN SD------------------------------------------
        // cek pilihan menu utama
        if (data.pilihan == '1') {
        	ofstream daftar1("pendaftaran.txt", ios::app);
        	daftar1 << endl << loginuser << " SD";
        	
			while (true) {
                // pilihan kelas SD
                cout << "\nPilihan Kelas Bimbel untuk SD:\n";
                cout << "1. Kelas 4 SD | Rp. 6.500.000\n";
                cout << "2. Kelas 5 SD | Rp. 6.900.000\n";
                cout << "3. Kelas 6 SD | Rp. 7.300.000\n";
                cout << "Masukkan Pilihan (1/2/3): "; cin >> data.kelas;
                
                if(data.kelas == '1'){
                	daftar1 << " kel_4";
				}
				else if(data.kelas == '2'){
					daftar1 << " kel_5";
				}
                else if(data.kelas == '3'){
                	daftar1 << " kel_6";
				}              
                system("cls");
				
                if (data.kelas == '1' || data.kelas == '2' || data.kelas == '3') {
                    // jadwal bimbel SD
                    while (true) {
                        cout << "Jadwal Bimbingan Belajar SD:\n";
                        cout << endl;
                        cout << "   [HARI]      [PELAJARAN]        [WAKTU]      " << endl;
						cout << "===============================================" << endl;
                        cout << "1. Senin    Bahasa Indonesia   13.00 - 14.00   " << endl;
                        cout << endl;
                        cout << "   Selasa   Bahasa Inggris     13.00 - 14.00   " << endl;
                        cout << endl;
                        cout << "   Kamis    Matematika         13.00 - 14.00   " << endl;
                        cout << "===============================================" << endl;
                        cout << "===============================================" << endl;
                        cout << "2. Selasa   Bahasa Indonesia   13.00 - 14.00   " << endl;
                        cout << endl;
                        cout << "   Kamis    Bahasa Inggris     13.00 - 14.00   " << endl;
                        cout << endl;
                        cout << "   Jumat    Matematika         13.00 - 14.00   " << endl;
						cout << "===============================================" << endl;
						cout << "===============================================" << endl;
                        cout << "3. Senin    Bahasa Inggris     13.00 - 14.00   " << endl;
                        cout << endl;
                        cout << "   Rabu     Matematika         13.00 - 14.00   " << endl;
                        cout << endl;
                        cout << "   Jumat    Bahasa Indonesia   13.00 - 14.00   " << endl;
                        cout << "===============================================" << endl;

                        cout << "Masukkan Pilihan Jadwal (1/2/3): "; cin >> data.jadwal;
                        system("cls");

                        if (data.jadwal == '1') {
                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
                            daftar1 << " jadSD1";
                            system("pause");
                            break;
                        }else if (data.jadwal == '2') {
                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
                            daftar1 << " jadSD2";
                            system("pause");
                            break;
                        }else if (data.jadwal == '3') {
                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
                            daftar1 << " jadSD3";
                            system("pause");
                            break;
                        }else {
                        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "Pilihan Jadwal Tidak Valid, Coba Lagi." << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                            cout << endl;
                        }
                    }
                    break; // Keluar dari loop kelas setelah jadwal dipilih
                }
                else{
                	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "Pilihan Kelas Tidak Valid, Coba Lagi." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << endl;
				}
			}
            daftar1.close(); 	
            
		}
		//------------------------------------------PILIHAN SMP------------------------------------------
		else if (data.pilihan == '2'){
		    ofstream daftar1("pendaftaran.txt", ios::app);
        	daftar1 << endl << loginuser << " SMP";
        	
			while(true) {
				//pilihan kelas SMP
				cout << "Pilihan Kelas Bimbel untuk SMP" << endl;
				cout << "1. Kelas 7 SMP | Rp. 8.200.000" << endl;
				cout << "2. Kelas 8 SMP | Rp. 8.700.000" << endl;
				cout << "3. Kelas 9 SMP | Rp. 9.200.000" << endl;
				cout << "Masukkan Pilihan (1/2/3) : "; cin >> data.kelas;
				
				if(data.kelas == '1'){
                	daftar1 << " kel_7";
				}
				else if(data.kelas == '2'){
					daftar1 << " kel_8";
				}
                else if(data.kelas == '3'){
                	daftar1 << " kel_9";
				}
				system("cls");
				
				if (data.kelas == '1' || data.kelas == '2' || data.kelas == '3') {
					//jadwal bimbel SMP
					while(true) {
						cout << "Jadwal Bimbingan Belajar SMP" << endl << endl;
						cout << "   [HARI]      [PELAJARAN]          [WAKTU]      " << endl;
						cout << "=================================================" << endl;
						cout << "1. Senin      Bahasa Inggris     15.00 - 16.20   " << endl;
						cout << "              IPS                16.40 - 18.00   " << endl;
						cout << endl;
						cout << "   Selasa     Matematika         15.00 - 16.20   " << endl;
						cout << endl;
						cout << "   Kamis      IPA                15.00 - 16.20   " << endl;
						cout << "              Bahasa Indonesia   16.40 - 18.00   " << endl;
						cout << "=================================================" << endl;
						cout << "=================================================" << endl;
						cout << "2. Selasa     Bahasa Inggris     15.00 - 16.20   " << endl;
						cout << "              IPS                16.40 - 18.00   " << endl;
						cout << endl;
						cout << "   Kamis      Matematika         15.00 - 16.20   " << endl;
						cout << endl;
						cout << "   Jumat      IPA                15.00 - 16.20   " << endl;
						cout << "              Bahasa Indonesia   16.40 - 18.00   " << endl;
						cout << "=================================================" << endl;
						cout << "=================================================" << endl;
						cout << "3. Senin      IPS                15.00 - 16.20   " << endl;
						cout << "              Bahasa Inggris     16.40 - 18.00   " << endl;
						cout << endl;
						cout << "   Rabu       IPA                15.00 - 16.20   " << endl;
						cout << "              Bahasa Indonesia   16.40 - 18.00   " << endl;
						cout << endl;
						cout << "   Kamis      Matematika         15.00 - 16.20   " << endl;
						cout << "=================================================" << endl;
						cout << "Masukkan Pilihan Jadwal (1/2/3) : "; cin >> data.jadwal;
						system("cls");
					
						if (data.jadwal == '1') {
                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
                            daftar1 << " jadSMP1";
                            system("pause");
                            break;
                        }else if (data.jadwal == '2') {
                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
                            daftar1 << " jadSMP2";
                            system("pause");
                            break;
                        }else if (data.jadwal == '3') {
                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
                            daftar1 << " jadSMP3";
                            system("pause");
                            break;
                        }else {
                        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "Pilihan Jadwal Tidak Valid, Coba Lagi." << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                            cout << endl;
                        }
					} // while
					break; // Keluar dari loop kelas setelah jadwal dipilih
				} // if
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "Pilihan Kelas Tidak Valid, Coba Lagi." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << endl;
				}
			} //while
			daftar1.close();
			
		}
		//------------------------------------------PILIHAN SMA------------------------------------------
		else if (data.pilihan == '3'){
			ofstream daftar1("pendaftaran.txt", ios::app);
        	daftar1 << endl << loginuser << " SMA";
        	
			while (true) {
				cout << "Pilihan Kelas Bimbel untuk SMA:\n";
				cout << "1. Kelas 10 SMA | Rp. 9.200.000\n";
				cout << "2. Kelas 11 SMA | Rp. 9.700.000\n";
				cout << "3. Kelas 12 SMA | Rp. 10.400.000\n";
				cout << "Masukkan Pilihan (1/2/3): "; cin >> data.kelas;
				
				if(data.kelas == '1'){
                	daftar1 << " kel_10";
				}
				else if(data.kelas == '2'){
					daftar1 << " kel_11";
				}
                else if(data.kelas == '3'){
                	daftar1 << " kel_12";
				}
				
				system("cls");
				
				if (data.kelas == '1' || data.kelas == '2' || data.kelas == '3') {
					while (true) {
				    	cout << "Pilih Jurusan:\n";
				    	cout << "1. IPA\n";
				    	cout << "2. IPS\n";
				    	cout << "Masukkan Pilihan (1/2): "; cin >> data.jurusan;
				        				
				    	system("cls");
				        
				            if (data.jurusan == '1') {
				            	// Loop pemilihan jadwal SMA IPA
			                    while (true) {
			                    	cout << "Jadwal Bimbingan Belajar SMA Jurusan IPA" << endl << endl;
									cout << "   [HARI]        [PELAJARAN]          [WAKTU]     " << endl;
									cout << "==================================================" << endl;
									cout << "1. Senin        Bahasa Inggris     16.00 - 17.30  " << endl;
									cout << "                Kimia              18.15 - 19.45  " << endl;
									cout << endl;
									cout << "   Selasa       Matematika         16.00 - 17.30  " << endl;
									cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
									cout << endl;
									cout << "   Kamis        Fisika             16.00 - 17.30  " << endl;
									cout << "                Biologi            18.15 - 19.45  " << endl;
									cout << "==================================================" << endl;
									cout << "==================================================" << endl;
									cout << "2. Selasa       Bahasa Inggris     16.00 - 17.30  " << endl;
									cout << "                Kimia              18.15 - 19.45  " << endl;
									cout << endl;
									cout << "   Kamis        Matematika         16.00 - 17.30  " << endl;
									cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
									cout << endl;
									cout << "   Jumat        Fisika             16.00 - 17.30  " << endl;
									cout << "                Biologi            18.15 - 19.45  " << endl;
									cout << "==================================================" << endl;
									cout << "==================================================" << endl;
									cout << "3. Senin        Matematika         16.00 - 17.30  " << endl;
									cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
									cout << endl;
									cout << "   Rabu         Bahasa Inggris     16.00 - 17.30  " << endl;
									cout << "                Kimia              18.15 - 19.45  " << endl;
									cout << endl;
									cout << "   Kamis        Biologi            16.00 - 17.30  " << endl;
									cout << "                Fisika             18.15 - 19.45  " << endl;
			                    	cout << "==================================================" << endl;
		                        	cout << "Masukkan Pilihan Jadwal (1/2/3): "; cin >> data.jadwal;
				                	system("cls");
				                	
				                        if (data.jadwal == '1') {
                            				cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
                            				daftar1 << " jadSMA_IPA1";
                            				system("pause");
                            				break;
				                        } else if (data.jadwal == '2') {
				                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
				                            daftar1 << " jadSMA_IPA2";
				                            system("pause");
				                            break;
				                        } else if (data.jadwal == '3') {
				                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
				                            daftar1 << " jadSMA_IPA3";
				                            system("pause");
				                            break;
				                        } else {
				                        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				                            cout << "Pilihan Jadwal Tidak Valid, Coba Lagi.\n";
				                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				                            cout << endl;
				                        }
				                    }
				                    break; //break loop IPA	
				                    
				                } else if (data.jurusan == '2') {	
				                    // Loop pemilihan jadwal SMA IPS
				                    while (true) {
				                    	cout << "Jadwal Bimbingan Belajar SMA Jurusan IPS" << endl << endl;
										cout << "   [HARI]        [PELAJARAN]          [WAKTU]     " << endl;
										cout << "==================================================" << endl;
										cout << "1. Senin        Bahasa Inggris     16.00 - 17.30  " << endl;
										cout << "                Sejarah            18.15 - 19.45  " << endl;
										cout << endl;
										cout << "   Selasa       Matematika         16.00 - 17.30  " << endl;
										cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
										cout << endl;
										cout << "   Kamis        Ekonomi            16.00 - 17.30  " << endl;
										cout << "                Sosiologi          18.15 - 19.45  " << endl;
										cout << "==================================================" << endl;
										cout << "==================================================" << endl;
										cout << "2. Selasa       Bahasa Inggris     16.00 - 17.30  " << endl;
										cout << "                Sejarah            18.15 - 19.45  " << endl;
										cout << endl;
										cout << "   Kamis        Matematika         16.00 - 17.30  " << endl;
										cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
										cout << endl;
										cout << "   Jumat        Ekonomi            16.00 - 17.30  " << endl;
										cout << "                Sosiologi          18.15 - 19.45  " << endl;
										cout << "==================================================" << endl;
										cout << "==================================================" << endl;
										cout << "3. Senin        Matematika         16.00 - 17.30  " << endl;
										cout << "                Bahasa Indonesia   18.15 - 19.45  " << endl;
										cout << endl;
										cout << "   Rabu         Bahasa Inggris     16.00 - 17.30  " << endl;
										cout << "                Sejarah            18.15 - 19.45  " << endl;
										cout << endl;
										cout << "   Kamis        Sosiologi          16.00 - 17.30  " << endl;
										cout << "                Ekonomi            18.15 - 19.45  " << endl;
				                    	cout << "==================================================" << endl;
			                        	cout << "Masukkan Pilihan Jadwal (1/2/3): "; cin >> data.jadwal;
				                        system("cls");
				
				                        if (data.jadwal == '1') {
				                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
				                            daftar1 << " jadSMA_IPS1";
				                            system("pause");
				                            break;
				                        } else if (data.jadwal == '2') {
				                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
				                            daftar1 << " jadSMA_IPS2";
				                            system("pause");
				                            break;
				                        } else if (data.jadwal == '3') {
				                            cout << "Anda Sudah Terdaftar. Silahkan lihat jadwal Anda." << endl;
				                            daftar1 << " jadSMA_IPS3";
				                            system("pause");
				                            break;
				                        } else {
				                        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				                            cout << "Pilihan Jadwal Tidak Valid, Coba Lagi.\n";
				                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				                            cout << endl;
				                        }	
				                    }
				                    break; //break loop IPS
				                }
								else {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				                    cout << "Pilihan Jurusan Tidak Valid, Silahkan Masukkan Pilihan Kembali.\n";
				                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				                    cout << endl;
				                }
				        	} // end while loop jurusan
				            break;
				    	} // end IF pilihan kelas
				    	else{
				    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				    		cout << "Pilihan Jurusan Tidak Valid, Coba Lagi." << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
							cout << endl;
						} //end dari ELSE dari IF pilihan kelas
				    	daftar1.close();
					} // while
		} //end dari IF pilihan SMA pusat
		//------------------------------------------PILIHAN EXIT-----------------------------------------
		else if (data.pilihan == '4'){
            break;
    	}
    	//------------------------------------------PILIHAN INVALID----------------------------------------------
    	else {
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "Pilihan Invalid, Silahkan Coba Lagi.\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            cout << endl;
            continue;
        }
        break; //exit while loop awal pilihan SD, SMP, SMA
    }
}

int interfaceAdmin(){
	system("cls");
	size_t va, vs;
	int piladm = 0, piladm_sch = 0;
	
		while(piladm != 3){
			titleAdm(); //panggil title admin
	 		cout << "Selamat datang Administrator!" << endl;
	 		cout << endl;
				
	 		cout << "Pilih Aksi Selanjutnya:";
	       	cout << "\n1. Lihat Daftar Akun Murid";
        	cout << "\n2. Lihat Jadwal Daftar Murid";
        	cout << "\n3. Exit";
        	cout << endl;
        	cout << "\nMasukkan Pilihan : "; cin >> piladm;
	 			
	 			if(piladm == 1){
	 					system("cls");
						vector<accRec> accounts = accountFromFile(); //<----- call vector buat data dari file
						//menampilkan data dari file ke console
						cout << "[USERNAME]          [PASSWORD]" << endl;
						for (int i = 0; i < accounts.size(); i++) {
							cout << accounts[i].username << "\t" << accounts[i].pass << endl;
	  					}
							cout << endl;
							system("pause");
							system("cls");
							interfaceAdmin();
			        		break;					
				}
				
				else if(piladm == 2){
	 					system("cls");
						vector<menu> jadwal = jadwalFromPendaftaran(); //<----- call vector buat data dari file
						//menampilkan data dari file ke console
						cout << "[USERNAME]    [GRADE]   [CLASS]  [JADWAL]" << endl;
						for (int i = 0; i < jadwal.size(); i++) {
							cout << jadwal[i].drafted_user << "\t" << jadwal[i].drafted_grade << "\t"
								 << jadwal[i].drafted_class << "\t" << jadwal[i].drafted_schedule << endl;
	  					}
	  						cout << endl;
			        		system("pause");
							system("cls");
							interfaceAdmin();
			        		break;
				}
				
				else if(piladm == 3){
					system("cls");
					cout << "[Program dikeluarkan]" << endl;
					break;
					return 0; //keluar dari loop dan masuk ke function					
				}
				
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        			cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
        			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        			system("pause");
        			system("cls");					
				}
			}
}

int interfaceMurid(string loginuser){
			system("cls");
			int pilmur = 0;
	 		while(pilmur != 3){
				titleStu(); //panggil title student
	 			cout << "Selamat datang " << loginuser << "!" << endl;
	 			cout << endl;
				
	 			cout << "Pilih Aksi Selanjutnya:";
	       		cout << "\n1. Pendaftaran";
        		cout << "\n2. Lihat Jadwal";
        		cout << "\n3. Exit";
        		cout << "\nMasukkan Pilihan : "; cin >> pilmur;
	 			
	 			if(pilmur == 1){
	 				if(checkDraftedAcc(loginuser)){       //<---- return true/false, if true akan jalanin pendaftaran
	 					system("cls");
	 					pendaftaranMurid(loginuser);
	 					interfaceMurid(loginuser);        //<--- looping fungsi UI murid <--- return username
						break;
					}
					else{
						cout << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << "Anda tidak bisa memilih jadwal lebih dari sekali, silahkan kembali dan lihat jadwal Anda." << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						system("pause");
						system("cls");
						interfaceMurid(loginuser);
						break; //keluar dari loop setelah sudah exit program
					}

				}
				else if(pilmur == 2){
					//for loop pembacaan data devisi SD, SMP, SMA dan read file pusat
					system("cls");
					if(checkDraftedAcc(loginuser)){
						cout << "[Sepertinya Anda belum memilih jadwal]" << endl;
						cout << "Silahkan mendaftar terlebih dahulu..." << endl << endl;
						system("pause");
						system("cls");
						interfaceMurid(loginuser); //<--- looping fungsi UI murid <--- return username
						break;
					}
					else{
						checkDraftedSchedule(loginuser);
						system("pause");
						system("cls");
						interfaceMurid(loginuser); //<--- looping fungsi UI murid <--- return username
						break;
					}
				}
				else if(pilmur == 3){
					system("cls");
					cout << "[Program dikeluarkan]" << endl;
					return 0; //keluar dari loop dan masuk ke function	
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        			system("pause");
        			system("cls");
        		}
			}
}



int main(){
	int pick, count = 0;
	const int maxtemp = 3;
	
	while(pick != 1 && pick != 2 && pick !=3){
		title();
		cout << endl;
		cout << "Silahkan Pilih Opsi di bawah ini:" << endl;
		cout << "1. Login / Sign In" << endl;
		cout << "2. Sign Up" << endl;
		cout << "3. Exit" << endl;
		cout << "Masukan angka: "; cin >> pick;
		
		//LOGIN
		if(pick == 1){
			while(count < maxtemp){
				system("cls");
				cout << "=========================" << endl;
				cout << "     LOGIN / SIGN IN     " << endl;
				cout << "=========================" << endl;
				
				string loginuser, loginpass;
				cout << "Masukan Username: "; cin >> loginuser;
				cout << "Masukan Password: ";
			
			
			//ganti character PASSWORD jadi tanda bintang (*)
			char ch;
			while (true) {
    			ch = _getch(); 
    			if (ch == 13) { 
     				break;
    			} else if (ch == 8) { 
     				if (loginpass.length() > 0) {
      					loginpass.resize(loginpass.length() - 1); 
      					cout << "\b \b";
			     	}
    			} else {
      				loginpass.push_back(ch);  
      				cout << "*";  
    				}
   			}
   			
   			
   		//LOGIN MURID
   		if (checkLogin(loginuser, loginpass)) {
   			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
	 		cout << "\nLogin berhasil!" << endl;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	 		cout << endl;
	 		system("pause");
	 		system("cls");
	 		
			interfaceMurid(loginuser);
     		break; //keluar program setelah exit pada bagian pendaftaran
     		
     	//LOGIN ADMINISTRATOR
		}else if(checkLoginAdmin(loginuser, loginpass)){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
			cout << "\nLogin berhasil!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << endl;
			system("pause");
	 		system("cls");
	 		system("color 0e");
	 		
	 		interfaceAdmin();
			break; //keluar dari loop dan masuk ke function
			
    	}else {
    		count++;
     		cout << "\nUsername atau password yang dimasukkan salah." << endl;
     		system("color 0c");
			system("pause");
			system("cls");
			system("color 0b");
     		if(count >= maxtemp){
     			system("color 0c");
				cout << "Anda salah memasukkan username atau password sebanyak 3 kali, program ditutup." << endl;
				return 0;
			}
    	}
	}
	
		//SIGN UP
		} else if(pick == 2){
			system("cls");
			
			char ch;
			accRec record;
			do{
			cout << "=========================" << endl;
			cout << "         SIGN UP         " << endl;
			cout << "=========================" << endl;
			cout << "Pembuatan Akun Baru" << endl;
			cin.ignore();
			accRec record;
			cout << "First Name      : "; cin >> record.fname;
			cout << "Last Name       : "; cin >> record.lname;
			record.username = record.fname + "_" + record.lname;
			
			//untuk mengecek apakah ada akun duplikat
			if(checkAccAvailability(record.username)){
				cout << "Password (Min 8 Char.) : "; 
				while (true) {
    			ch = _getch(); 
    			if (ch == 13) { 
     				break;
    			} else if (ch == 8) { 
     				if (record.pass.length() > 0) {
      					record.pass.resize(record.pass.length() - 1); 
      					cout << "\b \b";
			     	}
    			} else {
      				record.pass.push_back(ch);  
      				cout << "*";  
    				}
   			}
   		cout << endl;
   			
				while (record.pass.length() < 8) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "Minimal 8 karakter, silakan ulangi kembali." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << endl;
					cout << "Password (Min 8 Char.) : "; 
					while (true) {
    			ch = _getch(); 
    			if (ch == 13) { 
     				break;
    			} else if (ch == 8) { 
     				if (record.pass.length() > 0) {
      					record.pass.resize(record.pass.length() - 1); 
      					cout << "\b \b";
			     	}
    			} else {
      				record.pass.push_back(ch);  
      				cout << "*";  
    				}
   			}
   			cout << endl;
				}
				
    				cout << "Confirm Password       : ";
    				while (true) {
		    			ch = _getch(); 
		    			if (ch == 13) { 
		     				break;
		    			} else if (ch == 8) { 
		     				if (record.cfrm_pass.length() > 0) {
		      					record.cfrm_pass.resize(record.cfrm_pass.length() - 1); 
		      					cout << "\b \b";
					     	}
		    			} else {
		      				record.cfrm_pass.push_back(ch);  
		      				cout << "*";  
		    				}
		   			}
		   			cout << endl;
    				while(record.pass != record.cfrm_pass){
									cout << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
									cout << "Password tidak sesuai, tolong ulangi kembali" << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
									cout << endl;
									cout << "Confirm Password : ";
									while (true) {
					    			ch = _getch(); 
					    			if (ch == 13) { 
					     				break;
					    			} else if (ch == 8) { 
					     				if (record.cfrm_pass.length() > 0) {
					      					record.cfrm_pass.resize(record.cfrm_pass.length() - 1); 
					      					cout << "\b \b";
								     	}
					    			} else {
					      				record.cfrm_pass.push_back(ch);  
					      				cout << "*";  
					    				}
					   			}
					   			cout << endl;
    				}
    				
    		if(record.pass == record.cfrm_pass){
							cout << endl;
							cout << "Akun berhasil dibuat, silahkan login ulang.";
							cout << endl;
							cout << "------[ USERNAME ANDA : ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << record.username;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
							cout << " ]------" << endl;
								 
							cout << endl;
							cout << "-----------------------------------------" << endl;		
							ofstream signupfile("users.txt", ios::app);
								signupfile << record.username << " " << record.pass << endl;
					   			signupfile.close();
								system("pause");
								system("cls");
								main();
								break;
						}
							
			} else {
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //ganti warna text jadi MERAH
        		cout << "Username sudah diambil. Silahkan mencoba username yang berbeda." << endl;
        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // ganti warna text jadi BIRU MUDA
        		system("pause");
				system("cls");
	    }
	    
	} while(checkAccAvailability(record.username) == true);
	

		//EXIT PROGRAM
		} else if(pick == 3){
			system("cls");
			cout << "[Program dikeluarkan]";
			return 0;
		
		//CONDITION IF NOTHING IS TRUE
		} else{
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //ganti warna text jadi MERAH
			cout << "Pilihan Invalid, tolong ulangi kembali." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // ganti warna text jadi BIRU MUDA
			system("pause");
			system("cls");
		}
	}

    return 0;
}



//program ini dibuat oleh partisipasi semua anggota kelompok menggunakan ilmu dan kemampuan sendiri, serta bantuan asdos (ko Teddy & ko Gerrand) dalam pengembangan fitur-fitur seperti 
//mengganti char menjadi "*" menggunakan library <conio.h> dengan syntax getch(). Sumber-sumber lainnya meliputi:
// - https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
// - https://www.youtube.com/watch?v=pbvp6ZNXWqw
