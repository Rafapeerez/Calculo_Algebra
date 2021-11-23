"""
Name: Metodo de Euler
Author: Avaro David Serrano López
Date: 23/11/2021
Version: 1.0
"""

import matplotlib.pyplot as graficas # Implementamos matpotlib que es lo que nos va a hacer la grafica 

contador=1 # Definimos el contador para el bucle
x=[] # Definimos los vectores donde van ir quedando los resultados
y=[]

def solucion(funcion,x,y):
    return eval(funcion) #

paso = float(input("Introduzca el tamaño del paso: "))
fin = float(input("Introduzca el valor hasta donde quiere llegar: "))
iteraciones = (fin/paso) + 1 

funcion = input("Introduce la funcion a la que quiere implementar el metodo: ")
x.append(int(input("Introduzca el valor inicial para la X: ")))
y.append(int(input("Introduzca el valor inicial para la Y: ")))
print(x[0],y[0])

while contador <= iteraciones:
    x.append(x[contador-1]+ paso) 
    y.append(y[contador-1] + paso*(solucion(funcion,x[contador-1],y[contador-1])))
    print(f"El resultado de la iteracion {contador} es: ")
    print(x[contador], y[contador])
    contador = contador + 1



graficas.plot(x,y)
graficas.show()












    