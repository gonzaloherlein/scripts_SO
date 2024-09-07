import multiprocessing  # Importa el módulo necesario para el manejo de procesos

def productor(cola, mensaje):
    """
    Función que se ejecuta en el primer proceso.
    Envía un mensaje (string) a la cola.
    """
    cola.put(mensaje)  # Coloca el mensaje en la cola de mensajes para ser enviado al otro proceso
    print("Mensaje enviado al proceso receptor.")

def receptor(cola):
    """
    Función que se ejecuta en el segundo proceso.
    Recibe el mensaje de la cola y lo imprime.
    """
    mensaje = cola.get()  # Obtiene el mensaje de la cola
    print("Proceso receptor recibió el mensaje:", mensaje)  # Imprime el mensaje recibido

if __name__ == '__main__':
    # Bloque necesario para que funcione correctamente en Windows

    # Tomamos la entrada del usuario en el proceso principal
    mensaje = input("Introduce un mensaje para enviar al otro proceso: ")

    # Creamos una cola de mensajes
    cola = multiprocessing.Queue()

    # Creamos los procesos: uno que envía el mensaje y otro que lo recibe
    proceso_emisor = multiprocessing.Process(target=productor, args=(cola, mensaje))
    proceso_receptor = multiprocessing.Process(target=receptor, args=(cola,))

    # Iniciamos los procesos
    proceso_emisor.start()
    proceso_receptor.start()

    # Esperamos a que los procesos terminen
    proceso_emisor.join()
    proceso_receptor.join()

    print("Comunicación entre procesos finalizada.")
