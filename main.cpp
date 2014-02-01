#include <allegro.h> /* Adiciona as funções do Allegro */  
#include <iostream>
#include <stdio.h>
#include <time.h>                  
    
using namespace std;


volatile int a = 0;

void func() {
    a++;
}

int main() {
    allegro_init();
    install_timer();
    install_mouse();
    install_keyboard();
    install_int(func,100);
    LOCK_VARIABLE(a);
    LOCK_FUNCTION(func);
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,360,161,0,0);
    set_window_title("SD - Binary Clock");


   //declaracao das imagens
   PALETTE pal; /* declaração uma variável tipo PALETTE */   

   BITMAP *img = load_bitmap("arquivos/fundo.bmp",pal);/* Ponteiro BITMAP img e atribui seu valor */ 
   BITMAP *buffer = create_bitmap(360,240);
   draw_sprite(screen, img, 0,0 ); /* função para imprimir imagem */ 
   
   BITMAP *img1 = load_bitmap("arquivos/1.bmp",NULL);
   BITMAP *img0 = load_bitmap("arquivos/0.bmp",NULL);
   BITMAP *img00 = load_bitmap("arquivos/s_0.bmp",NULL);
   BITMAP *img01 = load_bitmap("arquivos/s_1.bmp",NULL);
   BITMAP *img_pm = load_bitmap("arquivos/pm.bmp",NULL);
   BITMAP *img_am = load_bitmap("arquivos/am.bmp",NULL);
   
   //---------------------------------------------------------------------------
    

    while (!key[KEY_ESC]) {
         
       //----- relogio -----------------------------------------
       time_t tempo;
       struct tm *tm;

       tempo = time(NULL);
       tm = localtime( &tempo);
      
       printf("\n %d:%d:%d \n", tm->tm_hour, tm->tm_min, tm->tm_sec );
       //-------------------------------------------------------

     if(tm->tm_hour>=12)
          draw_sprite(screen, img_pm, 296,25 ); 
     else
          draw_sprite(screen, img_am, 296,25 );

     //--------- relogio binario -----------------------------------------------

	 int horas[3],h[3],horas24;
	 int minutos[5],m[5];
	 int segundos[5],s[5];

     horas24= tm->tm_hour;
     //--------horas bin------------------	 
      if(horas24>12)
            horas24= horas24 -12;
     //-------------
     
     horas[0] = horas24 % 2;
     if (horas[0]==1)
	     { 
          draw_sprite(screen, img1, 247,26 );
         }
	 else
	     draw_sprite(screen, img0, 247,26 ); 
	     
	 h[0] = horas24/2;
	 horas[1] = h[0] % 2;
	 if (horas[1]==1)
	     {
          draw_sprite(screen, img1, 199,26 );
         }
	 else
	     draw_sprite(screen, img0, 199,26 );
	 
	 h[1] = h[0]/2;
	 horas[2] = h[1] % 2;
	 if (horas[2]==1)
	     {
          draw_sprite(screen, img1, 151,26 ); 
         }
	 else
	     draw_sprite(screen, img0, 151,26 );
	     
	 h[2] = h[1]/2;
	 horas[3] = h[2] % 2;
	 if (horas[3]==1)
	     {
          draw_sprite(screen, img1, 103,26 ); 
         }
	 else
	     draw_sprite(screen, img0, 103,26 );


     //-----------minutos bin-------------
	 minutos[0] = tm->tm_min % 2;
	 if (minutos[0]==1)
	     {
          draw_sprite(screen, img1, 247,74 ); 
         }
	  else
	      draw_sprite(screen, img0, 247,74 );
	      
	 m[0] = tm->tm_min/2;
	 minutos[1] = m[0] % 2;
	 if (minutos[1]==1)
	     {
          draw_sprite(screen, img1, 199,74 ); 
         }
	  else
	      draw_sprite(screen, img0, 199,74 );
	      
	 m[1] = m[0]/2;
	 minutos[2] = m[1] % 2;
	 if (minutos[2]==1)
	     {
          draw_sprite(screen, img1, 151,74 ); 
         }
	  else
	      draw_sprite(screen, img0, 151,74); 
	      
	 m[2] = m[1]/2;
	 minutos[3] = m[2] % 2;
	 if (minutos[3]==1)
	     {
          draw_sprite(screen, img1, 103,74 ); 
         }
	  else
	      draw_sprite(screen, img0, 103,74 );
	      
	 m[3] = m[2]/2;
	 minutos[4] = m[3] % 2;
	 if (minutos[4]==1)
	     {
          draw_sprite(screen, img1, 55,74 ); 
         }
	  else
	      draw_sprite(screen, img0, 55,74 ); 
	      
	 m[4] = m[3]/2;
     if (m[4]==1)
	     {
          draw_sprite(screen, img1, 7,74 );
         }
	  else
	      draw_sprite(screen, img0, 7,74 ); 
	      
	 //------bin segundos --------------------
     segundos[0] = tm->tm_sec % 2;
	 if (segundos[0]==1)
	     {
          draw_sprite(screen, img01, 262,138 ); 
         }
	  else
	      draw_sprite(screen, img00, 262,138 );

	 s[0] = tm->tm_sec/2;
	 segundos[1] = s[0] % 2;
	 if (segundos[1]==1)
	     {
          draw_sprite(screen, img01, 214,138 );
         }
	  else
	      draw_sprite(screen, img00, 214,138 );

	 s[1] = s[0]/2;
	 segundos[2] = s[1] % 2;
	 if (segundos[2]==1)
	     {
          draw_sprite(screen, img01, 166,138 );
         }
	  else
	      draw_sprite(screen, img00, 166,138);

	 s[2] = s[1]/2;
	 segundos[3] = s[2] % 2;
	 if (segundos[3]==1)
	     {
          draw_sprite(screen, img01, 118,138 );
         }
	  else
	      draw_sprite(screen, img00, 118,138 );

	 s[3] = s[2]/2;
	 segundos[4] = s[3] % 2;
	 if (segundos[4]==1)
	     {
          draw_sprite(screen, img01, 70,138 );
         }
	  else
	      draw_sprite(screen, img00, 70,138 );

	 s[4] = s[3]/2;
     if (s[4]==1)
	     {
          draw_sprite(screen, img01, 22,138 );
         }
	  else
	      draw_sprite(screen, img00, 22,138 );
          
    };

    return 0;
}
END_OF_MAIN();
