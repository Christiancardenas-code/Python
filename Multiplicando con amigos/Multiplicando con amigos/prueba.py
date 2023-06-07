import pygame
import math

ancho_ventana = 720
alto_ventana = 580

pygame.init()

# Crear la pantalla
pantalla_menu = pygame.display.set_mode((ancho_ventana, alto_ventana))
pygame.display.set_caption("Barra de Sonido")

NEGRO = (0, 0, 0)
BLANCO = (255, 255, 255)

# Tamaño de la barra de sonido
barra_ancho = ancho_ventana / 4
barra_alto = 4
barra_x = ancho_ventana - barra_ancho - 20
barra_y = alto_ventana - 50 - barra_alto

# Estado de la barra de sonido
punto_radio = 10
punto_x = 600
volumen = 5
pygame.mixer.music.set_volume(volumen)

# Función para dibujar la barra de sonido
def dibujar_barra_sonido():
    pygame.draw.rect(pantalla_menu, NEGRO, (barra_x, barra_y, barra_ancho, barra_alto))  # Dibujar fondo de la barra
    pygame.draw.circle(pantalla_menu, BLANCO, (punto_x, barra_y + barra_alto / 2), punto_radio)  # Dibujar punto
       

# Ciclo principal del juego
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        # Actualizar el volumen en función de la posición del punto en la barra de sonido
        if event.type == pygame.MOUSEMOTION and event.buttons[0] == 1:
            if barra_x <= event.pos[0] <= barra_x + barra_ancho:
                punto_x = event.pos[0]
                volumen = (punto_x - barra_x) / barra_ancho
                pygame.mixer.music.set_volume(volumen)
    dibujar_barra_sonido()
    pygame.display.update()
