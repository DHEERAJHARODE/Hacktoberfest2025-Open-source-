import math

def haversine_distance(lat1, lon1, lat2, lon2):
    """
    Calculate the great-circle distance between two points 
    on the earth (specified in decimal degrees)
    """
    # convert decimal degrees to radians 
    lon1, lat1, lon2, lat2 = map(math.radians, [lon1, lat1, lon2, lat2])

    # haversine formula 
    dlon = lon2 - lon1 
    dlat = lat2 - lat1 
    a = math.sin(dlat/2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon/2)**2
    c = 2 * math.asin(math.sqrt(a)) 
    r = 6371 # Radius of earth in kilometers. Use 3956 for miles
    return c * r

if __name__ == "__main__":
    # Co-ordinates of New York
    lat1, lon1 = 40.7128, -74.0060
    
    # Co-ordinates of London
    lat2, lon2 = 51.5074, -0.1278
    
    distance = haversine_distance(lat1, lon1, lat2, lon2)
    
    print(f"The distance between New York and London is {distance:.2f} km")
