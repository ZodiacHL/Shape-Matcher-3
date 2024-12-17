import pygame

pygame.init()
screenWidth = 1280
screenHeight = 720
screen = pygame.display.set_mode((screenWidth, screenHeight))
pygame.display.set_caption("Shape Matcher 3")
clock = pygame.time.Clock()
running = True

x = 50
y = 50
width = 150
height = 150
vel_speed = 20

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
             running = False
    
    pygame.draw.rect(screen, (255,0,0), (x, y, width, height))
    pygame.display.update()

    keys = pygame.key.get_pressed()

    if keys[pygame.K_LSHIFT] and vel == vel_speed:
        vel = 1
    else:
        vel = vel_speed
    
    if keys[pygame.K_a] and x > vel - vel:
        x -= vel
    if keys[pygame.K_d] and x < screenWidth - width:
        x += vel
    if keys[pygame.K_w] and y > vel - vel:
        y -= vel
    if keys[pygame.K_s] and y < screenHeight - height:
        y += vel
        
    screen.fill((131,137,150))
    
    clock.tick(60)

pygame.quit()