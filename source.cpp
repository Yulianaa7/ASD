#include "header.h"
#include <iomanip> //tabel

//untuk menginisialisasi list toko
void createListToko(list_toko &s)
{
	s.first_toko = NULL; //menandakan bahwa list toko masih kosong
}

//fungsi untuk membuat elm toko baru
adr_toko createElmToko(string id, string name)
{
	adr_toko p = new elm_toko; //membuat pointer p yang menunjuk ke elm baru dari elm_toko
	p->info_toko.name_toko = name; //nilai name disimpan dalam name_toko yang ditunjuk p
	p->info_toko.id_toko = id;
	p->next_toko = NULL; //mengatur next_toko menjadi null (belum terhubung dg elm manapun)
	return p; //mengembalikan nilai dari p
}

//untuk menginisialisasi list barang
void createListBarang(list_barang &c)
{
	c.first_barang = NULL; //menandakan bahwa list toko masih kosong
    c.last_barang = NULL;
}

//fungsi untuk membuat elm barang baru
adr_barang createElmBarang(string id, string name, int harga)
{
	adr_barang p = new elm_barang; //membuat pointer p yang menunjuk ke elm baru dari elm_barang
	p->info_barang.name_barang = name; //nilai name disimpan dalam name_barang yang ditunjuk p
	p->info_barang.id_barang = id;
	p->info_barang.harga = harga; //nilai harga disimpan dalam harga yang ditunjuk p
	p->next_barang = NULL; //mengatur next_barang menjadi null (belum terhubung dg elm manapun)
	p->prev_barang = NULL;
	return p;
}

//untuk menginisialisasi list relasi
void createListRelation(list_relation &r)
{
	r.first_relation = NULL; //menandakan bahwa list relasi masih kosong
}

//fungsi untuk membuat elm relasi baru
adr_relation createElmRelation()
{
	adr_relation p = new elm_relation; //membuat pointer p yang menunjuk ke elm baru dari elm_relasi
	p->next_barang = NULL; //next barang null menandakan belum terhubung ke elm barang lain
	p->next_relation = NULL; //next relasi null menandakan belum terhubung ke elm relasi lain
	p->next_toko = NULL; //next toko null menandakan belum terhubung ke elm toko lain
	return p; //mengembalikan nilai dari pointer p
}

//fungsi untuk menambahkan elm toko ke dalam daftar toko
void insertToko(list_toko &s, adr_toko p)
{
	// insertLast single linked list
	if (s.first_toko == NULL) //memeriksa apakah daftar toko kosong
	{
		s.first_toko = p; //jika kosong, maka elm toko yg baru ditambahkan akan menjadi elm pertama pada daftar
	}
	else //jika daftar toko tidak kosong
	{
		adr_toko q = s.first_toko; //membuat pointer q yang menunjuk ke elm pertama
		while (q->next_toko != NULL) //melakukan perulangan sampai elemen terakhir (selama next toko tidak sama dengan null)
		{
			q = q->next_toko; //memindah pointer q ke elm toko berikutnya
		}
		q->next_toko = p; //pointer q menunjuk ke elm terakhir dlm daftar
	}
}

//fungsi untuk menambahkan elm barang ke dlm daftar barang
void insertBarang(list_barang &c, adr_barang q)
{
	// insertLast multi linkedlist
	if ((c.first_barang == NULL) && (c.last_barang == NULL))//memeriksa apakah daftar barang kosong
	{
		c.first_barang = q; //jika kosong, elm baru ditambahkan menjadi elm pertama dlm daftar
        c.last_barang = q;
        q->prev_barang = NULL;
        q->next_barang = NULL;
	}
	else //jika daftar barang tidak kosong
	{
//		adr_barang p = c.first_barang; //membuat pointer p yang menunjuk ke elm pertama
////		while (p->next_barang != NULL) //melakukan perulangan sampai elm terakhir (selama next barang tidak sama dengan null)
////		{
////			p = p->next_barang; //memindahkan pointer p ke elm barang berikutnya
////		}
////		p->next_barang = q; //pointer p menunjuk ke elm terakhir dalam daftar
//        p->next_barang = c.first_barang;
//        c.first_barang->prev_barang = p;
//        c.first_barang = p;

        c.last_barang->next_barang = q;
        q->prev_barang = c.last_barang;
        q->next_barang = NULL;
        c.last_barang = q;
	}
}

//fungsi untuk menambahkan elm relasi ke dalam daftar relasi
void insertRelation(list_relation &r, adr_relation p)
{
	if (r.first_relation == NULL) //memeriksa apakah daftar relasi kosong
	{
		r.first_relation = p; //jika kosong, elemen baru ditambahkan menjadi elemen pertama pada daftar
	}
	else //jika daftar relasi tidak kosong
	{
		adr_relation q = r.first_relation; //membuat pointer q yang menunjuk ke elemen pertama
		while (q->next_relation != NULL) //melakukan perulangan sampai elemen terakhir (selama 'next_relation' tidak sama dengan NULL)
		{
			q = q->next_relation; //memindahkan pointer q ke elemen relasi berikutnya
		}
		q->next_relation = p; //pointer q menunjuk ke elemen terakhir dalam daftar
	}
}

//fungsi untuk mencari elemen toko berdasarkan nama toko
adr_toko searchToko(list_toko s, string name_toko)
{
	adr_toko p = s.first_toko; //membuat pointer p yang menunjuk ke elemen pertama pada daftar toko
	while ((p->info_toko.name_toko != name_toko) && (p->next_toko != NULL)) //melakukan perulangan sampai menemukan elm dgn nama yg sesuai atau mencapai elemen terakhir
	{
		p = p->next_toko; //memindahkan pointer p ke elemen toko berikutnya
	}
	if (p->info_toko.name_toko == name_toko) //jika elemen dengan nama yang sesuai dengan yang dicari ditemukan
	{
		return p; //mengembalikan nilai p
	}
	else //jika elm tidak ditemukan
	{
		return NULL; //mengembalikan nilai null
	}
}

//fungsi untuk mencari elemen barnag berdasarkan nama barang
adr_barang searchBarang(list_barang c, string name_barang)
{
	adr_barang p = c.first_barang; //membuat pointer p yang menunjuk ke elemen pertama pada daftar barang
	while ((p->info_barang.name_barang != name_barang) && (p->next_barang != NULL)) //melakukan perulangan sampai menemukan elemen dengan nama yang sesuai atau mencapai elemen terakhir
	{
		p = p->next_barang; //memindahkan pointer p ke elemen barang berikutnya
	}
	if (p->info_barang.name_barang == name_barang) //jika elemen dengan nama yang sesuai ditemukan
	{
		return p; //mengembalikan nilai p
	}
	else //jika elm tidak ditemukan
	{
		return NULL; //mengembalikan nilai NULL
	}
}

//fungsi untuk mencari elemen barnag berdasarkan nama barang
adr_relation searchRelation(list_relation r, string name_toko, string name_barang)
{
	adr_relation rr = r.first_relation;  //membuat pointer rr yang menunjuk ke elemen pertama pada daftar relasi
	while ((rr->next_relation != NULL) && ((rr->next_toko->info_toko.name_toko != name_toko) && (rr->next_barang->info_barang.name_barang != name_barang))) //melakukan perulangan sampai menemukan elemen relasi yang sesuai atau mencapai elemen terakhir
	{
		rr = rr->next_relation; //memindahkan pointer rr ke elemen relasi berikutnya
	}
	if ((rr->next_toko->info_toko.name_toko == name_toko) && (rr->next_barang->info_barang.name_barang == name_barang)) //jika elemen relasi dengan nama toko dan nama barang yang sesuai ditemukan
	{
		return rr; //mengembalikan nilai rr
	}
	else //jika elm relasi tidak ditemukan
	{
		return NULL; //mengembalikan nilai NULL
	}
}

//void addBarang(list_toko s, list_barang c, list_relation &r, string id_toko, string id_barang) {
//    adr_toko p = searchToko(s, id_toko); //memanggil fungsi searchstudent, dan hasil dari id yg dicari disimpan di p
//    adr_barang q = searchBarang(c, id_barang); //memanggil fungsi searchcourse, dan hasil dari id yg dicari disimpan di q
//    if ((p != NULL) && (q != NULL)) { //mengecek pointer p dan q bukan null (siswa dan pendidikan ditemukan)
//        adr_relation rr = createElmRelation(); //membuat pointer rr dan memanggil createelmrelation untuk membuat relasi antara siswa dan pendidikan
//        rr->next_toko = p; //p berisi alamat ke data yg ingin dihubungkan ke dalam next student
//        rr->next_barang = q; //q berisi alamat ke data pendidikan yg ingin dihubungkan ke dalam next course
//        insertRelation(r, rr); //memanggil fungsi insertrelation untuk memasukkan relasi
//    }
//}

//fungsi untuk menambahkan barang ke dalam daftar toko dan relasinya
void addBarang(list_toko s, list_barang c, list_relation &r, string name_toko, string name_barang)
{
	adr_toko p = searchToko(s, name_toko); //mencari toko dengan nama yang sesuai
	adr_barang q = searchBarang(c, name_barang); //mencari barang dengan nama yang sesuai
	if ((p != NULL) && (q != NULL)) //jika elm barang dan toko ditemukan
	{
		adr_relation rr = createElmRelation(); //membuat elm relasi baru
		rr->next_toko = p; //mengatur next toko ke elemen toko yg sesuai
		rr->next_barang = q; //mengatur next barang ke elemen barang yg sesuai
		insertRelation(r, rr); //memasukkan elm relasi ke dlm daftar
	} //jika nama barang dan toko tidak ditemukan
//	else {
//        if(p == NULL){
//            cout << "Nama Toko '" << name_toko << "' tidak ditemukan dalam daftar." << endl;
//        }
//        if (q == NULL){
//            cout << "Nama Barang '" << name_barang << "' tidak ditemukan dalam daftar." << endl;
//        }
//	}
}

//fungsi untuk menghapus elm relasi
void deleteElmRelation(list_relation &r, adr_relation p)
{
	if (p == r.first_relation)  //jika elemen yang akan dihapus adalah elemen pertama dalam daftar relasi
	{
		if (p->next_relation == NULL) //jika elemen yang akan dihapus adalah satu-satunya elemen dalam daftar relasi
		{
			r.first_relation = NULL; //elemen pertama menjadi NULL
		}
		else //jika elm yang akan dihapus bukan satu-satunya elm
		{
			r.first_relation = p->next_relation; //mengatur elemen pertama menjadi elemen relasi berikutnya
			p->next_relation = NULL; //memutus hubungan dengan mengubah next relasi p menjadi null
		}
	}
	else //jika elemen yang akan dihapus bukan elemen pertama dalam daftar relasi
	{
		adr_relation q = r.first_relation; //membuat pointer q yang menunjuk ke elemen pertama
		while (q->next_relation != p) //melakukan perulangan sampai menemukan elemen sebelum elemen yang akan dihapus
		{
			q = q->next_relation; //memindahkan pointer q ke elemen relasi berikutnya
		}
		q->next_relation = p->next_relation; //mengatur next relasi q untuk mengarah ke next relasi p
		p->next_relation = NULL; //memutus hubungan dengan mengubah next relasi p menjadi null
	}
}

//fungsi untuk menghapus relasi antara toko dan barang
void deleteRelation(list_toko s, list_barang c, list_relation &r, string name_toko, string name_barang)
{
	adr_relation p = searchRelation(r, name_toko, name_barang); //mencari elemen relasi antara toko dan barang dengan nama yang sesuai
	if (p != NULL) //jika elemen relasi yang sesuai ditemukan
	{
		p->next_toko = NULL; //memutuskan hubungan dari elemen relasi dengan elemen toko
		p->next_barang = NULL; //memutuskan hubungan dari elemen relasi dengan elemen barang
		deleteElmRelation(r, p); //menghapus elemen relasi dari daftar relasi dengan fungsi delete
	}
}

//fungsi untuk menghapus elm barang dengan multi
//void deleteElmBarang(list_barang &c, adr_barang p) {
//    if (p == c.first_barang) { //memeriksa apakah elemen yang akan dihapus adalah elemen pertama dalam daftar barang
//        if (p->next_barang == NULL) { //jika daftar barang hanya memiliki satu elemen
//            c.first_barang = NULL; //daftar barang menjadi null
//        } else { //jika daftar barang memiliki lebih dari satu elemen
//            c.first_barang = p->next_barang; //mengatur elemen berikutnya sebagai elemen pertama dalam daftar barang
//            p->next_barang = NULL; //memutuskan hubungan dari elemen yang dihapus
//        }
//    } else {  //jika elemen yang akan dihapus bukan elemen pertama dalam daftar barang
//        adr_barang q = c.first_barang; //membuat pointer q yang menunjuk ke elemen pertama
//        while (q->next_barang != p) { //melakukan perulangan sampai menemukan elemen sebelum elemen yang akan dihapus
//            q = q->next_barang; //memindahkan pointer q ke elemen barang berikutnya
//        }
//        q->next_barang = p->next_barang; //mengatur next_barang dari elemen sebelum elemen yang akan dihapus ke elemen barang setelahnya
//        p->next_barang = NULL; //memutuskan hubungan dari elemen yang dihapus
//    }
//}

//multilinkedlist
void deleteElmBarang(list_barang &c, adr_barang p) {
    if (p == c.first_barang) { // Jika elemen yang akan dihapus adalah elemen pertama
        if (p->next_barang == NULL) { // Jika daftar barang hanya memiliki satu elemen
            c.first_barang = NULL; // Daftar barang menjadi kosong
            c.last_barang = NULL;
        } else { // Jika daftar barang memiliki lebih dari satu elemen
            c.first_barang = p->next_barang; // Mengatur elemen berikutnya sebagai elemen pertama
            c.first_barang->prev_barang = NULL; // Mengatur prev_barang elemen pertama menjadi NULL
            p->next_barang = NULL; // Memutuskan hubungan elemen yang dihapus
        }
    } else if (p == c.last_barang) { // Jika elemen yang akan dihapus adalah elemen terakhir
        c.last_barang = p->prev_barang; // Mengatur elemen sebelumnya sebagai elemen terakhir
        c.last_barang->next_barang = NULL; // Mengatur next_barang elemen terakhir menjadi NULL
        p->prev_barang = NULL; // Memutuskan hubungan elemen yang dihapus
    } else { // Jika elemen yang akan dihapus berada di tengah
        adr_barang prev = p->prev_barang; // Menyimpan alamat elemen sebelumnya
        adr_barang next = p->next_barang; // Menyimpan alamat elemen berikutnya
        prev->next_barang = next; // Menghubungkan elemen sebelum dan sesudah elemen yang dihapus
        next->prev_barang = prev;
        p->next_barang = NULL; // Memutuskan hubungan elemen yang dihapus
        p->prev_barang = NULL;
    }
    delete p; // Menghapus memori yang dialokasikan
}

//fungsi untuk delete barang
void deleteBarang(list_barang &c, list_relation &r, string id_barang) {
    adr_barang p = searchBarang(c, id_barang); //mencari elemen barang dengan id tertentu
    if (p != NULL) { //jika elemen barang ditemukan
        adr_relation q = r.first_relation; //menginisialisasi pointer q dengan elemen relasi pertama
        while (q != NULL) { //melakukan perulangan untuk semua elemen relasi
            if (q->next_barang == p) { //jika elemen relasi menunjuk ke elemen barang yang akan dihapus
                q->next_barang = NULL; //memutuskan hubungan relasi dengan elemen barang
                q->next_toko = NULL; //memutuskan hubungan relasi dengan elemen toko
                deleteElmRelation(r, q); //menghapus elemen relasi
            }
            q = q->next_relation; //pindah ke elemen relasi berikutnya
        }
        deleteElmBarang(c, p); //menghapus elemen barang
    }
}

//fungsi untuk menghapus elm barang
void deleteElmToko(list_toko &s, adr_toko p) {
    if (p == s.first_toko) { // Jika elemen toko adalah elemen pertama
        s.first_toko = p->next_toko; // Set elemen berikutnya sebagai elemen pertama
        p->next_toko = NULL; // Memutuskan hubungan
    } else {
        adr_toko q = s.first_toko; // Inisialisasi pointer q
        while (q->next_toko != p) { // Mencari elemen sebelum elemen yang akan dihapus
            q = q->next_toko;
        }
        q->next_toko = p->next_toko; // Hubungkan elemen sebelum dengan elemen setelah elemen yang dihapus
        p->next_toko = NULL; // Memutuskan hubungan
    }
    delete p; // Menghapus memori yang dialokasikan
}


//fungsi untuk delete toko menggunakan single
void deleteToko(list_toko &s, list_relation &r, string id_toko) {
    adr_toko p = searchToko(s, id_toko); // Mencari elemen toko dengan nama tertentu
    if (p != NULL) { // Jika elemen toko ditemukan
        // Hapus semua relasi yang terkait dengan toko ini
        adr_relation q = r.first_relation;
        while (q != NULL) {
            if (q->next_toko == p) { // Jika relasi terkait dengan toko yang akan dihapus
                q->next_toko = NULL; // Memutuskan hubungan dengan toko
                q->next_barang = NULL; // Memutuskan hubungan dengan barang
                adr_relation temp = q; // Simpan pointer sementara
                q = q->next_relation; // Pindah ke elemen relasi berikutnya
                deleteElmRelation(r, temp); // Hapus elemen relasi
            } else {
                q = q->next_relation; // Pindah ke elemen relasi berikutnya
            }
        }
        deleteElmToko(s, p); // Hapus elemen toko dari daftar toko
    }
}


//fungsi untuk menampilkan nama-nama toko dalam daftar toko
void viewName(list_toko s)
{
	adr_toko p = s.first_toko; //membuat pointer p yang menunjuk ke elemen pertama pada daftar toko
	while (p != NULL) //melakukan perulangan sampai mencapai elemen terakhir
	{

		cout << p->info_toko.name_toko << ", "; //menampilkan nama toko
		p = p->next_toko; //memindahkan pointer p ke elemen toko berikutnya
	}
}

//fungsi untuk menampilkan nama-nama barang dalam daftar barang
void viewBarang(list_barang c)
{
	adr_barang p = c.first_barang; //membuat pointer p yang menunjuk ke elemen pertama pada daftar barang
	// int sumCourse = 0;
	// while (p != NULL)
	// {
	// 	sumCourse += p->info_course.credit;
	// }
	// p = c.first_course;

	while (p != NULL) //melakukan perulangan sampai mencapai elemen terakhir
	{
		cout << p->info_barang.name_barang << "[" << p->info_barang.harga << "], "; //menampilkan nama dan harga barang
		p = p->next_barang; //memindahkan pointer p ke elemen barang berikutnya
	}
}

//fungsi untuk menampilkan nama toko dan barang beserta harganya
void view(list_toko s, list_relation r){
	adr_toko p = s.first_toko; //membuat pointer p yang menunjuk ke elemen pertama pada daftar toko
	while (p != NULL) {
        cout << "Nama Toko: " << p->info_toko.name_toko << endl;
        cout << "+---------------+----------------+-------+" << endl;
        cout << "| ID Buku       | Nama Buku      | Harga |" << endl;
        cout << "+---------------+----------------+-------+" << endl;
        adr_relation q = r.first_relation;
        bool barangDitemukan = false;
        while (q != NULL) {
            if (q->next_toko == p) {
                cout << "| " << setw(13) << left << q->next_barang->info_barang.id_barang
                     << "| " << setw(15) << left << q->next_barang->info_barang.name_barang
                     << "| " << setw(6) << right << q->next_barang->info_barang.harga << " |" << endl;
                barangDitemukan = true;
            }
            q = q->next_relation;
        }
        if (!barangDitemukan) {
            cout << "|         Tidak ada buku          |"  << endl;
        }
        cout << "+---------------+----------------+-------+" << endl;
        cout << endl;
		p = p->next_toko; //pindah ke toko berikutnya
	}
}

//fungsi untuk menampilkan toko-toko yang menjual barang tertentu
void viewToko(list_relation &relations, adr_barang barang) {
//cout << "Daftar toko yang menjual barang " << barang->info_barang.name_barang << ":" << endl;
    cout << "+---------------+----------------+" << endl;
    cout << "| ID Toko       | Nama Toko     |" << endl;
    cout << "+---------------+----------------+" << endl;

    adr_relation r = relations.first_relation;
    bool tokoFound = false;
    while (r != NULL) {
        if (r->next_barang == barang) {
            cout << "| " << setw(13) << left << r->next_toko->info_toko.id_toko
                 << "| " << setw(15) << left << r->next_toko->info_toko.name_toko << " |" << endl;
            tokoFound = true;
        }
        r = r->next_relation;
    }

    if (!tokoFound) {
        cout << "|         Tidak ada toko        |"  << endl;
    }

    cout << "+---------------+----------------+" << endl;
}

//fungsi untuk menampilkan barang-barang yang dijual oleh sebuah toko
void viewBarang(list_relation &relations, adr_toko toko) {
//    cout << "Daftar barang yang dijual oleh " << toko->info_toko.name_toko << ":" << endl;
    cout << "+---------------+----------------+-------+" << endl;
    cout << "| ID Buku       | Nama Buku      | Harga |" << endl;
    cout << "+---------------+----------------+-------+" << endl;

    adr_relation r = relations.first_relation;
    bool barangFound = false;
    while (r != NULL) {
        if (r->next_toko == toko) {
            cout << "| " << setw(13) << left << r->next_barang->info_barang.id_barang
                 << "| " << setw(15) << left << r->next_barang->info_barang.name_barang
                 << "| " << setw(6) << right << r->next_barang->info_barang.harga << " |" << endl;
            barangFound = true;
        }
        r = r->next_relation;
    }

    if (!barangFound) {
        cout << "|                Tidak ada buku                |" << endl;
    }

    cout << "+---------------+----------------+-------+" << endl;
}

void findTokoWithMostItems(list_toko s, list_relation r) {
    adr_toko maxToko = NULL;
    int maxCount = 0;

    adr_toko p = s.first_toko;
    while (p != NULL) {
        int count = 0;
        adr_relation q = r.first_relation;
        while (q != NULL) {
            if (q->next_toko == p) {
                count++;
            }
            q = q->next_relation;
        }
        if (count > maxCount) {
            maxCount = count;
            maxToko = p;
        }
        p = p->next_toko;
    }

    if (maxToko != NULL) {
        cout << "Toko dengan buku terlengkap    : " << maxToko->info_toko.name_toko << endl;
        cout << "Daftar buku yang dijual        :" << endl;
        cout << "+---------------+----------------+-------+" << endl;
        cout << "| ID Buku       | Nama Buku      | Harga |" << endl;
        cout << "+---------------+----------------+-------+" << endl;
        adr_relation r_temp = r.first_relation;
        while (r_temp != NULL) {
            if (r_temp->next_toko == maxToko) {
                cout << "| " << setw(13) << left << r_temp->next_barang->info_barang.id_barang
                     << "| " << setw(15) << left << r_temp->next_barang->info_barang.name_barang
                     << "| " << setw(6) << right << r_temp->next_barang->info_barang.harga << " |" << endl;
            }
            r_temp = r_temp->next_relation;
        }
        cout << "+---------------+----------------+-------+" << endl;
    } else {
        cout << "Tidak ada toko dalam daftar." << endl;
    }
}

void findTokoWithLeastItems(list_toko s, list_relation r) {
    adr_toko minToko = NULL;
    int minCount = INT_MAX; // Gunakan nilai maksimum sebagai awal perbandingan

    adr_toko p = s.first_toko;
    while (p != NULL) {
        int count = 0;
        adr_relation q = r.first_relation;
        while (q != NULL) {
            if (q->next_toko == p) {
                count++;
            }
            q = q->next_relation;
        }
        if (count < minCount) {
            minCount = count;
            minToko = p;
        }
        p = p->next_toko;
    }

    if (minToko != NULL) {
        cout << "Toko dengan buku tersedikit: " << minToko->info_toko.name_toko << endl;
        cout << "Daftar buku yang dijual:" << endl;
        cout << "+---------------+----------------+-------+" << endl;
        cout << "| ID Buku       | Nama Buku      | Harga |" << endl;
        cout << "+---------------+----------------+-------+" << endl;
        adr_relation r_temp = r.first_relation;
        while (r_temp != NULL) {
            if (r_temp->next_toko == minToko) {
                cout << "| " << setw(13) << left << r_temp->next_barang->info_barang.id_barang
                     << "| " << setw(15) << left << r_temp->next_barang->info_barang.name_barang
                     << "| " << setw(6) << right << r_temp->next_barang->info_barang.harga << " |" << endl;
            }
            r_temp = r_temp->next_relation;
        }
        cout << "+---------------+----------------+-------+" << endl;
    } else {
        cout << "Tidak ada toko dalam daftar." << endl;
    }
}
