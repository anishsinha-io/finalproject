import os
import json
import struct

db_path = f"{os.getcwd()}/data/db.bin"
raw_path = f"{os.getcwd()}/data/raw.json"

packed_data_array = []
with open(raw_path, "r") as f:
    data = json.load(f)
    for obj in data["prizes"]:
        try:
            for person in obj["laureates"]:
                s = struct.Struct("I 50s 50s")
                packed_data = s.pack(int(person["id"]), bytes(person["firstname"], "utf-8"),
                                     bytes(person["surname"], "utf-8"))
                packed_data_array.append(packed_data)
        except KeyError as e:
            continue

with open(db_path, "w+b") as f:
    for el in packed_data_array:
        f.write(el)
