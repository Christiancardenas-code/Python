import tkinter as tk
from tkinter import messagebox

## Detalles de la ventana

ventana = tk.Tk()
ventana.title("Calculadora Perrona 2")
ventana.geometry("360x250")
ventana.resizable(0, 0)
ventana.iconbitmap("Texas-Willpower.ico")

## Contornos

contorno_1 = tk.LabelFrame(ventana, text = "Operaciones", font = "arial", width = 299, height = 82)
contorno_1.place(x = 24, y = 30)

contorno_2 = tk.LabelFrame(ventana, text = "Operadores", font = "arial", width = 299, height = 82)
contorno_2.place(x = 24, y = 138)

## Operadores

def suma():
   try:
        Num_1 = valor_1.get()
        Num_2 = valor_2.get()
    
        if Num_1 == "" or Num_2 == "":
            resultado["text"] = "¿?"
            messagebox.showinfo("Error", "Faltan valores")
        else:
            Resultado = int(Num_1) + int(Num_2)
            resultado["text"] = Resultado
   except:
        messagebox.showerror("Error", "Valores erroneos")
        
def resta():
   
   try:
        Num_1 = valor_1.get()
        Num_2 = valor_2.get()
    
        if Num_1 == "" or Num_2 == "":
            resultado["text"] = "¿?"
            messagebox.showinfo("Error", "Faltan valores")
        else:
            Resultado = int(Num_1) - int(Num_2)
            resultado["text"] = Resultado
   except:
        messagebox.showerror("Error", "Valores erroneos")
        
def multi():
   
   try:
        Num_1 = valor_1.get()
        Num_2 = valor_2.get()
    
        if Num_1 == "" or Num_2 == "":
            resultado["text"] = "¿?"
            messagebox.showinfo("Error", "Faltan valores")
        else:
            Resultado = int(Num_1) * int(Num_2)
            resultado["text"] = Resultado
   except:
        messagebox.showerror("Error", "Valores erroneos")
        
def divi():
   
   try:
        Num_1 = valor_1.get()
        Num_2 = valor_2.get()
    
        if Num_1 == "" or Num_2 == "":
            resultado["text"] = "¿?"
            messagebox.showinfo("Error", "Faltan valores")
        else:
            Resultado = int(Num_1) / int(Num_2)
            resultado["text"] = Resultado
   except:
        messagebox.showerror("Error", "Valores erroneos")

## Botones de operaciones

boton_suma = tk.Button(contorno_2, text = "+", font = "arial", width = 5, height = 1, command = suma)
boton_suma.place(x = 13, y = 2)

boton_resta = tk.Button(contorno_2, text = "-", font = "arial", width = 5, height = 1, command = resta)
boton_resta.place(x = 80, y = 2)

boton_multi = tk.Button(contorno_2, text = "*", font = "arial", width = 5, height = 1, command = multi)
boton_multi.place(x = 147, y = 2)

boton_divi = tk.Button(contorno_2, text = "/", font = "arial", width = 5, height = 1, command = divi)
boton_divi.place(x = 213, y = 2)

## Textbox y mensajes

valor_1 = tk.Entry(contorno_1, font = "arial", width = 5)
valor_1.place(x = 13, y = 10)
valor_1.insert(0, "0")

valor_2 = tk.Entry(contorno_1, font = "arial", width = 5)
valor_2.place(x = 110, y = 10)
valor_2.insert(0, "0")

resultado = tk.Label(contorno_1, text = "", fg = "black", bg = "white", font=("arial", 10), width = 7)
resultado.place(x = 210, y = 10)

texto_1 = tk.Label(ventana, text = "Numero 1", font = ("arial", 10))
texto_1.place(x = 38, y = 100)

texto_2 = tk.Label(ventana, text = "Numero 2", font = ("arial", 10))
texto_2.place(x = 134, y = 100)

texto_3 = tk.Label(ventana, text = "Resultado", font = ("arial", 10))
texto_3.place(x = 236, y = 100)

ventana.mainloop()