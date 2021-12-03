import json

data = {"json_object": []}


def fil_data(name, src, price):
    item = {"name": name, "src": src, "price": price}
    item = json.dumps(item)
    data["json_object"].append(item)


def get_data():
    return data
