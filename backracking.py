def recorrido(i, j):
    """ Dado un laberinto en donde se ubica un queso,
        retorna en una lista de pares ordenados (x,y)
        que indican el camino desde una posición inicial
        (i,j) hasta la posición en que se encuentra el
        queso.
        Entradas:
             (i, j) : posición inicial a partir de donde
                      se realizará la búsqueda de un camino
                      hasta la posición del queso.
        Salidas:
             Lista con las casillas, expresadas como pares
             ordenados, que llevan desde la posición inicial
             hasta la posición en que se encuentra el queso.
             Si no existe un camino retorna la lista vacía.
    """
 
    if laberinto[i][j] == 3:
        return [(i, j)]
 
    if laberinto[i][j] == 1:
        return []
 
    laberinto[i][j] = -1
 
    if i > 0 and laberinto[i - 1][j] in [0, 3]:                     # Norte
        camino = recorrido(i - 1, j)
        if camino: return [(i, j)] + camino
 
    if j < len(laberinto[i]) - 1 and laberinto[i][j + 1] in [0, 3]: # Este
        camino = recorrido(i, j + 1)
        if camino: return [(i, j)] + camino
 
    if i < len(laberinto) - 1 and laberinto[i + 1][j] in [0, 3]:    # Sur
        camino = recorrido(i + 1, j)
        if camino: return [(i, j)] + camino
 
    if j > 0 and laberinto[i][j - 1] in [0, 3]:                     # Oeste
        camino = recorrido(i, j - 1) 
        if camino: return [(i, j)] + camino
 
    return []
 
for x in recorrido(6,13) : print(x)