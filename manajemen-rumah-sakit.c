#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dokter
{
    int id;
    char nama[50];
    char spesialis[50];
    char alamat[50];
    char telepon[50];
};

struct pasien
{
    int id;
    char nama[50];
    char jenisKelamin[50];
    char umur[50];
    char alamat[100];
    char telepon[50];
    char penyakit[50];
    char dokter[50];
};

struct dokter dokter[9];
struct pasien daftarPasien[50];
int jumlahPasien = 0;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void tampilkanDokter()
{
    clearScreen();
    int l;

    printf("===============================================\n");
    printf("             Menu Tampilkan Dokter             \n");
    printf("===============================================\n");

    dokter[0].id = 1;
    strcpy(dokter[0].nama, "Dr. Siti");
    strcpy(dokter[0].spesialis, "Penyakit Dalam");
    strcpy(dokter[0].alamat, "Jl. Gunung Anyar");
    strcpy(dokter[0].telepon, "081111111111");

    dokter[1].id = 2;
    strcpy(dokter[1].nama, "Dr. Joko");
    strcpy(dokter[1].spesialis, "Penyakit Dalam");
    strcpy(dokter[1].alamat, "Jl. Gunung Salak");
    strcpy(dokter[1].telepon, "082222222222");

    dokter[2].id = 3;
    strcpy(dokter[2].nama, "Dr. Rina");
    strcpy(dokter[2].spesialis, "Penyakit Dalam");
    strcpy(dokter[2].alamat, "Jl. Gunung Bromo");
    strcpy(dokter[2].telepon, "083333333333");

    dokter[3].id = 4;
    strcpy(dokter[3].nama, "Dr. Eva\t");
    strcpy(dokter[3].spesialis, "Saraf\t");
    strcpy(dokter[3].alamat, "Jl. Gunung Semeru");
    strcpy(dokter[3].telepon, "084444444444");

    dokter[4].id = 5;
    strcpy(dokter[4].nama, "Dr. Adi\t");
    strcpy(dokter[4].spesialis, "Saraf\t");
    strcpy(dokter[4].alamat, "Jl. Gunung Merapi");
    strcpy(dokter[4].telepon, "085555555555");

    dokter[5].id = 6;
    strcpy(dokter[5].nama, "Dr. Budi");
    strcpy(dokter[5].spesialis, "Saraf\t");
    strcpy(dokter[5].alamat, "Jl. Gunung Merbabu");
    strcpy(dokter[5].telepon, "086666666666");

    dokter[6].id = 7;
    strcpy(dokter[6].nama, "Dr. Stone");
    strcpy(dokter[6].spesialis, "Bedah Umum");
    strcpy(dokter[6].alamat, "Jl. Gunung Lawu\t");
    strcpy(dokter[6].telepon, "087777777777");

    dokter[7].id = 8;
    strcpy(dokter[7].nama, "Dr. Strange");
    strcpy(dokter[7].spesialis, "Bedah Umum");
    strcpy(dokter[7].alamat, "Jl. Gunung Kelud");
    strcpy(dokter[7].telepon, "088888888888");

    dokter[8].id = 9;
    strcpy(dokter[8].nama, "Dr. Henry");
    strcpy(dokter[8].spesialis, "Bedah Umum");
    strcpy(dokter[8].alamat, "Jl. Gunung Ijen\t");
    strcpy(dokter[8].telepon, "089999999999");

    printf(" ID\tNama\t\tSpesialis\tAlamat\t\t\tNo.Telp\n\n");
    for (l = 0; l < 9; l++)
    {
        printf(" %d\t%s\t%s\t%s\t%s\n\n",
               dokter[l].id,
               dokter[l].nama,
               dokter[l].spesialis,
               dokter[l].alamat,
               dokter[l].telepon);
    }
}

void tambahPasien()
{
    clearScreen();
    int i, l;

    printf("===============================================================\n");
    printf("                          Data Dokter                          \n");
    printf("===============================================================\n");
    printf("  ID\t      Bidang\t\t  Hari\t\t    Hari");
    printf("\nDokter\t    Spesialis\t      Senin - Jumat\tSabtu - Minggu\n\n");
    printf("  1\t  Penyakit Dalam      09.00 - 15.00\t11.00 - 14.00\n");
    printf("  2\t  Penyakit Dalam      12.00 - 18.00\t09.00 - 12.00\n");
    printf("  3\t  Penyakit Dalam      15.00 - 21.00\t13.00 - 16.00\n");
    printf("  4\t  Saraf\t\t      12.00 - 18.00\t09.00 - 12.00\n");
    printf("  5\t  Saraf\t\t      09.00 - 15.00\t13.00 - 16.00\n");
    printf("  6\t  Saraf\t\t      15.00 - 21.00\t11.00 - 14.00\n");
    printf("  7\t  Bedah Umum\t      15.00 - 21.00\t11.00 - 14.00\n");
    printf("  8\t  Bedah Umum\t      12.00 - 18.00\t09.00 - 12.00\n");
    printf("  9\t  Bedah Umum\t      09.00 - 15.00\t13.00 - 16.00\n\n");

    if (jumlahPasien < 50)
    {
        printf("===============================================================\n");
        printf("                       Menu Tambah Pasien                      \n");
        printf("===============================================================\n");
        printf(" Masukkan ID Pasien\t: ");
        scanf("%d", &daftarPasien[jumlahPasien].id);

        int found = 0; // mengecek agar tidak ada ID yang double
        for (i = 0; i < jumlahPasien; i++)
        {
            if (daftarPasien[i].id == daftarPasien[jumlahPasien].id)
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            printf("\n ID pasien sudah ada. Silakan pilih ID lain...\n\n");
        }
        else
        {
            printf(" Masukkan nama\t\t: ");
            getchar(); // Clear input buffer
            gets(daftarPasien[jumlahPasien].nama);
            printf(" Masukkan jenis kelamin\t: ");
            gets(daftarPasien[jumlahPasien].jenisKelamin);
            printf(" Masukkan umur\t\t: ");
            gets(daftarPasien[jumlahPasien].umur);
            printf(" Masukkan alamat\t: ");
            gets(daftarPasien[jumlahPasien].alamat);
            printf(" Masukkan no.telp\t: ");
            gets(daftarPasien[jumlahPasien].telepon);
            printf(" Masukkan penyakit\t: ");
            gets(daftarPasien[jumlahPasien].penyakit);
            printf(" Masukkan dokter yang akan merawat pasien (ID): ");
            scanf("%d", &i);

            if (i < 1 || i > 9)
            {
                printf("\n Dokter untuk ID tersebut tidak ada!\n");
                printf(" Silahkan masukkan ulang data pasien...\n\n");
            }
            else
            {
                for (l = 0; l < 9; l++)
                {
                    if (dokter[l].id == i)
                    {
                        strcpy(daftarPasien[jumlahPasien].dokter, dokter[l].nama);
                        break;
                    }
                }
                printf("\n Pasien berhasil ditambahkan.\n\n");
                jumlahPasien = jumlahPasien + 1;
            }
        }
    }
    else
    {
        printf("!!! Kapasitas pasien penuh !!!\n\n");
    }
}

void tampilkanPasien()
{
    clearScreen();
    int i;

    printf("========================================\n");
    printf("             Menu Data Pasien           \n");
    printf("========================================\n");
    if (jumlahPasien == 0)
    {
        printf("\n Belum ada data pasien.\n\n");
    }

    else
    {
        for (i = 0; i < jumlahPasien; i++)
        {
            printf("\n ID\t\t: %d\n", daftarPasien[i].id);
            printf(" Nama\t\t: %s\n", daftarPasien[i].nama);
            printf(" Umur\t\t: %s\n", daftarPasien[i].umur);
            printf(" Jenis Kelamin\t: %s\n", daftarPasien[i].jenisKelamin);
            printf(" Alamat\t\t: %s\n", daftarPasien[i].alamat);
            printf(" No.telp\t: %s\n", daftarPasien[i].telepon);
            printf(" Penyakit\t: %s\n", daftarPasien[i].penyakit);
            printf(" Dokter\t\t: %s\n\n", daftarPasien[i].dokter);
        }
    }
}

void editPasien()
{
    clearScreen();
    int i, j, k, l;
    char confirmation;

    if (jumlahPasien > 0)
    {
        printf("========================================\n");
        printf("             Menu Edit Pasien           \n");
        printf("========================================\n");
        printf(" Pilih pasien yang ingin di-edit (ID): ");
        scanf("%d", &i);

        for (j = 0; j < jumlahPasien; j++)
        {
            if (daftarPasien[j].id == i)
            {
                printf("\n Data pasien ditemukan:\n");
                printf(" Nama\t\t: %s\n", daftarPasien[j].nama);
                printf(" Jenis Kelamin\t: %s\n", daftarPasien[j].jenisKelamin);
                printf(" Umur\t\t: %s\n", daftarPasien[j].umur);
                printf(" Alamat\t\t: %s\n", daftarPasien[j].alamat);
                printf(" No.telp\t: %s\n", daftarPasien[j].telepon);
                printf(" Penyakit\t: %s\n", daftarPasien[j].penyakit);
                printf(" Dokter\t\t: %s\n\n", daftarPasien[j].dokter);

                printf(" Apakah Anda yakin ingin mengedit data pasien ini? (y/n): ");
                getchar(); // Clear input buffer
                scanf("%c", &confirmation);

                if (confirmation == 'y' || confirmation == 'Y')
                {
                    printf("\n Masukkan nama\t\t: ");
                    getchar(); // Clear input buffer
                    gets(daftarPasien[j].nama);
                    printf(" Masukkan jenis Kelamin\t: ");
                    gets(daftarPasien[j].jenisKelamin);
                    printf(" Masukkan umur\t\t: ");
                    gets(daftarPasien[j].umur);
                    printf(" Masukkan alamat\t: ");
                    gets(daftarPasien[j].alamat);
                    printf(" Masukkan no.telp\t: ");
                    gets(daftarPasien[j].telepon);
                    printf(" Masukkan penyakit\t: ");
                    gets(daftarPasien[j].penyakit);
                    printf(" Masukkan dokter yang akan merawat pasien (ID): ");
                    scanf("%d", &k);

                    for (l = 0; l < 9; l++)
                    {
                        if (dokter[l].id == k)
                        {
                            strcpy(daftarPasien[j].dokter, dokter[l].nama);
                        }
                    }

                    printf("\n Data pasien berhasil di-edit.\n\n");
                }
                else
                {
                    printf("\n Edit data pasien dibatalkan.\n\n");
                }
                break;
            }
        }

        if (j == jumlahPasien)
        {
            printf("\n ID Pasien tidak ditemukan.\n\n");
        }
    }
    else
    {
        printf(" Tidak ada pasien untuk di-edit.\n\n");
    }
}

void hapusPasien()
{
    clearScreen();
    int i, j, k, l;

    if (jumlahPasien > 0)
    {
        printf("========================================\n");
        printf("             Menu Hapus Pasien           \n");
        printf("========================================\n");
        printf(" Pilih pasien yang ingin dihapus (ID): ");
        scanf("%d", &i);

        for (j = 0; j < jumlahPasien; j++)
        {
            if (daftarPasien[j].id == i)
            {
                printf("\n ID\t\t: %d\n", daftarPasien[j].id);
                printf(" Nama\t\t: %s\n", daftarPasien[j].nama);
                printf(" Jenis Kelamin\t: %s\n", daftarPasien[j].jenisKelamin);
                printf(" Umur\t\t: %s\n", daftarPasien[j].umur);
                printf(" Alamat\t\t: %s\n", daftarPasien[j].alamat);
                printf(" No.Telp\t: %s\n", daftarPasien[j].telepon);
                printf(" Penyakit\t: %s\n\n", daftarPasien[j].penyakit);

                printf(" Apakah Anda yakin ingin menghapus pasien ini dari daftar? (y/n): ");
                char confirm;
                scanf(" %c", &confirm);

                if (confirm == 'y' || confirm == 'Y')
                {
                    for (k = j; k < jumlahPasien - 1; k++)
                    {
                        daftarPasien[k] = daftarPasien[k + 1];
                    }
                    jumlahPasien = jumlahPasien - 1;
                    printf("\n Pasien berhasil dihapus.\n\n");
                    return;
                }
                else
                {
                    printf("\n Hapus pasien dibatalkan.\n\n");
                    break;
                }
            }
        }

        if (j == jumlahPasien)
        {
            printf("\n ID pasien tidak ditemukan.\n\n");
        }
    }
    else
    {
        printf(" Tidak ada data pasien untuk dihapus.\n\n");
    }
}

void jadwalDokter()
{
    clearScreen();

    printf("========================================\n");
    printf("              Jadwal Dokter             \n");
    printf("========================================\n\n");

    printf("\t\tDr. Siti\n ");
    printf("\t(Spesialis Penyakit Dalam)\n\n ");
    printf(" Senin-Jumat\t\t 09.00 - 15.00\n ");
    printf(" Sabtu-Minggu\t\t 11.00 - 14.00\n\n ");
    printf("-----------------------------------------\n");

    printf("\t\tDr. Joko\n ");
    printf("\t(Spesialis Penyakit Dalam)\n\n ");
    printf(" Senin-Jumat\t\t 12.00 - 18.00\n ");
    printf(" Sabtu-Minggu\t\t 09.00 - 12.00\n\n ");
    printf("-----------------------------------------\n");

    printf("\t\tDr. Rina\n ");
    printf("\t(Spesialis Penyakit Dalam)\n\n ");
    printf(" Senin-Jumat\t\t 15.00 - 21.00\n ");
    printf(" Sabtu-Minggu\t\t 13.00 - 16.00\n\n ");
    printf("-----------------------------------------\n");

    printf("\t\tDr. Eva\n ");
    printf("\t   (Spesialis Saraf)\n\n ");
    printf(" Senin-Jumat\t\t 12.00 - 18.00\n ");
    printf(" Sabtu-Minggu\t\t 09.00 - 12.00\n\n ");
    printf("-----------------------------------------\n");

    printf("\t\tDr. Adi\n ");
    printf("\t   (Spesialis Saraf)\n\n ");
    printf(" Senin-Jumat\t\t 09.00 - 15.00\n ");
    printf(" Sabtu-Minggu\t\t 13.00 - 16.00\n\n ");
    printf("-----------------------------------------\n");

    printf("\t\tDr. Budi\n ");
    printf("\t   (Spesialis Saraf)\n\n ");
    printf(" Senin-Jumat\t\t 15.00 - 21.00\n ");
    printf(" Sabtu-Minggu\t\t 11.00 - 14.00\n\n ");
    printf("-----------------------------------------\n");

    printf("\t\tDr. Stone\n ");
    printf("\t  (Spesialis Bedah Umum)\n\n ");
    printf(" Senin-Jumat\t\t 15.00 - 21.00\n ");
    printf(" Sabtu-Minggu\t\t 11.00 - 14.00\n\n ");
    printf("-----------------------------------------\n");

    printf("\t\tDr. Strange\n ");
    printf("\t  (Spesialis Bedah Umum)\n\n ");
    printf(" Senin-Jumat\t\t 12.00 - 18.00\n ");
    printf(" Sabtu-Minggu\t\t 09.00 - 12.00\n\n ");
    printf("-----------------------------------------\n");

    printf("\t\tDr. Henry\n ");
    printf("\t  (Spesialis Bedah Umum)\n\n ");
    printf(" Senin-Jumat\t\t 09.00 - 15.00\n ");
    printf(" Sabtu-Minggu\t\t 13.00 - 16.00\n\n ");
    printf("-----------------------------------------\n\n");
}

int main()
{
    int pilihan;

    do
    {
        clearScreen();

        printf("=========================================\n");
        printf("  Program Pengelolaan Data Rumah Sakit  \n");
        printf("=========================================\n");
        printf(" 1. Tampilkan Dokter\n");
        printf(" 2. Tambah Pasien\n");
        printf(" 3. Tampilkan Data Pasien\n");
        printf(" 4. Edit Pasien\n");
        printf(" 5. Hapus Pasien\n");
        printf(" 6. Jadwal Dokter\n");
        printf(" 7. Keluar\n\n");
        printf(" Pilih menu: ");
        scanf("%d", &pilihan);
        printf("\n");

        switch (pilihan)
        {
        case 1:
            tampilkanDokter();
            break;

        case 2:
            tambahPasien();
            break;

        case 3:
            tampilkanPasien();
            break;

        case 4:
            editPasien();
            break;

        case 5:
            hapusPasien();
            break;

        case 6:
            jadwalDokter();
            break;

        case 7:
            clearScreen();
            printf(" Terima kasih telah menggunakan program ini ^_^\n\n");
            break;

        default:
            printf(" Pilihan tidak valid. Silakan coba lagi.\n\n");
        }

        printf(" Press Enter to continue...");
        getchar();
        getchar();

    } while (pilihan != 7);

    return 0;
}