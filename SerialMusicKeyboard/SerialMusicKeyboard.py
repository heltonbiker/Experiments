#/usr/bin/env python

import os
import pygame
import serial

def pygameSetup():
    pygame.init()
    screen = pygame.display.set_mode((468, 60))

    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill((250, 250, 250))

    if pygame.font:
        font = pygame.font.Font(None, 36)
        text = font.render("Shut up 'n play yer keyboard!", 1, (10, 10, 10))
        textpos = text.get_rect(centerx=background.get_width()/2)
        background.blit(text, textpos)

    screen.blit(background, (0, 0))
    pygame.display.flip()


def main():

    pygameSetup()

    ser = serial.Serial('/dev/ttyACM0', 9600)

    clock = pygame.time.Clock()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
            elif event.type == pygame.KEYDOWN:
                ser.write(chr(event.key))            
            elif event.type == pygame.KEYUP:
                ser.write(chr(0))


if __name__ == '__main__': 
    main()