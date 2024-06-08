#include <iostream>
#include "header.h"

using namespace std;

int main() {
    list_toko toko; //mendeklarasikan variabel toko
    list_barang barang; //mendeklarasikan variabel barang
    list_relation relations; //mendeklarasikan variabel relasi

    createListToko(toko); //inisialisasi list toko
    createListBarang(barang); //inisialisasi list barang
    createListRelation(relations); //inisialisasi list relasi

    int pilihan, harga; //mendeklarasikan variabel untuk menyimpan pilihan dan harga
    string id, name;//mendeklarasikan variabel untuk menyimpan id dan nama
    string idToko, idBarang;//mendeklarasikan variabel untuk menyimpan idtoko dan idbarang

    do {
        system("cls");
        cout << "| ============================================== |" << endl;
        cout << "|           PROGRAM PENDATAAN TOKO BUKU          |" << endl;
        cout << "| ============================================== |" << endl;
//        view(toko, relations);
//        viewRelation(relations);
        cout << "| 1. Insert Toko                                 |" << endl;
        cout << "| 2. Insert Buku                                 |" << endl;
        cout << "| 3. Tambah Relasi Toko dan Buku                 |" << endl;
        cout << "| 4. View Data                                   |" << endl;
        cout << "| 5. Search Buku pada Toko Tertentu              |" << endl;
        cout << "| 6. Search Toko yang Jual Barang Tertentu       |" << endl;
        cout << "| 7. Hapus Data Buku                             |" << endl;
        cout << "| 8. Hapus Data Toko                             |" << endl;
        cout << "| 9. Toko yang Paling Lengkap dan Paling Sedikit |" << endl;
        cout << "| 10. Keluar                                     |" << endl;
        cout << endl;
        cout << "Masukkan pilihan anda      : "; //meminta user untuk menginputkan pilihan
        cin >> pilihan; //menyimpan inputan user

        switch(pilihan) {
            case 1: { //jika user memasukkan angka 1
                system("cls");
                printf("==================================\n");
                printf("       TAMBAH DATA TOKO         \n");
                printf("==================================\n");
                cout << "Masukkan ID Toko   : "; //meminta user memasukkan id toko
                cin >> id; //menyimpan inputan user
                cout << "Masukkan Nama Toko : "; //meminta user memasukkan nama toko
                cin >> name; //menyimpan inputan user
                adr_toko newToko = createElmToko(id, name); //membuat elemen baru untuk toko
                insertToko(toko, newToko); //memasukkan toko baru ke dalam list toko
                system("pause");
                break;
            }
            case 2: { //jika user memasukkan angka 2
                system("cls");
                printf("==================================\n");
                printf("         TAMBAH DATA BUKU         \n");
                printf("==================================\n");
                cout << "Masukkan ID Buku     : "; //meminta user memasukkan id barang
                cin >> id; //menyimpan inputan user
                cout << "Masukkan Nama Buku   : "; //meminta user memasukkan nama barang
                cin >> name; //menyimpan inputan user
                cout << "Masukkan Harga       : "; //meminta user memasukkan harga barang
                cin >> harga; //menyimpan inputan user
                adr_barang newBarang = createElmBarang(id, name, harga); //membuat elemen baru untuk barang
                insertBarang(barang, newBarang); //memasukkan barang baru ke dalam list barang
                system("pause");
                break;
            }
            case 3: { //jika user memasukkan angka 3
                system("cls");
                printf("==================================\n");
                printf("           TAMBAH RELASI         \n");
                printf("==================================\n");
                cout << "Masukkan Nama Toko     : "; //meminta user memasukkan nama toko
                cin >> idToko; //menyimpan inputan user
                cout << "Masukkan Nama Buku     : "; //meminta user memasukkan nama barang
                cin >> idBarang; //menyimpan inputan user
                addBarang(toko, barang, relations, idToko, idBarang);  //menambahkan relasi antara toko dan barang
                system("pause");
                break;
            }
            case 4: { //jika user memasukkan angka 4
                system("cls");
                cout << "============================================" << endl;
                cout << "             VIEW DATA TOKO" << endl;
                cout << "============================================" << endl;
                cout << endl;
                view(toko, relations); //enampilkan data toko
                system("pause");
                break;
            }
            case 5: { //jika user memasukkan angka 5
                system("cls");
                cout << "================================" << endl;
                cout << "         CARI DATA BUKU" << endl;
                cout << "================================" << endl;
                cout << "Masukkan Nama Buku         : "; //meminta user memasukkan id barang
                cin >> idBarang; //menyimpan inputan user
                system("cls");
                adr_barang p = searchBarang(barang, idBarang); //mencari barang berdasarkan nama
                if (p != NULL) { //jika barang ditemukan
//                    cout << "Buku ditemukan         : " << p->info_barang.name_barang << endl; //menampilkan nama barang
//                    cout << "Toko yang menjual buku :"<<endl; //menampilkan toko
                    cout << "================================" << endl;
                    cout << "        HASIL PENCARIAN" << endl;
                    cout << "================================" << endl;
                    viewToko(relations,p);//menampilkan toko
                } else { //jika barang tidak ditemukan
                    cout << "Buku tidak ditemukan." << endl;
                }
                system("pause");
                break;
            }
            case 6: { //jika user memasukkan angka 6
                system("cls");
                cout << "================================" << endl;
                cout << "         CARI DATA TOKO" << endl;
                cout << "================================" << endl;
                cout << "Masukkan Nama Toko : "; //meminta user memasukkan nama toko
                cin >> idToko; //menyimpan inputan user
                system("cls");
                adr_toko p = searchToko(toko, idToko); //mencari toko berdasarkan nama
                if (p != NULL) { //jika toko ditemukan
//                    cout << "Toko ditemukan : " << p->info_toko.name_toko << endl; //menampilkan nama toko
//                    cout << "Barang yang dijual di toko ini : "<<endl;
                    cout << "================================" << endl;
                    cout << "        HASIL PENCARIAN" << endl;
                    cout << "================================" << endl;
                    viewBarang(relations,p); //menampilkan barang-barang
                } else { //jika barang tidak ditemukan
                    cout << "Toko tidak ditemukan." << endl;
                }
                system("pause");
                break;
            }
            case 7: { //jika user memasukkan angka 7
                system("cls");
                cout << "================================" << endl;
                cout << "         HAPUS DATA BUKU" << endl;
                cout << "================================" << endl;
                cout << "Masukkan Nama Toko     : "; //meminta user memasukkan nama toko
                cin >> idToko; //menyimpan inputan user
                cout << "Masukkan Nama Buku   : "; //meminta user memasukkan nama barang
                cin >> idBarang; //menyimpan inputan user
                deleteRelation(toko, barang, relations, idToko, idBarang); //menghapus relasi antara toko dan barang
                system("pause");
                break;
            }
            case 8: { //jika user memasukkan angka 7
                system("cls");
                cout << "================================" << endl;
                cout << "        HAPUS DATA TOKO" << endl;
                cout << "================================" << endl;
                cout << "Masukkan nama toko     : ";
                cin >> idToko;
                deleteToko(toko, relations, idToko);
                system("pause");
                break;
            }
            case 9: { //jika user memasukkan angka 7
                system("cls");
                cout << "==========================================" << endl;
                cout << " Data Toko Buku Paling Lengkap dan Sedikit" << endl;
                cout << "==========================================" << endl;
                cout << endl;
                findTokoWithMostItems(toko, relations);
                cout << endl;
                findTokoWithLeastItems(toko, relations);
                system("pause");
                break;
            }
            case 10: //jika user memasukkan angka 9
                cout << "Terimakasih sudah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 10);

    return 0;
}
