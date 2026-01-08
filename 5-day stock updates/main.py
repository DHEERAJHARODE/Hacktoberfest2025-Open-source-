import requests
import itertools

# Required data
stock_name = input("Enter a stock symbol(like TSLA, IBM, MSFT, etc.): ")
API_KEY = "<your-api-key-here>"
API_ENDPOINT = "https://www.alphavantage.co/query"
API_FUNCTION = "TIME_SERIES_DAILY"

# Parameters
params = {
    'function': API_FUNCTION,
    'symbol': stock_name,
    'apikey': API_KEY
}

# Request response
response = requests.get(url=API_ENDPOINT, params=params)

# If status code is 200 display last 5 days stock data
if response.status_code == 200:
    data = response.json()['Time Series (Daily)']
    for (key, value) in itertools.islice(data.items(), 5):
        print(f"Date: {key}")
        print(f"Open: {data[key]['1. open']}")
        print(f"High: {data[key]['2. high']}")
        print(f"Low: {data[key]['3. low']}")
        print(f"Close: {data[key]['4. close']}")
        print()
# If error code produced
else:
    print("Error...")
