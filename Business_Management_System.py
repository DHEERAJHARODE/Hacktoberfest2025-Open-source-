class Product:
    def __init__(self, name, price, stock):
        self.name = name
        self.price = price
        self.stock = stock

class Business:
    def __init__(self):
        self.products = []
        self.revenue = 0

    def add_product(self, name, price, stock):
        self.products.append(Product(name, price, stock))

    def view_products(self):
        for p in self.products:
            print(f"{p.name} - ${p.price} - Stock: {p.stock}")

    def sell_product(self, name, quantity):
        for p in self.products:
            if p.name == name:
                if p.stock >= quantity:
                    p.stock -= quantity
                    self.revenue += p.price * quantity
                    print(f"Sold {quantity} of {p.name}")
                else:
                    print("Insufficient stock")
                return
        print("Product not found")

    def view_revenue(self):
        print(f"Total Revenue: ${self.revenue}")

b = Business()

while True:
    print("\n1. Add Product")
    print("2. View Products")
    print("3. Sell Product")
    print("4. View Revenue")
    print("5. Exit")
    choice = input("Enter choice: ")

    if choice == '1':
        n = input("Product Name: ")
        p = float(input("Product Price: "))
        s = int(input("Stock Quantity: "))
        b.add_product(n, p, s)
    elif choice == '2':
        b.view_products()
    elif choice == '3':
        n = input("Product Name: ")
        q = int(input("Quantity: "))
        b.sell_product(n, q)
    elif choice == '4':
        b.view_revenue()
    elif choice == '5':
        break
    else:
        print("Invalid choice")
