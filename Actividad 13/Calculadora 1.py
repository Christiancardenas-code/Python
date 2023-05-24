import tkinter as tk
import math

ventana = tk.Tk()

## Modificaciones de la ventana
ventana.title("Calculadora Perrona 2")
ventana.geometry("360x420")
ventana.resizable(0, 0)
ventana.iconbitmap("Texas-Willpower.ico")

## Operaciones
def Ent_Valores(tecla):
    try:
        if tecla >= "0" and tecla <= "9" or tecla == ".":
            entrada.set(entrada.get() + tecla)
            
        if tecla == "*" or tecla == "/" or tecla == "+" or tecla == "-":
            if tecla == "*":
                entrada.set(entrada.get() + "*")

            elif tecla == "/":
                entrada.set(entrada.get() + "/")

            elif tecla == "+":
                entrada.set(entrada.get() + "+")

            elif tecla == "-":
                entrada.set(entrada.get() + "-")

    except:
        entrada.set("ERROR")

def Mos_Res(tecla, *args):
    try:
        resultado = eval(entrada.get())
        entrada.set(resultado)

    except:
        entrada.set("ERROR")

def Raiz_Cuadrada():
    try:
        resultado = math.sqrt(float(entrada.get()))
        entrada.set(resultado)

    except:
        entrada.set("ERROR")

def Del(*args):
    inicio = 0
    final = len(entrada.get())
    entrada.set(entrada.get()[inicio:final-1])

def C_Borrar(*args):
    entrada.set("")

def Mmas():
    try:
        resultado = eval(entrada.get()) + float(entrada.get())
        entrada.set(resultado)

    except:
        entrada.set("ERROR")

def Mc():
    entrada.set("")

def Mr_Ms():
    try:
        resultado = eval(entrada.get())
        entrada.set(resultado)

    except:
        entrada.set("ERROR")

## Textbox
entrada = tk.StringVar()
caja_text = tk.Entry(ventana, font = ("Arial", 25), justify = tk.RIGHT, textvariable = entrada, bd=2)
caja_text.place(x = 20, y = 20, width = 315, height = 27)

## Botones de operaciones
Btn_Mas = tk.Button(ventana, text = "+", command = lambda: Ent_Valores("+"))
Btn_Mas.place(x = 219, y = 326, width = 50, height = 50)

Btn_Menos = tk.Button(ventana, text = "-", command = lambda: Ent_Valores("-"))
Btn_Menos.place(x = 219, y = 260, width = 50, height = 50)

Btn_Mul = tk.Button(ventana, text = "*", command = lambda: Ent_Valores("*"))
Btn_Mul.place(x = 219, y = 194, width = 50, height = 50)

Btn_Div = tk.Button(ventana, text = "/", command = lambda: Ent_Valores("/"))
Btn_Div.place(x = 219, y = 128, width = 50, height = 50)

Btn_Sqr = tk.Button(ventana, text = "sqr", command = lambda: Raiz_Cuadrada())
Btn_Sqr.place(x = 285, y = 62, width = 50, height = 50)

Btn_Punto = tk.Button(ventana, text = ".", command = lambda: Ent_Valores("."))
Btn_Punto.place(x = 153, y = 326, width = 50, height = 50)

Btn_Igual = tk.Button(ventana, text = "=", command = lambda: Mos_Res("="))
Btn_Igual.place(x = 285, y = 260, width = 50, height = 116)

Btn_Mc = tk.Button(ventana, text = "MC", command = lambda: Mc())
Btn_Mc.place(x = 22, y = 62, width = 50, height = 50)

Btn_Mr = tk.Button(ventana, text="MR", command=lambda:Mr_Ms())
Btn_Mr.place(x = 88, y = 62, width = 50, height = 50)

Btn_Ms = tk.Button(ventana, text = "MS", command = lambda: Mr_Ms())
Btn_Ms.place(x = 154, y = 62, width = 50, height = 50)

Btn_Mmas = tk.Button(ventana, text = "M+", command = lambda: Mmas())
Btn_Mmas.place(x = 220, y = 62, width = 50, height = 50)

Btn_Del = tk.Button(ventana, text = "<-", command = lambda: Del())
Btn_Del.place(x = 285, y = 194, width = 50, height = 50)

Btn_C = tk.Button(ventana, text = "C", command = lambda: C_Borrar())
Btn_C.place(x = 285, y = 128, width = 50, height = 50)

## Botones numericos
boton_1 = tk.Button(ventana, text = "1", command = lambda: Ent_Valores("1"))
boton_1.place(x = 21, y = 260, width = 50, height = 50)

boton_2 = tk.Button(ventana, text = "2", command = lambda: Ent_Valores("2"))
boton_2.place(x = 87, y = 260, width = 50, height = 50)

boton_3 = tk.Button(ventana, text = "3", command = lambda: Ent_Valores("3"))
boton_3.place(x = 153, y = 260, width = 50, height = 50)

boton_4 = tk.Button(ventana, text = "4", command = lambda: Ent_Valores("4"))
boton_4.place(x = 21, y = 194, width = 50, height = 50)

boton_5 = tk.Button(ventana, text = "5", command = lambda: Ent_Valores("5"))
boton_5.place(x = 87, y = 194, width = 50, height = 50)

boton_6 = tk.Button(ventana, text = "6", command = lambda: Ent_Valores("6"))
boton_6.place(x = 153, y = 194, width = 50, height = 50)

boton_7 = tk.Button(ventana, text = "7", command = lambda: Ent_Valores("7"))
boton_7.place(x = 21, y = 128, width = 50, height = 50)

boton_8 = tk.Button(ventana, text = "8", command = lambda: Ent_Valores("8"))
boton_8.place(x = 87, y = 128, width = 50, height = 50)

boton_9 = tk.Button(ventana, text = "9", command = lambda: Ent_Valores("9"))
boton_9.place(x = 153, y = 128, width = 50, height = 50)

boton_0 = tk.Button(ventana, text = "0", command = lambda: Ent_Valores("0"))
boton_0.place(x = 21, y = 326, width = 116, height = 50)

ventana.mainloop()