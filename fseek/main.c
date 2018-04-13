#include <windows.h>
#include <stdio.h>
#include <conio.h>
void Janela5 ( ) {
     int lin, col;
     for ( lin = 0; lin <= 36 ; lin++ ) {
         for ( col = 0; col <= 80 ; col++ ) {
//              gotoxy ( 22,7 );
              if ( lin == 2 ) {
                  // textbackground ( LIGHTRED );
                   printf ( " " );
              }
              if ( col == 1 ) {
          //         textbackground ( LIGHTRED );
                   printf ( " " );
              }
              if ( lin == 36 ) {
          //         textbackground ( LIGHTRED );
              }
              if ( col == 80 ) {
           //        textbackground ( LIGHTRED );
                   printf ( " " );
              }
         }
     }
  //   textbackground ( BLACK );
} //Fseek - posicionando um ponteiro para arquivo
void inicio ( ) {
     system ( "title FSEEK - POSICIONANDO UM PONTEIRO PARA ARQUIVO" );
     int i;
     do {
         Janela5 ( );
  //       textcolor ( LIGHTRED );
  //       gotoxy ( 22 , 7 );
         printf ( "FSEEK - POSICIONANDO UM PONTEIRO PARA ARQUIVO" );
   //      textcolor ( YELLOW );
   //      gotoxy ( 25 , 10 );
         printf ( "Programa desenvolvido por:" );
  //       textcolor ( LIGHTCYAN );
 //        gotoxy ( 52 , 10 );
         printf ( "Samuel Lima" );
  //       textcolor ( LIGHTGREEN );
 //        gotoxy ( 34 , 12 );
         printf ( "sa_sp10@hotmail.com" );
   //      textcolor ( LIGHTBLUE );
  //       gotoxy ( 24 , 14 );
         printf ( "DIGITE    PARA SAIR OU   PARA CONTINUAR  " );
  //       textcolor ( LIGHTRED );
  //       gotoxy ( 32 , 14 );
         printf ( "1" );
   //      textcolor ( LIGHTRED );
  //       gotoxy ( 47 , 14 );
         printf ( "2" );
  //       gotoxy ( 41 , 16 );
         scanf ( "%d" , &i );
         fflush ( stdin );
         if ( i == 1 ) {
  //            textcolor ( LIGHTRED );
   //           gotoxy ( 35 , 20 );
              printf ( "MUITO OBRIGADO" );
              Sleep ( 1800 );
              exit ( 0 );
         }
         if ( i == 2 ) {
              system ( "cls" );
              return;
         } else {
   //           textcolor ( LIGHTRED );
     //         gotoxy ( 37 , 20 );
              printf ( "\aOPÇÃO ERRADA" );
              Sleep ( 1800 );
              system ( "cls" );
         }
     } while ( i );
}
int main ( ) {
     inicio ( );
     char li_nha [ 27 ] = "Programando em linguagem C";
     char linha [ 27 ];
     int result;
     FILE *arq;
     if ( ( arq = fopen ( "Arquivo.txt" , "wb" ) ) == NULL ) {
         printf ( "Houve um erro na criação do arquivo" );
         getche ( );
         exit ( 1 );
     }
     if ( fwrite ( &li_nha , sizeof ( li_nha ) , 1 , arq ) != 1 ) {
         printf ( "Houve um erro na gravação do arquivo" );
         getche ( );
         exit ( 1 );
     }
     fclose ( arq );
     if ( ( arq = fopen ( "Arquivo.txt" , "rb" ) ) == NULL ) {
         printf ( "Houve um erro na abertura do arquivo" );
         getche ( );
         exit ( 1 );
     }
     if ( fread ( &linha , sizeof ( linha ) , 1 , arq ) != 1 ) {
         printf ( "Houve um erro na leitura do arquivo" );
         getche ( );
         exit ( 1 );
     }
     system ( "cls" );
     Janela5 ( );
   //  textcolor ( LIGHTRED );
   //  gotoxy ( 20 , 3 );
     printf ( "FSEEK - POSICIONANDO UM PONTEIRO PARA ARQUIVO" );
  //   textcolor ( LIGHTBLUE );
   //  gotoxy ( 26 , 5 );
     printf ( "Abaixo a leitura do arquivo aberto" );
  //   textcolor ( YELLOW );
  //   gotoxy ( 30 , 7 );
     printf ( "%s" , linha );
     getche ( );
     result = fseek ( arq , 13L , SEEK_SET );
     if ( result )
         perror ( "Arquivo.txt" );
     else {
 //        textcolor ( LIGHTBLUE );
    //     gotoxy ( 20 , 9 );
         printf ( "O Ponteiro de arquivo foi movido com sucesso" );
 //        textcolor ( LIGHTBLUE );
    //     gotoxy ( 20 , 10 );
         printf ( "Para o início na posição 13 num total de 9 posições" );
 //        textcolor ( LIGHTGREEN );
  //       gotoxy ( 30 , 13 );
         printf ( "Veja o resultado abaixo :" );
         fgets ( linha , 10 , arq );
    //     textcolor ( YELLOW );
  //       gotoxy ( 38 , 15 );
         printf ( "%s" , linha );
     }
     fclose ( arq );
     Sleep ( 1800 );
  //   textcolor ( LIGHTRED );
  //   gotoxy ( 36 , 20 );
     printf ( "MUITO OBRIGADO" );
     getche ( );
     exit ( 0 );
}
