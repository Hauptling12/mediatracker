#!/bin/python3
import pandas as pd
import os
import json
import sys
filename = '/home/' + os.environ["USER"] + '/.local/share/mediatracker/data.json'

if sys.argv[1] == "-h":
    print("-a   add media")
    print("-l   list media")
    print("-h   display this help")
if sys.argv[1] == "-l":
    print(pd.read_json(filename))
if sys.argv[1] == "-a":
    title = input("title: ")
    tv = input("is it a tv show? yes or no: ")
    if (tv == "yes") or (tv == "y"):
        eps = input("how many episode's: ")
        seasons = input("how many seasons: ")
    wat = input("watched yes or no: ")
# if tv == "yes":
    # wew = "{"title":"" + title + "","tv":"" + tv + "","eps":"" + eps + "","wat":"" + wat + ""}"
# else:
    # wew = "{"title":"" + title + "","tv":"" + tv + "","eps":"" + "0" + "","wat":"" + wat + ""}"
    d = {}
    d['title'] = title
    d['tv'] = tv
    if (tv == "yes") or (tv == "y"):
        d['seasons'] = seasons
        d['episode'] = eps
    else:
        d['episode'] = "0"
        d["seasons"] = "0"
    d['watched'] = wat
    entry = print(json.dumps(d))

# 1. Read file contents
    with open(filename, "r") as file:
         data = json.load(file)

 # 2. Update json object
    data.append(d)

 # 3. Write json file
    with open(filename, "w") as file:
        json.dump(data, file)
