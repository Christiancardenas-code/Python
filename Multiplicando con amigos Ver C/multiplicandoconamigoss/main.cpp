#include <allegro.h>
#include "inicia.h"

//using namespace std;

BITMAP  *buffer;//crea las variables bitmap
BITMAP  *ruleta1;
BITMAP  *ruleta2;
BITMAP  *ruleta3;
BITMAP  *ruleta4;
BITMAP  *ciencias1;
BITMAP  *ciencias2;
BITMAP  *ciencias3;
BITMAP  *ciencias4;
BITMAP  *ciencias5;
BITMAP  *deportes1;
BITMAP  *deportes2;
BITMAP  *deportes3;
BITMAP  *deportes4;
BITMAP  *deportes5;
BITMAP  *geografia1;
BITMAP  *geografia2;
BITMAP  *geografia3;
BITMAP  *geografia4;
BITMAP  *geografia5;
BITMAP  *historia1;
BITMAP  *historia2;
BITMAP  *historia3;
BITMAP  *historia4;
BITMAP  *historia5;
BITMAP  *correcto;
BITMAP  *incorrecto;
BITMAP  *inicio;
int x = 0;//posicion x
int y = 0;//posicion y


void rul1(BITMAP *rulet)// procedimiento para mostrar imagenes de la ruleta
{
  blit(rulet,screen,0,0,x,y,640,480);//carga la imagen en pantalla
  rest(30);//tiempo de la imagen en pantalla
}

int random(int max)// funcion randompara generar aleatoriedad
{
    int n;
    srand(time(NULL));
    n = rand();
    return n%max;
}

void respuesta(int correcta)//procedimiento para validarla respuesta correcta e incorrecta
{
    int val;
    while(keypressed()) //devuelve el ultimo valor almacenado en el buffer(limpia el buffer)
    readkey();// funcion lee la tecla presionada desde el teclado
    val = readkey();
    // rest(5000);
    if( (val >> 8) == correcta)//lee la letra presionada
       blit(correcto,screen,0,0,x,y,640,480);//si es igual a la tecla digitada muestra la imagen correcta
    else
       blit(incorrecto,screen,0,0,x,y,640,480);// si no es asi muestra el mensaje de incorrecto
}


void pregunta_aleatoria(BITMAP *preg1,BITMAP *preg2,BITMAP *preg3,BITMAP *preg4,BITMAP *preg5)//muestra las imagenes con las preguntas aleatoriamente
{
    int ran = (random(5)+1); //se llama la funcion random de 0 a 4 +1
    if(ran == 1)//si el numero aleatorio es 1
    {
        rest(1000);//espera 3 segundos antes de mostrar la imagen
         blit(preg1,screen,0,0,x,y,640,480);//muestra la imagen segun el parametro de tipo bitmap que se le pase

         respuesta(KEY_C);//llama al procedimiento respuesta paravalidar las respuestas
    }
    if(ran == 2)
    {
        rest(1000);
         blit(preg2,screen,0,0,x,y,640,480);

         respuesta(KEY_A);
    }
    if(ran == 3)
    {
        rest(1000);
         blit(preg3,screen,0,0,x,y,640,480);

         respuesta(KEY_B);
    }
    if(ran == 4)
    {
        rest(1000);
         blit(preg4,screen,0,0,x,y,640,480);

         respuesta(KEY_B);
    }
    if(ran == 5)
    {
        rest(1000);
         blit(preg5,screen,0,0,x,y,640,480);

         respuesta(KEY_A);
    }

}
void girar_ruleta()//procedimiento para girar la ruleta muestra las imagenes
{
if(key[KEY_ENTER])// si se presiona la tecla enter inicia el giro de la ruleta
 {
    for(int i=0;i<10;i++)//organiza para mostrar las imagenes
    {
        rul1(ruleta1);
        rul1(ruleta2);
        rul1(ruleta3);
        rul1(ruleta4);
    }
    int r = (random(4)+1);//genera un numero aleatorio de 0 a 4+1
    if(r == 1)// si el numero aleatorio es 1
        {rul1(ruleta1);//muestra la imagen de la ruleta en laprimera posicion
         pregunta_aleatoria(deportes1,deportes2, deportes3,deportes4, deportes5);//llama al procedimiento para generar preguntas aleatoriasde esta categoriarecibiendo como parametros los bitmapss de las imagenes
        }
    if(r == 2)
        {rul1(ruleta2);
         pregunta_aleatoria(ciencias1,ciencias2, ciencias3,ciencias4, ciencias5);
        }
    if(r == 3)
    {rul1(ruleta3);
         pregunta_aleatoria(historia1,historia2, historia3,historia4, historia5);
        }
    if(r == 4)
    {rul1(ruleta4);
         pregunta_aleatoria(geografia1,geografia2, geografia3,geografia4, geografia5);
        }

 }
}

void jugar()//procedimiento  parainiciar el juego
{
    blit(inicio,screen, 0,0,x,y,640,480);//muestra la imagen de inicio del juego
    //rest(500);
    while(!key[KEY_ESC])//mientras no se presione escape
    {
    girar_ruleta();//llama al procedimiento para girar la ruleta
    }

}


int main()
{

inicia_allegro(640, 480);//llama a todos los componentes para inicializar allegro
buffer = create_bitmap(640,480);//crea un buffer inicial de fondo blanco
clear_to_color(buffer,0xFFFFFF);
        ruleta1 = load_bitmap("images/images_ruleta/rul1.bmp",NULL);//carga las imagenes al bitmap
        ruleta2 = load_bitmap("images/images_ruleta/rul2.bmp",NULL);
        ruleta3 = load_bitmap("images/images_ruleta/rul3.bmp",NULL);
        ruleta4 = load_bitmap("images/images_ruleta/rul4.bmp",NULL);
        ciencias1 = load_bitmap("images/ciencia/Pciencia1.bmp",NULL);
        ciencias2 = load_bitmap("images/ciencia/Pciencia2.bmp",NULL);
        ciencias3 = load_bitmap("images/ciencia/Pciencia3.bmp",NULL);
        ciencias4 = load_bitmap("images/ciencia/Pciencia4.bmp",NULL);
        ciencias5 = load_bitmap("images/ciencia/Pciencia5.bmp",NULL);
        deportes1 = load_bitmap("images/deportes/Pdeportes1.bmp",NULL);
        deportes2 = load_bitmap("images/deportes/Pdeportes2.bmp",NULL);
        deportes3 = load_bitmap("images/deportes/Pdeportes3.bmp",NULL);
        deportes4 = load_bitmap("images/deportes/Pdeportes4.bmp",NULL);
        deportes5 = load_bitmap("images/deportes/Pdeportes5.bmp",NULL);
        geografia1 = load_bitmap("images/geografia/Pgeografia1.bmp",NULL);
        geografia2 = load_bitmap("images/geografia/Pgeografia2.bmp",NULL);
        geografia3 = load_bitmap("images/geografia/Pgeografia3.bmp",NULL);
        geografia4 = load_bitmap("images/geografia/Pgeografia4.bmp",NULL);
        geografia5 = load_bitmap("images/geografia/Pgeografia5.bmp",NULL);
        historia1 = load_bitmap("images/historia/Phistoria1.bmp",NULL);
        historia2 = load_bitmap("images/historia/Phistoria2.bmp",NULL);
        historia3 = load_bitmap("images/historia/Phistoria3.bmp",NULL);
        historia4 = load_bitmap("images/historia/Phistoria4.bmp",NULL);
        historia5 = load_bitmap("images/historia/Phistoria5.bmp",NULL);
        correcto = load_bitmap("images/Correcto.bmp",NULL);
        inicio = load_bitmap("images/logo1.bmp",NULL);
        incorrecto = load_bitmap("images/Incorrecto.bmp",NULL);
        blit(buffer,screen, 0,0,0,0,1200,600);

            jugar();//llama al procedimeinto jugar

               //readkey();
                  destroy_bitmap(buffer);//libera la las imagenes de lamemoria
                  destroy_bitmap(ruleta1);
                  destroy_bitmap(ruleta2);
                  destroy_bitmap(ruleta3);
                  destroy_bitmap(ruleta4);
                  destroy_bitmap(ciencias1);
                  destroy_bitmap(ciencias2);
                  destroy_bitmap(ciencias3);
                  destroy_bitmap(ciencias4);
                  destroy_bitmap(ciencias5);
                  destroy_bitmap(deportes1);
                  destroy_bitmap(deportes2);
                  destroy_bitmap(deportes3);
                  destroy_bitmap(deportes4);
                  destroy_bitmap(deportes5);
                  destroy_bitmap(geografia1);
                  destroy_bitmap(geografia2);
                  destroy_bitmap(geografia3);
                  destroy_bitmap(geografia4);
                  destroy_bitmap(geografia5);
                  destroy_bitmap(historia1);
                  destroy_bitmap(historia2);
                  destroy_bitmap(historia3);
                  destroy_bitmap(historia4);
                  destroy_bitmap(historia5);
                  destroy_bitmap(correcto);
                  destroy_bitmap(incorrecto);
                  destroy_bitmap(inicio);

                    return 0;
}
END_OF_MAIN();

