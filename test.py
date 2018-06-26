def amount(dic):
    return sheet["price"] * sheet["quantity"]


sheet = {"price": 100, "quantity": 25}
print(amount(sheet))
