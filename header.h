#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

//struktur untuk menyimpan informasi tentang siswa, yang isinya adalah id_student dan name_student
struct infotype_toko{
	string id_toko;
	string name_toko;
};

//struktur yang menyimpan informasi tentang pendidikan, yang isinya adalah id_course, name_course, dan credit
struct infotype_barang{
	string id_barang;
	string name_barang;
	int harga;
};

typedef struct elm_toko *adr_toko; //untuk mendefinisikan nama baru adr_student untuk pointer ke struktur elm_student
typedef struct elm_barang *adr_barang; //untuk mendefinisikan nama baru adr_course untuk pointer ke struktur elm_course
typedef struct elm_relation *adr_relation; //untuk mendefinisikan nama baru adr_relation untuk pointer ke struktur elm_relation

struct list_toko{ //struktur untuk menyimpan daftar siswa
	adr_toko first_toko; //variabel untuk menyimpan ke elemen pertama dari daftar siswa
};
struct list_barang{ //struktur untuk menyimpan daftar pendidikan
	adr_barang first_barang; //variabel untuk menyimpan ke elemen pertama dari daftar pendidikan
    adr_barang last_barang;
};
struct list_relation{ //struktur untuk menyimpan daftar hubungan siswa dan pendidikan
	adr_relation first_relation; //variabel untuk menyimpan ke elemen pertama dari hubungan antar siswa dan pendidikan
};

struct elm_toko{ //struktur untuk merepresentasikan elemen dalam daftar siswa
	infotype_toko info_toko; //untuk menyimpan informasi tentang siswa yang terdiri dari id dan nama
	adr_toko next_toko; //digunakan untuk menghubungkan elemen dalam daftar siswa
};
struct elm_barang{ //struktur untuk merepresentasikan elemen dalam daftar pendidikan
	infotype_barang info_barang; //untuk menyimpan informasi tentang pendidikan yang terdiri dari id, nama, dan credit
	adr_barang next_barang; //digunakan untuk menghubungkan elemen dalam daftar pendidikan
    adr_barang prev_barang;
};

struct elm_relation{ //struktur untuk merepresentasikan hubungan dari siswa dan pendidikan
	adr_barang next_barang; //untuk menyimpan pendidikan yang terhubung dengan siswa
	adr_toko next_toko; //untuk menyimpan mahasiswa yang terhubung dengan pendidikan yang diambil
	adr_relation next_relation; //untuk menghubungkan elemen dalam daftar relasi
};

void createListToko(list_toko &s);  //mendeklarasikan fungsi untuk membuat daftar siswa baru
adr_toko createElmToko(string id, string name); //mendeklarasikan fungsi untuk membuat elemen siswa baru
void createListBarang(list_barang &c); //mendeklarasikan fungsi untuk membuat daftar pendidikan baru
adr_barang createElmBarang(string id, string name, int harga); //mendeklarasikan fungsi untuk membuat elemen pendidikan baru
void createListRelation(list_relation &r); //mendeklarasikan fungsi untuk membuat daftar relasi baru
adr_relation createElmRelation(); //mendeklarasikan fungsi untuk membuat elemen relasi baru

adr_toko searchToko(list_toko s, string id_toko); //mendeklarasikan fungsi untuk mencari siswa berdasarkan ID
adr_barang searchBarang(list_barang c, string id_barang); //mendeklarasikan fungsi untuk mencari pendidikan dengan ID
adr_relation searchRelation(list_relation r, string id_toko, string id_barang); //mendeklarasikan fungsi untuk mencari relasi antara siswa dan pendidikan berdasarkan ID

void insertToko(list_toko &s, adr_toko p); //mendeklarasikan fungsi untuk memasukkan elm siswa ke daftar siswa
void insertBarang(list_barang &c, adr_barang q); //mendeklarasikan fungsi untuk memasukkan elm pendidikan ke daftar pendidikan
void insertRelation(list_relation &r, adr_relation p); //mendeklarasikan fungsi untuk memasukkan elm relasi ke dalam daftar relasi

void addBarang(list_toko s, list_barang c, list_relation &r, string name_toko, string name_barang); //mendeklarasikan fungsi untuk menambahkan relasi antara siswa dan pendidikan

void deleteElmRelation(list_relation &r, adr_relation p); //mendeklarasikan fungsi untuk menghapus relasi dari daftar relasi
void deleteRelation(list_toko s, list_barang c, list_relation &r, string id_toko, string id_barang);//mendeklarasikan fungsi untuk menghapus relasi antara siswa dan pendidikan berdasarkan ID
void deleteToko(list_toko &s,list_relation &r, string id_toko); //mendeklarasikan fungsi untuk menghapus elm siswa dari daftar mahasiswa

void viewRelation(list_relation r); //mendeklarasikan fungsi untuk menampilkan semua daftar relasi siswa dan pendidikan
void view(list_toko s, list_relation r); //mendeklarasikan fungsi untuk menampilkan semua siswa dan pendidikan yang diambil
void viewToko(list_relation &relations, adr_barang barang);
void viewBarang(list_relation &relations, adr_toko toko);
void deleteElmToko(list_toko &s, adr_toko p);
void deleteToko(list_toko &s, list_relation &r, string idToko);
void findTokoWithLeastItems(list_toko s, list_relation r);
void findTokoWithMostItems(list_toko s, list_relation r);

#endif // HEADER_H_INCLUDED
