#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// gcc -o phong phong.c &&
//./phong 1 sinhvien khancap hopdong nhanvien phongktx hoadon

int checkthang(int thang)
{
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return 28;
    }
}

int checkArgc(int argc, char *argv[])
{
    if (argc == 2 && (strcmp(argv[1], "--version") == 0))
        return 1;
    if (argc == 2 && (strcmp(argv[1], "--help") == 0))
        return 2;
    if (argc == 8 && (strcmp(argv[1], "1") == 0)) //
        return 3;
    return 0;
}
int main(int argc, char *argv[])
{

    char *names1[] = {"Nguyen", "Tran", "Le", "Hoang", "Pham", "Vu", "Dang", "Ngo", "Do", "Phan", "Bui", "Duong", "Ly"};

    char *names2[] = {"Hoang", "Phuong", "Thanh", "Khanh", "Ngoc", "Hong"};

    char *names3[] = {"Anh", "Trang", "Linh", "Phuong", "Nhi", "Huong", "Nga", "Mai", "Gam", "Thu", "Hoa", "Mai", "Hien"};

    char *names4[] = {"Van", "Quoc", "Bao", "Thanh", "Trong", "Gia"};

    char *names5[] = {"Huy", "Khang", "Bao", "Minh", "Tung", "Manh", "Khoa", "Phat", "Đat", "Long", "Duc", "Trung", "Toan"};

    char *nganh[] = {"Ki Thuat Hoa Hoc", "Ki Thuat Sinh Hoc", "Co Khi", "Cong Nghe Sinh Hoc", "Khoa Hoc May Tinh", "Ki Thuat May Tinh", "Ki Thuat Vat Lieu", "Toan Tin", "He Thong Thong Tin Quan Li", "Dien Tu Vien Thong", "Vat Ly Ki Thuat", "Su Pham Ky Thuat", "Kinh Te Quan Ly", "Ki Thuat Det May", "Ki Thuat Co Khi Dong Luc", "Phan Tich Kinh Doanh", "Ki Thuat Hoa Duoc", "He Thong Nhung Thong Minh Va IoT", "Cong Nghe Thong Tin Viet-Nhat", "Ki Thuat O to"};

    char *hokhau[] = {"Ha Noi", "Hai Phong", "Thai Binh", "Bac Ninh", "Thanh Hoa", "Nghe An", "Lao Cai", "Ha Tinh", "Lai Chau", "Quang Ninh", "Nam Dinh", "Lang Son", "Thai Nguyen"};

    int soluongSV;

    int namecount1 = sizeof(names1) / sizeof(names1[1]);
    int namecount2 = sizeof(names2) / sizeof(names2[0]);
    int namecount3 = sizeof(names3) / sizeof(names3[0]);
    int namecount4 = sizeof(names4) / sizeof(names4[0]);
    int namecount5 = sizeof(names5) / sizeof(names5[0]);
    int nganhcount = sizeof(nganh) / sizeof(nganh[0]);
    int hokhaucount = sizeof(hokhau) / sizeof(hokhau[0]);

    int ngay1;
    int thang1;
    int nam1;
    int sdt1;
    int gioitinh;

    switch (checkArgc(argc, argv))
    {
    case 1:
    {
        printf("phan mem tao ten sv version 1.0 .\n");
        break;
    }
    case 2:
    {
        printf("./main 1 sv khancap hopdong nhanvien phongktx hoadon\n");
        break;
    }
    case 3:
    {

        char fileout1[50], fileout2[50], fileout3[50], filenv[50], filephong[50], filehd[50];
        strcpy(fileout1, argv[2]);
        strcpy(fileout2, argv[3]);
        strcpy(fileout3, argv[4]);
        strcpy(filenv, argv[5]);
        strcpy(filephong, argv[6]);
        strcpy(filehd, argv[7]);
        FILE *fo1 = fopen(fileout1, "w"); // mo file de ghi
        FILE *fo2 = fopen(fileout2, "w");
        FILE *fo3 = fopen(fileout3, "w");
        FILE *fo4 = fopen(filenv, "w");
        FILE *fo5 = fopen(filephong, "w");
        FILE *fo6 = fopen(filehd, "w");

        fprintf(fo1, "insert into sinhvien\nvalues\n");
        fprintf(fo2, "insert into thongtinkhancap\nvalues\n");
        fprintf(fo3, "insert into hopdong\nvalues\n");
        fprintf(fo4, "insert into nhanvien\nvalues\n");
        fprintf(fo5, "insert into phong\nvalues\n");
        fprintf(fo6, "insert into hoadon\nvalues\n");

        printf("so luong sinh vien:");
        scanf("%d", &soluongSV);
        int phong = -1;
        int tang = 1;
        int toa = 1;
        int soSV1phong = 0;
        int dem = 0;
        int du;
        int chisodien, chisonuoc;
        int sodien, sonuoc;
        srand((int)time(0));
       
        for (int i = 1; i <= soluongSV; i++)
        {
            if (soSV1phong == dem)
            {
                soSV1phong = 6 + rand() % (5); //random so sv 1 phong

                dem = 0;
                
                if (phong == 9 && tang == 4)
                {
                    toa++;       // đủ 10 phòng của tầng 4 --> sang tòa tiếp theo
                    phong = 0; //reset
                    tang = 1;    //reset
                    if (soSV1phong != 10)
                    {
                        fprintf(fo5, "(\'%d0%d\', \'B%d\',\'%d\',\'con trong %d cho\', \'NV%d\'),\n", tang, phong, toa, soSV1phong, 10 - soSV1phong, toa);
                    }
                    else
                    {
                        fprintf(fo5, "(\'%d0%d\', \'B%d\',\'%d\',\'da du\', \'NV%d\'),\n", tang, phong, toa, soSV1phong, toa);
                    }
                    chisodien = rand() % (1000);
                    chisonuoc = rand() % (1000);
                    for (int k = 1; k < 6; k++)
                    {
                        int a = 8 + k > 12 ? 8 + k - 12 : 8 + k;
                        int b = 8 + k > 12 ? 22 : 21;
                        sodien = 150 + rand() % (200);
                        sonuoc = 20 + rand() % (30);
                        fprintf(fo6, "(\'D%d%d0%d%d%d\', \'N%d%d0%d%d%d\', \'NV%d\',\'%d0%d\', \'B%d\',", toa, tang, phong, a, b, toa, tang, phong, a, b, toa, tang, phong, toa);
                        fprintf(fo6, "\'%d-%d-%d\', ", 8 + k > 12 ? 2022 : 2021, 8 + k > 12 ? 8 + k - 12 : 8 + k, 15);
                        fprintf(fo6, "%d, %d, %d, %d, ", chisodien, chisodien + sodien, chisonuoc, chisonuoc + sonuoc);
                        fprintf(fo6, "%02d, 20%d,%d,%d),\n", a, b, sodien * 3, sonuoc * 5);
                        chisodien = chisodien + sodien;
                        chisonuoc = chisonuoc + sonuoc;
                    }
                }
                else
                {
                    if (phong == 9)
                    {
                        gioitinh = rand() % (2);
                        phong = 0;
                        tang++; // đủ 10 phòng của 1 tầng --> lên tầng tiếp theo
                        if (soSV1phong != 10)
                        {
                            fprintf(fo5, "(\'%d0%d\', \'B%d\',\'%d\',\'con trong %d cho\', \'NV%d\'),\n", tang, phong, toa, soSV1phong, 10 - soSV1phong, toa);
                        }
                        else
                        {
                            fprintf(fo5, "(\'%d0%d\', \'B%d\',\'%d\',\'da du\', \'NV%d\'),\n", tang, phong, toa, soSV1phong, toa);
                        }
                        chisodien = rand() % (1000);
                        chisonuoc = rand() % (1000);
                        for (int k = 1; k < 6; k++)
                        {
                            int a = 8 + k > 12 ? 8 + k - 12 : 8 + k;
                            int b = 8 + k > 12 ? 22 : 21;
                            sodien = 150 + rand() % (200);
                            sonuoc = 20 + rand() % (30);
                            fprintf(fo6, "(\'D%d%d0%d%d%d\', \'N%d%d0%d%d%d\', \'NV%d\',\'%d0%d\', \'B%d\',", toa, tang, phong, a, b, toa, tang, phong, a, b, toa, tang, phong, toa);
                            fprintf(fo6, "\'%d-%d-%d\', ", 8 + k > 12 ? 2022 : 2021, 8 + k > 12 ? 8 + k - 12 : 8 + k, 15);
                            fprintf(fo6, "%d, %d, %d, %d, ", chisodien, chisodien + sodien, chisonuoc, chisonuoc + sonuoc);
                            fprintf(fo6, "%02d, 20%d,%d,%d),\n", a, b, sodien * 3, sonuoc * 5);
                            chisodien = chisodien + sodien;
                            chisonuoc = chisonuoc + sonuoc;
                        }
                    }
                    else
                    {
                        phong++;
                        if (soSV1phong != 10)
                        {
                            fprintf(fo5, "(\'%d0%d\', \'B%d\',\'%d\',\'con trong %d cho\', \'NV%d\'),\n", tang, phong, toa, soSV1phong, 10 - soSV1phong, toa);
                        }
                        else
                        {
                            fprintf(fo5, "(\'%d0%d\', \'B%d\',\'%d\',\'da du\', \'NV%d\'),\n", tang, phong, toa, soSV1phong, toa);
                        }
                        chisodien = rand() % (1000);
                        chisonuoc = rand() % (1000);
                        for (int k = 1; k < 6; k++)
                        {
                            int a = 8 + k > 12 ? 8 + k - 12 : 8 + k;
                            int b = 8 + k > 12 ? 22 : 21;
                            sodien = 150 + rand() % (200);
                            sonuoc = 20 + rand() % (30);
                            fprintf(fo6, "(\'D%d%d0%d%d%d\', \'N%d%d0%d%d%d\', \'NV%d\',\'%d0%d\', \'B%d\',", toa, tang, phong, a, b, toa, tang, phong, a, b, toa, tang, phong, toa);
                            fprintf(fo6, "\'%d-%d-%d\', ", 8 + k > 12 ? 2022 : 2021, 8 + k > 12 ? 8 + k - 12 : 8 + k, 15);
                            fprintf(fo6, "%d, %d, %d, %d, ", chisodien, chisodien + sodien, chisonuoc, chisonuoc + sonuoc);
                            fprintf(fo6, "%02d, 20%d,%d,%d),\n", a, b, sodien * 3, sonuoc * 5);
                            chisodien = chisodien + sodien;
                            chisonuoc = chisonuoc + sonuoc;
                        }
                    }
                }
            }

            dem++;

            //ghi file sinh vien
            int cccd1 = 10000000 + rand() % (90000000 + 1 - 10000000);

            int thang1 = 1 + rand() % (12 + 1 - 1);

            int ngay1 = 1 + rand() % (checkthang(thang1) + 1 - 1);

            nam1 = 1998 + rand() % (6);
            int nam2 = 1998 + rand() % (6);
            int nam3 = 2018 + rand() % (6);
            sdt1 = 10000000 + rand() % (90000000 + 1 - 10000000);

            int mssv1 = 20190001 + rand() % (20219999 + 1 - 20190001);


            if (gioitinh == 0)
            {
                fprintf(fo1, "(03%d,\'%s %s %s\',\'%d-%02d-%02d\','nu',\'0%d\','BKHN',\'%s\',\'%d\',\'%s\'),\n", cccd1, names1[rand() % (namecount1)], names2[rand() % (namecount2)], names3[rand() % (namecount3)], nam1, thang1, ngay1, sdt1, nganh[rand() % (nganhcount)], mssv1, hokhau[rand() % (hokhaucount)]);
            }
            else
            {
                fprintf(fo1, "(03%d,\'%s %s %s\',\'%d-%02d-%02d\','nam',\'0%d\','BKHN',\'%s\',\'%d\',\'%s\'),\n", cccd1, names1[rand() % (namecount1)], names4[rand() % (namecount4)], names5[rand() % (namecount5)], nam1, thang1, ngay1, sdt1, nganh[rand() % (nganhcount)], mssv1, hokhau[rand() % (hokhaucount)]);
            }

            //ghi file thong tin khan cap
            int sdt1a = 10000000 + rand() % (90000000 + 1 - 10000000);
            int sdt1b = 10000000 + rand() % (90000000 + 1 - 10000000);

            fprintf(fo2, "(03%d,\'%s %s %s\',\'0%d\',\'%s %s %s\',\'0%d\'),\n", cccd1, names1[rand() % (namecount1)], names2[rand() % (namecount2)], names5[rand() % (namecount5)], sdt1a, names1[rand() % (namecount1)], names4[rand() % (namecount4)], names3[rand() % (namecount3)], sdt1b);

            //ghi file thong tin hop dong

            fprintf(fo3, "(%d%d0%d%d,\'03%d\',\'2021-08-20\',\'2022-02-20\',\'%d0%d\',\'B%d\',\'NV%d\'),\n", toa, tang, phong, dem, cccd1, tang, phong, toa, toa);
        }
        
        //ghi file nhanvien
        for (int i = 0; i < toa; i++)
        {
            int thang1 = 1 + rand() % (12 + 1 - 1);

            int ngay1 = 1 + rand() % (checkthang(thang1) + 1 - 1);

            nam1 = 1970 + rand() % (20);
            sdt1 = 10000000 + rand() % (90000000 + 1 - 10000000);
            gioitinh = rand() % (2);

            if (gioitinh == 0)
            {
                fprintf(fo4, "(\'NV%d\',\'%s %s %s\',\'%d-%02d-%02d\','nu',\'%s\',\'NhanVienQuanLi\',\'03%d\'),\n", i + 1, names1[rand() % (namecount1)], names2[rand() % (namecount2)], names3[rand() % (namecount3)], nam1, thang1, ngay1, hokhau[rand() % (hokhaucount)], sdt1);
            }
            else
            {
                fprintf(fo4, "(\'NV%d\',\'%s %s %s\',\'%d-%02d-%02d\','nam',\'%s\',\'NhanVienQuanLi\',\'01%d\'),\n", i + 1, names1[rand() % (namecount1)], names4[rand() % (namecount4)], names5[rand() % (namecount5)], nam1, thang1, ngay1, hokhau[rand() % (hokhaucount)], sdt1);
            }
        }

        fclose(fo1); // dong file fo
        fclose(fo2);
        fclose(fo3);
        fclose(fo4);
        fclose(fo5);
        fclose(fo6);
    }
    }
}
