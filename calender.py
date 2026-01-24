import calendar

def display_calendar(year, month):
    try:
        # Print the calendar for the given month and year
        cal = calendar.month(year, month)
        print(cal)
    except:
        print("Invalid input! Please enter a valid year and month.")

if __name__ == "__main__":
    print("### Calendar Program ###")
    # Take user input for year and month
    year = int(input("Enter the year (e.g., 2024): "))
    month = int(input("Enter the month (1-12): "))

    # Display the calendar
    display_calendar(year, month)
