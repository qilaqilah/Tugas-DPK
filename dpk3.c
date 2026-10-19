#include <stdio.h>
#include  <stdlib.h>

char c[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int main(int argc, char *argv[]) {
    int posisi, baris, kolom;
    char pemain = 'X';
    int langkah = 0;
    int menang = 0;

    while(langkah < 9 && menang == 0) {
        for(int baris=0;baris<3;baris++) {
            for(int kolom=0;kolom<3;kolom++) {
                printf(" %c ", c[baris][kolom]);
                if(kolom<2)
                    printf("|");
            }
            printf("\n");
            if(baris<2)
                printf("---+---+---\n");
        }

        printf("Pemain %c, pilih posisi (1-9): ", pemain);
        scanf("%d", &posisi);

        if(posisi < 1 || posisi > 9) {
            printf("Posisi tidak valid!\n");
            continue;
        }

        baris = (posisi-1)/3;
        kolom = (posisi-1)%3;

        if(c[baris][kolom] == 'X' || c[baris][kolom] == 'O') {
            printf("Posisi sudah terisi!\n");
            continue;
        }

        c[baris][kolom] = pemain;
        langkah++;

        for(int i=0;i<3;i++) {
            if(c[i][0] == pemain && c[i][1] == pemain && c[i][2] == pemain)
                menang = 1;

            if(c[0][i] == pemain && c[1][i] == pemain && c[2][i] == pemain)
                menang = 1;
        }

        if(c[0][0] == pemain && c[1][1] == pemain && c[2][2] == pemain)
            menang = 1;

        if(c[0][2] == pemain && c[1][1] == pemain && c[2][0] == pemain)
            menang = 1;

        if(menang == 0) {
            if(pemain == 'X')
                pemain = 'O';
            else
                pemain = 'X';
        }
    }

    for(int baris=0;baris<3;baris++) {
        for(int kolom=0;kolom<3;kolom++) {
            printf(" %c ", c[baris][kolom]);
            if(kolom<2)
                printf("|");
        }
        printf("\n");
        if(baris<2)
            printf("---+---+---\n");
    }

    if(menang == 1)
        printf("Pemain %c menang!\n", pemain);
    else
        printf("Permainan seri!\n");

    return 0;
}