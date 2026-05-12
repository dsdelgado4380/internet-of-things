import matplotlib.pyplot as plt

# Datos de ejemplo
x = [1, 2, 3, 4, 5]
y = [10, 20, 25, 30, 42]

plt.plot(x, y, marker='o', linestyle='--', color='b')
plt.title("Mi primera gráfica en VS Code")
plt.xlabel("Eje X")
plt.ylabel("Eje Y")

# ¡Fundamental para que abra la ventana!
plt.show()