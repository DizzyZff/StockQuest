import re
import time

import requests
import json
import os
import pandas as pd
import numpy as np
import sqlite3


# Fetch data from the API
def fetch_data():
    api_key = "U475FETN67CTAANU"
    interval = "1min"
    symbol = "AAPL"
    slice = []
    for i in range(1, 3):
        for j in range(1, 13):
            slice.append("year" + str(i) + "month" + str(j))

    for i in slice:
        url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY_EXTENDED&symbol=" + symbol + "&interval=" + interval + "&slice=" + i + "&apikey=" + api_key + "&datatype=csv"
        r = requests.get(url)
        print(r.status_code)
        with open("data/" + symbol + " " + i + ".csv", "wb") as code:
            code.write(r.content)
        print("Downloaded " + symbol + " " + i + ".csv")
        time.sleep(61)


# Create a database
def create_db():
    conn = sqlite3.connect('database.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE data
                    (time text, open real, high real, low real, close real, volume real, symbol text)''')
    conn.commit()
    conn.close()


# Insert data into the database
def insert_data(symbol):
    slice = []
    for i in range(1, 3):
        for j in range(1, 13):
            slice.append("year" + str(i) + "month" + str(j))
    for i in slice:
        file = "data/" + symbol + " " + i + ".csv"
        df = pd.read_csv(file)
        # add a column for symbol
        df['symbol'] = symbol
        print(df.head())
        conn = sqlite3.connect('database.db')
        df.to_sql('data', conn, if_exists='append', index=False)
        conn.commit()


#fetch_data()
create_db()
insert_data("AAPL")
