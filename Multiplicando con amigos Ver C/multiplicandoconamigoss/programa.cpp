#include <allegro.h>
#include "inicia.h"

//using namespace std;

BITMAP  *buffer;//crea las variables bitmap
BITMAP  *ruleta1;
BITMAP  *ruleta2;
BITMAP  *ruleta3;
BITMAP  *ruleta4;
BITMAP  *division1;
BITMAP  *division2;
BITMAP  *division3;
BITMAP  *division4;
BITMAP  *division5;
BITMAP  *multiplicacion1;
BITMAP  *multiplicacion2;
BITMAP  *multiplicacion3;
BITMAP  *multiplicacion4;
BITMAP  *multiplicacion5;
BITMAP  *resta1;
BITMAP  *resta2;
BITMAP  *resta3;
BITMAP  *resta4;
BITMAP  *resta5;
BITMAP  *suma1;
BITMAP  *suma2;
BITMAP  *suma3;
BITMAP  *suma4;
BITMAP  *suma5;
BITMAP  *correcto;
BITMAP  *incorrecto;
BITMAP  *inicio;
int x = 0;//osicion x
int y = 0;//osicion y


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

void respuesta(int correcta)//rocedimiento para validarla respuesta correcta e incorrecta
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
void girar_ruleta()//rocedimiento para girar la ruleta muestra las imagenes
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
         pregunta_aleatoria(multiplicacion1,multiplicacion2, multiplicacion3,multiplicacion4, multiplicacion5);//llama al procedimiento para generar preguntas aleatoriasde esta categoriarecibiendo como parametros los bitmapss de las imagenes
        }
    if(r == 2)
        {rul1(ruleta2);
         pregunta_aleatoria(division1,division2, division3,division4, division5);
        }
    if(r == 3)
    {rul1(ruleta3);
         pregunta_aleatoria(suma1,suma2, suma3,suma4, suma5);
        }
    if(r == 4)
    {rul1(ruleta4);
         pregunta_aleatoria(resta1,resta2, resta3,resta4, resta5);
        }

 }
}

void jugar()//rocedimiento  parainiciar el juego
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
        ruleta1 = load_bitmap("imagenes/images_ruleta/rul1.bmp",NULL);//carga las imagenes al bitmap
        ruleta2 = load_bitmap("imagenes/images_ruleta/rul2.bmp",NULL);
        ruleta3 = load_bitmap("imagenes/images_ruleta/rul3.bmp",NULL);
        ruleta4 = load_bitmap("imagenes/images_ruleta/rul4.bmp",NULL);
        division1 = load_bitmap("imagenes/divi/divi1.bmp",NULL);
        division2 = load_bitmap("imagenes/divi/divi2.bmp",NULL);
        division3 = load_bitmap("imagenes/divi/divi3.bmp",NULL);
        division4 = load_bitmap("imagenes/divi/divi4.bmp",NULL);
        division5 = load_bitmap("imagenes/divi/divi5.bmp",NULL);
        multiplicacion1 = load_bitmap("imagenes/multi/multi1.bmp",NULL);
        multiplicacion2 = load_bitmap("imagenes/multi/multi2.bmp",NULL);
        multiplicacion3 = load_bitmap("imagenes/multi/multi3.bmp",NULL);
        multiplicacion4 = load_bitmap("imagenes/multi/multi4.bmp",NULL);
        multiplicacion5 = load_bitmap("imagenes/multi/multi5.bmp",NULL);
        resta1 = load_bitmap("imagenes/resta/resta1.bmp",NULL);
        resta2 = load_bitmap("imagenes/resta/resta2.bmp",NULL);
        resta3 = load_bitmap("imagenes/resta/resta3.bmp",NULL);
        resta4 = load_bitmap("imagenes/resta/resta4.bmp",NULL);
        resta5 = load_bitmap("imagenes/resta/resta5.bmp",NULL);
        suma1 = load_bitmap("imagenes/suma/suma1.bmp",NULL);
        suma2 = load_bitmap("imagenes/suma/suma2.bmp",NULL);
        suma3 = load_bitmap("imagenes/suma/suma3.bmp",NULL);
        suma4 = load_bitmap("imagenes/suma/suma4.bmp",NULL);
        suma5 = load_bitmap("imagenes/suma/suma5.bmp",NULL);
        correcto = load_bitmap("imagenes/correcto.bmp",NULL);
        inicio = load_bitmap("imagenes/logo1.bmp",NULL);
        incorrecto = load_bitmap("imagenes/incorrecto.bmp",NULL);
        blit(buffer,screen, 0,0,0,0,1200,600);

            jugar();//llama al procedimeinto jugar

               //readkey();
                  destroy_bitmap(buffer);//libera la las imagenes de lamemoria
                  destroy_bitmap(ruleta1);
                  destroy_bitmap(ruleta2);
                  destroy_bitmap(ruleta3);
                  destroy_bitmap(ruleta4);
                  destroy_bitmap(division1);
                  destroy_bitmap(division2);
                  destroy_bitmap(division3);
                  destroy_bitmap(division4);
                  destroy_bitmap(division5);
                  destroy_bitmap(multiplicacion1);
                  destroy_bitmap(multiplicacion2);
                  destroy_bitmap(multiplicacion3);
                  destroy_bitmap(multiplicacion4);
                  destroy_bitmap(multiplicacion5);
                  destroy_bitmap(resta1);
                  destroy_bitmap(resta2);
                  destroy_bitmap(resta3);
                  destroy_bitmap(resta4);
                  destroy_bitmap(resta5);
                  destroy_bitmap(suma1);
                  destroy_bitmap(suma2);
                  destroy_bitmap(suma3);
                  destroy_bitmap(suma4);
                  destroy_bitmap(suma5);
                  destroy_bitmap(correcto);
                  destroy_bitmap(incorrecto);
                  destroy_bitmap(inicio);

                    return 0;
}
END_OF_MAIN();

